#include <QPushButton>

#include "main_menu.hpp"

MainMenu::MainMenu( QWidget* const parent, IMenuStack& menu_stack )
	: QWidget( parent )
	, menu_stack_( menu_stack )
	, layout_( QBoxLayout::TopToBottom, this )
{
	QPushButton* const new_button= new QPushButton( "Singleplayer", this );
	layout_.addWidget( new_button );
	connect(
		new_button, &QPushButton::clicked,
		[this]
		{
			menu_stack_.PushMenu( singleplayer_menu_.data() );
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

	singleplayer_menu_= new SingleplayerMenu( parent, menu_stack );
	singleplayer_menu_->setVisible( false );

	quit_menu_= new QuitMenu( parent, menu_stack );
	quit_menu_->setVisible( false );
}

MainMenu::~MainMenu()
{
}
