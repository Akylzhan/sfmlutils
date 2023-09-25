cmake_minimum_required(VERSION 3.24)
project(sfmlutils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB sfmlutils_INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/sfmlutils/*.h")

add_library(sfmlutils
    src/App.cpp
    "${sfmlutils_INCLUDE_FILES}"
)

target_include_directories(sfmlutils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# set_target_properties(sfmlutils PROPERTIES PUBLIC_HEADER "${sfmlutils_INCLUDE_FILES}")

find_package(SFML REQUIRED)
target_link_libraries(sfmlutils PUBLIC sfml-graphics sfml-window)

add_executable(test src/main.cpp)
target_link_libraries(test sfmlutils)

include(GNUInstallDirs)
install(DIRECTORY include/sfmlutils DESTINATION include)
install(TARGETS sfmlutils)
