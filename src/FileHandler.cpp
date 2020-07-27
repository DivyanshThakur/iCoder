#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <queue>
#include <algorithm>
#include "../header/FileHandler.hpp"
#include "../header/Ui.hpp"
#include "../settings/header/Settings.hpp"
#include "../constant/Constants.hpp"

std::string FileHandler::toString(const AbstractSaveable &iSaver)
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
        outFile << std::setw(Constant::Ui::USERNAME_WIDTH * 2) << std::left << pair.first
                << pair.second << std::endl;
    }

    outFile << "~" << std::endl;
}

void FileHandler::print(std::ofstream &outFile, const std::pair<std::string, std::string> &pair)
{
    outFile << std::setw(Constant::Ui::USERNAME_WIDTH * 2) << std::left << pair.first
            << pair.second << std::endl
            << "~" << std::endl;
}

std::vector<std::pair<std::string, std::string>> FileHandler::toVector(std::stringstream &ss)
{
    std::vector<std::pair<std::string, std::string>> vec;
    std::string line;

    while (std::getline(ss, line))
    {
        if (line == "~")
            break;

        vec.emplace_back(getPair(line));
    }

    return vec;
}

void FileHandler::updateSavedNumbers(std::string &numbers, int dig)
{
    std::stringstream ss(numbers);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int n;

    while (ss >> n)
    {
        pq.push(n);
    }

    pq.push(dig);

    numbers = std::to_string(pq.top());
    pq.pop();

    while (!pq.empty())
    {
        numbers += (" " + std::to_string(pq.top()));
        pq.pop();
    }
}

void FileHandler::saveDefName(std::ofstream &outFile, const AbstractSaveable &iSaver, std::stringstream &ss)
{
    if (iSaver.getPath() != Constant::Path::USER)
        return;

    auto fileData = toVector(ss);
    auto dataToSave = iSaver.save();
    std::string name = dataToSave.at(0).second;
    std::string strType = dataToSave.at(1).second;
    int number;

    size_t firstDigitIndex = std::find_if(name.begin(), name.end(), [](char c) { return isalpha(c); }) - name.begin();
    std::stringstream ssNum(name.substr(firstDigitIndex));
    if (!(ssNum >> number))
        return;

    for (auto &pair : dataToSave)
        if (strType == pair.first)
            updateSavedNumbers(pair.second, number);

    print(outFile, dataToSave);
}

void FileHandler::save(const AbstractSaveable &iSaver)
{
    std::stringstream ss{toString(iSaver)};
    std::ofstream outFile(iSaver.getPath());
    auto dataToSave = iSaver.save();

    bool isSaved{false}, isSettingsOrUser{false}, isDataStructure{false};

    saveDefName(outFile, iSaver, ss);

    while (true)
    {
        auto fileData = toVector(ss);

        if (fileData.empty())
            break;

        isSettingsOrUser = (fileData.at(0).first == dataToSave.at(0).first);
        // check name of data structure
        isDataStructure = isSettingsOrUser && (fileData.at(0).second == dataToSave.at(0).second);

        if (isSettingsOrUser || isDataStructure)
        {
            print(outFile, dataToSave);
            isSaved = true;
        }
        else
            print(outFile, fileData);
    }

    if (!isSaved) // adds new setting or user data to the end of file
        print(outFile, dataToSave);
}

void FileHandler::load(AbstractSaveable &iSaver, const std::string &tag)
{
    std::stringstream ss{toString(iSaver)};

    while (true)
    {
        auto fileData = toVector(ss);

        if (fileData.empty())
            break;

        bool isSettingsOrUser = (tag == "");
        bool isDataStructure = (fileData.at(0).first == Constant::DataFile::NAME) && (fileData.at(0).second == tag);

        if (isSettingsOrUser)
        {
            iSaver.load(fileData);
        }
        else if (isDataStructure)
        {
            iSaver.load(fileData);
            break;
        }
    }
}

bool FileHandler::find(const AbstractSaveable &iSaver, const std::string &tag)
{
    std::stringstream ss{toString(iSaver)};

    while (true)
    {
        auto fileData = toVector(ss);

        if (fileData.empty())
            break;

        bool isSettingsOrUser = (fileData.at(0).first == tag);
        bool isDataStructure = (fileData.at(0).first == Constant::DataFile::NAME) && (fileData.at(0).second == tag);

        if (isSettingsOrUser || isDataStructure)
            return true;
    }

    return false;
}

bool FileHandler::empty(const AbstractSaveable &iSaver)
{
    std::stringstream ss{toString(iSaver)};
    std::string word;

    if (ss >> word)
        return false;

    return true;
}

std::vector<std::pair<std::string, std::string>> FileHandler::searchTag(const AbstractSaveable &iSaver)
{
    std::vector<std::pair<std::string, std::string>> tags;
    std::stringstream ss{toString(iSaver)};

    while (true)
    {
        auto fileData = toVector(ss);

        if (fileData.empty())
            break;

        tags.push_back(fileData.at(0));
    }

    return tags;
}

// Generate default name of the file by checking available name from the user file
std::string FileHandler::nameGenerator(const AbstractSaveable &iSaver, const std::string &title)
{
    iSaver.generate();

    std::stringstream ss(toString(iSaver));
    int num = 0, minVal = 1;

    auto fileData = toVector(ss);
    ss.clear();

    for (const auto &pair : fileData)
    {
        if (pair.first == title)
        {
            ss << pair.second;
            while (ss >> num)
            {
                // if the file number matches with minimum index it checks
                // next number by incrementing minVal and  again scanning
                // fileIndex. Loops till the two values are not equal and
                // then breaks the loop and returns the generated getPath

                if (minVal == num)
                    minVal++;
                else
                    break;
            }
        }
    }

    std::string name(title);
    std::transform(name.begin(), name.end(), name.begin() + 1, ::tolower);

    // eg. Array1 or String3
    return (name + std::to_string(minVal));
}