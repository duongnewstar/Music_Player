#ifndef SONGMODEL_H
#define SONGMODEL_H
#include <QAbstractListModel>
#include "song.h"
#include <QObject>
#include <QSortFilterProxyModel>

enum SongRoles {
    name = Qt::UserRole + 1,
    path,
    artist,
    album
};
class SongModel : public QAbstractListModel
{
    Q_OBJECT
public:

    SongModel(QObject * parent = nullptr);
    void addSong(const Song &song);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public slots:
    void list_music(QString music);
    void getCurrentSongIndex(QString);
    void removeCurrentItem();
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Song> listSong;
    int m_index = 0;
signals:
    void currentItemRemoved(int index);

};

class FilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:

    FilterProxyModel(QObject* parent = nullptr);

    ~FilterProxyModel();

    Q_INVOKABLE void setFilterString(QString string);

    Q_INVOKABLE void setSortOrder(bool checked);
    void clear(int);
};
#endif // SONGMODEL_H
