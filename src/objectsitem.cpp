/* objectsitem.cpp

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

#include "objectsitem.h"

ObjectsItem::ObjectsItem(ObjectsItem *parent)
{
    m_parent = parent;
}

ObjectsItem::~ObjectsItem()
{
    qDeleteAll(m_children);
}

void ObjectsItem::appendChild(ObjectsItem *child)
{
    m_children.append(child);
}

ObjectsItem *ObjectsItem::child(int row)
{
    return m_children.value(row);
}

int ObjectsItem::childrenCount() const
{
    return m_children.size();
}

int ObjectsItem::propertiesCount() const
{
    return m_properties.size() + 5; // there are 5 common proprties
}

QVariant ObjectsItem::property(const QString &label) const
{
    return m_properties.value(label);
}

int ObjectsItem::row() const
{
    if(m_parent)
        return m_parent->m_children.indexOf(const_cast<ObjectsItem*>(this));
    return 0;
}

ObjectsItem *ObjectsItem::parent()
{
    return m_parent;
}

quint32 ObjectsItem::id() const
{
    return m_id;
}

void ObjectsItem::setId(quint32 id)
{
    m_id = id;
}

ObjectsItem::ObjectType ObjectsItem::type() const
{
    return m_type;
}

void ObjectsItem::setType(ObjectType type)
{
    m_type = type;
}

QString ObjectsItem::name() const
{
    return m_name;
}

void ObjectsItem::setName(const QString &name)
{
    m_name = name;
}

quint64 ObjectsItem::size() const
{
    return m_size;
}

void ObjectsItem::setSize(quint64 size)
{
    m_size = size;
}

qint64 ObjectsItem::x() const
{
    return m_x;
}

void ObjectsItem::setX(qint64 x)
{
    m_x = x;
}

qint64 ObjectsItem::y() const
{
    return m_y;
}

void ObjectsItem::setY(qint64 y)
{
    m_y = y;
}

qint64 ObjectsItem::z() const
{
    return m_z;
}

void ObjectsItem::setZ(qint64 z)
{
    m_z = z;
}

qint64 ObjectsItem::vx() const
{
    return m_vx;
}

void ObjectsItem::setVX(qint64 vx)
{
    m_vx = vx;
}

qint64 ObjectsItem::vy() const
{
    return m_vy;
}

void ObjectsItem::setVY(qint64 vy)
{
    m_vy = vy;
}

qint64 ObjectsItem::vz() const
{
    return m_vz;
}

void ObjectsItem::setVZ(qint64 vz)
{
    m_vz = vz;
}

quint64 ObjectsItem::modTime() const
{
    return m_modTime;
}

void ObjectsItem::setModTime(quint64 time)
{
    m_modTime = time;
}
