#include <cassert>
#include <QtGui/QtEvents>
#include <QtGui/QPainter>

#include "main_window.hpp"

MainWindow::MainWindow()
{
	resize( 640, 480 );

	background_image_= QImage( QString( "back.png" ) );

	main_menu_= new MainMenu( this, *this );
	PushMenu( main_menu_.data() );

	show();
}

MainWindow::~MainWindow()
{
}

void MainWindow::PushMenu( QWidget* const widget )
{
	if( !menu_stack_.empty() )
	{
		takeCentralWidget();
		menu_stack_.back()->setVisible( false );
	}

	menu_stack_.push_back( widget );
	setCentralWidget( widget );
	widget->setVisible( true );
}

void MainWindow::PopMenu()
{
	assert( menu_stack_.size() >= 2 );

	QWidget* const previous_widget= menu_stack_.back();
	menu_stack_.pop_back();
	QWidget* const current_widget= menu_stack_.back();

	previous_widget->setVisible( false );
	current_widget->setVisible( true );
	takeCentralWidget();
	setCentralWidget( current_widget );
}

void MainWindow::keyPressEvent( QKeyEvent* const event )
{
	if( event == nullptr )
		return;

	if( event->key() == Qt::Key_Escape )
	{
		if( menu_stack_.size() >= 2 )
			PopMenu();

		event->accept();
	}
}

void MainWindow::paintEvent( QPaintEvent* const event )
{
	Q_UNUSED(event);

	QPainter painter( this );

	const QSize window_size= QWidget::size();
	const QSize img_size= background_image_.size();

	QRectF target_rect;
	target_rect.setLeft  ( window_size.width () / 2 - img_size.width() / 2 );
	target_rect.setRight ( target_rect.left()       + img_size.width() );
	target_rect.setTop   ( window_size.height() / 2 - img_size.height() / 2 );
	target_rect.setBottom( target_rect.top()        + img_size.height() );

	painter.drawImage( target_rect, background_image_, background_image_.rect() );
}
