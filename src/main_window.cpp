#include <cassert>

#include "main_window.hpp"

MainWindow::MainWindow()
{
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
