cmake_minimum_required(VERSION 3.5)

message("examples dir:${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
add_library(my_exemples STATIC ${SOURCES})

target_link_libraries(my_exemples PUBLIC lvgl)

add_custom_command(PRE_BUILD OUTPUT examples.h
	COMMAND bash ./findIncludes.sh
)
