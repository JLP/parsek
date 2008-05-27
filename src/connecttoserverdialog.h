/* connecttoserverdialog.h

    Parsek - free client for playing 4X space strategy games
    Copyright (C) 2006-2007  Jure Repinc <jlp@holodeck1.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef CONNECTTOSERVERDIALOG_H
#define CONNECTTOSERVERDIALOG_H

#include "ui_connecttoserverdialog.h"
#include <QDialog>

class ConnectToServerDialog : public QDialog, public Ui::ConnectToServerDialog
{
    Q_OBJECT
public:
    ConnectToServerDialog(QWidget *parent = 0);
private slots:
    void enableConnectButton(const QString &text);
};

#endif // CONNECTTOSERVERDIALOG_H
