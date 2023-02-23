set(INCLUDES 
    ../include/renderer.hpp
    ../include/game.hpp
)

set(SOURCES
    renderer.cpp
    game.cpp
)

add_library(chesslib ${SOURCES} ${INCLUDES})