#include "port_qt.h"

#include <QImage>

#define DISP_BUF_SIZE (LV_MEM_SIZE)

static lv_indev_drv_t indev_drv;
static int touchpad_x = 0, touchpad_y = 0;
static lv_indev_state_t touchpad_state = LV_INDEV_STATE_REL;
static lv_indev_state_t touchpad_old_state = LV_INDEV_STATE_REL;

//----------- prototypes ----------
static void disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

static DEFOULT_CLASS *displayWidget;
QImage displayImage;


void init_disp(DEFOULT_CLASS *widget)
{
    displayImage = QImage(LV_HOR_RES, LV_VER_RES, QImage::Format_RGB32);
    lv_init();
    displayWidget = widget;
    static lv_disp_draw_buf_t draw_buf_dsc_1;
    static lv_color_t buf_1[DISP_BUF_SIZE];                          /*A buffer for 10 rows*/
    lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL, DISP_BUF_SIZE);   /*Initialize the display buffer*/

    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LV_HOR_RES;
    disp_drv.ver_res = LV_VER_RES;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf_dsc_1;

#if LV_USE_GPU
    /*Fill a memory array with a color*/
    disp_drv.gpu_fill_cb = gpu_fill;
#endif

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);

    //pointerReadr
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = (void (*)(struct _lv_indev_drv_t *, lv_indev_data_t * )) touchpad_read;
    lv_indev_drv_register(&indev_drv);
}

void lv_integr_update_pointer(int x, int y, int state)
{
    touchpad_x = x;
    touchpad_y = y;
    touchpad_state = (lv_indev_state_t) state;
}

void lv_integr_timer(void)
{
    lv_tick_inc(LVGL_TICK_TIME);
}

void lv_handler(void)
{
    lv_task_handler();
}

static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    Q_UNUSED(indev_drv);
    data->point.x = touchpad_x;
    data->point.y = touchpad_y;
    data->state = touchpad_state; //LV_INDEV_STATE_REL; //LV_INDEV_STATE_PR or LV_INDEV_STATE_REL;
    if ( touchpad_state != touchpad_old_state) {
        touchpad_old_state = touchpad_state;
//        qDebug("mouse down: x=%d y=%d", touchpad_x, touchpad_y);
    }
}

static void updateDisplay (const lv_area_t * area, lv_color_t * color_p, bool last)
{
    int32_t x, y;
    lv_color_t pixel;

    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            pixel = *color_p;
            displayImage.setPixelColor(x,y, (QRgb)lv_color_to32(pixel));
            color_p++;
        }
    }
    if (last) {
#if USE_QLABEL
        displayWidget->setPixmap(QPixmap::fromImage(displayImage));
#elif USE_QWIDGET || USE_QOPENGL
        displayWidget->update();
#endif
    }

}

static void disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    updateDisplay(area, color_p, lv_disp_flush_is_last( disp));
    lv_disp_flush_ready(disp);         /* Indicate you are ready with the flushing*/
}
