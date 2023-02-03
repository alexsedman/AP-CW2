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
// Current test file pathnames:
// /Users/alexsedman/Downloads/fragmentary sample v2.wav
// /Users/alexsedman/Downloads/fragmentary sample v2 MONO.wav
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

#include "commandLib.hpp"
#include "wavEdit.hpp"



int main() {
    /*----------INITIALISATION----------*/
    // Classes declared.
    commandLib cmd;
    wavEdit edit;
    
    // Variables declared: pointer to the filepath name and an input string.
    int hdrSize = sizeof(cmd.wavHdr); // A variable to measure the size of the WAV header (this should be equivalent to 44 bytes).
    const char* filePath;
    std::string input;
    
    while (1) {
        /*----------MAIN MENU----------*/
        // Calls main menu
        input = cmd.mainMenu(input);
        
        // Quit/info conditionals.
        if (input == "-quit") {
            std::cout << "\nBye!\n" << std::endl;
            return 0;
        } else if (input == "-info") {
            cmd.info();
            continue;
        }
        
        /*----------FILE READ----------*/
        // The file pathname is read, and the file info is committed to memory as a data stream, with 'wav_file' pointing to the first byte of data in this stream.
        //This means that the position of every value in the data stream is known, and committed to memory sequentially.
        filePath = input.c_str();
        FILE* wavFile;
        wavFile = fopen(filePath, "rb+"); // 'rb+' is a binary read/update parameter. This allows the file to be read and separated into bytes easier, as well as updated if need be.
        
        // Parity checks and file read.
        if (wavFile == nullptr) {
            std::cout << "\nERROR: File can't be read/input is invalid." << std::endl; // Throw an error if the file pointer returns a null value (i.e. the file read is unsuccessful).
        } else {
            
            fread(&cmd.wavHdr, 1, hdrSize, wavFile); // An unsigned integer 'bytes_read' is assigned the value using the 'fread' function.
            if (cmd.wavHdr.noChannels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                continue;
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }
            
            /*----------OPTION SECTION----------*/
            // Calls the options menu.
            input = cmd.options(input);
            
            if (input == "1") {
                edit.printHdr(hdrSize, wavFile); // File information is printed.
            } else if (input == "2") {
                //sample recalc
                cmd.filename(input, filePath);
            } else if (input == "3") {
                
                cmd.filename(input, filePath);
            } else if (input == "4") {
                
                cmd.filename(input, filePath);
            } else if (input == "5") {
                
                cmd.filename(input, filePath);
            } else {
                std::cout << "\nERROR: Invalid option selection. Returning to the main menu." << std::endl;
            }
        }
        
        fclose(wavFile);
        std::cout << std::endl;
    }
}

