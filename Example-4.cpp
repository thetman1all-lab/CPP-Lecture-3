#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Use <sstream> to parse lines with delimiters (space, colon, comma)

int main() {

    // Make file accessable to the program
    std::ifstream inputFile("telemetry_sample.txt");

    // Check to see if file even opens
    if (!inputFile.is_open()) return 1;

    // Declare line variable
    std::string line;
    
    while (std::getline(inputFile, line)) {  // Read full line

        // Make stream variable "iss" for parsing
        std::istringstream iss(line);

        std::string token;
        double sig = -1, pos = -1, vel = -1;  // Default values for invalid

        while (iss >> token) {  // Split on spaces (field delimiter)
            size_t colonPos = token.find(':');  // Colon as key-value delimiter
            if (colonPos == std::string::npos) continue;

            std::string key = token.substr(0, colonPos);
            std::string valueStr = token.substr(colonPos + 1);
            double value;
            try {
                value = std::stod(valueStr);  // Convert to double
            } catch (...) {
                continue;  // Bad value (e.g., "abc")
            }

            if (key == "SIG") sig = value;
            else if (key == "POS") pos = value;
            else if (key == "VEL") vel = value;
        }

        // Now use parsed values (e.g., for your parseSignal)
        if (sig != -1) {
            std::cout << "Parsed SIG: " << sig << ", POS: " << pos << ", VEL: " << vel << std::endl;
        } else {
            std::cout << "Invalid line: " << line << std::endl;
        }
    }

    inputFile.close();

    return 0;
}