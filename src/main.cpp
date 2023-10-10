#include <iostream>
#include "SDL.h"
#include "bus.h"
#include "lr35902.h"
#include "load_rom.h"	
#include "cartridge.h"

int main(int argc, char* argv[]) {

	auto game_rom = load_game_file(argc, argv);

	std::shared_ptr<Bus> bus = std::make_shared<Bus>();

	auto cartridge = Cartridge(game_rom, bus);

	auto cpu = lr35902(bus);

	return 0;
}