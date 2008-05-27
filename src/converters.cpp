/* converters.cpp

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

#include <QString>
#include "converters.h"

QString secondsToDHMS(const int seconds)
{
  int d = 0;
  int h = 0;
  int m = 0;
  int s = seconds;

  if (s >= 86400) {
    d = s / 86400;
    s = s % 86400;
  }
  if (s >= 3600) {
    h = s / 3600;
    s = s % 3600;
  }
  if (s >= 60) {
    m = s / 60;
    s = s % 60;
  }
  return QString::number(d) + "d " + QString::number(h) + "h "
         + QString::number(m) + "m " + QString::number(s) + 's';
}

QString positionToString(const qint64 x, const qint64 y, const qint64 z)
{
    QString position = "(";
    position += QString::number(x);
    position += ", ";
    position += QString::number(y);
    position += ", ";
    position += QString::number(z);
    position += ')';
    return position;
}

QString velocityToString(const qint64 vx, const qint64 vy, const qint64 vz)
{
    QString velocity = "(";
    velocity += QString::number(vx);
    velocity += ", ";
    velocity += QString::number(vy);
    velocity += ", ";
    velocity += QString::number(vz);
    velocity += ')';
    return velocity;
}
