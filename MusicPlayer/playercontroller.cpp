#include "playercontroller.h"

Playercontroller::~Playercontroller()
{
    delete m_player;
    m_player=nullptr;
    delete m_playlist;
    m_playlist=nullptr;
}

Playercontroller::Playercontroller(QObject *parent) : QObject(parent),m_playbtn(true),m_prevbtn(true),
    m_nextbtn(true),m_shufflebtn(true),m_duration(0),m_position(0),
    m_rotorStatus(0),m_cover("image://ImageProvider/defaultCD.png"),m_volume(50),
    m_playerState(QMediaPlayer::StoppedState),m_clearbtn(true)
{
    m_player->setPlaylist(m_playlist);
    QObject::connect(m_player,&QMediaPlayer::durationChanged,this,&Playercontroller::getDuration);
    QObject::connect(m_player,&QMediaPlayer::positionChanged,this,&Playercontroller::getPosition);
    QObject::connect(m_player,&QMediaPlayer::currentMediaChanged,this,&Playercontroller::saveCurrentState);
    QObject::connect(m_player,&QMediaPlayer::metaDataAvailableChanged,this,&Playercontroller::getSongName);
    QObject::connect(m_player,&QMediaPlayer::metaDataAvailableChanged,this,&Playercontroller::getCoverArt);
    QObject::connect(this,&Playercontroller::volumeChanged,this,&Playercontroller::changeVolume);
    QObject::connect(m_player,&QMediaPlayer::stateChanged,this,&Playercontroller::setPlayerState);
    QObject::connect(this,&Playercontroller::playerStateChanged,this,&Playercontroller::saveCurrentState);
}

QString Playercontroller::converttime(qint64 time)
{
    QString s=QString("%1").arg(time, 2, 10, QChar('0'));
    return s;
}

void Playercontroller::addFolder()
{
    QFileDialog filedialog;
    QStringList folder;
    filedialog.setFileMode(QFileDialog::DirectoryOnly);
    filedialog.exec();
    folder=filedialog.selectedFiles();
    QDir dir(folder[0]);
    QStringList listsong = dir.entryList(QStringList() << "*.mp3" << "*.MP3",QDir::Files);
    for(QString filename: listsong) {
        m_playlist->addMedia(QUrl::fromLocalFile((folder[0])+"/"+filename));
        emit list_music1(filename);

    }
    m_player->setPlaylist(m_playlist);
}

void Playercontroller::addSong()
{
    QFileDialog filedialog;
    QStringList Myfile;
    filedialog.setFileMode(QFileDialog::ExistingFiles);
    filedialog.exec();
    Myfile=filedialog.selectedFiles();
    for(QString filename: Myfile)
    {
        m_playlist->addMedia(QUrl::fromLocalFile(filename));
        emit list_music1(filename);
    }
    m_player->setPlaylist(m_playlist);
}

void Playercontroller::playSong()
{
    if(m_playbtn){
        m_player->play();
    }
    else{
        m_player->pause();
    }
}

void Playercontroller::nextSong()
{
    if(m_playlist->currentIndex()==m_playlist->mediaCount()-1&&m_playlist->playbackMode()==2){
    }
    else {
        m_playlist->next();
        qDebug()<<m_playlist->currentIndex();
        qDebug()<<m_player->duration();
    }
}

void Playercontroller::prevSong()
{
    if(m_playlist->currentIndex()==0&&m_playlist->playbackMode()==2){
    }
    else{
        m_playlist->previous();
    }
}

void Playercontroller::shuffleSong()
{
    if(!m_shufflebtn){
        m_playlist->setPlaybackMode(QMediaPlaylist::Sequential);
        qDebug()<<"Shuffle off";
    }
    else{
        m_playlist->setPlaybackMode(QMediaPlaylist::Random);
        qDebug()<<"Shuffle on";
    }
    setShufflebtn(!shufflebtn());
    emit playerStateChanged();
}

void Playercontroller::repeatSong()
{
    if(!m_repeatbtn){
        m_playlist->setPlaybackMode(QMediaPlaylist::Sequential);
    }
    else{
        m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    }
    setRepeatbtn(!repeatbtn());
    emit playerStateChanged();
}

