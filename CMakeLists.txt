cmake_minimum_required(VERSION 3.14)
project(Parking_Lot)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql)

set(CMAKE_CXX_STANDARD 14)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR} ParkingLot.sqlite
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE_FILES acc.cpp compactspot.cpp electricspot.cpp entrancepanel.cpp
    handicappedspot.cpp largespot.cpp main.cpp mediumspot.cpp motorcyclespot.cpp 
    parkingfloor.cpp parkinglot.cpp parkingrate.cpp parkingspot.cpp parkingticket.cpp 
    vehicle.cpp view.cpp Types.h acc.h compactspot.h electricspot.h entrancepanel.h
    handicappedspot.h largespot.h mediumspot.h motorcyclespot.h parkingfloor.h 
    parkinglot.h parkingrate.h parkingspot.h parkingticket.h vehicle.h view.h view.ui
    acc.ui resources.qrc)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Sql
        )
