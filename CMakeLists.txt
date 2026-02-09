cmake_minimum_required(VERSION 4.2.3)
project(tiktaktoe-cpp)
add_executable(TikTakToe)
target_sources(TikTakToe PRIVATE
    main.cpp
    Game.cpp
    Board.cpp
    GameState.cpp
    Player.cpp

)
