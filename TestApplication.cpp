#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty) 
{
    std::cout << "\n\nYou are a criminal mastermind called 'Sickan' planning the perfect bank heist ";
    std::cout << std::endl;
    std::cout << "You need to crack the safes with the keys leading into the main vault starting with the level " << Difficulty << std::endl; 
    std::cout << "safe" << std::endl;
}

bool PlayGame(int Difficulty) 
{
    PrintIntro(Difficulty);

    //Initial declarations
    const int SafeNumberA = rand() % Difficulty + Difficulty;
    const int SafeNumberB = rand() % Difficulty + Difficulty;
    const int SafeNumberC = rand() % Difficulty + Difficulty;

    const int SafeNumberSum = SafeNumberA + SafeNumberB + SafeNumberC;
    const int SafeNumberProduct = SafeNumberA * SafeNumberB * SafeNumberC;

    //Instructions
    std::cout << std::endl;
    std::cout << "There is a 3-number combination lock on each safe" << std::endl;
    std::cout << "According to one of your sources the numbers add up to: " << SafeNumberSum << std::endl;
    std::cout << "and the numbers multiply to: " << SafeNumberProduct << std::endl;

    //Buffer with pointers
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //If-function
    if (GuessSum == SafeNumberSum && GuessProduct == SafeNumberProduct) 
    {
        std::cout << "You cracked the safe";
        return true;
    }
    else 
    {
        std::cout << "You triggered the alarm and got shot by a cop. Try again in another life.";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 7;

    while(LevelDifficulty <= MaxDifficulty) //Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//error message cleanup
        std::cin.ignore();//buffer cleanup

        if(bLevelComplete)
        {
            //Increase difficulty
            ++LevelDifficulty;
        }
    }
    
    std::cout << "You broke into the vault and got financially independent. Have fun retiring in Hawaii ^^.";
    return 0;
}