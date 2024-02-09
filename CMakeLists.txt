cmake_minimum_required(VERSION 3.26)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(OpenGL REQUIRED)

add_executable(Chess
        chess.cpp
        point.h
        uiDraw.cpp
        uiDraw.h
        uiInteract.cpp
        uiInteract.h
        testMove.h
        testMove.cpp
        testPosition.h
        testPosition.cpp
        move.cpp
        move.h
        position.cpp
        position.h
        board.cpp
        board.h
        pieceType.h
        piece.cpp
        location.cpp)

target_link_libraries(Chess OpenGL::GL)

target_link_libraries(Chess "-framework GLUT")