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

#ifndef OLD_DATA_DLG_H
#define OLD_DATA_DLG_H

#include <QDialog>
#include <QDebug>

namespace Ui
{
class old_data_dlg;
}

class OldDataDlg:public QDialog
{
Q_OBJECT public:
        explicit OldDataDlg(QWidget * parent = 0);
        void setData(QString output);

private:
        Ui::old_data_dlg* ui;
};

#endif // OLD_DATA_DLG_H
