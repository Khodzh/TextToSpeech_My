#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTextToSpeech>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void speechState(QTextToSpeech::State state);
    void start(bool b = true);
    void stop();
   void voiceOptions();
  void engineOptions();

private:
    Ui::MainWindow *ui;
    QTextToSpeech *speech;
    QVector<QVoice> voices;
    QString text;
};

#endif // MAINWINDOW_H
