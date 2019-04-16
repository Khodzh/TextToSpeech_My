#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString engine = QTextToSpeech::availableEngines().at(0);
    speech = new QTextToSpeech(engine, this);

    connect(speech, &QTextToSpeech::stateChanged, this, &MainWindow::speechState);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::start );

    speech->setLocale(speech->availableLocales().first());
    foreach(QLocale l, speech->availableLocales())
    {
        if(l.name() == "en_EN")
        {
            speech->setLocale( l );
        }
    }

    speech->setVoice(speech->availableVoices().last());
    foreach(QVoice v, speech->availableVoices())
    {
        qDebug() << v.name();
        if(v.name() == "Alexandr")
        {
            speech->setVoice(v);
        }
    }

    speech->setVolume(1);
    speech->setRate(0);
    speech->setPitch(-1);
}

MainWindow::~MainWindow()
{
    speech->stop();
    delete ui;
}

void MainWindow::speechState(QTextToSpeech::State state)
{

}

void MainWindow::start(bool b)
{
    text = ui->plainTextEdit->toPlainText();
    if(!text.isEmpty())
    {
        speech->say(text);
    }
}

void MainWindow::stop()
{

}

void MainWindow::voiceOptions()
{

}

void MainWindow::engineOptions()
{

}
