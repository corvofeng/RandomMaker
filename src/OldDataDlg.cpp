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

#include "OldDataDlg.h"
#include "ui_old_data_dlg.h"
#include <QDialog>
#include <QSqlTableModel>
#include "QStandardItemModel"
#include "DatabaseHelper.h"

OldDataDlg::OldDataDlg(QWidget * parent):
        QDialog (parent), ui (new Ui::old_data_dlg)
{
        ui->setupUi (this);
        ui->dataTable->setModel(DataBaseHelper::getAllDataModel());

//        QStandardItemModel *model = new QStandardItemModel (2, 3);
//        model->setHorizontalHeaderItem (0, new QStandardItem (QString ("Column1 Header")));
//        model->setHorizontalHeaderItem (1, new QStandardItem (QString ("Column2 Header")));
//        model->setHorizontalHeaderItem (2, new QStandardItem (QString ("Column3 Header")));
//        QStandardItem *first = new QStandardItem (QString ("ColumnValue"));
//        model->setItem (0, 0, first);
//        ui->dataTable->setModel (model);
}
