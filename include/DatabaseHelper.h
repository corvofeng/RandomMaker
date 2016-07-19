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

#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include "LatestDatabase.h"
#include <QSqlTableModel>

// 数据库帮助类, 调用此类实现数据库操作, 可以将此类更改来实现数据库连接池
class DataBaseHelper
{
public:
        DataBaseHelper();
        static void saveLatestData (QString event, QString outRandom);
        static QSqlTableModel* getAllDataModel();
        static QString getLatestData();

private:
        static LatestDatabase myDB;
};

#endif // DATABASEHELPER_H
