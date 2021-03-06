######################################################################
# Automatically generated by qmake (3.1) Mon Apr 6 15:41:33 2020
######################################################################

TEMPLATE = vcapp
TARGET = DinosaurusMain
#INCLUDEPATH += C:\Users\PHODMAN.DESKTOP-1VM7GFC\Desktop\New folder\S2-2020-GI\App7\Dinosaurus_rex
INCLUDEPATH += C:\Users\faund\Desktop\Uni\S2\APP7\Problematique\Dinosaurus_rex

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += warn_on qt debug windows console

# Input
HEADERS += header/level.h \
           header/obstacle.h \
           header/player.h \
           header/list.h \
           header/vecteur.h \
           header/dinosaurus.h \
           header/mainMenu.h \
           header/meteorite.h \
           header/bullet.h \
		   header/leaderboard.h \ 
           header/cloud.h
SOURCES += src/level.cpp \
           src/main.cpp \
           src/obstacle.cpp \
           src/player.cpp \
           src/meteorite.cpp \
           src/bullet.cpp \
           src/mainMenu.cpp \
           src/dinosaurus.cpp \
		   src/leaderboard.cpp \
           src/cloud.cpp

QT += widgets
