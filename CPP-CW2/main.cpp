#include <iostream>
#include <string>
#include <fstream>
#include <cstdint> //Test

// A data structure is defined for the WAV header.
struct WAV_HEADER {
    // RIFF Chunk Descriptor
    uint8_t RIFF[4];
    uint32_t chunk_size;
    uint8_t WAVE[4];

    // fmt subchunk
    uint8_t fmt[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numOfChan;
    uint32_t samplesPerSec;
    uint32_t bytesPerSec;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    
    // Data subchunk
    uint8_t subchunk2ID[4];
    uint32_t subchunk2Size;
} wav_hdr;

int main() {
    // Variables declared:
    int headerSize = sizeof(wav_hdr); // A variable to measure the size of the WAV header
    const char* filePath;
    std::string input;
    
    // User is asked to input the file location of the desired WAV file.
    std::cout << "Input wave file name: ";
    std::cin >> input;
    filePath = input.c_str();
    
    //
    FILE* wavFile;
    wavFile = fopen(filePath, "rb+");
    
    //Read the header
    size_t bytesRead = fread(&wav_hdr, 1, headerSize, wavFile);
    std::cout << bytesRead << std::endl;
    char buffer[] = { 'R' , 'I' , 'F' , 'X' };
    fseek(wavFile,0,SEEK_SET);
    fwrite(buffer, 2, 4, wavFile);
     //Print the header
    std::cout << "Chank ID: " << wav_hdr.RIFF[0] << wav_hdr.RIFF[1] << wav_hdr.RIFF[2] << wav_hdr.RIFF[3] << std::endl;
    std::cout << "Chank Size: " << wav_hdr.ChunkSize << std::endl;
    std::cout << "Format: " << wav_hdr.WAVE[0] << wav_hdr.WAVE[1] << wav_hdr.WAVE[2] << wav_hdr.WAVE[3] << std::endl;
    std::cout << "SUb-Chank1 ID: " << wav_hdr.fmt[0] << wav_hdr.fmt[1] << wav_hdr.fmt[2] << wav_hdr.fmt[3] << std::endl;
    std::cout << "Sub-Chank1 Size: " << wav_hdr.Subchunk1Size << std::endl;
    std::cout << "Audio Format: " << wav_hdr.AudioFormat << std::endl;
    std::cout << "Num of Channels: " << wav_hdr.NumOfChan << std::endl;
    std::cout << "Sample Rate: " << wav_hdr.SamplesPerSec << std::endl;
    std::cout << "Bits Per Sample: " << wav_hdr.BytesPerSec << std::endl;
    std::cout << "Block Align: " << wav_hdr.blockAlign << std::endl;
    std::cout << "Bits Per Sample: " << wav_hdr.bitsPerSample << std::endl;
    std::cout << "Sub-Chank2 ID: " << wav_hdr.Subchunk2ID[0] << wav_hdr.Subchunk2ID[1] << wav_hdr.Subchunk2ID[2] << wav_hdr.Subchunk2ID[3] << std::endl;
    std::cout << "Sub-Chank2 Size: " << wav_hdr.Subchunk2Size << std::endl;
    fclose(wavFile);
    return 0;
}
