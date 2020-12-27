#include <QApplication>
#include "dialog.h"
#include "mainwindow.h"
#include <QTime>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include<QtMultimedia/QMediaPlayer>
#include <QMediaPlaylist>
int Volume;
QString filePath;
QString musicPath;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    musicPath=("qrc:/picture/summer.mp3");
    QMediaPlayer *player;
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl(musicPath));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    //gameList->addMedia(QUrl("qrc:/img/game.mp3"));//添加音乐
    //gameList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放

    player=new QMediaPlayer;//设置默认背景音乐
    player->setMedia(QUrl(musicPath));
    Volume=5;
    player->setVolume(Volume);//音量
    player->play();
    Dialog dlg;
    dlg.show();
    return app.exec();

}
