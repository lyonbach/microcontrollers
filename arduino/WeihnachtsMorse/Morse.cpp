#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <thread>

#include "Constants.cpp"

#define Print(m) std::cout << m << std::endl

std::map<char ,std::string> getMappedAlphabet()
{
    std::map<char, std::string> mappedAlphabet;
    std::vector<std::string> splitted;
    std::string currentCode = "";

    for (char currentChar : morseCodes)
    {
        if(currentChar == ' ')
            {
                splitted.push_back(currentCode);
                currentCode = "";
            }

        else
            {
                currentCode += currentChar;
            }
    }

    for (int i = 0; i < asciiLowerCase.length(); i++)
        {
            mappedAlphabet[asciiLowerCase[i]] = splitted[i];
        }

    return mappedAlphabet;
}


std::string getMorseCode(const std::string& charsToInterpret, std::map<char, std::string> mappedMorseAlphabet)
{

    std::string converted;
    std::string currentMorseChar;

    for (char c : charsToInterpret)
    {
        currentMorseChar = mappedMorseAlphabet[c] + 'e';
        if (c == ' ')
        {
            currentMorseChar + 's';
        }

        converted += currentMorseChar;
    }
    return converted;
}


int main(int argc, char const *argv[])
{
    std::string fileFullPath;
    std::string stringToBeConverted;

    if (argc < 3)
    {
        Print("Not enough arguments! Aborted...");
        return 1;

    }
    else
    {
        for (int i = 0; i < argc; i++)
            {
                Print(argv[i]);
            }
        fileFullPath = argv[1];
        stringToBeConverted = argv[2];
    }
    std::map<char, std::string> mapped = getMappedAlphabet();
    std::ofstream currentFile;

    currentFile.open(fileFullPath);
    std::string output;

    // Build default part of the string
    // we use pin 13 for connecting the led
    
    output += "int led = 13;\n";
    output += "\n";
    output += "void setup(){\n";
    output += "\tpinMode(13, OUTPUT);\n";
    output += "}\n";
    output += "\n";
    output += "void loop(){\n";

    for (char c : getMorseCode(stringToBeConverted, mapped))
    {
        if (c == '.')
        {
            output += "\tdigitalWrite(led, HIGH);\n";
            output += "\tdelay(" + T_DOT + ");\n";
            output += "\tdigitalWrite(led, LOW);\n";
            output += "\tdelay(" + T_EOC_LOW + ");\n";
        }
        if (c == '-')
        {
            output += "\tdigitalWrite(led, HIGH);\n";
            output += "\tdelay(" + T_DASH + ");\n";
            output += "\tdigitalWrite(led, LOW);\n";
            output += "\tdelay(" + T_EOC_LOW + ");\n";
        }
        if (c == 'e')
        {
            output += "\tdigitalWrite(led, LOW);\n";
            output += "\tdelay(" + T_SPACE_LOW + ");\n";
        }
    }
    output += "}\n";
    Print(output);
    currentFile << output;
    currentFile.close();

}

