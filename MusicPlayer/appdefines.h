#ifndef APPDEFINES_H
#define APPDEFINES_H
#include <QObject>
#include <QMap>

#define MAIN_QML    "qrc:/main.qml"

class AppEnums: public QObject
{
    Q_OBJECT

    Q_ENUMS(SCREEN_ID)
    Q_ENUMS(LIST_CATEGORY)
    Q_ENUMS(LIST_FUNCTION)
public:
    enum SCREEN_ID: int
    {
//        SCREEN_ID_HOME,

        // music screens
        SCREEN_ID_MUSIC_PLAYER,
        SCREEN_ID_MUSIC_LIST,

        // video screens
//        SCREEN_ID_VIDEO_PLAYER,

//        // photo screens
//        SCREEN_ID_PHOTO_VIEWER,
    };

    enum LIST_CATEGORY: int
    {
        LIST_CATEGORY_SONG,
        LIST_CATEGORY_FOLDER,
        LIST_CATEGORY_ALBUM,
        LIST_CATEGORY_ARTIST,
    };
    enum LIST_FUNCTION: int
    {
        ADD_FOLDER,
        ADD_SONG,
        PLAY_SONG,
        NEXT_SONG,
        PREV_SONG,
        SHUFFLE_SONG,
        REPEAT_SONG,
        LOAD_LAST_STATE,
    };
};

const QMap<int, QString> ScreenNameMap
{
//    {AppEnums::SCREEN_ID_HOME, "qrc:/Screen/HomeScreen.qml"},

    // music screens
    {AppEnums::SCREEN_ID_MUSIC_PLAYER, "qrc:/Screen/PlayerScreen.qml"},
    {AppEnums::SCREEN_ID_MUSIC_LIST, "qrc:/Screen/ListScreen.qml"},

};
#endif // APPDEFINES_H
