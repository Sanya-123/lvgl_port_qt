cmake_minimum_required(VERSION 3.5)

project(lvgl_port_qt)
enable_language(C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-fPIE)

# select run demos
if(NOT RUN_DEMO)
    set(RUN_DEMO lv_demo_widgets)
    message(STATUS "Defoult run demo is ${RUN_DEMO}")
else()
    message(STATUS "Demo is set ${RUN_DEMO}")
endif()

# select widget type
if(NOT WIDGET_TYPE)
    set(WIDGET_TYPE "QLabel") # set defoult type
endif()

set(USE_QLABEL 0)
set(USE_QWIDGET 0)
set(USE_QOPENGL 0)

if(WIDGET_TYPE STREQUAL "QLabel")
    set(USE_QLABEL 1)
elseif(WIDGET_TYPE STREQUAL "QWidget")
    set(USE_QWIDGET 1)
elseif(WIDGET_TYPE STREQUAL "QOpenGL")
    set(USE_QOPENGL 1)
else()
    message( SEND_ERROR "You select wrong widget" )
endif()


set(DEFINES LV_CONF_INCLUDE_SIMPLE
    QT_DEPRECATED_WARNINGS
    LUA_EMBEDDED
    MOS_DESKTOP
    projCOVERAGE_TEST=1
    LV_USE_DEMO_MUSIC=1
    USE_DEMO_MUSIC
    LV_USE_LOG=LV_LOG_LEVEL_WARN
    USE_DL_PREFIX
    MSPACES=1
    USE_DOUG_LEA_MALLOC
    ONLY_MSPACES=0
    NO_MALLINFO=0
    RUN_DEMO=${RUN_DEMO}
    USE_QLABEL=${USE_QLABEL}
    USE_QWIDGET=${USE_QWIDGET}
    USE_QOPENGL=${USE_QOPENGL}
    )

add_compile_definitions(${DEFINES})

include_directories( ./ ./src )

add_subdirectory(lvgl)
add_subdirectory(localexamples)
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE )

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

find_package(Qt5 COMPONENTS Widgets REQUIRED)
#if(USE_QOPENGL)
#    # note if qt6 use OpenGLWidgets
#    find_package(Qt5 COMPONENTS OpenGL REQUIRED)
#endif()

set(SRC
    ./src/main.cpp
    ./src/mainwindow.cpp
    ./src/port_qt.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

#target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE ${DEFINES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Gui Qt5::Core)
#if(USE_QOPENGL)
#    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt5::OpenGL)
#endif()
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE lvgl::lvgl lvgl::examples lvgl::demos)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE my_exemples)

