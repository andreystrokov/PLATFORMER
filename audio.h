#ifndef AUDIO_H
#define AUDIO_H


#include <QObject>
#include <QMediaPlayer>

class audio : public QObject
{
    Q_OBJECT
public:
    explicit audio(QObject* parent = nullptr);
signals:

public slots:
    void play();
};

#endif // AUDIO_H
