#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton buton("Bonjour le monde");
    buton.show();

    return app.exec();
}
