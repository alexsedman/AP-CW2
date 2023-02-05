//
// wavEdit.cpp
// CPP-CW2
//
// Created by Alex Sedman on 03/02/2023.
// A class containing the various wav edit functions that the program can perform, depending on what the user desires.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include "commandLib.hpp"
#include "wavEdit.hpp"

/*----------(1) PRINT WAV HEADER----------*/
// Function to print WAV header.
void wavEdit::printHdr(int hdrSize, FILE* wavFile) {
    using namespace std;
    commandLib hdr;
    //Print the header.
    cout << endl;
    cout << "---OPTION 1: PRINT---" << endl;
    cout << "Chunk ID (File Spec): " << hdr.wavHdr.RIFF[0] << hdr.wavHdr.RIFF[1] << hdr.wavHdr.RIFF[2] << hdr.wavHdr.RIFF[3] << endl;
    cout << "Chunk Size: " << hdr.wavHdr.fileSize << endl;
    cout << "File Type (FourCC Tag): " << hdr.wavHdr.WAVE[0] << hdr.wavHdr.WAVE[1] << hdr.wavHdr.WAVE[2] << hdr.wavHdr.WAVE[3] << endl;
    
    cout << "Subchunk 1 ID (Format): " << wavHdr.fmt[0] << wavHdr.fmt[1] << wavHdr.fmt[2] << wavHdr.fmt[3] << endl;
    cout << "Subchunk Size: " << wavHdr.fmtLen << endl;
    cout << "Audio Format: " << wavHdr.fmtType << endl;
    cout << "Number of Channels: " << wavHdr.numOfChannels << endl;
    cout << "Sample Rate: " << wavHdr.sampleRate << endl;
    cout << "Data Rate (Bps): " << wavHdr.dataRate << endl;
    cout << "Block Align: " << wavHdr.blockAlign << endl;
    cout << "Bits Per Sample: " << wavHdr.bitDepth << endl;
    
    cout << "Subchunk 2 ID (Data): " << wavHdr.DATA[0] << wavHdr.DATA[1] << wavHdr.DATA[2] << wavHdr.DATA[3] << endl;
    cout << "Subchunk 2 Size: " << wavHdr.dataSize << endl;
    fclose(wavFile);
}

/*----------(2) CHANGE SAMPLE RATE----------*/
// Changes sample rate of the WAV file according to user input.
uint32_t wavEdit::changeSampleRate(std::string input, uint32_t sampleRate) {
    std::cout << "---OPTION 2: CHANGE SAMPLE RATE---" << std::endl;
    std::cout << "Please choose a new sample rate between 24000-192000Hz." << std::endl;
    /*input = " ";
    while (input.is_number() == 0)
        std::getline(std::cin, input);
        if (input.is_number() == 0) {
            std::cout << "Invalid input" << std::endl;
        }
    }
    std::cout << "New sample rate: ";*/
    
    return sampleRate;
}

/*----------(3) ADD PAUSE----------*/
/*----------(4) NORMALISE----------*/
/*----------(5) FILTER----------*/
