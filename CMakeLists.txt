cmake_minimum_required(VERSION 3.16.3)
project(Breakout VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(Breakout
                src/Main.cpp src/MessageQueue.cpp src/Framework.cpp src/GameStateMachine.cpp src/Breakout.cpp
                src/Assets/Texture.cpp src/Assets/Font.cpp src/Assets/Sound.cpp src/Assets/Tune.cpp src/Assets/Save.cpp src/Assets/Level.cpp
                src/GameObjects/Ball.cpp src/GameObjects/Block.cpp src/GameObjects/Button.cpp src/GameObjects/Image.cpp src/GameObjects/Paddle.cpp src/GameObjects/Text.cpp
                src/GameStates/MenuState.cpp src/GameStates/PlayState.cpp src/GameStates/PauseState.cpp src/GameStates/OptionsState.cpp
                src/MessageQueue.hpp src/Framework.hpp src/GameStateMachine.hpp src/Breakout.hpp
                src/Assets/Asset.hpp src/Assets/Texture.hpp src/Assets/Font.hpp src/Assets/Sound.hpp src/Assets/Tune.hpp src/Assets/Save.hpp src/Assets/Level.hpp
                src/GameObjects/GameObject.hpp src/GameObjects/Ball.hpp src/GameObjects/Block.hpp src/GameObjects/Button.hpp src/GameObjects/Image.hpp src/GameObjects/Paddle.hpp src/GameObjects/Text.hpp
                src/GameStates/GameState.hpp src/GameStates/MenuState.hpp src/GameStates/PlayState.hpp src/GameStates/PauseState.hpp src/GameStates/OptionsState.hpp
                )
target_link_libraries(Breakout ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})