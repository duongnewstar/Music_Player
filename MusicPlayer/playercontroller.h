#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include <QString>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QDebug>
#include <QMediaMetaData>
#include <QImage>
#include <QBuffer>
#include <QByteArray>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <iostream>
#include <string>
#include <fstream>
#include "songmodel.h"
#include "song.h"
#include <QMediaResource>

class Playercontroller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playbtn READ playbtn WRITE setPlaybtn NOTIFY playbtnChanged)
    Q_PROPERTY(bool prevbtn READ prevbtn WRITE setPrevbtn NOTIFY prevbtnChanged)
    Q_PROPERTY(bool nextbtn READ nextbtn WRITE setNextbtn NOTIFY nextbtnChanged)
    Q_PROPERTY(bool repeatbtn READ repeatbtn WRITE setRepeatbtn NOTIFY repeatbtnChanged)
    Q_PROPERTY(bool shufflebtn READ shufflebtn WRITE setShufflebtn NOTIFY shufflebtnChanged)
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QUrl cover READ cover WRITE setcover NOTIFY coverChanged)
    Q_PROPERTY(int rotorStatus READ rotorStatus WRITE setRotorStatus NOTIFY rotorStatusChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(QMediaPlayer::State playerState READ playerState WRITE setPlayerState NOTIFY playerStateChanged)
    Q_PROPERTY(bool clearbtn READ clearbtn WRITE setClearbtn NOTIFY clearbtnChanged)
public:
    ~Playercontroller();
    explicit Playercontroller(QObject *parent = nullptr);
    Q_INVOKABLE QString converttime(qint64);
    void addFolder();
    void addSong();
    void playSong();
    void nextSong();
    void prevSong();
    void shuffleSong();
    void repeatSong();
    Q_INVOKABLE void setSongPosition(qint64);
    Q_INVOKABLE void changeVolume();
    Q_INVOKABLE void process(int);
    Q_INVOKABLE void playSelectedSong(int);
    void getSongName();
    void getCoverArt();
    Q_INVOKABLE void changePlayRate(qreal);
    void getDuration();
    void getPosition();
    void saveCurrentState();
    void loadLastState();
    void removeCurrentItem(int index);

    bool playbtn() const;
    bool prevbtn() const;
    bool nextbtn() const;
    bool repeatbtn() const;
    bool shufflebtn() const;
    qint64 duration() const;
    qint64 position() const;
    QString title() const;
    qreal playRate() const;    
    int rotorStatus() const;
    QUrl cover() const;
    int volume() const;

    QMediaPlayer::State playerState() const;

    bool clearbtn() const;

signals:

    void playbtnChanged(bool playbtn);
    void prevbtnChanged(bool prevbtn);
    void nextbtnChanged(bool nextbtn);
    void repeatbtnChanged(bool repeatbtn);
    void shufflebtnChanged(bool shufflebtn);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);
    void titleChanged(QString title);
    void rotorStatusChanged(int rotorStatus);
    void list_music1(QString song);
    void coverChanged(QUrl cover);
    void volumeChanged(int volume);
    void currentStateChanged();

    void playerStateChanged();

    void clearbtnChanged(bool clearbtn);

public slots:
    void setPlaybtn(bool playbtn);
    void setPrevbtn(bool prevbtn);
    void setNextbtn(bool nextbtn);
    void setRepeatbtn(bool repeatbtn);
    void setShufflebtn(bool shufflebtn);
    void setDuration(qint64 duration);
    void setPosition(qint64 position);
    void setTitle(QString title);
    void setRotorStatus(int rotorStatus);
    void setcover(QUrl cover);
    void setVolume(int volume);

    void setPlayerState(QMediaPlayer::State playerState);

    void setClearbtn(bool clearbtn);

private:
    QMediaPlayer* m_player = new QMediaPlayer();
    QMediaPlaylist* m_playlist=new QMediaPlaylist();

//    PlayerModel m_model;
    bool m_playbtn;
    bool m_prevbtn;
    bool m_nextbtn;
    bool m_repeatbtn;
    bool m_shufflebtn;
    qint64 m_duration;
    qint64 m_position;
    QString m_title;
    int m_rotorStatus;
    QUrl m_cover;
    int m_volume;
    QMediaPlayer::State m_playerState;
    QUrl m_currentSongUrl;
    bool m_clearbtn;
};

#endif // PLAYERCONTROLLER_H
