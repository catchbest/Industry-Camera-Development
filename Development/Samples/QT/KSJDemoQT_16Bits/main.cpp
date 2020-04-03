#include "KSJDemoQT_16Bits.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_16Bits w;
	w.show();
	return a.exec();
}
