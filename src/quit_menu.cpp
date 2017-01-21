#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

#include "quit_menu.hpp"


#include <QPushButton>

#include "main_menu.hpp"

QuitMenu::QuitMenu( QWidget* const parent, IMenuStack& menu_stack )
	: QWidget( parent )
	, menu_stack_(menu_stack)
	, layout_( QBoxLayout::LeftToRight, this )
{
	QPushButton* const yes_button= new QPushButton( "Yes", this );
	layout_.addWidget( yes_button );
	connect(
		yes_button, &QPushButton::clicked,
		[this]
		{
			QApplication::instance()->quit();
		} );


	QPushButton* const no_button= new QPushButton( "No", this );
	layout_.addWidget( no_button );
	connect(
		no_button, &QPushButton::clicked,
		[this]
		{
			menu_stack_.PopMenu();
		} );

	layout_.setSizeConstraint( QBoxLayout::SetFixedSize );
}

QuitMenu::~QuitMenu()
{
}
