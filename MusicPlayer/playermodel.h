#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QObject>
#include <QMediaPlayer>

class PlayerModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QMediaPlayer::State playerState READ playerState WRITE setPlayerState NOTIFY playerStateChanged)
    Q_PROPERTY(bool playbtn READ playbtn WRITE setPlaybtn NOTIFY playbtnChanged)
    Q_PROPERTY(bool prevbtn READ prevbtn WRITE setPrevbtn NOTIFY prevbtnChanged)
    Q_PROPERTY(bool nextbtn READ nextbtn WRITE setNextbtn NOTIFY nextbtnChanged)
    Q_PROPERTY(bool repeatbtn READ repeatbtn WRITE setRepeatbtn NOTIFY repeatbtnChanged)
    Q_PROPERTY(bool shufflebtn READ shufflebtn WRITE setShufflebtn NOTIFY shufflebtnChanged)
    Q_PROPERTY(bool checkImage READ checkImage WRITE setCheckImage NOTIFY checkImageChanged)
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coverart READ coverart WRITE setCoverart NOTIFY coverartChanged)
    Q_PROPERTY(QUrl cover READ cover WRITE setcover NOTIFY coverChanged)
    Q_PROPERTY(int rotorStatus READ rotorStatus WRITE setRotorStatus NOTIFY rotorStatusChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)

private:
    QMediaPlayer::State m_playerState;
    bool m_playbtn;
    bool m_prevbtn;
    bool m_nextbtn;
    bool m_repeatbtn;
    bool m_shufflebtn;
    bool m_checkImage;
    qint64 m_duration;
    qint64 m_position;
    QString m_title;
    QString m_coverart;
    QUrl m_cover;
    int m_rotorStatus;
    int m_volume;

public:
    explicit PlayerModel(QObject *parent = nullptr);
    ~PlayerModel();
    QMediaPlayer::State playerState() const;
    bool playbtn() const;
    bool prevbtn() const;
    bool nextbtn() const;
    bool repeatbtn() const;
    bool shufflebtn() const;
    bool checkImage() const;
    qint64 duration() const;
    qint64 position() const;
    QString title() const;
    QString coverart() const;
    QUrl cover() const;
    int rotorStatus() const;
    int volume() const;

signals:
    void playerStateChanged(QMediaPlayer::State playerState);
    void playbtnChanged(bool playbtn);
    void prevbtnChanged(bool prevbtn);
    void nextbtnChanged(bool nextbtn);
    void repeatbtnChanged(bool repeatbtn);
    void shufflebtnChanged(bool shufflebtn);
    void checkImageChanged(bool checkImage);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);
    void titleChanged(QString title);
    void coverartChanged(QString coverart);
    void coverChanged(QUrl cover);
    void rotorStatusChanged(int rotorStatus);
    void volumeChanged(int volume);

public slots:
    void setPlayerState(QMediaPlayer::State playerState);
    void setPlaybtn(bool playbtn);
    void setPrevbtn(bool prevbtn);
    void setNextbtn(bool nextbtn);
    void setRepeatbtn(bool repeatbtn);
    void setShufflebtn(bool shufflebtn);
    void setCheckImage(bool checkImage);
    void setDuration(qint64 duration);
    void setPosition(qint64 position);
    void setTitle(QString title);
    void setCoverart(QString coverart);
    void setcover(QUrl cover);
    void setRotorStatus(int rotorStatus);
    void setVolume(int volume);
};

#endif // PLAYERMODEL_H