void Playercontroller::setSongPosition(qint64 pos)
{
    m_player->setPosition(pos);
}

void Playercontroller::changeVolume()
{
    m_player->setVolume(m_volume);
    emit playerStateChanged();
}

void Playercontroller::process(int a)
{
    switch (a) {
    case 0:
        return addFolder();
    case 1:
        return addSong();
    case 2:
        return playSong();
    case 3:
        return nextSong();
    case 4:
        return prevSong();
    case 5:
        return shuffleSong();
    case 6:
        return repeatSong();
    case 7:
        return loadLastState();
    default:
        break;
    }
}

void Playercontroller::playSelectedSong(int current_index)
{
    m_playlist->setCurrentIndex(current_index);
    m_player->play();
}

void Playercontroller::getSongName()
{
    if(m_player->isMetaDataAvailable()){
        setTitle(m_player->metaData(QMediaMetaData::Title).toString());
    }
}

void Playercontroller::getCoverArt()
{
    if(m_player->isMetaDataAvailable()){

        //        QByteArray bArray;
        //        QBuffer buffer(&bArray);
        //        QVariant  images = m_player->metaData(QMediaMetaData::CoverArtImage) ;

        //        buffer.open(QIODevice::WriteOnly);

        //        QImage ac = images.value<QImage>();
        //        ac.save(&buffer,"JPEG");
        //        qDebug()<<ac;
        //        QString image("data:image/jpg;base64,");
        //        image.append(QString::fromLatin1(bArray.toBase64().data()));
        //        qDebug()<<images;
        //        setCoverart(image);
        //        //    if(ac==NULL){
        //        //        setCheckImage(false);
        //        //    }
        QUrl url=m_player->metaData(QMediaMetaData::CoverArtUrlLarge).value<QUrl>();
        if(url==QUrl::fromUserInput("")){
            return;
        }
        setcover(url);
    }
}

void Playercontroller::changePlayRate(qreal rate)
{
    m_player->setPlaybackRate(rate);
}

void Playercontroller::getDuration()
{
    setDuration(m_player->duration());
    emit playerStateChanged();
}

void Playercontroller::getPosition()
{
    setPosition(m_player->position());
    emit playerStateChanged();
}

void Playercontroller::saveCurrentState()
{
    std::ofstream fileOutput("../MusicPlayer/state.txt");

    if (fileOutput.fail())
    {
        return;
    }
    if(!fileOutput.eof()){
        fileOutput<<m_repeatbtn<<","<<m_shufflebtn<<","<<m_position<<","<<m_volume<<",";
        QString aa = m_player->currentMedia().canonicalUrl().toString();
        std::string str = aa.toStdString();
        fileOutput<<str;
    }
}
void Playercontroller::loadLastState()
{
    std::ifstream fileInput("../MusicPlayer/state.txt");
    if (fileInput.fail())
    {
        return;
    }
    if(!fileInput.eof()){
        std::string data;
        fileInput>>data;
        QString qdata=QString::fromStdString(data);
        m_repeatbtn= !(qdata.split(",")[0].toInt());
        repeatSong();
        this->m_shufflebtn = qdata.split(",")[1].toInt();
        if(m_shufflebtn){
            this->m_playlist->setPlaybackMode(QMediaPlaylist::Sequential);
        }
        else{
            this->m_playlist->setPlaybackMode(QMediaPlaylist::Random);
        }
        int pos = qdata.split(",")[2].toInt();
        this->m_volume = qdata.split(",")[3].toInt();
        QUrl url=QUrl::fromUserInput(qdata.split(",")[4]);
        if(url==QUrl::fromUserInput("")){
            return;
        }
        else{
            m_playlist->addMedia(url);
            m_player->setPlaylist(m_playlist);
            setSongPosition(pos);
            emit list_music1(qdata.split(",")[4]);
        }
    }
}

void Playercontroller::removeCurrentItem(int index)
{
    m_playlist->removeMedia(index);
    m_player->setPlaylist(m_playlist);
}

