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

#include "MakeRandom.h"
#include "DatabaseHelper.h"

void swap(int &a, int &b)
{
        int c = a;
        a = b;
        b = c;
}

MakeRandom::MakeRandom()
{
        srand(time(0));
        isCreate = false;
}

MakeRandom::MakeRandom(QString start, QString end, QString unconsider, QString count)
{
        srand(time(0));
        setStartNum(start);
        setEndNum(end);
        setCountNum(count);
        setUnconsiderNum(unconsider);
        isCreate = false;
}

void MakeRandom::setStartNum(QString start)
{
        startNum = start.toInt();
}

void MakeRandom::setEndNum(QString end)
{
        endNum = end.toInt();
}

void MakeRandom::setCountNum(QString count)
{
        countNum = count.toInt();
}

// 一部分数据从数据库读入
void MakeRandom::setUnconsiderNum(QString unconsider)
{
        if (!unconsiderNumList.isEmpty())
        {
                unconsiderNumList.clear();
        }

        // 从界面读入
        QStringList list = unconsider.split(";");
        for (int i = 0; i < list.size(); i++)
        {
                unconsiderNumList.append(list[i].toInt());
        }

        // 从数据库读取最后一次生成的随机数
        QStringList lastList = DataBaseHelper::getLatestData().split (";");
        for (int i = 1; i < lastList.size(); i++)
        {
                unconsiderNumList.append(lastList[i].toInt());
        }

        qSort(unconsiderNumList);               // 排序
        setLatestEvent(lastList[0]);
}

void MakeRandom::setEventName(QString eventName)
{
        this->eventName = eventName;
}

void MakeRandom::setLatestEvent(QString eventName)
{
        this->latestEventName = eventName;
}

int MakeRandom::getCountNum()
{
        return this->countNum;
}

int MakeRandom::getEndNum()
{
        return this->endNum;
}

int MakeRandom::getStartNum()
{
        return this->startNum;
}

QString MakeRandom::getLatestEvent()
{
        return getLatestEvent();
}

MakeRandom::~MakeRandom ()
{
}

void MakeRandom::createRandom ()
{
        int totalCnt = endNum - startNum + 1;
        if ((totalCnt - unconsiderNumList.size ()) < countNum)
        {
                return;
        }

        outputNumList.clear ();
        int *app = new int[totalCnt];
        random (app, totalCnt);

        for (int i = 0; i < totalCnt; i++)
                app[i] += 1;

        int tmpCnt = countNum;
        for (int i = 0; i < tmpCnt; i++)
        {
                if (unconsiderNumList.contains(app[i]))
                {
                        tmpCnt += 1;
                        continue;
                }
                outputNumList.append(app[i]);
        }

        isCreate = true;

        qSort(outputNumList);                   // 排序
        delete[]app;
}

QString MakeRandom::getUnconsiderNum()
{
        qDebug() << "In The MakeRandom::getUnconsiderNum";
        QString unconsider = "";
        int i;
        for (i = 0; i < unconsiderNumList.size() - 1; i++)
        {
                unconsider += QString::number(unconsiderNumList[i]) + "  ";
        }
        unconsider += QString::number(unconsiderNumList[i]);
        qDebug() << unconsider << endl;

        return unconsider;
}

QString MakeRandom::getOutputRandom()
{
        QString out;

        if (!isCreate)
        {
                return "";
        }

        int i;
        for (i = 0; i < outputNumList.size () - 1; i++)
        {
                out += QString::number(outputNumList[i]) + "  ";
        }
        out += QString::number(outputNumList[i]);

        return out;
}

// return Random Array String
QString MakeRandom::getDatabaseRandom()
{
        QString out;

        if (!isCreate)
        {
                return "";
        }

        int i;
        for (i = 0; i < outputNumList.size () - 1; i++)
        {
                out = out + QString::number (outputNumList[i]) + ";";
        }
        out = out + QString::number (outputNumList[i]);

        isCreate = false;
        return out;
}

/*
 *
 * 在此处进行数据库操作并不是十分优雅, 但是更改了显示就必须更新数据库,
 * 所以我放在了一起, 可能我的功底还不够
 *
 */
QString MakeRandom::getOutput()
{
        QString out;
        if (!isCreate) {
                out += "输入数据有误, 未产生随机数";
                return out;
        }
        out += "This time we don't consider those number: \n";
        out += "    " + getUnconsiderNum();
        out += "\n\n";
        out += "This time we choose: \n";
        out += "    " + getOutputRandom();

        // 将此次产生的随机数存入数据库
        DataBaseHelper::saveLatestData(this->eventName, getDatabaseRandom());

        qDebug() << out << endl;

        return out;
}

void MakeRandom::showData ()
{
        qDebug() << "In The MakeRandom::showData";
        qDebug() << startNum << endNum << countNum;
        qDebug() << eventName;
        for (int i = 0; i < unconsiderNumList.size(); i++)
        {
                qDebug () << unconsiderNumList[i] << "  ";
        }
}

void MakeRandom::random(int *num, int totalCnt)
{
        for (int i = 0; i < totalCnt; i++)
        {
                num[i] = i;
        }

        for (int i = totalCnt - 1; i >= 1; i--)
        {
                int x = rand () % i;
                swap(num[x], num[i]);
        }

}
