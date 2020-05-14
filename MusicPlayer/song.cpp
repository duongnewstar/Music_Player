#include "song.h"

Song::Song()
{

}

Song::~Song()
{

}

Song::Song(QString name,QString artist,QString album,QString path):m_songName(name),
    m_artist(artist),m_album(album),m_path(path)
{

}

Song::Song(QString name)
{
    m_songName=name;
}
QString Song::getSongName() const{
    return m_songName;
}

QString Song::getAlbum() const
{
    return m_album;
}

QString Song::getArtist() const
{
    return m_artist;
}

QString Song::getPath() const
{
    return m_path;
}

void Song::setAlbum(QString album)
{
    m_album=album;
}

void Song::setSongName(QString name)
{
    m_songName=name;
}

void Song::setArtist(QString artist)
{
    m_artist=artist;
}

void Song::setPath(QString path)
{
    m_path=path;
}

bool Song::operator ==(const Song &song)
{
    if(this->m_songName==song.m_songName){
        return true;
    }
    else {
        return false;
    }
}

