#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

void InitConsoleApp(std::string FileName);
std::vector<std::string> FileToVector(std::string FileName);
std::string RandomStringFromVector(std::vector<std::string> VectorName);

int main()  //Use main method to test or initiate other methods, do not write any code in here that you want to keep!
{
    InitConsoleApp("./questions.txt");

    return 0;
}

//Put methods here: (Please write a brief description of what they are supposed to do and any headers they require)

void InitConsoleApp(std::string FileName)   //Starts the console application. ()[]
{
    std::cout << "****** NEVER HAVE I EVER v0.1 by RustySoul ******" << std::endl;
    std::cout << std::endl;

    bool Exit = false;
    while (!Exit)
    {
        std::vector<std::string> QuestionList = FileToVector(FileName);
    
        std::cout << "Please select an option using 0-9 on the keyboard:" << std::endl;

        std::cout << "1. Get random question" << std::endl;
        std::cout << "0. Exit Game" << std::endl;

        int Input;
        std::cin >> Input;
        std::cout << std::endl;

        switch (Input)
        {
        case 0:
            Exit = true;
            break;

        case 1:
            std::cout << RandomStringFromVector(QuestionList) << std::endl;
            break;

        default:
            break;
        }
    std::cout << std::endl;
    }
}

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
    else
    {
        std::cout << "The file called " << FileName << " did not open!" << std::endl;
    }

    return lines;
}

std::string RandomStringFromVector(std::vector<std::string> VectorName)    //Takes a vector of strings and outputs a random string from the list. (ctime, string, vector) *Left as method as can be made more random later!
{
    std::string RandomString;
    srand(time(NULL)*VectorName.size());

    RandomString = VectorName[rand()%VectorName.size()];

    return RandomString;
}