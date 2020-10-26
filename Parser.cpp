#include "Parser.h"
#include "string.h"
#include <iostream>
using namespace std;

//taken from cplusplus.com
Command Parser::getCommand(){
  char inputLine[50];
  char word1[20];
  char word2[20];
  cout << "> ";
  cin.get(inputLine, 50);
  cin.get();

  char *charPtr;
  charPtr = strtok(inputLine, " ");
  strcpy(word1, charPtr);
  charPtr = strtok(NULL, " ");
  strcpy(word2, charPtr);

  if(commands.isCommand(word1)){
    return Command(word1, word2);
  }
  else {
    return Command(NULL, word2);
  }
}

Command Parser::showCommand(){
  //commands->showAll();


}
Parser::Parser(){
  commands = CommandWords();

}
