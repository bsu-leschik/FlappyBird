cmake_minimum_required(VERSION 3.5)

project(FlappyBird VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        resources.qrc
        flappybird.cpp
        flappybird.h
        flappybird.ui
        Models/TubePair.cpp Models/TubePair.h Models/Bird.cpp Models/Bird.h Controllers/BirdController.cpp Controllers/BirdController.h Controllers/TubeController.cpp Controllers/TubeController.h Controllers/IntersectionController.cpp Controllers/IntersectionController.h Controllers/ScoreController.cpp Controllers/ScoreController.h Settings/SettingsWindow.cpp Settings/SettingsWindow.h Menu/StartMenu.cpp Menu/StartMenu.h Models/Ground.cpp Models/Ground.h Controllers/GroundController.cpp Controllers/GroundController.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FlappyBird
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FlappyBird APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FlappyBird SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FlappyBird
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FlappyBird PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(FlappyBird PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FlappyBird)
endif()
