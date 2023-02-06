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
#include "commandLib.hpp"
#include "wavEdit.hpp"

commandLib cmd;

/*----------(1) PRINT WAV HEADER----------*/
// Function to print WAV header.
void wavEdit::printHdr(int headerSize, FILE* wavFile) {
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
}

/*----------(2) CHANGE SAMPLE RATE----------*/
// Changes sample rate of the WAV file according to user input.
void wavEdit::changeSampleRate(std::string input) {
    std::cout << "\n---OPTION 2: CHANGE SAMPLE RATE---" << std::endl;
    std::cout << "Please choose a new sample rate between 11025-192000Hz." << std::endl;
    
    while (true) {
        std::cout << "New sample rate: ";
        getline(std::cin, input);
        try {
            uint32_t sampleRange = std::stoul(input);
            if (sampleRange < 11025 || sampleRange > 192000) {
                throw std::out_of_range("Value is outside of allowed range (11025-192000Hz)"); // The range 11025-192000Hz is representative of (44.1k/4) to (48k*4).
            }
            std::cout << sampleRange << std::endl;  // Output: 42
        } catch (const std::invalid_argument&) {
            std::cerr << "ERROR: Invalid input." << std::endl;
            continue;
        } catch (const std::out_of_range&) {
            std::cerr << "ERROR: Value out of range! (11025-192000Hz)" << std::endl;
            continue;
        }
        break;
    }
    
    wavHdr.sampleRate = std::stoul(input);
}

/*----------(3) ADD PAUSE----------*/
void wavEdit::addPause(int16_t* audioData, int numOfSamples) {
    int pauseStart = ((numOfSamples/2) + (numOfSamples/100)), pauseEnd = ((numOfSamples/2) + (numOfSamples/30)); // Start and end samples of pause are defined.
    for (int i = pauseStart; i <= pauseEnd; i++) {
        audioData[i] = 0;
    }
}

/*----------(4) NORMALISE----------*/
void wavEdit::normalise(int16_t* audioData, int numOfSamples) {
    int16_t maxValue = audioData[0];
      for (int i = 1; i < numOfSamples; i++) {
        if (audioData[i] > maxValue) {
          maxValue = audioData[i];
        }
      }
    
    // Normalize the data using a for loop.
    for (int i = 0; i < numOfSamples; i++) {
        audioData[i] = (audioData[i] * 32767) / maxValue;
      }
}
/*----------(5) FILTER----------*/
// Reverses the data stream.
void wavEdit::reverse(int16_t* audioData, int numOfSamples) {
    int start = 0, end = numOfSamples - 1;
    while (start < end)
        {
            int temp = audioData[start];
            audioData[start] = audioData[end];
            audioData[end] = temp;
            start++;
            end--;
        }
}
