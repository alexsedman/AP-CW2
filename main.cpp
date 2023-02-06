//
// main.cpp
// C++ CW2
//
// Created by Alex Sedman.
//
// TASK: Create a program without using any Audio Libraries to read a .wav file, perform some basic processed to the audio data and write the resulting audio data to a new .wav file.
// NOTE: Due to the file naming system in this program, it will only work robustly on Mac OS.
//

/*
/Users/alexsedman/Downloads/test.wav
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <algorithm>
#include "commandLib.hpp"
#include "wavEdit.hpp"

int main() {
    // Classes initialised.
    commandLib cmd;
    wavEdit edit;
    
    // Variables declared.
    int headerSize = sizeof(wavHdr);
    std::string input;
    const char* filePath;
    int16_t* audioData;
    FILE* wavFile;
    
    while (true) {
        std::cin.clear();
        input = cmd.mainMenu(input); // Calls main menu.
        
        if (input == "-quit") {
            std::cout << "\nBye!\n" << std::endl;
            return 0; // Quits program.
            
        } else if (input == "-info") {
            cmd.infoMenu(); // Calls info menu.
            continue;
        }
    
        filePath = input.c_str(); // Sets the file path to the user input.
        wavFile = fopen(filePath, "rb+"); // Attempts to open the inputted file.
        
        if (wavFile == nullptr) {
            std::cout << "\nERROR: File can't be read/input is invalid.\n" << std::endl;
            continue; // If the input is invalid (i.e. 'fopen' returns a null pointer), then this error is thrown and the loop is skipped.
        } else {
            
            fread(&wavHdr, 1, headerSize, wavFile); // Header information is read from 'wavFile'.
            fseek(wavFile, headerSize, SEEK_SET); // File pointer is set to the start of the audio stream.
            int numOfSamples = wavHdr.dataSize / 2;
            int16_t* audioData = new(std::nothrow) int16_t[numOfSamples]; // A pointer to a dynamic array is created; the audio stream will be stored here.
            fread(audioData, 2, numOfSamples, wavFile); // Audio stream is read from 'wavFile'.
            fclose(wavFile); // Close the original file.
            
            //TEST
            for (int i = 0; i < 1000; i++) {
                printf("Sample %d: %d\n", i, audioData[i]);
            }
            
            // ADD CONDITIONAL FOR NON-16BIT FILES
            
            if (wavHdr.numChannels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                //continue; // If the file is stereo, throw an error:
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }

            input = cmd.optionsMenu(input); // Calls the options menu.
            
            if (input == "1") {
                edit.printHdr(headerSize, wavFile); // File information is printed.
                fclose(wavFile);
                continue; // Skips the write phase of the program, as it is not needed for this option.
            } else if (input == "2") {
                edit.changeSampleRate(input);
            } else if (input == "3") {
                edit.addPause(audioData, numOfSamples);
            } else if (input == "4") {
                edit.normalise(audioData, numOfSamples);
            } else if (input == "5") {
                edit.reverse(audioData, numOfSamples);
            } else {
                std::cout << "\nERROR: Invalid option selection. Returning to the main menu.\n" << std::endl;
                continue;
            }
            
            std::string newFilePath = cmd.filenameMenu(input, filePath); // Asks user for new filename.
            cmd.writeFile(headerSize, numOfSamples, newFilePath, audioData); // Writes new file.
            
        }
        std::cout << std::endl; // Console new line.
    }
}
