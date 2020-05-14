

#include "qmltranslator.h"
#include <QApplication>
#include <QDebug>
Qmltranslator::Qmltranslator(QObject *parent) : QObject(parent)
{

}

void Qmltranslator::setTranslation(QString translation)
{
    qDebug() << Q_FUNC_INFO + translation;
    m_translator.load(":/QmlLanguage_" + translation + ".qm");
    qApp->installTranslator(&m_translator);
    emit languageChanged();
}

QString Qmltranslator::emptytxt() const
{
    return "";
}
