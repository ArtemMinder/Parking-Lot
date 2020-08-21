cmake_minimum_required(VERSION 3.14)
project(Parking_Lot)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql Qt5::Network)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR} ParkingLot.sqlite
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE_FILES acc.cpp compactspot.cpp electricspot.cpp entrancepanel.cpp
    handicappedspot.cpp largespot.cpp main.cpp mediumspot.cpp motorcyclespot.cpp 
    parkingfloor.cpp parkingrate.cpp parkingspot.cpp parkingticket.cpp 
    vehicle.cpp view.cpp Types.h acc.h compactspot.h electricspot.h entrancepanel.h
    handicappedspot.h largespot.h mediumspot.h motorcyclespot.h parkingfloor.h 
    parkingrate.h parkinglot.h parkinglot.cpp parkingrate.cpp exchange.cpp
    exchange.h parkingspot.h IExchange.h IAcc.h parkingticket.h vehicle.h
    simulation.cpp simulation.h sqlitedb.cpp CarModel.h Idatabase.h sqlitedb.h model.h
    view.h view.ui acc.ui resources.qrc)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Sql
        Qt5::Network
        )
