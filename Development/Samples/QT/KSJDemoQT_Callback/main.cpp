#include "KSJDemoQT_Callback.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KSJDemoQT_Callback w;
	w.show();
	return a.exec();
}
