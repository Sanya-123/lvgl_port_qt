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

#include "mainwindow.h"
#include <QDebug>
#include <QThread>
#include <QMouseEvent>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : DEFOULT_CLASS(parent)
    , lastState(LV_INDEV_STATE_REL)
{
//    setGeometry(this->x(), this->y(), LV_HOR_RES, LV_VER_RES);
//    setMinimumSize(LV_HOR_RES, LV_VER_RES);
//    setMaximumSize(LV_HOR_RES, LV_VER_RES);
    setFixedSize(LV_HOR_RES, LV_VER_RES);

    QString useWidget;
#if USE_QLABEL
    useWidget = "QLabel";
#elif USE_QWIDGET
    useWidget = "QWidget";
#elif USE_QOPENGL
    useWidget = "QOpenGL";
#endif
    setWindowTitle("LVGL Qt Simulator " + useWidget);

    timerLVGL.setInterval(LVGL_TICK_TIME);
    haderLVGL.setInterval(LVGL_HANDLER_TIME);


//    installEventFilter(this);

    init_disp(this);

    connect(&timerLVGL, &QTimer::timeout, this, [=]() {lv_integr_timer();});
    connect(&haderLVGL, &QTimer::timeout, this, [=]() {lv_handler();});

    timerLVGL.start();
    haderLVGL.start();

#if USE_QOPENGL
    setAutoFillBackground(false);
#endif
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    lv_integr_update_pointer(event->x(), event->y(), LV_INDEV_STATE_PR);
    lastState = LV_INDEV_STATE_PR;
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    lv_integr_update_pointer(event->x(), event->y(), LV_INDEV_STATE_REL);
    lastState = LV_INDEV_STATE_REL;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(lastState == LV_INDEV_STATE_PR)
        lv_integr_update_pointer(event->x(), event->y(), lastState);
}

#if USE_QWIDGET || USE_QOPENGL
extern QImage displayImage;
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter;
    painter.begin(this);
#if USE_QOPENGL
    painter.setRenderHint(QPainter::Antialiasing);
#endif
    painter.drawImage(0, 0, displayImage);
    painter.end();
}
#endif
