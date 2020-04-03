#include "KSJDemoQT_Image.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_Image w;
	w.show();
	return a.exec();
}
