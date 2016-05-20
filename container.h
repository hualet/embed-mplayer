#ifndef CONTAINER_H
#define CONTAINER_H

#include <QWidget>

class Container : public QWidget
{
    Q_OBJECT

public:
    Container(QWidget *parent = 0);
    ~Container();
};

#endif // CONTAINER_H
