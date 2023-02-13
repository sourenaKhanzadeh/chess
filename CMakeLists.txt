cmake_minimum_required(VERSION 3.0)
# set the project name
project(chess)
# set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")


# find library SFML
find_package(SFML COMPONENTS window graphics audio REQUIRED)

add_library(chesslib STATIC ${SOURCES} ${HEADERS})

# add the executable
add_executable(chess main.cpp )

target_link_libraries(chess chesslib
    sfml-graphics sfml-audio sfml-window)

target_include_directories(chess PUBLIC ${PROJECT_BINARY_DIR}/include)
