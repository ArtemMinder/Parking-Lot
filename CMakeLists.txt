cmake_minimum_required(VERSION 3.14)
project(Parking_Lot)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest""googletest")
enable_testing()
include_directories(googletest/googletest/include ${gtest_SOURCE_DIR})


find_package(Qt5Charts)
if(Qt5Charts_FOUND)
    set( QT_INCLUDE_DIR
        ${Qt5Charts_INCLUDE_DIRS}
        )
    include_directories( ${QT_INCLUDE_DIR} )
    set (LIBS ${LIBS} ${Qt5Charts_LIBRARIES} )
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)

include_directories(Data_layer)
include_directories(Data_layer/Model)
include_directories(Data_layer/Data_presentation)
include_directories(Presentation_layer)
include_directories(Bussiness_logic)
include_directories(tests)
find_package(Qt5Charts)
    if(Qt5Charts_FOUND)
        set( QT_INCLUDE_DIR
            ${Qt5Charts_INCLUDE_DIRS}
        )
        include_directories( ${QT_INCLUDE_DIR} )
        set (LIBS ${LIBS} ${Qt5Charts_LIBRARIES} )
    endif()

set(GTEST_SRC googletest/googletest/src/gtest-all.cc)
add_library(Gtest STATIC ${GTEST_SRC})
target_link_libraries(${CMAKE_THREAD_LIBS_INIT} Gtest)
#add_executable(G)
add_test(Gtest g)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql Qt5::Network)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY Data_layer/ParkingLot.sqlite
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(RESOURCE_FILES resources.qrc)
file(GLOB MODEL Data_layer/Model/*.cpp *.h */*.h */*.cpp)
file(GLOB DATA_PRESENTATION Data_layer/Data_presentation/*.cpp *.h */*.h */*.cpp)
file(GLOB BUSSINES_LOGIC Bussiness_logic/*.cpp *.h */*.h */*.cpp)
file(GLOB PRESENTATION_LAYER Presentation_layer/*.cpp *.h  *.ui */*.h */*.cpp */*.ui)
file(GLOB DATA_LAYER Data_layer/*.cpp *.h */*.h */*.cpp)

add_executable(${PROJECT_NAME} ${BUSSINES_LOGIC} ${PRESENTATION_LAYER}
    ${DATA_LAYER} ${RESOURCE_FILES} ${MODEL} ${DATA_PRESENTATION})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Sql
        Qt5::Network
        ${LIBS}
        )
