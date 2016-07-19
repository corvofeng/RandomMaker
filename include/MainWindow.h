/******************************************************************************
 *  Copyright © 2016 corvo
 *  
 *  This file is part of RandomMaker.
 *  
 *  RandomMaker is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  RandomMaker is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with RandomMaker.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include "MakeRandom.h"

namespace Ui
{
class main_window;
}

// 主窗口
class MainWindow:public QMainWindow
{
        Q_OBJECT public:
        explicit MainWindow(QWidget * parent = 0);
        ~MainWindow();

private:
        void setTextRandom ();
        MakeRandom *makeRandom;
        Ui::main_window * ui;

private slots:
        void onBtnCheckClick ();
        void jsonSelect();
        void showOldData();
        void showAbout();
};

#endif // MAINWINDOW_H
