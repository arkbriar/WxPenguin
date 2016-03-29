TEMPLATE = app

CONFIG += release console

TARGET = WxPenguin

QMAKE_CXX_FLAGS_RELEASE -= O2
QMAKE_CXX_FLAGS_RELEASE += -Ofast -flto -fno-strict-aliasing -std=c++11
QMAKE_LFLAGS_RELEASE -= -Wl,-O1
QMAKE_LFLAGS_RELEASE += -Ofast -flto -Wl,-rpath,. -Wl,-rpath,lib -Wl,-rpath,/usr/lib64/ -Wl,-rpath,/usr/lib

RESOURCES += ui/ui.qrc
RESOURCES += ui/img.qrc

QT += qml quick script network core

SOURCES += ui/ui_main.cc \
        ui/ui_handler.cc \
        wxqt/qthttp.cc \
        plugin/dynamiclib.cc \
        plugin/plugin_instance.cc \
        plugin/plugin_manager.cc \
        utils/utils.cc \

HEADERS += ui/ui_handler.hpp \
        utils/utils.hpp \
        wxqt/qthttp.hpp \
        plugin/dynamiclib.hpp \
        plugin/plugin_instance.hpp \
        plugin/plugin_manager.hpp \
        plugin/wxplugin.hpp \

unix:!macx: {
# STATIC -Wl,-Bstatic
# DYNAMIC
    LIBS += lib/libwebwx.so
}

INCLUDEPATH += include/ \
