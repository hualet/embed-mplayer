#ifndef CONTAINER_H
#define CONTAINER_H

#include <QWidget>

class QMenu;
class Container : public QWidget
{
    Q_OBJECT

public:
    Container(QWidget *parent = 0);
    ~Container();

public slots:
    void menuItemTriggered(QAction *);

protected:
    void contextMenuEvent(QContextMenuEvent *);

private:
    QMenu *m_menu;
    QAction *m_quitAction;
};

#endif // CONTAINER_H
