#include <iostream>
#include "bus.h"


Bus::Bus() {
	for (auto& i : m_Bus) i = 0x00;
	
	std::cout << "BUS SIZE: " << m_Bus.size() << std::endl;

}

void Bus::write(uint16_t addr, uint8_t data) {
	if (addr >= 0x0000 && addr <= 0xFFFF) {
		m_Bus[addr] = data;
	}
	std::cout << "Panic addr out of scope: <" << addr << ">" << std::endl;

}

uint8_t Bus::read(uint16_t addr) {
	if (addr >= 0x0000 && addr <= 0xFFFF) {
		return m_Bus[addr];
	}
	return 0x00;
}