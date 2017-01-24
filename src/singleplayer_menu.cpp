#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

#include "singleplayer_menu.hpp"

#include "main_menu.hpp"

SingleplayerMenu::SingleplayerMenu( QWidget* const parent, IMenuStack& menu_stack )
	: QWidget( parent )
	, menu_stack_(menu_stack)
	, layout_( QBoxLayout::LeftToRight, this )
{
	QPushButton* const new_button= new QPushButton( "new", this );
	layout_.addWidget( new_button );
	connect(
		new_button, &QPushButton::clicked,
		[this]
		{
		} );


	QPushButton* const load_button= new QPushButton( "load", this );
	layout_.addWidget( load_button );
	connect(
		load_button, &QPushButton::clicked,
		[this]
		{
		} );

	QPushButton* const save_button= new QPushButton( "save", this );
	layout_.addWidget( save_button );
	connect(
		save_button, &QPushButton::clicked,
		[this]
		{
		} );

	layout_.setSizeConstraint( QBoxLayout::SetFixedSize );
}

SingleplayerMenu::~SingleplayerMenu()
{
}
