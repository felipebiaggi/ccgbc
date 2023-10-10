#include <iostream>
#include "cartridge.h"
#include "bus.h"

Cartridge::Cartridge(std::vector<uint8_t> rom, std::shared_ptr<Bus> bus)
{
	this->m_Bus = bus;
	this->m_Rom = rom;

	// Cartridge Address - Game Title
	// Hex -> 0x0104~0x0143
	// Dec     -> 308~323
	this->game_title = { &rom[308], &rom[323] };

	// Cartridge Address - Manufacturer Code
	// Hex -> 0x013F~0x0142
	// Dec -> 319~322
	this->manufactured_code = { &rom[319], &rom[322] };
	
	// CGB Flag
	// Hex -> 0x0143
	// Dec -> 323
	this->cgb_flag = { rom.at(323) };
	
	// New Licensee Code 
	// Convert the value of addresses 324 and 325 to ASCII
	std::string s_lic;
	s_lic += rom.at(324);
	s_lic += rom.at(325);

	this->licensee_code = { s_lic };

	// SGB Flag
	// Hex -> 0x0146
	// Dec -> 326
	this->sgb_flag = { rom.at(326) };
	
	// Cartridge Type
	this->cartridge_type = { rom.at(327) };

	this->rom_size = { rom.at(328) };

	this->ram_size = { rom.at(329) };

	this->destination_code = { rom.at(330) };

	this->old_licensee_code = { rom.at(331) };

	this->mask_rom_version_number = { rom.at(332) };

	this->header_checksum = { rom.at(333) };

	this->global_checksum = { &rom[334], &rom[335] };
}
