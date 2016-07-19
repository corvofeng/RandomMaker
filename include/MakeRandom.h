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

#ifndef RANDOM_H
#define RANDOM_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <QTextBrowser>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "LatestDatabase.h"

void swap (int &a, int &b);

/*
 * 程序中的核心类, 随机数产生及数据库处理
 *
 */

class MakeRandom
{
private:
        int startNum;
        int endNum;
        QString eventName;              // 每产生一次随机数, 都需要设置事件名称
        QString latestEventName;        // 最近一次事件的名称

        QVector<int> unconsiderNumList; // 不加考虑的序列
        int countNum;                   // 产生随机数个数
        QVector<int> outputNumList;     // 产生的数据集合
        bool isCreate;


public:
        MakeRandom();

        MakeRandom(QString start, QString end, QString unconsider, QString count);

        // 一些set, get函数
        void setStartNum(QString start);
        void setEndNum(QString end);
        void setCountNum(QString count);
        void setUnconsiderNum(QString unconsider);
        void setEventName(QString eventName);
        void setLatestEvent(QString eventName);

        int getStartNum();
        int getEndNum();
        int getCountNum();
        QString getOutputRandom();
        QString getUnconsiderNum();
        QString getLatestEvent();

        void showData();                        // Debug函数

        ~MakeRandom();

        void createRandom();                    // 用户主动调用, 生成随机数

        QString getOutput();                    // 产生结果, 同时更改数据库


private:
        // 由createRandom调用
        void random(int *num, int totalCnt);

        // 产生数据库插入文本
        QString getDatabaseRandom();
};

#endif
