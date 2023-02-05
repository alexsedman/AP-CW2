//
// commandLib.hpp
// CPP-CW2
//
// Created by Alex Sedman on 03/02/2023.
// A general command library for the program.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#ifndef commandLib_hpp
#define commandLib_hpp

/*----------WAV HEADER STRUCT----------*/
// A data structure is defined for the WAV header.
inline struct WAV_HEADER {
    // RIFF Chunk Descriptor
    uint8_t RIFF[4];
    uint32_t fileSize;
    uint8_t WAVE[4];

    // fmt subchunk
    uint8_t fmt[4];
    uint32_t fmtLen;
    uint16_t fmtType;
    uint16_t numOfChannels;
    uint32_t sampleRate;
    uint32_t dataRate;
    uint16_t blockAlign;
    uint16_t bitDepth;
    
    // Data subchunk
    uint8_t DATA[4];
    uint32_t dataSize;
} wavHdr;

class commandLib {
public:
    struct WAV_HEADER wavHdr;
    
    // General functions.
    std::string mainMenu(std::string input); // Main Menu.
    void infoMenu(); // Info menu.
    std::string optionsMenu(std::string input); // Options menu.
    std::string filenameMenu(std::string input, std::string filePathString, std::string newFilepath); // New file name menu.
    int16_t* readFile(int hdrSize, FILE* wavFile, int bytesPerSample, int numOfSamples); // Read file.
    void writeFile(int hdrSize, int numOfSamples, std::string newFilePath, int16_t* audioStream); // Write file.
};

#endif /* commandLib_hpp */
