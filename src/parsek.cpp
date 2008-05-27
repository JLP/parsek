/* parsek.cpp

    Parsek - free client for playing 4X space strategy games
    Copyright (C) 2006-2008  Jure Repinc <jlp@holodeck1.com>

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

#include <kapplication.h>
#include <klocale.h>
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <kstandarddirs.h>

#include "mainwindow.h"
#include "version.h"

static const KLocalizedString description = 
                         ki18n("Client for playing multi-player "
                               "turn-based space strategy games");

int main(int argc, char *argv[])
{
    KAboutData aboutData("parsek", // program name
                         "parsek", // translation catalog
                         ki18n("Parsek"),
                         PARSEK_VERSION,
                         description,
                         KAboutData::License_GPL_V3,
                         ki18n("Copyright (c) 2006-2008, Jure Repinc")
                         );

    aboutData.addAuthor(ki18n("Jure Repinc"),
                        ki18n("Main developer"),
                        "jlp@holodeck1.com",
                        "http://jlp.holodeck1.com/");

    KCmdLineArgs::init( argc, argv, &aboutData );

    KApplication parsek;

    if (parsek.isSessionRestored())
        RESTORE(MainWindow)
    else {
        MainWindow *mainWindow = new MainWindow;
        mainWindow->show();
    }
    return parsek.exec();

}
