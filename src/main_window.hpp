#pragma once
#include <QtCore/QPointer>
#include <QtCore/QVector>
#include <QtWidgets/QMainWindow>

#include "i_menu_stack.hpp"
#include "main_menu.hpp"

class MainWindow final : public QMainWindow, public IMenuStack
{
Q_OBJECT

public:
	MainWindow();
	virtual ~MainWindow() override;

public: // IMenuStack
	virtual void PushMenu( QWidget* widget ) override;
	virtual void PopMenu() override;

public:
	virtual void keyPressEvent( QKeyEvent* event ) override;

private:
	QPointer<MainMenu> main_menu_;
	QVector<QWidget*> menu_stack_;
};
