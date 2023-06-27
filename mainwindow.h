
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionMute_triggered();

    void on_ProgressBar_sliderMoved(int position);


    void on_positionChange(qint64 position);

    void on_durationChange(qint64 position);


    void on_verticalSliderVolume_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *video;
    QAudioOutput *audio;
};

#endif // MAINWINDOW_H
