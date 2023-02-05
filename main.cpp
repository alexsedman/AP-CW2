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

// Current test file pathnames [TEMP]:
// /Users/alexsedman/Downloads/fragmentary sample v2.wav
// /Users/alexsedman/Downloads/fragmentary sample v2 MONO.wav
// /Users/alexsedman/Downloads/test.wav

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

#include "commandLib.hpp"
#include "wavEdit.hpp"



int main() {
    // Classes declared.
    commandLib cmd;
    wavEdit edit;
    
    // Variables declared.
    int hdrSize = sizeof(wavHdr), numOfSamples;
    std::string filePath, newFilePath, input;
    int16_t* audioStream;
    FILE* wavFile;
    
    while (true) {
        input = cmd.mainMenu(input); // Calls main menu.
        
        // Quit/info conditionals. [PUT THIS IN FUNCTION]
        if (input == "-quit") {
            std::cout << "\nBye!\n" << std::endl;
            return 0; // Quits program.
        } else if (input == "-info") {
            cmd.infoMenu(); // Calls info menu.
            continue;
        }
    
        // PUT THIS IN FILEREAD FUNCTION
        filePath = input;
        wavFile = fopen(input.c_str(), "rb+"); // 'rb+' is a binary read/update parameter. This allows the file to be read and separated into bytes easier, as well as updated if need be.
        
        //cmd.readFile(hdrSize, wavFile); // Reads the file and returns the audio data via a dynamic array pointer.
        
        // Throw an error if the file pointer returns a null value (i.e. the file read is unsuccessful).
        //REMOVE THIS CONDITIONAL - PUT IN READ FUNCTION
        if (wavFile == nullptr) {
            std::cout << "\nERROR: File can't be read/input is invalid." << std::endl;
        } else {
            
            //READ
            fread(&wavHdr, 1, hdrSize, wavFile); // An unsigned integer 'bytes_read' is assigned the value using the 'fread' function.
            fseek(wavFile, hdrSize, SEEK_SET);
            auto numOfSamples = wavHdr.dataSize / 2;
            int16_t* audioData = new(std::nothrow) int16_t[numOfSamples];
            fread(audioData, 2, numOfSamples, wavFile); //read audio data from sample 0
            
            // If the file is stereo, throw an error:
            if (wavHdr.numOfChannels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                continue;
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }

            input = cmd.optionsMenu(input); // Calls the options menu.
            
            if (input == "1") {
                edit.printHdr(hdrSize, wavFile); // File information is printed.
            } else if (input == "2") {
                
            } else if (input == "3") {
                
            } else if (input == "4") {
                
            } else if (input == "5") {
                
                
            } else {
                std::cout << "\nERROR: Invalid option selection. Returning to the main menu." << std::endl;
                continue;
            }
            
            newFilePath = cmd.filenameMenu(input, filePath, newFilePath); // Asks user for new filename.
            cmd.writeFile(hdrSize, newFilePath); // Writes new file.
        }
        
        fclose(wavFile);
        std::cout << std::endl; // Console new line.
    }
}
