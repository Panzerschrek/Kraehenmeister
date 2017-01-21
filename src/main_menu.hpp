#pragma once
#include <QtCore/QPointer>
#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>

#include "i_menu_stack.hpp"
#include "quit_menu.hpp"

class MainMenu final : public QWidget
{
Q_OBJECT

public:
	MainMenu( QWidget* parent, IMenuStack& menu_stack );
	virtual ~MainMenu() override;

private:
	IMenuStack& menu_stack_;
	QBoxLayout layout_;
	QPointer <QuitMenu> quit_menu_;
};
