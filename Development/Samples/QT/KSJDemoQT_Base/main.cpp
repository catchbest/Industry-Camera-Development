#include "KSJDemoQT_Base.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_Base w;
	w.show();
	return a.exec();
}
