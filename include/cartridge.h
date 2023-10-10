#ifndef CARTRIDGE_H
#define CARTRIDGE_H
#include <iostream>
#include <cstdint>
#include <memory>
#include "bus.h"

class Cartridge {
public:
	Cartridge(std::vector<uint8_t> rom, std::shared_ptr<Bus> bus);

private:
	std::string game_title{};
	std::string manufactured_code{};
    uint8_t cgb_flag{};
    std::string licensee_code;
    uint8_t sgb_flag{};
    uint8_t cartridge_type{};
    uint8_t rom_size{};
    uint8_t ram_size{};
    uint8_t destination_code{};
    uint8_t old_licensee_code{};
    uint8_t mask_rom_version_number{};
    uint8_t header_checksum{};
    std::string global_checksum{};

	std::shared_ptr<Bus> m_Bus;
    std::vector<uint8_t> m_Rom;
};

#endif // !CARTRIDGE_H
