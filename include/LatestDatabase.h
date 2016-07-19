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

#ifndef LATESTDATABASE_H
#define LATESTDATABASE_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include "OldDataDlg.h"

/*
 *
 *  程序采用sqlite数据库
 *  不允许直接调用该类, 所有操作封装在DatabaseHelper中,
 *
 *
 */
class LatestDatabase
{
private:
        QSqlDatabase db;
        QSqlTableModel *tableModel;
        QSqlQuery query;
        QString databaseName = "latest.db";
        QString tableName = "latest_choose";

        void openDatabase ();

public:
        LatestDatabase();
        ~LatestDatabase();

        QSqlDatabase getDataBase();

        // Input
        void InsertData(QString event, QString output);

        // Output
        QString getLatestData();
        QSqlTableModel *getAllData();
};

#endif // LATESTDATABASE_H
