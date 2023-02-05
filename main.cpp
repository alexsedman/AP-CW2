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
#include "commandLib.hpp"
#include "wavEdit.hpp"

int main() {
    // Classes initialised.
    commandLib cmd;
    wavEdit edit;
    
    // Variables declared.
    int hdrSize = sizeof(wavHdr), numOfSamples, bytesPerSample;
    std::string input;
    const char* filePath;
    int16_t* audioStream;
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
            
            //audioData = cmd.readFile(hdrSize, wavFile, bytesPerSample, numOfSamples); // Reads inputted file
            fread(&wavHdr, 1, hdrSize, wavFile); // Header information is read from 'wavFile'.
            fseek(wavFile, hdrSize, SEEK_SET); // File pointer is set to the start of the audio stream.
            bytesPerSample = wavHdr.bitDepth / 8;
            numOfSamples = wavHdr.dataSize / bytesPerSample; // Number of samples is calculated (bit depth/2).
            int16_t* audioData = new int16_t[numOfSamples]; // A pointer to a dynamic array is created; the audio stream will be stored here.
            fread(audioData, bytesPerSample, numOfSamples, wavFile); // Audio stream is read from 'wavFile'.
            
            for (int i = 0; i < 1000; i++) {
                printf("Sample %d: %d\n", i, audioStream[i]);
            }
            
            if (wavHdr.numOfChannels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                continue; // If the file is stereo, throw an error:
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }

            input = cmd.optionsMenu(input); // Calls the options menu.
            
            if (input == "1") {
                edit.printHdr(hdrSize, wavFile); // File information is printed.
                fclose(wavFile);
                continue; // Skips the write phase of the program, as it is not needed for this option.
            } else if (input == "2") {
                
            } else if (input == "3") {
                
            } else if (input == "4") {
                
            } else if (input == "5") {
                
            } else {
                std::cout << "\nERROR: Invalid option selection. Returning to the main menu.\n" << std::endl;
                continue;
            }
            
            std::string newFilePath = cmd.filenameMenu(input, filePath); // Asks user for new filename.
            cmd.writeFile(hdrSize, numOfSamples, newFilePath, audioStream); // Writes new file.
            fclose(wavFile);
        }
        std::cout << std::endl; // Console new line.
    }
}
