#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>

class MainMenu final : public QWidget
{
Q_OBJECT

public:
	explicit MainMenu( QWidget* parent );
	virtual ~MainMenu() override;

private:
	QBoxLayout layout_;
};
