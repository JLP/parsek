/* objectsmodel.h

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
* This file defines the class ObjectsModel which is used to store a Universe
* @author Jure Repinc <jlp@holodeck1.com>
*/

#ifndef OBJECTSMODEL_H
#define OBJECTSMODEL_H

#include <QAbstractItemModel>

#include <tpproto/gamelayer.h>
#include <tpproto/object.h>

#include "objectsitem.h"

using namespace TPProto;

/** Class for storing ObjectsItems and representing a Universe */
class ObjectsModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ObjectsModel(QObject *parent = 0);
    virtual ~ObjectsModel();
    /** Sets up Universe data for the game @p game */
    void setUniverse(GameLayer *game);
    /** Adds object @p object with parent @p parent to the Universe tree */
    void addObject(GameLayer *game, Object *object, ObjectsItem *parent = 0);
    /** Returns model index for object at 
        row @p row, column @p column and with parent @p parent */
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    /** Returns the model index of the object's parent */
    QModelIndex parent(const QModelIndex &index) const;
    /** Returns the number of children of the @p parent */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /** Returns the number of properties of the @p parent */
    int columnCount (const QModelIndex &parent = QModelIndex()) const;
    /** Returns information for object with index @p index */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    /** Returns the header for the object data */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    ObjectsItem *m_objectsItemFromIndex(const QModelIndex &index) const;
    ObjectsItem *m_universe;
};

#endif // OBJECTSMODEL_H
