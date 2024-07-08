cmake_minimum_required(VERSION 3.15)
project(dzielny_maly_aksolotl_final_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(dzielny_maly_aksolotl_final_project Algae.cpp Algae.h AngleFish.cpp AngleFish.h Axolotl.cpp Axolotl.h AxolotlController.cpp AxolotlController.h AxolotlView.cpp AxolotlView.h CannonFish.cpp CannonFish.h dzielny_maly_aksolotl_final_project.cpp Enemy.cpp Enemy.h EnemyArray.cpp EnemyArray.h Garbage.cpp Garbage.h HealthBar.cpp HealthBar.h HocusPocusFish.cpp HocusPocusFish.h MusketFish.cpp MusketFish.h Octopus.cpp Octopus.h PowerUps.cpp PowerUps.h RainbowFish.cpp RainbowFish.h SeaTurtle.cpp SeaTurtle.h Shark.cpp Shark.h SoundEffects.cpp SoundEffects.h StarFish.cpp StarFish.h Stingray.cpp Stingray.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(dzielny_maly_aksolotl_final_project sfml-system sfml-window sfml-graphics sfml-audio)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})