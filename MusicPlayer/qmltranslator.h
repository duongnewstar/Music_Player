#ifndef QMLTRANSLATOR_H
#define QMLTRANSLATOR_H

#include <QObject>
#include <QTranslator>
class Qmltranslator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptytxt READ emptytxt NOTIFY languageChanged)

public:
    explicit Qmltranslator(QObject *parent = nullptr);

signals:
    void languageChanged();

public:
    Q_INVOKABLE void setTranslation(QString translation);

    QString emptytxt() const;

public slots:

private:
    QTranslator m_translator;
    QString m_emptytxt;
};

#endif // QMLTRANSLATOR_H
