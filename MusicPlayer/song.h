#ifndef SONG_H
#define SONG_H
#include <QString>

class Song

{
public:
    Song();
    ~Song();
    Song(QString,QString,QString,QString);
    Song(QString);
    QString getSongName() const;
    QString getAlbum() const;
    QString getArtist() const;
    QString getPath() const;
    void setAlbum(QString album);
    void setSongName(QString name);
    void setArtist(QString artist);
    void setPath(QString path);
    static const QString pathFolder;
    bool operator ==(const Song& );
private:
    QString m_songName;
    QString m_album;
    QString m_artist;
    QString m_path;
};

#endif // SONG_H
