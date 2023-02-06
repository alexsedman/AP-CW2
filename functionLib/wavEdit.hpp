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
    void printHdr(int headerSize, FILE* wavFile);
    void changeSampleRate(std::string input);
    void addPause(int16_t* audioData, int numOfSamples);
    void normalise(int16_t* audioData, int numOfSamples);
    void reverse(int16_t* audioDaa, int numOfSamples);
};

#endif /* wavEdit_hpp */
