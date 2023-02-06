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
    cout << "Chunk ID (File Spec): " << wavHdr.RIFF[0] << wavHdr.RIFF[1] << wavHdr.RIFF[2] << wavHdr.RIFF[3] << endl;
    cout << "Chunk Size: " << wavHdr.fileSize << endl;
    cout << "File Type (FourCC Tag): " << wavHdr.WAVE[0] << wavHdr.WAVE[1] << wavHdr.WAVE[2] << wavHdr.WAVE[3] << endl;
    
    cout << "Subchunk 1 ID (Format): " << wavHdr.fmt[0] << wavHdr.fmt[1] << wavHdr.fmt[2] << wavHdr.fmt[3] << endl;
    cout << "Subchunk Size: " << wavHdr.fmtSize << endl;
    cout << "Audio Format: " << wavHdr.fmtType << endl;
    cout << "Number of Channels: " << wavHdr.numChannels << endl;
    cout << "Sample Rate: " << wavHdr.sampleRate << endl;
    cout << "Data Rate (Bps): " << wavHdr.byteRate << endl;
    cout << "Block Align: " << wavHdr.blockAlign << endl;
    cout << "Bits Per Sample: " << wavHdr.bitsPerSample << endl;
    
    cout << "Subchunk 2 ID (Data): " << wavHdr.DATA[0] << wavHdr.DATA[1] << wavHdr.DATA[2] << wavHdr.DATA[3] << endl;
    cout << "Subchunk 2 Size: " << wavHdr.dataSize << endl << endl;
    fclose(wavFile);
}

/*----------(2) CHANGE SAMPLE RATE----------*/
// Changes sample rate of the WAV file according to user input.
uint32_t wavEdit::changeSampleRate(std::string input, uint32_t sampleRate) {
    std::cout << "---OPTION 2: CHANGE SAMPLE RATE---" << std::endl;
    std::cout << "Please choose a new sample rate between 11025-192000Hz." << std::endl;
    
    return sampleRate;
}

/*----------(3) ADD PAUSE----------*/
/*----------(4) NORMALISE----------*/
/*----------(5) FILTER----------*/
