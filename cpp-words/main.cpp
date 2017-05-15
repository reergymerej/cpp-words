//
//  main.cpp
//  cpp-words
//
//  Created by Jeremy Greer on 5/14/17.
//  Copyright © 2017 Grizzle. All rights reserved.
//

#include <iostream>

// forward delcarations
bool promptToContinue();
std::string getAfter(std::string word);
std::string getBefore(std::string word);
std::string getUsersGuess();
std::string pickWord();
void endGame();
void showHints(std::string word);
void showResult(std::string word, std::string guess);
void updateScore(std::string word, std::string guess, int score);

bool promptToContinue()
{
  return false;
}

std::string getAfter(std::string word)
{
  return "after";
}

std::string getBefore(std::string word)
{
  return "before";
}

std::string getUsersGuess()
{
  return "guess";
}

std::string pickWord()
{
  return "word";
}

void endGame()
{
}

void showHints(std::string word)
{
  std::string before = getBefore(word);
  std::string after = getAfter(word);
}

void showResult(std::string word, std::string guess)
{
}

void updateScore(std::string word, std::string guess, int score)
{
}

int main(int argc, const char * argv[])
{
  int score = 0;
  while (1)
  {
    std::string word = pickWord();
    showHints(word);
    std::string guess = getUsersGuess();
    showResult(word, guess);
    updateScore(word, guess, score);
    if (!promptToContinue())
    {
      endGame();
      return 1;
    }
  }
  return 0;
}
