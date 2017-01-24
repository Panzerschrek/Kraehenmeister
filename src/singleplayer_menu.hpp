#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>

#include "i_menu_stack.hpp"

class SingleplayerMenu final : public QWidget
{
Q_OBJECT

public:
	SingleplayerMenu( QWidget* parent, IMenuStack& menu_stack );
	virtual ~SingleplayerMenu() override;

private:
	IMenuStack& menu_stack_;
	QBoxLayout layout_;
};
