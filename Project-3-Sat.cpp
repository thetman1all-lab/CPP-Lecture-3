#include <iostream>

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

// Validation function to check if input is valid
bool validatePacket(const std::string& packet) {
    
}

// Extract signal value
double parseSignal(const std::string& packet) {}

// Average srray of signals (use pass-by-const-reference for efficiency)
double computeAverage(const double signals[], int count) {}

int main() {

    int menu_input;

    // Main do/while loop
    do {

        // Error handling shoice input
        if (!(std::cin >> menu_input)) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
            std::cout << "Invalid input! Please enter an integer.\n";
            continue; // Skip
        }

    } while(menu_input !=3);

    return 0;
}