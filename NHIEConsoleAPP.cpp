#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> FileToVector(std::string FileName);

int main()  //Use main method to test or initiate other methods, dont write any code in here that you want to keep!
{
    std::vector<std::string> QuestionList = FileToVector("./questions.txt");

    return 0;
}

//Put methods here: (Please write a brief description of what they are supposed to be doing)

std::vector<std::string> FileToVector(std::string FileName) //Simple system to convert a text file containing a list of strings into a vector of strings.
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