bool Playercontroller::playbtn() const
{
    return m_playbtn;
}

bool Playercontroller::prevbtn() const
{
    return m_prevbtn;
}

bool Playercontroller::nextbtn() const
{
    return m_nextbtn;
}

bool Playercontroller::repeatbtn() const
{
    return m_repeatbtn;
}

bool Playercontroller::shufflebtn() const
{
    return m_shufflebtn;
}

qint64 Playercontroller::duration() const
{
    return m_duration;
}

qint64 Playercontroller::position() const
{
    return m_position;
}

QString Playercontroller::title() const
{
    return m_title;
}

int Playercontroller::rotorStatus() const
{
    return m_rotorStatus;
}

QUrl Playercontroller::cover() const
{
    return m_cover;
}

int Playercontroller::volume() const
{
    return m_volume;
}

QMediaPlayer::State Playercontroller::playerState() const
{
    return m_playerState;
}

bool Playercontroller::clearbtn() const
{
    return m_clearbtn;
}


void Playercontroller::setPlaybtn(bool playbtn)
{
    if (m_playbtn == playbtn)
        return;
    m_playbtn = playbtn;
    emit playbtnChanged(m_playbtn);
}

void Playercontroller::setPrevbtn(bool prevbtn)
{
    if (m_prevbtn == prevbtn)
        return;
    m_prevbtn = prevbtn;
    emit prevbtnChanged(m_prevbtn);
}

void Playercontroller::setNextbtn(bool nextbtn)
{
    if (m_nextbtn == nextbtn)
        return;
    m_nextbtn = nextbtn;
    emit nextbtnChanged(m_nextbtn);
}

void Playercontroller::setRepeatbtn(bool repeatbtn)
{
    if (m_repeatbtn == repeatbtn)
        return;
    m_repeatbtn = repeatbtn;
    emit repeatbtnChanged(m_repeatbtn);
    emit playerStateChanged();
}

void Playercontroller::setShufflebtn(bool shufflebtn)
{
    if (m_shufflebtn == shufflebtn)
        return;
    m_shufflebtn = shufflebtn;
    emit shufflebtnChanged(m_shufflebtn);
    emit playerStateChanged();
}

void Playercontroller::setDuration(qint64 duration)
{
    if (m_duration == duration)
        return;
    m_duration = duration;
    emit durationChanged(m_duration);
}

void Playercontroller::setPosition(qint64 position)
{
    if (m_position == position)
        return;
    m_position = position;
    emit positionChanged(m_position);
}

void Playercontroller::setTitle(QString title)
{
    if (m_title == title)
        return;
    m_title = title;
    emit titleChanged(m_title);
}

void Playercontroller::setRotorStatus(int rotorStatus)
{
    if (m_rotorStatus == rotorStatus)
        return;

    m_rotorStatus = rotorStatus;
    emit rotorStatusChanged(m_rotorStatus);
}

void Playercontroller::setcover(QUrl cover)
{
    if (m_cover == cover)
        return;

    m_cover = cover;
    emit coverChanged(m_cover);
}

void Playercontroller::setVolume(int volume)
{
    if (m_volume == volume)
        return;
    m_volume = volume;
    emit volumeChanged(m_volume);
}

void Playercontroller::setPlayerState(QMediaPlayer::State playerState)
{
    if (m_playerState == playerState)
        return;

    m_playerState = playerState;
    switch (playerState) {
    case QMediaPlayer::StoppedState:
        setPlaybtn(true);
        setRotorStatus(2);
        break;
    case QMediaPlayer::PlayingState:
        setPlaybtn(false);
        setRotorStatus(1);
        break;
    case QMediaPlayer::PausedState:
        setPlaybtn(true);
        setRotorStatus(2);
        break;
    }
    emit playerStateChanged();
}

void Playercontroller::setClearbtn(bool clearbtn)
{
    if (m_clearbtn == clearbtn)
        return;

    m_clearbtn = clearbtn;
    emit clearbtnChanged(m_clearbtn);
}


