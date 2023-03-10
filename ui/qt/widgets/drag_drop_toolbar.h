/** @file
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef DRAG_DROP_TOOLBAR_H
#define DRAG_DROP_TOOLBAR_H

#include <QToolBar>
#include <QPoint>

class WiresharkMimeData;

class DragDropToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit DragDropToolBar(const QString &title, QWidget *parent = Q_NULLPTR);
    explicit DragDropToolBar(QWidget *parent = Q_NULLPTR);
    ~DragDropToolBar();

    virtual void clear();

signals:
    void actionMoved(QAction * action, int oldPos, int newPos);

    void newFilterDropped(QString description, QString filter);

protected:

    virtual WiresharkMimeData * createMimeData(QString name, int position);

    virtual void childEvent(QChildEvent * event);

    virtual bool eventFilter(QObject * obj, QEvent * ev);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dropEvent(QDropEvent *event);

private:

    QPoint dragStartPosition;
    int childCounter;

    void setupToolbar();
    void moveToolbarItems(int fromPos, int toPos);

};

#endif // DRAG_DROP_TOOLBAR_H
