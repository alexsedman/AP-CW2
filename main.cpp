//
// main.cpp
// C++ CW2
//
// Created by Alex Sedman.
//
// GitHub branch update - I'm avoiding a heavy object-based approach for this code as the scope of the project is more manageable in a couple CPP files.
// NOTE: Due to the file naming system in this program, it will only work robustly on Mac OS.
//
// TASK: Create a program without using any Audio Libraries to read a .wav file, perform some basic processed to the audio data and write the resulting audio data to a new .wav file.
//
// Current test file pathnames:
// /Users/alexsedman/Downloads/fragmentary sample v2.wav
// /Users/alexsedman/Downloads/fragmentary sample v2 MONO.wav
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

/*----------WAV HEADER STRUCT----------*/
// A data structure is defined for the WAV header.
struct WAV_HEADER {
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

/*----------MAIN MENU----------*/
// Function to output main menu and return the user input.
std::string mainMenu(std::string input) {
    using namespace std;
    
    //Print the main menu.
    cout << "---MAIN MENU---" << endl;
    cout << "Welcome to AJ's WAV file editor!" << endl;
    cout << "- Enter the pathname for the mono WAV file that you would like to edit." << endl;
    cout << "- Enter '-info' for more info." << endl;
    cout << "- Enter '-quit' to quit." <<endl;
    cout << "Please input your choice: ";
    
    getline(cin, input);
    return input;
}

/*----------INFO MENU----------*/
// Function to print info section.
void info() {
    using namespace std;
    //Print info.
    cout << endl;
    cout << "---INFO---" << endl;
    cout << "This program can read a .wav file, perform some basic processed to the audio data and write the resulting audio data to a new .wav file. Created by Alex Sedman." << endl;
    cout << "At the main menu, please find a pathname for a mono WAV file that you would like to use. For example, an example pathname could be '/Users/username/Documents/testwav.wav'" << endl;
    cout << "You can also enter '-quit' to end the program, or 'info' to bring this menu up again!" << endl;
    cout << endl;
}

/*----------OPTIONS MENU----------*/
// Function to output options once file has been read.
std::string options(std::string input) {
    using namespace std;
    
    //Print the option menu.
    cout << "---OPTIONS---" << endl;
    cout << "- Enter '1' to read the WAV header info." << endl;
    cout << "- Enter '2' to change the sample rate (CREATES A NEW FILE)." << endl;
    cout << "- Enter '3' to insert a pause (CREATES A NEW FILE)." << endl;
    cout << "- Enter '4' to peak normalise (CREATES A NEW FILE)." << endl;
    cout << "- Enter '5' to add a mystery audio effect (CREATES A NEW FILE)." << endl;
    cout << "- Enter anything else to return to the main menu." << endl;
    cout << "Please input your choice: ";
    
    getline(cin, input);
    return input;
}

/*----------NEW FILENAME----------*/
// Gets a file name from user for the new WAV and converts this input to a new file path.
std::string filename(std::string input, const char* filePath) {
    // The new path variable is defined, and instructions are outputted.
    std::string newFilePath = filePath;
    std::cout << "\nPlease select a new filename." << std::endl;
    std::cout << "NOTE: Files can not: \n- Contain a colon (':') \n- Contain a forward slash ('/') \n- Start with a period ('.') \n- Be more than 32 characters long \n- Be an empty input\nThe extension '.wav' will be automatically appended." << std::endl;
    std::cout << "The new WAV will be created in the same directory as the old WAV." << std::endl;
   
    // This while loop demands a valid filename input from the user.
    while (true) {
        std::cout << "Filename: ";
        std::getline(std::cin, input);
        
        // Parity checks: Make sure the requirements for a legal filename are met, as outlines above by the console output.
        if ((input.find(':') != std::string::npos) || (input.find('/') != std::string::npos) || (input.length() == 0) || (input.at(0) == '.') || (input.length() > 32)) {
            std::cout << "ERROR: Invalid filename." << std::endl;
            continue;
        }
        
        // The following lines construct the new path name.
        input.std::string::append(".wav"); // Appends '.wav' to user input.
        newFilePath.std::string::resize(newFilePath.std::string::find_last_of("/")+1); // Derives parent folder of old WAV.
        newFilePath.std::string::append(input); // Appends the user file name to the file path.
        break;
    }
    return newFilePath;
}

/*----------WRITE NEW FILE----------*/
// Function to write the data stream to a new file.
void write_file(int hdrSize, std::string newFilePath) {
    //A new file is created, and the header is written from the data structure.
    filePath = input.c_str();
    FILE* newFile;
    newFile = fopen(newFilePath, "w");
    
    //wav_write.close();
}

/*----------(1) PRINT WAV HEADER----------*/
// Function to print WAV header.
void print_header(int hdrSize, FILE* wavFile) {
    using namespace std;
    //Print the header.
    cout << endl;
    cout << "---OPTION 1: PRINT---" << endl;
    cout << "Chunk ID (File Spec): " << wavHdr.RIFF[0] << wavHdr.RIFF[1] << wavHdr.RIFF[2] << wavHdr.RIFF[3] << endl;
    cout << "Chunk Size: " << wavHdr.fileSize << endl;
    cout << "File Type (FourCC Tag): " << wavHdr.WAVE[0] << wavHdr.WAVE[1] << wavHdr.WAVE[2] << wavHdr.WAVE[3] << endl;
    
    cout << "Subchunk 1 ID (Format): " << wavHdr.fmt[0] << wavHdr.fmt[1] << wavHdr.fmt[2] << wavHdr.fmt[3] << endl;
    cout << "Subchunk Size: " << wavHdr.fmtLen << endl;
    cout << "Audio Format: " << wavHdr.fmtType << endl;
    cout << "Number of Channels: " << wavHdr.noChannels << endl;
    cout << "Sample Rate: " << wavHdr.sampleRate << endl;
    cout << "Data Rate (Bps): " << wavHdr.byteRate << endl;
    cout << "Block Align: " << wavHdr.blockAlign << endl;
    cout << "Bits Per Sample: " << wavHdr.sampleLen << endl;
    
    cout << "Subchunk 2 ID (Data): " << wavHdr.DATA[0] << wavHdr.DATA[1] << wavHdr.DATA[2] << wavHdr.DATA[3] << endl;
    cout << "Subchunk 2 Size: " << wavHdr.dataSize << endl;
}

/*----------(2) CHANGE SAMPLE RATE----------*/
// Changes sample rate of the WAV file according to user input.
uint32_t change_sample(std::string input, uint32_t sampleRate) {
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

int main() {
    /*----------INITIALISATION----------*/
    // Variables declared: pointer to the filepath name and an input string.
    int hdrSize = sizeof(wavHdr); // A variable to measure the size of the WAV header (this should be equivalent to 44 bytes).
    const char* filePath;
    std::string input;
    
    while (1) {
        /*----------MAIN MENU----------*/
        // Calls main menu
        input = mainMenu(input);
        
        // Quit/info conditionals.
        if (input == "-quit") {
            std::cout << "\nBye!\n" << std::endl;
            return 0;
        } else if (input == "-info") {
            info();
            continue;
        }
        
        /*----------FILE READ----------*/
        // The file pathname is read, and the file info is committed to memory as a data stream, with 'wav_file' pointing to the first byte of data in this stream.
        //This means that the position of every value in the data stream is known, and committed to memory sequentially.
        filePath = input.c_str();
        FILE* wavFile;
        wavFile = fopen(filePath, "rb+"); // 'rb+' is a binary read/update parameter. This allows the file to be read and separated into bytes easier, as well as updated if need be.
        
        // Parity checks and file read.
        if (wavFile == nullptr) {
            std::cout << "\nERROR: File can't be read/input is invalid." << std::endl; // Throw an error if the file pointer returns a null value (i.e. the file read is unsuccessful).
        } else {
            
            fread(&wavHdr, 1, hdrSize, wavFile); // An unsigned integer 'bytes_read' is assigned the value using the 'fread' function.
            if (wavHdr.noChannels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                continue;
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }
            
            /*----------OPTION SECTION----------*/
            // Calls the options menu.
            input = options(input);
            
            if (input == "1") {
                print_header(hdrSize, wavFile); // File information is printed.
            } else if (input == "2") {
                //sample recalc
                filename(input, filePath);
            } else if (input == "3") {
                
                filename(input, filePath);
            } else if (input == "4") {
                
                filename(input, filePath);
            } else if (input == "5") {
                
                filename(input, filePath);
            } else {
                std::cout << "\nERROR: Invalid option selection. Returning to the main menu." << std::endl;
            }
        }
        
        fclose(wavFile);
        std::cout << std::endl;
    }
}

