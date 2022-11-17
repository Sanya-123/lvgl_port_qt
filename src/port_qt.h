#ifndef PORT_QT_H
#define PORT_QT_H

#define LVGL_TICK_TIME 5 // 5 milliseconds
#define LVGL_HANDLER_TIME 10 // 10 milliseconds

#include <QLabel>
#include "lv_conf.h"
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

void init_disp(QLabel *label);
void lv_integr_update_pointer(int x, int y, int state);
void lv_integr_timer(void);
void lv_handler(void);




#endif // PORT_QT_H
