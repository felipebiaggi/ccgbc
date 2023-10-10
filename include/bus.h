#ifndef BUS_H
#define BUS_H
#include <vector>
#include <cstdint>
#include <array>

class Bus {
public:
	Bus();

public:
	std::array<uint8_t, 64 * 1024> m_Bus = { 0 };
	
public:
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr);
};

#endif // !BUS_H
