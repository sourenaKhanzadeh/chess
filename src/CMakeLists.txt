file(GLOB SOURCES *.cpp)
file(GLOB INCLUDES ../include/*.hpp)


add_library(chesslib STATIC ${SOURCES} ${INCLUDES})