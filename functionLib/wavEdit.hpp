//
//  wavEdit.hpp
//  CPP-CW2
//
//  Created by Alex Sedman on 03/02/2023.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

#ifndef wavEdit_hpp
#define wavEdit_hpp

class wavEdit {
public:
    // WAV file edit functions (options).
    void printHdr(int hdrSize, FILE* wavFile);
    uint32_t changeSampleRate(std::string input, uint32_t sampleRate);
};

#endif /* wavEdit_hpp */
