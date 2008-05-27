/* connecttoserverdialog.cpp

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

#include "connecttoserverdialog.h"
#include "connecttoserverdialog.moc"

ConnectToServerDialog::ConnectToServerDialog(QWidget *parent)
                          : QDialog(parent)
{
    setupUi(this);
    serversHistoryCombo->addToHistory("demo1.thousandparsec.net");
    enableConnectButton(serversHistoryCombo->currentText());
    connect(cancelButton, SIGNAL(clicked()),
            this, SLOT(reject()));
    connect(connectButton, SIGNAL(clicked()),
            this, SLOT(accept()));
    connect(serversHistoryCombo, SIGNAL(editTextChanged(const QString &)),
            this, SLOT(enableConnectButton(const QString &)));
}

void ConnectToServerDialog::enableConnectButton(const QString &text)
{
    connectButton->setEnabled(!text.isEmpty());
}
