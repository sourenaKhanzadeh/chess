cmake_minimum_required(VERSION 3.0)
# set the project name
project(chess)
# set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find library SFML
find_package(SFML COMPONENTS window graphics audio REQUIRED)

# add the executable
add_executable(chess main.cpp )

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include)

add_subdirectory(src)

target_link_libraries(chess 
PRIVATE
sfml-graphics sfml-audio sfml-window
chesslib)

target_include_directories(chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
