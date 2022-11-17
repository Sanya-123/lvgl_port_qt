#ifndef PORT_QT_H
#define PORT_QT_H

#define LVGL_TICK_TIME 5 // 5 milliseconds
#define LVGL_HANDLER_TIME 10 // 10 milliseconds

#include "lv_conf.h"
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if USE_QLABEL
#include <QLabel>
#define DEFOULT_CLASS   QLabel
#elif USE_QWIDGET
#include <QWidget>
#define DEFOULT_CLASS   QWidget
#elif USE_QOPENGL
//TODO
#include <QOpenGLWidget>
#define DEFOULT_CLASS   QOpenGLWidget
#else
#error "you ned select widget type"
#endif


void init_disp(DEFOULT_CLASS *widget);
void lv_integr_update_pointer(int x, int y, int state);
void lv_integr_timer(void);
void lv_handler(void);




#endif // PORT_QT_H
