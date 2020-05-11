//
//  main.cpp
//  Triple X Game
//
//  Created by Ashwani on 11/05/20.
//  Copyright © 2020 Ashwani. All rights reserved.
//

#include <iostream>
#include <ctime>

void PrintIntroduction(unsigned Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(unsigned Difficulty)
{
    PrintIntroduction(Difficulty);
    
    //Generate code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;
    
    //Store User guess
    int GuessA, GuessB, GuessC;
    
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
    
}

int main()
{
    srand(static_cast<unsigned>(time(NULL))); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer
        
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    
    return 0;
}
