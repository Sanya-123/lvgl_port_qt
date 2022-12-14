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

#include <QApplication>
#include "mainwindow.h"
#include "demos/lv_demos.h"
#include "examples/lv_examples.h"
#include "localexamples/examples.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //start demo application
    RUN_DEMO();


    return a.exec();
}
