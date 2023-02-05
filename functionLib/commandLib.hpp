//
//  commandLib.hpp
//  CPP-CW2
//
//  Created by Alex Sedman on 03/02/2023.
//

#ifndef commandLib_hpp
#define commandLib_hpp
#include <cstdint>

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
    uint16_t noChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t sampleLen;
    
    // Data subchunk
    uint8_t DATA[4];
    uint32_t dataSize;
} wavHdr;

class commandLib {
    
public:
    struct WAV_HEADER wavHdr;
    
    // General functions
    std::string mainMenu(std::string input);
    void infoMenu();
    std::string optionsMenu(std::string input);
    std::string filenameMenu(std::string input, const char* filePath);
    void writeFile(int hdrSize, std::string newFilePath);
};

#endif /* commandLib_hpp */
