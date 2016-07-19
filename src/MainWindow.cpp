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

#include "MainWindow.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QDebug>
#include <OldDataDlg.h>
#include "ui_about.h"
#include <QIcon>

MainWindow::MainWindow (QWidget * parent):
        QMainWindow (parent), ui (new Ui::main_window)
{
        ui->setupUi (this);
        ui->BtnCheck->setText ("确认");

        connect(ui->BtnCheck, &QPushButton::clicked, this, &MainWindow::onBtnCheckClick);
        connect(ui->jsonSelect, &QAction::triggered, this, &MainWindow::jsonSelect);
        connect(ui->ShowOldData, &QAction::triggered, this, &MainWindow::showOldData);
        connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAbout);

        ui->statusBar->showMessage("本次不考虑的同学填入不参与框中, 以`;`间隔", 3000);
}

void MainWindow::showOldData ()
{
        qDebug () << "Show Old Data";
        OldDataDlg *oldDataDlg = new OldDataDlg(this);
        oldDataDlg->show();
}

void MainWindow::onBtnCheckClick()
{
        setTextRandom ();
}

void MainWindow::setTextRandom ()
{
        QString startNum = ui->lineEditStartNum->text ();
        QString endNum = ui->lineEditEndNum->text ();
        QString countNum = ui->lineEditCount->text ();
        QString unconsiderNum = ui->lineEditUnconsider->text ();

        // 询问用户此次的活动名称
        bool ok;
        QString event = QInputDialog::getText(this, tr("Event name"),
                                              tr("Input Event"),
                                              QLineEdit::Normal,
                                              tr("无名称事件"),
                                              &ok
                                              );
        if (!ok) {
                ui->textRandomOut->setText(tr("请输入此次事件名称"));
                return;
        }

        qDebug() << event;

        makeRandom = new MakeRandom ();
        // 初始化
        makeRandom->setStartNum (startNum);
        makeRandom->setEndNum (endNum);
        makeRandom->setCountNum (countNum);
        makeRandom->setUnconsiderNum (unconsiderNum);
        makeRandom->setEventName(event);

        // 产生随机数
        makeRandom->createRandom ();

        QString str = makeRandom->getOutput();

        // 更新textBrowser
        ui->textRandomOut->setText(str);
}

void MainWindow::jsonSelect ()
{
        QString sFileName;
        QFileDialog *fileDialog = new QFileDialog (this);
        fileDialog->setWindowTitle ("Json File");
        fileDialog->setDirectory (".");
        fileDialog->setNameFilter ("JSON Config (*.json)");
        fileDialog->setViewMode (QFileDialog::Detail);
        fileDialog->setFileMode (QFileDialog::ExistingFile);

        if (fileDialog->exec () == QDialog::Accepted)
        {
                sFileName = fileDialog->selectedFiles ()[0];
        }
        else
        {
                sFileName = "Thank You";
        }

        qDebug () << sFileName;
        ui->textRandomOut->setText (sFileName);
}

void MainWindow::showAbout()
{
        QMessageBox::about(this, "RandomMaker", "A small random maker");
}

MainWindow::~MainWindow ()
{
        delete ui;
        delete makeRandom;
}
