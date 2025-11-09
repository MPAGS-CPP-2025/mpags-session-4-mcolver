#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };

    for(int i{0}; i < argc; i++) {
        if(cmdLineArgs[i] == "--help" || cmdLineArgs[i] == "-h") {
            std::cout << "This programs encrypts and decrypts input text to and from a cipher your your choice.\n"
                         " \n"
                         "Usage:\n"
                         "-c type: Provide cipher type. Currently supported: None\n"
                         "-i filename: Provide input file. If not provided, input from terminal.\n"
                         "-o filename: Provide output file. If not provided, output to terminal.\n"
                         "-k key: Provide cipher key. Currently supported: None\n"
                         "--encrypt: Encrypt input text. Default action.\n"
                         "--decrypt: Decrypt input text.\n" << std::endl;
            return 0;
        }
        else if(cmdLineArgs[i] == "--version" || cmdLineArgs[i] == "-v") {
            std::cout << "mpags-cipher version 0.1.0" << std::endl;
            return 0;
        }
        else if(cmdLineArgs[i] == "--input" || cmdLineArgs[i] == "-i") {
            const std::string inputFileName = cmdLineArgs[i+1];
            std::cout << "Input file name provided: " << inputFileName << std::endl;
        }
        else if(cmdLineArgs[i] == "--output" || cmdLineArgs[i] == "-o") {
            const std::string outputFileName = cmdLineArgs[i+1];
            std::cout << "Output file name provided: " << outputFileName << std::endl;
        }
    }

    // Initialise variables
    char c{'x'};
    std::string out_text;

    // loop over each character from user input
    while (std::cin >> c) {
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}