#include "container.h"

Container::Container(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::X11BypassWindowManagerHint);
}

Container::~Container()
{

}
