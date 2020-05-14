#ifndef BUTTONSIGNAL_H
#define BUTTONSIGNAL_H

#include <QObject>
#include <QDebug>

class Buttonsignal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playbtn READ playbtn WRITE setplaybtn NOTIFY playbtnChanged)
    Q_PROPERTY(bool nextbtn READ nextbtn WRITE setnextbtn NOTIFY nextbtnChanged)
    bool m_playbtn;

    bool m_nextbtn;

public:
    explicit Buttonsignal(QObject *parent = nullptr);

bool playbtn() const;

bool nextbtn() const
{
    return m_nextbtn;
}

signals:

void playbtnChanged(bool playbtn);

void nextbtnChanged(bool nextbtn);

public slots:
void setplaybtn(bool playbtn);
void setnextbtn(bool nextbtn)
{
    if (m_nextbtn == nextbtn)
        return;

    m_nextbtn = nextbtn;
    emit nextbtnChanged(m_nextbtn);
}
};

#endif // BUTTONSIGNAL_H
