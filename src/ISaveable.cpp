#include <fstream>
#include "../header/ISaveable.hpp"
#include "../header/FileHandler.hpp"

bool ISaveable::generate() const
{
    std::ifstream inFile(Constant::Path::USER);

    if (inFile)
    {
        inFile.close(); // if already exists, return false
        return false;
    }

    std::ofstream outFile(Constant::Path::USER);

    std::vector<cod::pair<std::string, std::string>> vec;
    vec.push_back(cod::pair<std::string, std::string>(Constant::Title::ARRAY, ""));
    vec.push_back(cod::pair<std::string, std::string>(Constant::Title::STRING, ""));

    // create file with default data
    FileHandler::print(outFile, vec);

    outFile.close();
    return true;
}
