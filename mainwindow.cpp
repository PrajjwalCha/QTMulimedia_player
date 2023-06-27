
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    video = new QVideoWidget(this);
    audio = new QAudioOutput(this);
    video->setGeometry(45,20,1080,720);
    player->setAudioOutput(audio);
    player->setVideoOutput(video);
    connect(player,&QMediaPlayer::positionChanged , this ,&MainWindow::on_positionChange);
    connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::on_durationChange);
}
QString source;
int audiostate = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    source = QFileDialog::getOpenFileName(this,"Open a File","",tr("Open File(*.mp3 *.mkv *.mp4 *.av *.mvb)"));
    player->setSource(QUrl::fromLocalFile(source));
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();    
}

void MainWindow::on_actionPause_triggered()
{
    player ->pause();
}

void MainWindow::on_actionMute_triggered()
{
    audiostate += 1;
    if(audiostate %2 != 0){
        audio->setMuted(true);

    }
    else{
        audio->setMuted(false);
    }
}

void MainWindow::on_ProgressBar_sliderMoved(int position)
{
    player->setPosition(position);
}


void MainWindow::on_positionChange(qint64 position)
{
    ui->ProgressBar->setValue(position);
}

void MainWindow::on_durationChange(qint64 position)
{
    ui->ProgressBar->setMaximum(position);
}

void MainWindow::on_verticalSliderVolume_sliderMoved(int position)
{
    qreal vol = QAudio::convertVolume(position/qreal(100.0),QAudio::LogarithmicVolumeScale,QAudio::LinearVolumeScale);
    audio->setVolume(vol);
}

