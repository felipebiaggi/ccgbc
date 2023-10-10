#ifndef LR35902_H
#define LR35902_H
#include <cstdint>
#include <memory>
#include "bus.h"

class lr35902 {
	
public:
	lr35902(std::shared_ptr<Bus> bus);
	~lr35902();


public:

	// Register A
	uint8_t A = 0x00;

	// Flags - Register F
	// |7|6|5|4|3|2|1|0
	// ----------------
	// |Z|N|H|C|0|0|0|0

	union FLAGS {
		struct
		{
			uint8_t : 4;
			uint8_t C : 1;
			uint8_t H : 1;
			uint8_t N : 1;
			uint8_t Z : 1;

		} bits;
		uint8_t values;
	} F = { 0x00 };


	// Register BC
	uint8_t B = 0x00;
	uint8_t C = 0x00;

	// Register DE
	uint8_t D = 0x00;
	uint8_t E = 0x00;

	// Register HL
	uint8_t H = 0x00;
	uint8_t L = 0x00;

	//Stack Pointer 
	uint8_t S = 0x00;
	uint8_t P = 0x00;

	// Program Counter
	uint16_t PC = 0x0000;


	bool halt = false;
	bool interruption = false;

	uint8_t opcode = 0x00;
	uint8_t cycles = 0;

	void clock();

	uint8_t read(uint16_t addr);
	void write(uint16_t addr, uint8_t data);

private:
	
	std::shared_ptr<Bus> m_Bus;

	void reset();

	void ld(uint8_t* u8, uint16_t* addr);
	void ld(uint8_t* upper, uint8_t* lower, uint8_t* u8);
	void ld(uint8_t* u8, uint8_t* value);

	void ld_hlp(uint8_t* upper, uint8_t* lower, uint8_t* u8);
	void ld_hlm(uint8_t* upper, uint8_t* lower, uint8_t* u8);

	void add_hl(uint8_t* upper, uint8_t* lower);

	void inc(uint8_t* upper, uint8_t* lower);
	void inc(uint8_t* u8);

	void dec(uint8_t* upper, uint8_t* lower);
	void dec(uint8_t* u8);

	void jr(uint16_t* pc);
	void jp(uint16_t* pc);

	void call(uint16_t* pc);

	uint8_t add(uint8_t u8_1, uint8_t u8_2);
	uint8_t add(uint8_t u8, uint16_t r16);

	uint8_t adc(uint8_t u8_1, uint8_t u8_2);
	uint8_t adc(uint8_t u8, uint16_t r16);

	uint8_t sub(uint8_t u8_1, uint8_t u8_2);
	uint8_t sub(uint8_t u8, uint16_t r16);

	uint8_t sbc(uint8_t u8_1, uint8_t u8_2);
	uint8_t sbc(uint8_t u8, uint16_t r16);

	uint8_t and_op(uint8_t u8_1, uint8_t u8_2);
	uint8_t and_op(uint8_t u8, uint16_t r16);

	uint8_t or_op(uint8_t u8_1, uint8_t u8_2);
	uint8_t or_op(uint8_t u8, uint16_t r16);

	void cp(uint8_t u8_1, uint8_t u8_2);
	void cp(uint8_t u8, uint16_t r16);

	void pop(uint16_t* u16);
	void pop(uint8_t* upper, uint8_t* lower);

	void process(uint16_t opcode);

};

#endif // !LR35902_H
