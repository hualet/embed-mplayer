#include "container.h"

#include <QMouseEvent>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QApplication>

Container::Container(QWidget *parent)
    : QWidget(parent),
      m_menu(new QMenu(this)),
      m_quitAction(new QAction("退出", this))
{
    setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint);

    m_menu->addAction(m_quitAction);
    connect(m_menu, SIGNAL(triggered(QAction*)), this, SLOT(menuItemTriggered(QAction*)));
}

Container::~Container()
{

}

void Container::menuItemTriggered(QAction *)
{
    qApp->quit();
}

void Container::contextMenuEvent(QContextMenuEvent *event)
{
    m_menu->exec(event->globalPos());
}
