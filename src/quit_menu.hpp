#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>

#include "i_menu_stack.hpp"

class QuitMenu final : public QWidget
{
Q_OBJECT

public:
	QuitMenu( QWidget* parent, IMenuStack& menu_stack );
	virtual ~QuitMenu() override;

private:
	IMenuStack& menu_stack_;
	QBoxLayout layout_;
};
