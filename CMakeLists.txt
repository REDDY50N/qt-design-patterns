cmake_minimum_required(VERSION 3.16) # focal

project(QtDesignPatterns VERSION 0.2 LANGUAGES CXX)

set(CMAKE_AUTORCC ON) # embedd .qrc ressources into binary (https://doc.qt.io/qt-6/resources.html)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core REQUIRED)

include_directories( include/ )

set(HEADERS
    include/*.h
)

set(SOURCES
    src/main.cpp
    README.md
)

#qt_add_resources(SOURCES ui/qml.qrc)
qt_add_executable(${PROJECT_NAME}  ${SOURCES} ${HEADERS} )


set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
#    Qt6::Gui
#    Qt6::Quick
#    Qt6::DBus
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})