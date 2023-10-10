cmake_minimum_required (VERSION 3.8)

project ("emulator_gbc")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(SDL2 REQUIRED)

add_executable (emulator_gbc "src/main.cpp" "include/lr35902.h" "include/bus.h" "src/bus.cpp" "src/lr35902.cpp" "include/cartridge.h" "src/cartridge.cpp" "include/load_rom.h")

target_include_directories(
	emulator_gbc
	PRIVATE
	include
)

target_link_libraries(
	emulator_gbc 
	SDL2::SDL2 
	SDL2::SDL2main
)	

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET emulator_gbc PROPERTY CXX_STANDARD 20)
endif()

