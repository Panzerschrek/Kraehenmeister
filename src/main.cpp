#include <QtWidgets/QApplication>

#include "main_window.hpp"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	MainWindow main_window;

	return app.exec();
}
