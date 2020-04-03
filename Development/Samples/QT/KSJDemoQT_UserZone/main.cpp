#include "KSJDemoQT_UserZone.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_UserZone w;
	w.show();
	return a.exec();
}
