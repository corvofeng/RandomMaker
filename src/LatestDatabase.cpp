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

#include "LatestDatabase.h"

LatestDatabase::LatestDatabase()
{
        openDatabase();
        this->tableModel = NULL;
}

QSqlDatabase LatestDatabase::getDataBase()
{
        return this->db;
}

QSqlTableModel* LatestDatabase::getAllData()
{
        if (tableModel == NULL) {
                this->tableModel = new QSqlTableModel();
        }
        this->tableModel->setTable(this->tableName);
        this->tableModel->select();
        return tableModel;
}

void LatestDatabase::openDatabase()
{
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(databaseName);
        if (!db.open())
        {
                qDebug () << "Connsqliteect Error";
                return;
        }
        query = QSqlQuery (db);

        int ok = query.exec("CREATE TABLE IF NOT EXISTS " + tableName +
                            "(id INTEGER PRIMARY " +
                            "KEY AUTOINCREMENT, " +
                            "event VARCHAR, " +
                            "output VARCHAR)"
                            );
        // 创建失败
        if (!ok)
        {
                qDebug() << db.lastError ().databaseText ();
        }

}

void LatestDatabase::InsertData(QString event, QString output)
{
        QSqlQuery insert = QSqlQuery(db);
        insert.prepare ("INSERT INTO " + tableName +
                        " (event, output) "
                        "VALUES "
                        "(:event, :output)"
                        );

        insert.bindValue(":event", event);
        insert.bindValue(":output", output);
        if (!insert.exec())
        {
                qDebug() << query.lastError().databaseText();
        }
}

/*
 * 所有数据包括事件名称和随机数序列, 数据库中均为String, 所以以分号隔开来返回
 * For example:
 *      "无名称事件;29;32;15;20;8;31;5;2;24;13"
 */
QString LatestDatabase::getLatestData()
{
        qDebug() << "show last time data";

        // 取得最后一条记录
        query.exec("select event,output from " + tableName + " ORDER BY ID DESC LIMIT 1");

        QString event;
        QString output;
        if (query.next())
        {
                event = query.value(0).toString ();
                output = query.value(1).toString ();
        }
        qDebug() << event + ";" + output;
        return event+ ";" + output;
}

LatestDatabase::~LatestDatabase()
{
        db.close ();
        if (tableModel != NULL) {
                delete tableModel;
        }
}
