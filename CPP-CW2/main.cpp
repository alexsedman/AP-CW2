//
// main.cpp
// C++ CW2
//
// Created by Alex Sedman.
//
// GitHub branch v5 - avoiding object-based for this code as the scope of the project is more manageable in a single CPP file.
//
// Create a program without using any Audio Libraries to read a .wav file, perform some basic processed to the audio data and write the resulting audio data to a new .wav file.
//
// Current test file pathnames:
// /Users/alexsedman/Downloads/fragmentary sample v2.wav
// /Users/alexsedman/Downloads/fragmentary sample v2 MONO.wav

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

/*----------WAV HEADER STRUCT----------*/
// A data structure is defined for the WAV header.
struct WAV_HEADER {
    // RIFF Chunk Descriptor
    uint8_t RIFF[4];
    uint32_t file_size;
    uint8_t WAVE[4];

    // fmt subchunk
    uint8_t fmt[4];
    uint32_t fmt_len;
    uint16_t fmt_type;
    uint16_t no_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t sample_len;
    
    // Data subchunk
    uint8_t DATA[4];
    uint32_t data_size;
} wav_hdr;

/*----------MAIN MENU----------*/
// Function to output main menu and return the user input.
std::string main_menu(std::string input) {
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

/*----------INFO----------*/
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

/*----------(1) PRINT WAV HEADER----------*/
// Function to print WAV header.
void print_header(int hdr_size, FILE* wav_file) {
    using namespace std;
    //Print the header.
    cout << endl;
    cout << "---OPTION 1: PRINT---" << endl;
    cout << "Chunk ID (File Spec): " << wav_hdr.RIFF[0] << wav_hdr.RIFF[1] << wav_hdr.RIFF[2] << wav_hdr.RIFF[3] << endl;
    cout << "Chunk Size: " << wav_hdr.file_size << endl;
    cout << "File Type (FourCC Tag): " << wav_hdr.WAVE[0] << wav_hdr.WAVE[1] << wav_hdr.WAVE[2] << wav_hdr.WAVE[3] << endl;
    
    cout << "Subchunk 1 ID (Format): " << wav_hdr.fmt[0] << wav_hdr.fmt[1] << wav_hdr.fmt[2] << wav_hdr.fmt[3] << endl;
    cout << "Subchunk Size: " << wav_hdr.fmt_len << endl;
    cout << "Audio Format: " << wav_hdr.fmt_type << endl;
    cout << "Number of Channels: " << wav_hdr.no_channels << endl;
    cout << "Sample Rate: " << wav_hdr.sample_rate << endl;
    cout << "Data Rate (Bps): " << wav_hdr.byte_rate << endl;
    cout << "Block Align: " << wav_hdr.block_align << endl;
    cout << "Bits Per Sample: " << wav_hdr.sample_len << endl;
    
    cout << "Subchunk 2 ID (Data): " << wav_hdr.DATA[0] << wav_hdr.DATA[1] << wav_hdr.DATA[2] << wav_hdr.DATA[3] << endl;
    cout << "Subchunk 2 Size: " << wav_hdr.data_size << endl;
}

/*----------(2) CHANGE SAMPLE RATE----------*/
/*----------(3) ADD PAUSE----------*/
/*----------(4) NORMALISE----------*/
/*----------(5) FILTER----------*/
/*----------NEW FILENAME----------*/

/*----------WRITE NEW FILE----------*/
// Function to write the data stream to a new file.
void write_file(int hdr_size) {
    //A new file is created, and the header is written from the data structure.
    std::ofstream wav_write("/Users/alexsedman/Downloads/name.wav");
    //std::fwrite(, 1, hdr_size, wav_write);
    
    wav_write.close();
}

int main() {
    /*----------INITIALISATION----------*/
    // Variables declared: pointer to the filepath name and an input string.
    int hdr_size = sizeof(wav_hdr); // A variable to measure the size of the WAV header (this should be equivalent to 44 bytes).
    const char* file_path;
    std::string input;
    
    while (1) {
        /*----------MAIN MENU----------*/
        // Calls main menu
        input = main_menu(input);
        
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
        file_path = input.c_str();
        FILE* wav_file;
        wav_file = fopen(file_path, "rb+"); // 'rb+' is a binary read/update parameter. This allows the file to be read and separated into bytes easier, as well as updated if need be.
        //
        
        /*----------OPTION SECTION----------*/
        if (wav_file == nullptr) {
            std::cout << "\nERROR: File can't be read/input is invalid." << std::endl; // Throw an error if the file pointer returns a null value (i.e. the file read is unsuccessful).
        } else {
            size_t bytes_read = fread(&wav_hdr, 1, hdr_size, wav_file); // An unsigned integer 'bytes_read' is assigned the value using the 'fread' function.
            if (wav_hdr.no_channels != 1) {
                std::cout << "\nERROR: The inputted file is not mono! Please only supply a mono file.\n" << std::endl;
                continue;
            } else {
                std::cout << "\nFile read successful!\n" << std::endl;
            }
            
            // Calls the options menu.
            input = options(input);
            
            switch(input) {
                case 1:
                    print_header(hdr_size, wav_file); // File information is printed.
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                default:
                    std::cout << "\nERROR: Invalid option selection. Returning to the main menu." << std::endl;
            }
            //choose filename
            //print file
        }
        
        fclose(wav_file);
        std::cout << std::endl;
    }
}
