#include "playermodel.h"

PlayerModel::PlayerModel(QObject *parent) : QObject(parent),m_playbtn(true),m_prevbtn(true),
    m_nextbtn(true),m_repeatbtn(true),m_shufflebtn(true),m_duration(0),m_position(0),m_coverart(""),m_checkImage(true),
    m_rotorStatus(0),m_cover("image://ImageProvider/defaultCD.png"),m_volume(50)
{

}

PlayerModel::~PlayerModel()
{

}

QMediaPlayer::State PlayerModel::playerState() const
{
    return m_playerState;
}

bool PlayerModel::playbtn() const
{
    return m_playbtn;
}

bool PlayerModel::prevbtn() const
{
    return m_prevbtn;
}

bool PlayerModel::nextbtn() const
{
    return m_nextbtn;
}

bool PlayerModel::repeatbtn() const
{
    return m_repeatbtn;
}

bool PlayerModel::shufflebtn() const
{
    return m_shufflebtn;
}

bool PlayerModel::checkImage() const
{
    return m_checkImage;
}

qint64 PlayerModel::duration() const
{
    return m_duration;
}

qint64 PlayerModel::position() const
{
    return m_position;
}

QString PlayerModel::title() const
{
    return m_title;
}

QString PlayerModel::coverart() const
{
    return m_coverart;
}

QUrl PlayerModel::cover() const
{
    return m_cover;
}

int PlayerModel::rotorStatus() const
{
    return m_rotorStatus;
}

int PlayerModel::volume() const
{
    return m_volume;
}

void PlayerModel::setPlayerState(QMediaPlayer::State playerState)
{
    if (m_playerState == playerState)
        return;
    switch (playerState) {
    case QMediaPlayer::StoppedState:
        setPlaybtn(true);
        break;
    case QMediaPlayer::PlayingState:
        setPlaybtn(false);
        break;
    case QMediaPlayer::PausedState:
        setPlaybtn(true);
        break;
    }
    m_playerState = playerState;
    emit playerStateChanged(m_playerState);
}

void PlayerModel::setPlaybtn(bool playbtn)
{
    if (m_playbtn == playbtn)
        return;

    m_playbtn = playbtn;
    emit playbtnChanged(m_playbtn);
}

void PlayerModel::setPrevbtn(bool prevbtn)
{
    if (m_prevbtn == prevbtn)
        return;

    m_prevbtn = prevbtn;
    emit prevbtnChanged(m_prevbtn);
}

void PlayerModel::setNextbtn(bool nextbtn)
{
    if (m_nextbtn == nextbtn)
        return;

    m_nextbtn = nextbtn;
    emit nextbtnChanged(m_nextbtn);
}

void PlayerModel::setRepeatbtn(bool repeatbtn)
{
    if (m_repeatbtn == repeatbtn)
        return;

    m_repeatbtn = repeatbtn;
    emit repeatbtnChanged(m_repeatbtn);
}

void PlayerModel::setShufflebtn(bool shufflebtn)
{
    if (m_shufflebtn == shufflebtn)
        return;

    m_shufflebtn = shufflebtn;
    emit shufflebtnChanged(m_shufflebtn);
}

void PlayerModel::setCheckImage(bool checkImage)
{
    if (m_checkImage == checkImage)
        return;

    m_checkImage = checkImage;
    emit checkImageChanged(m_checkImage);
}

void PlayerModel::setDuration(qint64 duration)
{
    if (m_duration == duration)
        return;

    m_duration = duration;
    emit durationChanged(m_duration);
}

void PlayerModel::setPosition(qint64 position)
{
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged(m_position);
}

void PlayerModel::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void PlayerModel::setCoverart(QString coverart)
{
    if (m_coverart == coverart)
        return;

    m_coverart = coverart;
    emit coverartChanged(m_coverart);
}

void PlayerModel::setcover(QUrl cover)
{
    if (m_cover == cover)
        return;

    m_cover = cover;
    emit coverChanged(m_cover);
}

void PlayerModel::setRotorStatus(int rotorStatus)
{
    if (m_rotorStatus == rotorStatus)
        return;

    m_rotorStatus = rotorStatus;
    emit rotorStatusChanged(m_rotorStatus);
}

void PlayerModel::setVolume(int volume)
{
    if (m_volume == volume)
        return;

    m_volume = volume;
    emit volumeChanged(m_volume);
}
