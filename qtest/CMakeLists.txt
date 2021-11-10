project(mytest LANGUAGES CXX)

message("test_project: ${CMAKE_SOURCE_DIR}.")

find_package(Qt5
    COMPONENTS
        Widgets
        Test
    REQUIRED
)


enable_testing(true)


## mytest.
## 引用 qthelp://org.qt-project.qttest.5152/qttest/qtest-tutorial.html
set(MYTEST mytest)
add_executable(${MYTEST}
    tst_mytest.cpp
    tst_mytest.h
)

add_test(NAME ${MYTEST} COMMAND ${MYTEST})

target_link_libraries(${MYTEST}
    PRIVATE
        Qt5::Test
        Qt5::Widgets
)


## testclass
## 引用 qthelp://org.qt-project.qttest.5152/qttest/qttest-module.html
set(TESTCLASS testclass)
add_executable(${TESTCLASS}
    tst_testclass.h
    tst_testclass.cpp
)

add_test(NAME ${TESTCLASS} COMMAND ${TESTCLASS})

target_link_libraries(${TESTCLASS}
    PRIVATE
        Qt5::Test
        Qt5::Widgets
)


## testform
## 测试自定义的界面库.
set(TESTFORM testform)
add_executable(${TESTFORM}
    tst_form.cpp
    tst_form.h
)

add_test(NAME ${TESTFORM} COMMAND ${TESTFORM})

target_link_libraries(${TESTFORM}
    PRIVATE
    Qt5::Test
    Qt5::Widgets
    ${SRC_PROJECT}
)

target_include_directories(${TESTFORM}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}
)

## testfile
set(TESTFILE testfile)
add_executable(${TESTFILE}
    tst_file.cpp
    tst_file.h
    ${CMAKE_SOURCE_DIR}/src/mainwindow.cpp
)

add_test(NAME ${TESTFILE} COMMAND ${TESTFILE})

target_link_libraries(${TESTFILE}
    PRIVATE
    Qt5::Test
    Qt5::Widgets
)
target_include_directories(${TESTFILE}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
