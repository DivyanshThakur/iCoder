#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../header/FileHandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Settings.hpp"
#include "../constant/Constants.hpp"
#include "../namespace/header/cod_algorithm.hpp"

std::string FileHandler::toString(const ISaveable &iSaver)
{
    iSaver.generate();

    std::ifstream inFile(iSaver.getPath());

    std::string fileStr, line;

    // Scans and appends the data from the settings file to the fileStr variable
    while (std::getline(inFile, line))
    {
        fileStr += (line + "\n");
    }

    inFile.close();

    return fileStr;
}

std::pair<std::string, std::string> FileHandler::getPair(const std::string &line)
{
    std::stringstream ssLine(line);
    std::string word, title, val;

    ssLine >> title >> val;

    while (ssLine >> word)
        val += (" " + word);

    return {title, val};
}

void FileHandler::print(std::ofstream &outFile, const std::vector<std::pair<std::string, std::string>> &vec)
{
    for (const auto &pair : vec)
    {
        outFile << std::setw(Constant::Ui::USERNAME_WIDTH * 2) << std::left << pair.first()
                << pair.second() << std::endl;
    }

    outFile << "~" << std::endl;
}

void FileHandler::print(std::ofstream &outFile, const std::pair<std::string, std::string> &pair)
{
    outFile << std::setw(Constant::Ui::USERNAME_WIDTH * 2) << std::left << pair.first()
            << pair.second() << std::endl
            << "~" << std::endl;
}

void FileHandler::save(const ISaveable &iSaver)
{
    std::stringstream ss{toString(iSaver)};
    std::vector<std::pair<std::string, std::string>> vec;
    std::ofstream outFile(iSaver.getPath());
    auto iVector = iSaver.save();

    std::string line;
    bool isSaved{false};

    while (std::getline(ss, line))
    {
        if (line != "~")
        {
            vec.push_back(getPair(line));
        }
        else
        {
            bool isSettingsOrUser = (vec.at(0).first() == iVector.at(0).first());
            bool isDataStructure = (vec.at(0).first() == iVector.at(0).first()) && (vec.at(0).second() == iVector.at(0).second());

            if (isSettingsOrUser || isDataStructure)
            {
                print(outFile, iVector);
                isSaved = true;
            }
            else
                print(outFile, vec);

            vec.clear();
        }
    }

    if (!isSaved) // adds new setting to the end of file
        print(outFile, iVector);
}

void FileHandler::load(ISaveable &iSaver, const std::string &tag)
{
    std::stringstream ss{toString(iSaver)};
    std::vector<std::pair<std::string, std::string>> vec;
    std::string line;

    while (std::getline(ss, line))
    {

        if (line != "~")
        {
            vec.push_back(getPair(line));
        }
        else
        {
            // NULL means the reference is of settings or
            // user file not NUll means the references are
            // of data structures and other main data stored

            bool isSettingsOrUser = (tag == "");
            bool isDataStructure = (vec.at(0).first() == Constant::DataFile::NAME) && (vec.at(0).second() == tag);

            if (isSettingsOrUser)
            {
                iSaver.load(vec);
            }
            else if (isDataStructure)
            {
                iSaver.load(vec);
                break;
            }

            vec.clear();
        }
    }
}

bool FileHandler::find(const ISaveable &iSaver, const std::string &tag)
{
    std::stringstream ss{toString(iSaver)};
    std::vector<std::pair<std::string, std::string>> vec;
    std::string line;

    while (std::getline(ss, line))
    {

        if (line != "~")
        {
            vec.push_back(getPair(line));
        }
        else
        {
            bool isSettingsOrUser = (vec.at(0).first() == tag);
            bool isDataStructure = (vec.at(0).first() == Constant::DataFile::NAME) && (vec.at(0).second() == tag);

            if (isSettingsOrUser || isDataStructure)
                return true;

            vec.clear();
        }
    }

    return false;
}

bool FileHandler::empty(const ISaveable &iSaver)
{
    std::stringstream ss{toString(iSaver)};
    std::string word;

    if (ss >> word)
        return false;

    return true;
}

std::vector<std::pair<std::string, std::string>> FileHandler::searchAll(const ISaveable &iSaver)
{
    std::vector<std::pair<std::string, std::string>> vec;
    std::vector<std::pair<std::string, std::string>> fileVector;
    std::stringstream ss{toString(iSaver)};
    std::string line;

    while (std::getline(ss, line))
    {

        if (line != "~")
            fileVector.push_back(getPair(line));
        else
        {
            vec.push_back(fileVector.at(0));
            fileVector.clear();
        }
    }

    return vec;
}

// Common function to update the Status enum variables
void FileHandler::updateStats(enum Status &stats, int c)
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

void FileHandler::saveActiveUser(const std::string &userID)
{
    Settings mySetting;

    Global::activeUser = userID;

    // save the current user to
    //the file for automatically log in
    mySetting.save(std::pair<std::string, std::string>(Constant::File::CURRENT_USER, Global::activeUser));
}

// Generate default name of the file by checking available name from the user file
std::string FileHandler::nameGenerator(const ISaveable &iSaver, const std::string &title)
{
    iSaver.generate();

    // minIndex contains the number which is to be given to the file
    // fileIndex stores the temporary index
    std::string fileStr, fileTitle, line;
    int minIndex = 1, fileIndex;
    bool toStop = false;

    std::ifstream inFile(iSaver.getPath());

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
                // then breaks the loop and returns the generated getPath

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