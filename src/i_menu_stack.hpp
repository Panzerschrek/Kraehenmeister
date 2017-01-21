#pragma once
#include <QtWidgets/QWidget>

class IMenuStack
{
public:
	virtual ~IMenuStack(){}

	virtual void PushMenu( QWidget* widget )= 0;
	virtual void PopMenu()= 0;
};
