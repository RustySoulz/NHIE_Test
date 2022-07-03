#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

void InitMainConsoleApp(std::string FileName);
void InitVanillaConsoleApp(std::string FileName);
void InitNaughtyConsoleApp(std::string FileName);
std::vector<std::string> FileToVector(std::string FileName);
std::string RandomStringFromVector(std::vector<std::string> VectorName);

#pragma region main

int main()  //Use main method to test or initiate other methods, do not write any code in here that you want to keep!
{
    InitMainConsoleApp("./questions.txt");

    return 0;
}

#pragma endregion

//Put methods here: (Please write a brief description of what they are supposed to do and any headers they require)

#pragma region InitMainConsoleApp

void InitMainConsoleApp(std::string FileName) //Starts the main menu of the console application. ()[]
{
    std::cout << "****** NAUGHTY HAVE I EVER v1.0 by RustySoul ******" << std::endl;
    std::cout << std::endl;
        for (;;)
        {
            std::cout << "Please select an option using 0-9 on the keyboard:" << std::endl;

            std::cout << "1. Play in Vanilla Mode" << std::endl;
            std::cout << "2. Play in Naughty Mode 18+ (Coming soon)" << std::endl;
            std::cout << "0. Exit Game" << std::endl;

            int Input2;
            std::cin >> Input2;
            std::cout << std::endl;

            switch (Input2)
            {
            case 0:
                return;
                break;
            
            case 1:
                InitVanillaConsoleApp(FileName);
                break;

            case 2:
                InitNaughtyConsoleApp(FileName);
                break;
            
            default:
                std::cout << "Something went wrong, please try again!" << std::endl;
                break;
            }
        }

}

#pragma endregion

#pragma region InitVanillaConsoleApp

void InitVanillaConsoleApp(std::string FileName)   //Starts the vanilla version of the console application. ()[]
{
    struct Player
    {
        std::string Name;
        int LivesLost = 0;
        bool Eliminated = false;
    };
    Player NewPlayer;

    int MaxLives = 10;
    int PlayerNum;
    std::vector<Player> PlayerList;

    std::vector<std::string> QuestionList = FileToVector(FileName);

    while (true)
    {
        std::cout << "Please select an option using 0-9 on the keyboard:" << std::endl;

        std::cout << "1. Get Random Question" << std::endl;
        std::cout << "2. Set Lives" << std::endl;
        std::cout << "3. Add Player" << std::endl;
        std::cout << "4. Player List" << std::endl;
        std::cout << "5. Rules (Coming soon)" << std::endl;
        std::cout << "0. Exit To Main Menu" << std::endl;

        int Input0;
        std::cin >> Input0;
        std::cout << std::endl;

        switch (Input0)
        {
        case 0:
            return;
            break;

        case 1:
            std::cout << RandomStringFromVector(QuestionList) << std::endl;
            PlayerNum = 0;
            for (Player CurrentPlayer : PlayerList)
            {
                std::cout << std::endl;
                if (MaxLives > CurrentPlayer.LivesLost)
                {
                    std::cout << "Did " << CurrentPlayer.Name << " lose a life? (y/n): ";
                    char Input1;
                    std::cin >> Input1;
                    if (Input1 == 'y')
                    {
                        PlayerList[PlayerNum].LivesLost++;
                    }
                    std::cout << CurrentPlayer.Name << " has " << MaxLives-PlayerList[PlayerNum].LivesLost << " lives remaining" << std::endl;
                }
                else
                {
                    std::cout << CurrentPlayer.Name << " was eliminated!" << std::endl;
                }
                PlayerNum++;
            }
            break;

        case 2:
            std::cout << "Please enter the max number of lives: ";
            std::cin >> MaxLives;
            std::cout << "Each player now starts with " << MaxLives << " lives!" << std::endl;
            break;

        case 3:
            std::cout << "Please name the new player: ";
            std::cin >> NewPlayer.Name;
            PlayerList.push_back(NewPlayer);
            std::cout << NewPlayer.Name << " was added to the game. There are now " << PlayerList.size() << " player(s)!" << std::endl;
            break;

        case 4:
            std::cout << "There are " << PlayerList.size() << " players in total:" << std::endl;
            for (Player CurrentPlayer : PlayerList)
            {
                if (MaxLives > CurrentPlayer.LivesLost)
                {
                    std::cout << CurrentPlayer.Name << " has " << MaxLives-CurrentPlayer.LivesLost << " lives remaining" << std::endl;
                }
                else
                {
                    std::cout << CurrentPlayer.Name << " was eliminated!" << std::endl;
                }
            }
            break;

        default:
            std::cout << "Something went wrong, please try again!" << std::endl;
            break;
        }
    std::cout << std::endl;
    }
}

#pragma endregion

#pragma region InitNaughtyConsoleApp

void InitNaughtyConsoleApp(std::string FileName)
{
    struct Player
    {
        std::string Name;
        int Lives;
        bool Eliminated = false;
    };
    Player NewPlayer;

    int PlayerNum;
    std::vector<Player> PlayerList;

    std::vector<std::string> QuestionList = FileToVector(FileName);

    while (true)
    {
        std::cout << "Please select an option using 0-9 on the keyboard:" << std::endl;

        std::cout << "1. Get Random Question" << std::endl;
        std::cout << "2. Add Player" << std::endl;
        std::cout << "3. Player List" << std::endl;
        std::cout << "4. Rules (Coming soon)" << std::endl;
        std::cout << "0. Exit To Main Menu" << std::endl;

        int Input3;
        std::cin >> Input3;
        std::cout << std::endl;

        switch (Input3)
        {
        case 0:
            return;
            break;

        case 1:
            std::cout << RandomStringFromVector(QuestionList) << std::endl;
            PlayerNum = 0;
            for (Player CurrentPlayer : PlayerList)
            {
                PlayerNum++;
            }
            break;

        case 2:
            std::cout << "Please name the new player: ";
            std::cin >> NewPlayer.Name;
            std::cout << "Enter the number of items of clothing are they wearing: ";
            std::cin >> NewPlayer.Lives;
            PlayerList.push_back(NewPlayer);
            std::cout << NewPlayer.Name << " was added to the game. There are now " << PlayerList.size() << " player(s)!" << std::endl;
            break;

        case 3:
            std::cout << "There are " << PlayerList.size() << " players in total:" << std::endl;
            for (Player CurrentPlayer : PlayerList)
            {
                if (CurrentPlayer.Lives > 0)
                {
                    std::cout << CurrentPlayer.Name << " has " << CurrentPlayer.Lives << " lives remaining" << std::endl;
                }
                else
                {
                    std::cout << CurrentPlayer.Name << " was eliminated!" << std::endl;
                }
            }
            break;

        default:
            std::cout << "Something went wrong, please try again!" << std::endl;
            break;
        }
    std::cout << std::endl;
    }
}

#pragma endregion

#pragma region FileToVector

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

#pragma endregion

#pragma region RandomStringFromVector

std::string RandomStringFromVector(std::vector<std::string> VectorName)    //Takes a vector of strings and outputs a random string from the list. (ctime, string, vector) *Left as method as can be made more random later!
{
    std::string RandomString;
    srand(time(NULL)*VectorName.size());

    RandomString = VectorName[rand()%VectorName.size()];

    return RandomString;
}

#pragma endregion