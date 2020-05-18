#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../header/FileHandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Settings.hpp"
#include "../namespace/header/cod_algorithm.hpp"

std::string FileHandler::file_str(const ISaveable &iSaver)
{
    iSaver.generate();

    std::ifstream inFile(iSaver.filename());

    std::string fileStr, line;

    // Scans and appends the data from the settings file to the fileStr variable
    while (std::getline(inFile, line))
    {
        fileStr += line;
    }

    inFile.close();

    return fileStr;
}

void FileHandler::print(std::ofstream &outFile, const std::vector<cod::pair<std::string, std::string>> &vec)
{
    for (const auto &pair : vec)
    {
        outFile << std::setw(Ui::widthUsername * 2) << std::left << pair.first()
                << pair.second() << std::endl;
    }

    outFile << "~" << std::endl;
}

void FileHandler::print(std::ofstream &outFile, const cod::pair<std::string, std::string> &pair)
{
    outFile << std::setw(Ui::widthUsername * 2) << std::left << pair.first()
            << pair.second() << std::endl
            << "~" << std::endl;
}

void FileHandler::save(const ISaveable &iSaver)
{
    std::stringstream ss{file_str(iSaver)};

    std::ofstream outFile(iSaver.filename());
    auto iVector = iSaver.save();

    std::string line, word;
    bool isSaved{false};

    while (ss.eof())
    {
        std::stringstream ssLine;
        std::vector<cod::pair<std::string, std::string>> vec;

        // creating the vector for scanning
        while (std::getline(ss, line) && (line != "~"))
        {
            std::string title, val;

            ssLine << line;
            ss >> title;

            while (ssLine >> word)
            {
                val += (word + " ");
            }

            val.pop_back();
            vec.push_back(cod::pair<std::string, std::string>(title, val));
        }

        bool isSettings = (vec.at(0).first() == iVector.at(0).first());
        bool isDataStructure = (vec.at(0).first() == iVector.at(0).first()) && (vec.at(0).second() == iVector.at(0).second());

        if (isSettings || isDataStructure)
        {
            print(outFile, iVector);
            isSaved = true;
        }
        else
            print(outFile, vec);
    }

    if (!isSaved) // adds new setting to the end of file
        print(outFile, iVector);
}

void FileHandler::load(ISaveable &iSaver)
{
    std::stringstream ss{file_str(iSaver)};
    auto iVector = iSaver.save();
    std::string line, word;

    while (ss.eof())
    {
        std::stringstream ssLine;
        std::vector<cod::pair<std::string, std::string>> vec;

        // creating the vector for scanning
        while (std::getline(ss, line) && (line != "~"))
        {
            std::string title, val;

            ssLine << line;
            ss >> title;

            while (ssLine >> word)
            {
                val += (word + " ");
            }

            val.pop_back();
            vec.push_back(cod::pair<std::string, std::string>(title, val));
        }

        // NULL means the reference is of settings
        // not NUll means the references are of
        // data structures and other main datas

        bool isDataStructure = (vec.at(0).first() == iVector.at(0).first()) && (vec.at(0).second() == iVector.at(0).second());
        bool isSettings = (vec.at(0).first() == iVector.at(0).first());

        if (isSettings)
        {
            iSaver.load(vec);
        }
        else if (isDataStructure)
        {
            iSaver.load(vec);
            break;
        }
    }
}

// Common function to update the Status enum variables
void FileHandler::update_stats(enum Status &stats, int c)
{
    switch (c)
    {
    case 0:
        stats = DEFAULT;
        break;

    case 1:
        stats = EASY;
        break;

    case 2:
        stats = ADV;
        break;
    }
}

void FileHandler::save_active_user(const std::string &userID)
{
    Settings setting;

    Global::signedUserID = userID;

    // save the current user to the file for automatically log in
    save(setting); //, Global::signedUserID);
}

// Generate default name of the file by checking available name from the user file
std::string FileHandler::name_generator(const ISaveable &iSaver, const std::string &title)
{
    iSaver.generate();

    // minIndex contains the number which is to be given to the file
    // fileIndex stores the temporary index
    std::string fileStr, fileTitle, line;
    int minIndex = 1, fileIndex;
    bool toStop = false;

    std::ifstream inFile(iSaver.filename());

    // scan each line from file
    while (!toStop && (std::getline(inFile, line)))
    {
        std::stringstream ss{line};

        ss >> fileTitle; // scan title from stringstream

        // if the fileTitle equals the given title. eg. ARRAY == ARRAY
        // it then scans the numbers availabe
        if (fileTitle == title)
        {
            while (!toStop && (ss >> fileIndex)) // scan each number from same line
            {
                // if the file number matches with minimum index it checks
                // next number by incrementing minIndex and  again scanning
                // fileIndex. Loops till the two values are not equal and
                // then breaks the loop and returns the generated fileName

                if (minIndex == fileIndex)
                    minIndex++;
                else
                    toStop = true;
            }
        }
    }

    inFile.close();

    // eg. Array1 or String3
    return (title.at(0) + cod::tolower(title, 1) + std::to_string(minIndex));
}