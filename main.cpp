#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow fenetre(300,300);
    fenetre.show();

    return app.exec();
}
