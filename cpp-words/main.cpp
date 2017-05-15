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
void showResult(std::string word, bool isCorrect);
int updateScore(bool goodGuess, int score);

bool promptToContinue()
{
  std::cout << "Quit? (y/n): ";
  std::string response;
  std::cin >> response;
  return response != "y";
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
  std::string input;
  std::cin >> input;
  return input;
}

std::string pickWord()
{
  return "word";
}

void endGame()
{
  std::cout << "Ciao!" << std::endl;
}

void showHints(std::string word)
{
  std::string before = getBefore(word);
  std::string after = getAfter(word);
  std::cout << before << std::endl;
  std::cout << "?" << std::endl;
  std::cout << after << std::endl;
}

void showResult(std::string word, bool isCorrect)
{
  if (isCorrect)
  {
    std::cout << "correct" << std::endl;
  }
  else
  {
    std::cout << "wrong, it is \"" << word << "\"" << std::endl;
  }
}

int updateScore(bool goodGuess, int score)
{
  int newScore = goodGuess ? score + 1 : score - 1;
  std::cout << "score: " << newScore << std::endl;
  return newScore;
}

int main(int argc, const char * argv[])
{
  std::cout << "cpp-words" << std::endl;
  int score = 0;
  bool goodGuess;
  while (1)
  {
    std::cout << std::endl;
    std::string word = pickWord();
    showHints(word);
    std::string guess = getUsersGuess();
    goodGuess = guess == word;
    showResult(word, goodGuess);
    score = updateScore(goodGuess, score);
    if (!promptToContinue())
    {
      endGame();
      return 1;
    }
  }
  return 0;
}
