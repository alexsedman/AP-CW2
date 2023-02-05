//
// main.cpp
// C++ CW2
//
// Created by Alex Sedman.
//
// GitHub branch update - I'm avoiding a heavy object-based approach for this code as the scope of the project is more manageable in a few CPP files.
// NOTE: Due to the file naming system in this program, it will only work robustly on Mac OS.
//
// TASK: Create a program without using any Audio Libraries to read a .wav file, perform some basic processed to the audio data and write the resulting audio data to a new .wav file.
//

// /Users/alexsedman/Downloads/test.wav

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include "commandLib.hpp"
#include "wavEdit.hpp"

int main() {
    // Classes initialised.
    commandLib cmd;
    wavEdit edit;
    
    // Variables declared.
    int hdrSize = sizeof(wavHdr), numOfSamples, bytesPerSample;
    std::string filePath, newFilePath, input;
    int16_t* audioStream;
    FILE* wavFile;
    
    while (true) {
        input = cmd.mainMenu(input); // Calls main menu.
        
        if (input == "-quit") {
            std::cout << "\nBye!\n" << std::endl;
            return 0; // Quits program.
            
        } else if (input == "-info") {
            cmd.infoMenu(); // Calls info menu.
            continue;
        }
    
        filePath = input; // Sets the file path to the user input.
        wavFile = fopen(input.c_str(), "rb+"); // Attempts to open the inputted file.
        
        if (wavFile == nullptr) {
            std::cout << "\nERROR: File can't be read/input is invalid.\n" << std::endl;
            continue; // If the input is invalid (i.e. 'fopen' returns a null pointer), then this error is thrown and the loop is skipped.
        } else {
            
            audioStream = cmd.readFile(hdrSize, wavFile, bytesPerSample, numOfSamples); // Reads inputted file
            
            if (wavHdr.numOfChannels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                continue; // If the file is stereo, throw an error:
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }

            input = cmd.optionsMenu(input); // Calls the options menu.
            
            if (input == "1") {
                edit.printHdr(hdrSize, wavFile); // File information is printed.
                continue; // Skips the write phase of the program, as it is not needed for this option.
            } else if (input == "2") {
                
            } else if (input == "3") {
                
            } else if (input == "4") {
                
            } else if (input == "5") {
                
            } else {
                std::cout << "\nERROR: Invalid option selection. Returning to the main menu.\n" << std::endl;
                continue;
            }
            newFilePath = cmd.filenameMenu(input, filePath, newFilePath); // Asks user for new filename.
            cmd.writeFile(hdrSize, numOfSamples, newFilePath, audioStream); // Writes new file.
        }
        std::cout << std::endl; // Console new line.
    }
}
