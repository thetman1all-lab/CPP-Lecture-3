#include <iostream>
#include <fstream>

int main() {

    // Use std::ofstream for output; append mode prevents overwriting
    std::ofstream outputFile("output_metrics.txt", std::ios::app);  // Append mode

    if (!outputFile.is_open()) {
        std::cerr << "Error: Failed to open output file!" << std::endl;
        return 1;
    }

    double averageSignal = 55.3; // Simulated from computing average

    outputFile << "Average Signal Strength: " << averageSignal << std::endl; // Write line

    outputFile.close(); // Always close your files damnit!

    std::cout << "Data written successdully." << std::endl;

    return 0;
}