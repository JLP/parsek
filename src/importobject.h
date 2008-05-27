/* importobject.h

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
* This a group of functions to convert objects from format used by
* libtpproto-cpp into format used by Parsek.
* @author Jure Repinc <jlp@holodeck1.com>
*/

#ifndef IMPORTOBJECT_H
#define IMPORTOBJECT_H

#include <tpproto/fleet.h>
#include <tpproto/galaxy.h>
#include <tpproto/object.h>
#include <tpproto/planet.h>
#include <tpproto/starsystem.h>
#include <tpproto/universe.h>

#include "objectsitem.h"

using namespace TPProto;

void importObject(Object *object, ObjectsItem *imported);
void importObject(Universe *object, ObjectsItem *imported);
void importObject(Galaxy *object, ObjectsItem *imported);
void importObject(StarSystem *object, ObjectsItem *imported);
void importObject(Planet *object, ObjectsItem *imported);
void importObject(Fleet *object, ObjectsItem *imported);
void setCommonProperties(Object *source, ObjectsItem *target);

#endif // IMPORTOBJECT_H
