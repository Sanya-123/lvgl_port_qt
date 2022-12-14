#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/***************************************************************
 *
 *                 This code is part of LVGL-Qt-Simulator
 *
 * Copyrights 2021 - Varanda Labs Inc.
 *
 * License:
 *   Creative Commons: CC BY-NC-SA 4.0
 *   Attribution-NonCommercial-ShareAlike 4.0 International
 *   https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 *
 *   Note: for purchasing a commertial license contact:
 *     m@varanda.ca
 *
 ***************************************************************
 */

#include <QTimer>
#include "port_qt.h"


class MainWindow : public DEFOULT_CLASS
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
#if USE_QWIDGET || USE_QOPENGL
    void paintEvent(QPaintEvent *event);
#endif
//  virtual bool eventFilter(QObject *obj, QEvent *event);

private:
  QTimer timerLVGL, haderLVGL;
  int lastState;

};
#endif // MAINWINDOW_H
