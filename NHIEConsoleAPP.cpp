#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

std::vector<std::string> FileToVector(std::string FileName);
std::string RandomStringFromVector(std::vector<std::string> VectorName);

int main()  //Use main method to test or initiate other methods, do not write any code in here that you want to keep!
{
    std::vector<std::string> QuestionList = FileToVector("./questions.txt");
    std::string exit;

    while (exit != "stop")
    {
        std::cout << RandomStringFromVector(QuestionList) << std::endl;
        std::cin >> exit;
    }

    return 0;
}

//Put methods here: (Please write a brief description of what they are supposed to do and any headers they require)

std::vector<std::string> FileToVector(std::string FileName) //Converts a text file containing a list of strings into a vector of strings. (iostream, fstream, string, vector)
{
    std::vector<std::string> lines;
    std::fstream myFile;
 
    myFile.open(FileName, std::ios::in);  
    if (myFile.is_open())
    {
        std::string line;
        while (std::getline(myFile, line)) {lines.push_back(line);}

        myFile.close();
    }
    if (!myFile.is_open())
    {
        std::cout << "The file called " << FileName << " did not open!" << std::endl;
    }

    return lines;
}

std::string RandomStringFromVector(std::vector<std::string> VectorName)    //Takes a vector of strings and outputs a random string from the list. ()
{
    std::string RandomString;
    srand(time(NULL)*VectorName.size());

    RandomString = VectorName[rand()%VectorName.size()];

    return RandomString;
}