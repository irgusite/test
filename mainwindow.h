#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QPushButton>
#include <QMessageBox>
#include <QtNetwork>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(int width, int height);
    
signals:
    
public slots:
    void changeBar();
    void finishedSlot(QNetworkReply* );

private:
    QProgressBar *m_progress;
    QSlider *m_slider;
    QPushButton *m_button;
    QNetworkAccessManager *nam;
    QLabel *m_label;
    
};

#endif // MAINWINDOW_H
