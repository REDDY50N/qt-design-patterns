cmake_minimum_required(VERSION 3.16) # cmake 3.16 is supported on focal: apt install cmake 

project(QtDesignPatterns VERSION 0.2 LANGUAGES CXX)

#set(CMAKE_AUTORCC ON) # embedd .qrc ressources into binary (https://doc.qt.io/qt-6/resources.html)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core REQUIRED)

include_directories( include/ )

set(HEADERS
    singleton.h
    prototype.h
    factory.h
    smartfactory.h
    strategy.h
)

set(SOURCES
    main.cpp
    README.md
)

#qt_add_resources(SOURCES ui/qml.qrc)
qt_add_executable(QtDesignPatterns  ${SOURCES} ${HEADERS} )


set_target_properties(QtDesignPatterns PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(QtDesignPatterns PRIVATE
    Qt6::Core
)

install(TARGETS QtDesignPatterns
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
