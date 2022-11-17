# lvgl_port_qt
A simple LVGL Simulator. Use QImage(QLabel) or QWidget for drawing.

## Requirements
- Qt (tested with 5.12.8)

## Build
```
git clone --recursive https://github.com/Sanya-123/lvgl_port_qt.git
cd lvgl_port_qt
mkdir ./build
cd ./build
cmake ../ # or cmake -DRUN_DEMO=<demo> -DWIDGET_TYPE="<widget>" ../
```

## Add demo
#### For adding demos you need:
- Create folder in "localexample" with headers and source files
- Run findIncludes.sh in "localexample" folder or add your includes files in "examples.h"
- Rebuild project

## Select demo
By defoult is select lv_demo_widgets;<br>
You can selected any demos and examples from folders: *localexamples*, *lvgl/demos* and *lvgl/examples*;<br>
You need just set RUN_DEMO(ex: *cmake -DRUN_DEMO=lv_example_btn_1 ../* or *cmake -DRUN_DEMO=lv_demo_music ../*);

## Select widget type
You can select widget type betwen QLabel and QWidget;<br>
By defoult is select QLabel;<br>
For select type just set *WIDGET_TYPE="QWidget"* or *"QLabel"*;





