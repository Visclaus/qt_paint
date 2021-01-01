#ifndef ERASERWIDGET_H
#define ERASERWIDGET_H

#include <QToolButton>
#include <QWidget>

class eraserWidget : public QToolButton
{
    Q_OBJECT
public:
    explicit eraserWidget(QWidget *parent = nullptr);

signals:

public slots:
protected :
    void mousePressEvent(QMouseEvent * event);
};

#endif // ERASERWIDGET_H
