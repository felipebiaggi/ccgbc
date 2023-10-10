#ifndef LOAD_ROM_H
#define LOAD_ROM_H
#include <filesystem>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <iomanip>

struct GameRomException : public std::exception {
	virtual const char* what() const throw()
	{
		return "Game ROM doesn't exist!";
	}
};

struct GameRomNotFoundException : public std::exception {
	virtual const char* what() const throw()
	{
		return "Game ROM not found";
	}
};


struct FileStruct {
	std::string filename;
	std::string extension;
	std::string path;
	std::vector<std::string> argv;
};

void validate_rom_name(char* argv[])
{
	std::string filename = argv[1];
}

std::vector<uint8_t> load_game_file(int argc, char* argv[]) {
	std::string debug;

	if (argc <= 1) {
		throw GameRomException();
	}
	else if(argc >= 3) {
		debug = argv[2];
	}

	std::filesystem::path f_path(argv[1]);

	std::ifstream s_file(std::filesystem::absolute(f_path), std::ios::binary);

	if (!s_file.good()) {
		throw GameRomNotFoundException();
	}
	else {
		int count = 0;
		std::stringstream c_string;

		if (debug == "--debug") {
			while (!s_file.eof()) {
				int value = s_file.get();

				if (count < 32) {
					c_string << std::setfill('0') << std::setw(2) << std::hex << value << " ";
				}
				else {
					count = 0;
					std::cout << c_string.str() << std::endl;
					c_string.str(std::string());
					c_string << std::hex << value << " ";
				}
				count++;
			}
			std::ifstream s_file(std::filesystem::absolute(f_path), std::ios::binary);
		}

		s_file.seekg(0, std::ios::end);
		std::cout << "Filename and extension: " << f_path.filename() << std::endl;
		std::cout << "File size: " << s_file.tellg() << std::endl;
		std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
		std::cout << "Absolute path: " << std::filesystem::absolute(f_path) << std::endl;
	}
	
	s_file.seekg(0, std::ios::beg);

	std::vector<uint8_t> game_data((std::istreambuf_iterator<char>(s_file)), std::istreambuf_iterator<char>());
	
	s_file.close();

	return game_data;
}

#endif // !LOAD_ROM_H
