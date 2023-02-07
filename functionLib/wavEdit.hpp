//
// wavEdit.cpp
// C++ CW2
//
// Created by Alex Sedman on 03/02/2023.
// A class containing the various wav edit functions that the program can perform, depending on what the user desires.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <algorithm>
#ifndef wavEdit_hpp
#define wavEdit_hpp

class wavEdit {
public:
    // WAV file edit functions (options).
    void printHdr(int headerSize, FILE* wavFile); // Prints header.
    void changeSampleRate(std::string input); // Changes sample rate.
    void addPause(int16_t* audioData, int numOfSamples); // Adds a pause.
    void normalise(int16_t* audioData, int numOfSamples); // Normalises audio.
    void reverse(int16_t* audioDaa, int numOfSamples); // Reverses audio.
};

#endif /* wavEdit_hpp */
