#include "KSJDemoQT_TriggerMode.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_TriggerMode w;
	w.show();
	return a.exec();
}
