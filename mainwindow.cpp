#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QWidget(parent)//constructeur
{
    setFixedSize(800,600);

}
MainWindow::MainWindow(int width, int height) : QWidget(0)
{
    setFixedSize(width, height);

    m_progress = new QProgressBar(this);
    m_progress->setGeometry(10, 20, 150, 30);

    m_button = new QPushButton("Reset", this);
    m_button->setGeometry(150, 80, 50, 20);

    m_label = new QLabel(this);
    m_label->move(10, 200);
    m_label->setText("Mon text");

    //connect(m_slider, SIGNAL(valueChanged(int)), m_progress, SLOT(setValue(int)));
    connect(m_button, SIGNAL(clicked()), this, SLOT(changeBar()));
}
void MainWindow::changeBar()
{
    m_progress->setValue(0);

    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
    QUrl url("http://localhost/clear.html");

    QNetworkReply* reply = nam->get(QNetworkRequest(url));


    //QMessageBox::information(this, "Bonjour", "Vous avez appuye sur le bouton reset! Cool!");
}
void MainWindow::finishedSlot(QNetworkReply* reply)
{
        // no error received?
        if (reply->error() == QNetworkReply::NoError)
        {
            // read data from QNetworkReply here
            m_progress->setValue(70);


            // Example 2: Reading bytes form the reply
            QByteArray bytes = reply->readAll();  // bytes
            QString str(bytes); // string
            //m_label->setText(bytes);
            m_progress->setValue(100);

            //QMessageBox::information(this, "Bonjour", "Recu!");

        }
        // Some http error received
        else
        {
            // handle errors here
        }

        // We receive ownership of the reply object
        // and therefore need to handle deletion.
        delete reply;
}
