/* mainwindow.cpp

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

#include <tpproto/board.h>
#include <tpproto/gamelayer.h>
#include <tpproto/object.h>

#include <QDockWidget>
#include <QLabel>
#include <QTableView>
#include <QTimer>
#include <QTreeView>

#include <kaction.h>
#include <kicon.h>
#include <kled.h>
#include <kmenu.h>
#include <kmenubar.h>
#include <kmessagebox.h>
#include <kstatusbar.h>
#include <kstandardaction.h>

#include "connecttoserverdialog.h"
#include "converters.h"
#include "loggerwidget.h"
#include "loggerwidget.moc"
#include "mainwindow.h"
#include "mainwindow.moc"
#include "messagesmodel.h"
#include "objectsmodel.h"
#include "version.h"


using namespace std;
using namespace TPProto;

MainWindow::MainWindow(QWidget *parent) : KMainWindow(parent)
{
    setupActions();
    setupMenus();
    setupStatusBar();
    game = new GameLayer();
    game->setClientString(string("parsek/") + PARSEK_VERSION);
    time = 0;
    gotServerTime = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

void MainWindow::setupActions()
{
    connectAction = new KAction(this);
    connectAction->setIcon(KIcon("network-connect"));
    connectAction->setText(i18n("&Connect to server..."));
    connectAction->setStatusTip(i18n("Connect to a game server"));
    connect(connectAction, SIGNAL(triggered()),
            this, SLOT(connectToServer()));
    quitAction = KStandardAction::quit(this, SLOT(quitGame()), this);
    quitAction->setStatusTip(i18n("Quit the game"));
}

void MainWindow::setupMenus()
{
    gameMenu = new KMenu(i18n("&Game"));
    gameMenu->addAction(connectAction);
    gameMenu->addSeparator();
    gameMenu->addAction(quitAction);
    menuBar()->addMenu(gameMenu);
    help = helpMenu();
    menuBar()->addMenu(help);
}

void MainWindow::setupStatusBar()
{
    statusLabel = new QLabel(i18n("Welcome to Parsek!"));
    timeLabel = new QLabel("99d 99h 99m 99s");
    timeLabel->setAlignment(Qt::AlignHCenter);
    timeLabel->setMinimumSize(timeLabel->sizeHint());
    timeLabel->clear();
    connectionLed = new KLed(Qt::red);
    statusBar()->addWidget(statusLabel, 1);
    statusBar()->addWidget(timeLabel);
    statusBar()->addWidget(connectionLed);
}

void MainWindow::setupDockWindows()
{
    ObjectsModel *objectsModel = new ObjectsModel();
    objectsModel->setUniverse(game);
    QTreeView *objectsTree = new QTreeView();
    objectsTree->setModel(objectsModel);
    QDockWidget *objectsDock = new QDockWidget(i18n("Objects Tree"), this);
    objectsDock->setAllowedAreas(Qt::BottomDockWidgetArea
                                 | Qt::TopDockWidgetArea);
    objectsDock->setWidget(objectsTree);
    addDockWidget(Qt::TopDockWidgetArea, objectsDock);

    MessagesModel *messagesModel = new MessagesModel();
    messagesModel->setMessages(game, messageBoard);
    QTableView *messagesView = new QTableView();
    messagesView->setModel(messagesModel);
    QDockWidget *messagesDock = new QDockWidget(i18n("Messages"), this);
    messagesDock->setAllowedAreas(Qt::BottomDockWidgetArea
                                  | Qt::TopDockWidgetArea);
    messagesDock->setWidget(messagesView);
    addDockWidget(Qt::BottomDockWidgetArea, messagesDock);

    LoggerWidget *loggerWidget = new LoggerWidget();
    game->setLogger(loggerWidget);
    QDockWidget *loggerDock = new QDockWidget(i18n("Log"), this);
    loggerDock->setAllowedAreas(Qt::BottomDockWidgetArea
                                | Qt::TopDockWidgetArea);
    loggerDock->setWidget(loggerWidget);
    addDockWidget(Qt::BottomDockWidgetArea, loggerDock);
}

void MainWindow::connectToServer()
{
    ConnectToServerDialog connectionDialog(this);
    if (connectionDialog.exec()) {
        connectionLed->setColor(Qt::yellow);
        statusLabel->setText(i18n("Connecting to server..."));
        qApp->processEvents();
        string address = connectionDialog.serversHistoryCombo->
                         currentText().toUtf8().constData();
        if (game->getStatus() == gsDisconnected && game->connect(address)) {
            string user = connectionDialog.usernameLine->
                          text().toUtf8().constData();
            string pass = connectionDialog.passwordLine->
                          text().toUtf8().constData();
            game->login(user, pass);
            updateTime();
            messageBoard = game->getPersonalBoard();
            statusLabel->setText(i18n("Connected. Enjoy the game!"));
            connectionLed->setColor(Qt::green);
            setupDockWindows();
        } else {
            statusLabel->setText(i18n("Connection failed!"));
            connectionLed->setColor(Qt::red);
            KMessageBox::error(0L,
              i18n("It is not possible to connect to the server."),
              i18n("Could Not Connect"));
        }

    }
}

void MainWindow::updateTime()
{
    if (gotServerTime == true) {
      time = time -1;
      if (time == 1) gotServerTime = false;
    } else {
      time = game->getTimeRemaining();
      gotServerTime = true;
      timer->start(1000);
    }
    timeLabel->setText(secondsToDHMS(time));
}

void MainWindow::quitGame()
{
    if (game->getStatus() != gsDisconnected) game->disconnect();
    close();
}
