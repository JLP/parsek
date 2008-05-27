/* objectsitem.h

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

/** @file
* This file defines the class ObjectsItem which is used in ObjectsModel
* @author Jure Repinc <jlp@holodeck1.com>
*/

#ifndef OBJECTSITEM_H
#define OBJECTSITEM_H

#include <QHash>
#include <QList>
#include <QVariant>

/** Class for representing individual space object in space objects model */
class ObjectsItem
{
public:
    enum ObjectType { Unknown = -1, Universe, Galaxy, StarSystem, Planet, Fleet };
    ObjectsItem(ObjectsItem *parent = 0);
    ~ObjectsItem();
    /** Adds object @p child to the list of children */
    void appendChild(ObjectsItem *child);
    /** Returns child at row @p row in the list of children of this object */
    ObjectsItem *child(int row);
    /** Returns number of children objects */
    int childrenCount() const;
    /** Returns number of object's extra properties */
    int propertiesCount() const;
    /** Returns object's extra property labeled with @p label */
    QVariant property(const QString &label) const;
    /** Returns position of this object in the list of parents children */
    int row() const;
    /** Returns parent of this object */
    ObjectsItem *parent();
    quint32 id() const;
    void setId(quint32 id);
    ObjectType type() const;
    void setType(ObjectType type);
    QString name() const;
    void setName(const QString &name);
    quint64 size() const;
    void setSize(quint64 size);
    qint64 x() const;
    void setX(qint64 x);
    qint64 y() const;
    void setY(qint64 y);
    qint64 z() const;
    void setZ(qint64 z);
    qint64 vx() const;
    void setVX(qint64 vx);
    qint64 vy() const;
    void setVY(qint64 vy);
    qint64 vz() const;
    void setVZ(qint64 vz);
    quint64 modTime() const;
    void setModTime(quint64 time);

private:
    QList<ObjectsItem*> m_children;
    QHash<QString, QVariant> m_properties;
    ObjectsItem *m_parent;
    quint32 m_id;
    ObjectType m_type;
    QString m_name;
    quint64 m_size;
    qint64 m_x;
    qint64 m_y;
    qint64 m_z;
    qint64 m_vx;
    qint64 m_vy;
    qint64 m_vz;
    quint64 m_modTime;
};

#endif // OBJECTSITEM_H
