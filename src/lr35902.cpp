#include "lr35902.h"

lr35902::lr35902(std::shared_ptr<Bus> bus) {

	this->m_Bus = bus;

	reset();
}

lr35902::~lr35902() {

}


void lr35902::clock()
{

}

void lr35902::reset() {
	
}

uint8_t lr35902::read(uint16_t addr)
{
	return m_Bus->read(addr);
}

void lr35902::write(uint16_t addr, uint8_t data)
{
	m_Bus->write(addr, data);
}

void lr35902::ld(uint8_t* u8, uint16_t* addr)
{
	*u8 = read(*addr);
}

void lr35902::ld(uint8_t* upper, uint8_t* lower, uint8_t* u8) 
{
	uint16_t addr = (*upper << 8 | *lower);

	write(addr, *u8);
}

void lr35902::ld(uint8_t* u8, uint8_t* value) 
{
	*u8 = *value;
}

void lr35902::ld_hlp(uint8_t* upper, uint8_t* lower, uint8_t* u8)
{
	uint16_t addr = (*upper << 8 | *lower);

	write(addr, *u8);

	addr++;

	*upper = static_cast<uint8_t>(addr >> 8 & 0x00FF);
	*lower = static_cast<uint8_t>(addr & 0x00FF);
}

void lr35902::ld_hlm(uint8_t* upper, uint8_t* lower, uint8_t* u8)
{
	uint16_t addr = (*upper << 8 | *lower);

	write(addr, *u8);

	addr--;

	*upper = static_cast<uint8_t>(addr >> 8 & 0x00FF);
	*lower = static_cast<uint8_t>(addr & 0x00FF);

}

void lr35902::inc(uint8_t* upper, uint8_t* lower)
{
	uint16_t increment = (*upper << 8 | *lower);

	increment++;

	*upper = static_cast<uint8_t>(increment >> 8 & 0x00FF);
	*lower = static_cast<uint8_t>(increment & 0x00FF);

}

void lr35902::inc(uint8_t* u8)
{
	F.bits.N = 0;

	uint8_t result = *u8 = 1;

	if (result == 0x00) {
		F.bits.Z = 1;
 	}

	if ((result & 0x0F) == 0x00) {
		F.bits.H = 1;
	}

	*u8 = static_cast<uint8_t>(result);
}

void lr35902::dec(uint8_t* u8)
{
	F.bits.N = 1;

	uint8_t result = *u8 - 1;

	if (result == 0x00) {
		F.bits.Z = 1;
	}

	if ((result & 0x0F) == 0x0F) {
		F.bits.H = 1;
	}

	*u8 = static_cast<uint8_t>(result);

}
