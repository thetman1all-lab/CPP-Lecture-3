#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>




int main(){

    // Use ifstream to link file to program to be able to extract data from it
    std::ifstream inputFile("telemetry_sample.txt");

    // Validate the opening of the file
    if (!inputFile.is_open()) {
        std::cerr << "Error: Failed to open file!" << std::endl;
        return 1;  // Exit with error code
    }

    // Initialize variable for lines
    std::string line;

    // Read entire line with while loop (delimited by newline)
    while (std::getline(inputFile, line)) {
        std::cout << "Read line: " << line << std::endl;
    }

    // Always close the file for good practice
    inputFile.close();

    return 0;
}