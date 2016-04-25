#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameView(QWidget * parent = 0);
    ~GameView();

};

#endif // GAMEVIEW_H
