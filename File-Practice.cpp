#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Validation function to check if file can open
bool ValidateFile(const std::string& filename) {
    std::ifstream file(filename);

    // Checks existence and open state
    if (!file.good()) {
        std::cerr << "Invalid file: Does not exist or unreadable." << std::endl;
        return false;
    }

    file.close();
    return true;
}

// Packet content validation
bool ValidatePacket(const std::string& packet) {
    // Check: Length > 10, contains "SIG:", or no negatives
    // std::string::npos is a constant "not found" state
    // If "SIG:" is not found with find() function, we compare its result to it
    if (packet.length() < 10 || packet.find("SIG:") == std::string::npos) {
        return false;
    }

    // Advanced: Parse and check values (e.g., signal >0)
    // size_t is an unsigned (0 or positive) integer type used to represent the sizes of objects
    size_t sigPos = packet.find("SIG:");
    
    // If sigPos not equal to Not Found, then save signal values
    if (sigPos != std::string::npos) {
        // Once "SIG:" is found, save a sub string that is 4 positions out (SIG: is 4 characters)
        std::string sigStr = packet.substr(sigPos + 4);

        // Extract the bool value of the signal
        double sig = std::stod(sigStr.substr(0, sigStr.find(' ')));

        if (sig < 0) return false;
    }
}

int main(){

    //------------------------------------------------------------------------------------------------------------------
    // Reading a File (Basic Line-by-Line)
    //------------------------------------------------------------------------------------------------------------------

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
        // Output: Prints each telemetry packet as-is
        std::cout << "Read line: " << line << std::endl;
    }

    // Always close the file for good practice
    inputFile.close();

    //------------------------------------------------------------------------------------------------------------------
    // Validating a File and Its Content
    //------------------------------------------------------------------------------------------------------------------

    // Declare file name as a string
    std::string filename = "telemetry_sample.txt";

    // If file cannot be opened (false), negate (true) and return 1
    if (!ValidateFile(filename)) return 1;

    // 
    std::ifstream inputFile(filename);
    std::string line;
    while (std::getline(inputFile, line)) {
        if (ValidatePacket(line)) {
            std::cout << "Valid packet: " << line << std::endl;
        } else {
            std::cout << "Invalid packet: " << line << std::endl;
        }
    }
    inputFile.close();

    return 0;
}