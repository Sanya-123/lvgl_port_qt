# lvgl_port_qt
A simple LVGL Simulator. Use QImage for drawing.

## Requirements
- Qt (tested with 5.12.8)

## Build
```
git clone --recursive https://github.com/Sanya-123/lvgl_port_qt.git
cd lvgl_port_qt
mkdir ./build
cd ./build
cmake ../ # or cmake -DRUN_DEMO=<demo> ../
```

## Add demo
#### For adding demos you need:
- create folder in "localexample" with headers and source files
- run findIncludes.sh in "localexample" folder or add your includes files in "examples.h"
- rebuild project

## Select demo
By defoult is select lv_demo_widgets;<br>
You can selected any demos and examples from folders: *localexamples*, *lvgl/demos* and *lwgl/examples*;<br>
You need just set RUN_DEMO(ex: *cmake -DRUN_DEMO=lv_example_btn_1 ../* or *cmake -DRUN_DEMO=lv_demo_music ../*);





