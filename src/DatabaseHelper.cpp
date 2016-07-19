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

#include "DatabaseHelper.h"

// 初始化静态变量
LatestDatabase DataBaseHelper::myDB = LatestDatabase();

DataBaseHelper::DataBaseHelper()
{

}

void DataBaseHelper::saveLatestData(QString event, QString outRandom)
{
        DataBaseHelper::myDB.InsertData(event, outRandom);
}

QString DataBaseHelper::getLatestData()
{
        return DataBaseHelper::myDB.getLatestData();
}

QSqlTableModel * DataBaseHelper::getAllDataModel()
{
        return DataBaseHelper::myDB.getAllData();
}
