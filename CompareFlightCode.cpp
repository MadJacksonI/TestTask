#include <iostream> 
#include <string>
#include "CompareFlightCode.h"

/*Function compare flight codes
inp args: code1 - first compared flight codes
		  code2 - second compared flight codes
*/
bool compareFlightCodes(const std::string& code1, const std::string& code2) {
    size_t i1 = 0, i2 = 0;

    // Determining the length of airline number
    size_t airlineEnd1 = (code1.size() >= 3 && std::isdigit(code1[2])) ? 2 : 3;
    size_t airlineEnd2 = (code2.size() >= 3 && std::isdigit(code2[2])) ? 2 : 3;

    // Compare codes
    while (i1 < airlineEnd1 && i2 < airlineEnd2 && i1 < code1.length() && i2 < code2.length()) {
        if (std::toupper(code1[i1]) != std::toupper(code2[i2])) {
			return false; // if finds difference ends check
		}
        i1++;
        i2++;
    }

    while (i1 < code1.length() && (code1[i1] == '0'|| code1[i1] == ' ')) i1++;
    while (i2 < code2.length() && (code2[i2] == '0'|| code2[i2] == ' ')) i2++;
        
    // Compare flight number
    return code1.substr(i1) == code2.substr(i2);
}


