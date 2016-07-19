#-------------------------------------------------
# Copyright © 2016 corvo
# 
# This file is part of RandomMaker.
# 
# RandomMaker is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# RandomMaker is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with RandomMaker.  If not, see <http://www.gnu.org/licenses/>.
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Random
TEMPLATE = app


SOURCES +=\
    tests/Main.cpp \
    src/OldDataDlg.cpp \
    src/MakeRandom.cpp \
    src/MainWindow.cpp \
    src/LatestDatabase.cpp \
    src/DatabaseHelper.cpp

INCLUDEPATH += ./include/
HEADERS  += \
    include/DatabaseHelper.h \
    include/OldDataDlg.h \
    include/LatestDatabase.h \
    include/MainWindow.h \
    include/MakeRandom.h

FORMS    += \
    ui/main_window.ui \
    ui/old_data_dlg.ui \
    ui/about.ui
