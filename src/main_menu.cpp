#include <QPushButton>

#include "main_menu.hpp"

MainMenu::MainMenu( QWidget* const parent, IMenuStack& menu_stack )
	: QWidget( parent )
	, menu_stack_( menu_stack )
	, layout_( QBoxLayout::TopToBottom, this )
{
	QPushButton* const new_button= new QPushButton( "New", this );
	layout_.addWidget( new_button );
	connect(
		new_button, &QPushButton::clicked,
		[this]
		{
			printf( "clicked\n" );
		} );

	QPushButton* const quit_button= new QPushButton( "Quit", this );
	layout_.addWidget( quit_button );
	connect(
		quit_button, &QPushButton::clicked,
		[this]
		{
			menu_stack_.PushMenu( quit_menu_.data() );
		} );

	layout_.setSizeConstraint( QBoxLayout::SetFixedSize );

	quit_menu_= new QuitMenu( parent, menu_stack );
	quit_menu_->setVisible( false );
}

MainMenu::~MainMenu()
{
}
