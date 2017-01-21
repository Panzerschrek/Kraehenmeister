#include <cassert>

#include "main_window.hpp"

MainWindow::MainWindow()
{
	main_menu_= new MainMenu( this );
	PushMenu( main_menu_.data() );

	show();
}

MainWindow::~MainWindow()
{}

void MainWindow::PushMenu( QWidget* const widget )
{
	menu_stack_.push_back( widget );
	setCentralWidget( widget );
}

void MainWindow::PopMenu()
{
	assert( menu_stack_.size() >= 2 );
	menu_stack_.pop_back();
	setCentralWidget( menu_stack_.back() );
}
