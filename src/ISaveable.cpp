#include <fstream>
#include "../header/ISaveable.hpp"
#include "../header/FileHandler.hpp"

bool ISaveable::generate() const
{
    std::ifstream inFile(Path::userFilePath);

    if (inFile)
    {
        inFile.close(); // if already exists, return false
        return false;
    }

    std::ofstream outFile(Path::userFilePath);

    std::vector<cod::pair<std::string, std::string>> vec;
    vec.push_back(cod::pair<std::string, std::string>(Tag::ARRAY, ""));
    vec.push_back(cod::pair<std::string, std::string>(Tag::STRING, ""));

    // create file with default data
    FileHandler::print(outFile, vec);

    outFile.close();
    return true;
}
