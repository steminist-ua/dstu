cmake_minimum_required(VERSION 3.5)

project(001 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(001 main.cpp
    sportsman.h sportsman.cpp
)

include(GNUInstallDirs)
install(TARGETS 001
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
