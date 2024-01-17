#include <iostream> 
#include <thread> 
#include <mutex>
#include <vector>
#include "GanearateFlightCodes.h"
#include "CompareFlightCode.h"
#include "FilterUniqFlightCode.h"

std::mutex cout_mutex;

int main() 
{
    while (true) {
        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Process Files\n";
        std::cout << "2. Compare Flight Codes\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: 
            {
            	std::cout << "Start working...\n";
                std::thread thread1(processFile, "1_in.txt", "1_out.txt"); 
                std::thread thread2(processFile, "2_in.txt", "2_out.txt"); 

                thread1.join(); 
                thread2.join(); 
                break;
            }
            case 2: 
            {
                std::string flightCode1, flightCode2;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter first flight code (or type 'S' for standard set): "<< std::endl;
                std::getline(std::cin, flightCode1);

                if (flightCode1 == "S") {
                    std::vector<std::pair<std::string, std::string>> codes = {
                        {"ALF0001", "ALF1"}, {"D2 25", "D225"}, {"D2025", "D2 25"}, {"D225", "D2025"}
                    };
                    for (const auto& pair : codes) {
                        std::cout << (compareFlightCodes(pair.first, pair.second) ? pair.first + " " + pair.second + " " + "Equal": pair.first + " " + pair.second + " " + "Not Equal") << std::endl;
                    }
                } else 
                {
                    //Clean 
                    std::cout << "Enter second flight code: " << std::endl;
                    std::getline(std::cin, flightCode2);
                    std::cout << (compareFlightCodes(flightCode1, flightCode2) ? "Equal" : "Not Equal") << std::endl;
                    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            }
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
