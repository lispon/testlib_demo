find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_library(${SRC_PROJECT}
    ${PROJECT_SOURCES}
)

target_link_libraries(${SRC_PROJECT}
    PUBLIC
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${SRC_PROJECT}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
