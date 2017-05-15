//
//  main.cpp
//  cpp-words
//
//  Created by Jeremy Greer on 5/14/17.
//  Copyright © 2017 Grizzle. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

// forward delcarations
bool promptToContinue();
std::string getAfter(int wordIndex);
std::string getBefore(int wordIndex);
std::string getUsersGuess();
int pickWordIndex();
void endGame();
void showHints(int wordIndex);
void showResult(std::string word, bool isCorrect);
int updateScore(bool goodGuess, int score);

std::string wordBank [73] =
{
  "and",
  "and_eq",
  "asm",
  "auto",
  "bitand",
  "bitor",
  "bool",
  "break",
  "case",
  "catch",
  "char",
  "class",
  "compl",
  "const",
  "const_cast",
  "continue",
  "default",
  "delete",
  "do",
  "double",
  "dynamic_cast",
  "else",
  "enum",
  "explicit",
  "extern",
  "false",
  "float",
  "for",
  "friend",
  "goto",
  "if",
  "inline",
  "int",
  "long",
  "mutable",
  "namespace",
  "new",
  "not",
  "not_eq",
  "operator",
  "or",
  "or_eq",
  "private",
  "protected",
  "public",
  "register",
  "reinterpret_cast",
  "return",
  "short",
  "signed",
  "sizeof",
  "static",
  "static_cast",
  "struct",
  "switch",
  "template",
  "this",
  "throw",
  "true",
  "try",
  "typedef",
  "typeid",
  "typename",
  "union",
  "unsigned",
  "using",
  "virtual",
  "void",
  "volatile",
  "wchar_t:wchar_t",
  "while",
  "xor",
  "xor_eq"
};

bool promptToContinue()
{
  std::cout << "Quit? (y/n): ";
  std::string response;
  std::cin >> response;
  return response != "y";
}

std::string getAfter(int wordIndex)
{
  if (wordIndex < 72) {
    return wordBank[wordIndex + 1];
  }
  return "-";
}

std::string getBefore(int wordIndex)
{
  if (wordIndex > 0) {
    return wordBank[wordIndex - 1];
  }
  return "-";
}

std::string getUsersGuess()
{
  std::string input;
  std::cin >> input;
  return input;
}

int pickWordIndex()
{
  return rand() % 73;
}

void endGame()
{
  std::cout << "Ciao!" << std::endl;
}

void showHints(int wordIndex)
{
  std::string before = getBefore(wordIndex);
  std::string after = getAfter(wordIndex);
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
  srand((int) time(NULL));
  int score = 0;
  bool goodGuess;
  while (1)
  {
    std::cout << std::endl;
    int wordIndex = pickWordIndex();
    std::string word = wordBank[wordIndex];
    showHints(wordIndex);
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
