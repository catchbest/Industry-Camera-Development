#include "KSJDemoQT_Matrix.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_Matrix w;
	w.show();
	return a.exec();
}
