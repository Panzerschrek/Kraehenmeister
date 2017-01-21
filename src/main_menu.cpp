#include <QPushButton>

#include "main_menu.hpp"

MainMenu::MainMenu( QWidget* const parent )
	: QWidget( parent )
	, layout_( QBoxLayout::TopToBottom, this )
{
	layout_.addWidget( new QPushButton( "New", this ) );
	layout_.addWidget( new QPushButton( "Quit", this ) );
}

MainMenu::~MainMenu()
{}
