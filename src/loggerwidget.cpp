/* loggerwidget.cpp

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

#include "loggerwidget.h"
#include "loggerwidget.moc"
#include <QString>
#include <cstdarg>

LoggerWidget::LoggerWidget(QWidget *parent)
            : QWidget(parent)
{
    setupUi(this);
}

LoggerWidget::~LoggerWidget()
{
}

void LoggerWidget::error(const char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "EE: " + message;
    logView->append(fullmessage);
}

void LoggerWidget::warning(const char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "WW: " + message;
    logView->append(fullmessage);
}

void LoggerWidget::info(const char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "II: " + message;
    logView->append(fullmessage);
}

void LoggerWidget::debug(const char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "DD: " + message;
    logView->append(fullmessage);
}
