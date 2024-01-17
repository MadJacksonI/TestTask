#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "GanearateFlightCodes.h"

#define NumberFlightCodes 20

// generation random symbols
char randomChar(bool isAlpha) {
    if (isAlpha) {
        return 'A' + rand() % 26; 
    } else {
        return '1' + rand() % 9; 
    }
}

// Generation file of flight codes
std::string generateFlightCode() {
    std::string code;

    // Random generation of airline number
    int airlineCodeLength = rand() % 4;
    for (int i = 0; i < airlineCodeLength; ++i) {
        code += randomChar(true); 
    }

    if (airlineCodeLength == 2) {
        code += ' ';
    }

    // Random generation of flight number
    int maxFlightNumberLength = 7 - code.length();
    int flightNumberLength = 1 + rand() % maxFlightNumberLength;
    for (int i = 0; i < flightNumberLength; ++i) {
        code += randomChar(false); 
    }

    return code;
}

int generator(const std::string& input_file) 
{
    srand(time(0));

    std::ofstream file(input_file);

    for (int i = 0; i < NumberFlightCodes; ++i) 
	{
		std::string code = generateFlightCode();
        file << code << std::endl<< code << std::endl;
    }

    return 1;
}
