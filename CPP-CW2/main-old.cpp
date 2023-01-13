//
//  main.cpp
//  cpp-cw-ajs_v5
//
//  Created by Alex Sedman on 03/01/2023.
//
// by AJS ----FILL METADATA HERE----
#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

struct WAV_HEADER {
    /* RIFF Chunk Descriptor */
    uint8_t RIFF[4];
    uint32_t ChunkSize;
    uint8_t WAVE[4];

    /* "fmt" sub-chunk */
    uint8_t fmt[4];
    uint32_t Subchunk1Size;
    uint16_t AudioFormat;
    uint16_t NumOfChan;
    uint32_t SamplesPerSec;
    uint32_t BytesPerSec;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    
    /* "data" sub-chunk */
    uint8_t subchunk2ID[4];
    uint32_t subChunk2Size;
} wav_hdr;

int main() {
    //Check header size
    int headerSize = sizeof(wav_hdr);
    std::cout << headerSize << std::endl;
    
    const char* filePath;
    std::string input;

    std::cout << "Input wave file name: ";
    std::cin >> input;
    filePath = input.c_str();

    for(int i=0; i<9; i++) {
        std::cout << filePath[i] << std::endl;
    }
    
    FILE* wavFile;
    wavFile = fopen(filePath, "r");
    
    if (wavFile==nullptr) {
        std::cout << "Unable to open the file" << std::endl;
        return 0;
    } else {
        std::cout << "All OK...!" << std::endl;
    }
    
    //Read the header
    size_t bytesRead = fread(&wav_hdr, 1, headerSize, wavFile);
    std::cout << bytesRead << std::endl;
    //cout << wav_hdr.blockAlign << endl;
    return 0;
}
