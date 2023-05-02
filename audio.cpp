#include "audio.h"
#include <QAudioOutput>
audio::audio(QObject *parent) : QObject{parent}
{


}

void audio::play()
{
    QMediaPlayer *player = new QMediaPlayer(this);

        // set the audio file to play
        player = new QMediaPlayer;
        QAudioOutput* audioOutput = new QAudioOutput;
        player->setAudioOutput(audioOutput);
        connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        player->setSource(QUrl::fromLocalFile("/home/andrey/music.mp3"));
        audioOutput->setVolume(50);
        player->play();
        //       return 0;
}
