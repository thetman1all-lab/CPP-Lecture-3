#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Project Assignment: Satellite Telemetry Parser Simulator
// Build a C++ program simulating a Starlink satellite ground station parser. It processes "telemetry packets" (user-input strings or numbers representing satellite data like position, velocity, signal strength). Use functions to modularize: one for validation, one for parsing, one for computing metrics (e.g., average signal using loops from Lesson 2).

// Requirements:

// Main loop (do-while) for menu: 1 = Input packet, 2 = Compute metrics, 3 = Quit.

// Function 1: bool validatePacket(const std::string& packet) — Check if valid (e.g., length >5, contains numbers via conditionals).

// Function 2: double parseSignal(const std::string& packet) — Extract signal value (e.g., assume format "SIG:42.5"—use loops to find ':' and convert).

// Function 3: double computeAverage(const double signals[], int count) — Average array of signals (use pass-by-const-reference for efficiency).

// Store up to 10 signals in an array; use I/O and conditionals for input handling.

// Handle errors (e.g., invalid packet discards without crash).

// Under 100 lines; clean, commented code.

// Autonomy Relevance: Simulates parsing satellite telemetry for fault detection—invalid data could indicate jamming or failure, requiring real-time rejection for network stability.

// Signal Packet:
// 1. SIG:42.5 POS:100.0 VEL:20.5
// 2. SIG:85.2 POS:150.3 VEL:15.0
// 3. SIG:-10.0 POS:200.5 VEL:10.2
// 4. SIG:60.0 POS:abc VEL:5.0
// 5. SIG:75.4 POS:300.0 VEL:25.8
// 6. SIG:30.1 POS:400.2 VEL:-5.0
// 7. SIG:95.0
// 8. SIG:50.5 POS:500.0 VEL:30.0
// 9. SIG:20.0 POS:600.5 VEL:35.2
// 10. SIG:invalid POS:700.0 VEL:40.0

// Signal Packet Key:
// 1. Valid packet
// 2. Valid
// 3. Invalid (negative signal)
// 4. Invalid (non-numeric position)
// 5. Valid
// 6. Invalid (negative velocity)
// 7. Invalid (incomplete, missing POS/VEL)
// 8. Valid
// 9. Valid
// 10. Invalid (non-numeric signal)

// File validation function
void loadTelemetryFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file!\n";
    }

    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines or comments (lines starting with //)
        if (line.empty() || line.find("//") == 0) {
            continue;
        }

        std::istringstream iss(line);   // treat the line as a stream
        std::string token;

        double sig = 0.0, pos = 0.0, vel = 0.0;
        bool hasSig = false, hasPos = false, hasVel = false;

        while (iss >> token) {          // split on spaces
            // token will be something like "SIG:42.5"
            size_t colonPos = token.find(':');
            if (colonPos == std::string::npos) continue;   // no colon → skip

            std::string key = token.substr(0, colonPos);
            std::string valueStr = token.substr(colonPos + 1);

            // Convert value to double
            double value = 0.0;
            try {
                value = std::stod(valueStr);
            } catch (...) {
                continue;   // bad number → skip
            }

            if (key == "SIG") { sig = value; hasSig = true; }
            else if (key == "POS") { pos = value; hasPos = true; }
            else if (key == "VEL") { vel = value; hasVel = true; }
        }

        // Now you have the three values for this packet
        std::cout << "Packet → SIG: " << sig 
                  << "  POS: " << pos 
                  << "  VEL: " << vel << "\n";

        // You can now call your functions here:
        // if (validatePacket(line)) {
        //     double signal = parseSignal(line);
        //     // store signal for averaging
        // }
    }

    file.close();
}

// Validation function to check if input is valid
bool validatePacket(const std::string& packet) {
    
}

// Extract signal value
double parseSignal(const std::string& packet) {
    // extract SIG value only
    size_t colon = packet.find("SIG:");
    if (colon == std::string::npos) return -1.0;  // error flag
    
    std::string val = packet.substr(colon + 4);
    // find next space or end
    size_t space = val.find(' ');
    if (space != std::string::npos) val = val.substr(0, space);
    return std::stod(val);
}

// Average srray of signals (use pass-by-const-reference for efficiency)
double computeAverage(const double signals[], int count) {}

int main() {

    int menu_input;

    // Main do/while loop
    do {

        // Error handling choice input
        if (!(std::cin >> menu_input)) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
            std::cout << "Invalid input! Please enter an integer.\n";
            continue; // Skip
        }

    } while(menu_input !=3);

    return 0;
}