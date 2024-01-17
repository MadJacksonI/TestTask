#include <iostream> 
#include <fstream> 
#include <set> 
#include <string> 
#include <mutex>
#include "GanearateFlightCodes.h"

extern std::mutex cout_mutex;

/* Text file processing func
arg: const std::string& input_file - input file path
	 const std::string& output_file - output file path
*/
int processFile(const std::string& input_file, const std::string& output_file) 
{
    std::set<std::string> unique_lines;
    std::string line; 

    std::ifstream infile(input_file); 
    
    //If file in1 or in2 are not exist, generates them
    if (!infile){
    	std::cerr << "Error open file" << input_file << std::endl;
    	std::cerr << "Start generation file" << input_file << std::endl;
    	generator(input_file);
    	infile.open(input_file);
	}
    	
    while (getline(infile, line)) { 
        unique_lines.insert(line); 
    }
    infile.close(); 

    std::ofstream outfile(output_file); 
    
    for (const auto& unique_line : unique_lines) { 
        outfile << unique_line << std::endl; 
    }
    outfile.close(); 
    
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Thread has finished working. Find "<< unique_lines.size()  << " uniq flight code" << std::endl;
    
    return 1;
}
