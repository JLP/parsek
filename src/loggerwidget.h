/* loggerwidget.h

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

#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include "ui_loggerwidget.h"
#include <QWidget>
#include <tpproto/logger.h>

class LoggerWidget : public QWidget, public Ui::LoggerWidget,
                     public TPProto::Logger
{
public:
    LoggerWidget(QWidget *parent = 0);
    virtual ~LoggerWidget();
    void error(const char* mesg, ...);
    void warning(const char* mesg, ...);
    void info(const char* mesg, ...);
    void debug(const char* mesg, ...);
};

#endif // LOGGERWIDGET_H
