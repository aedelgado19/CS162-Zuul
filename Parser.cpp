#include "Parser.h"
#include "string.h"
#include <iostream>
using namespace std;

//taken from cplusplus.com
Command Parser::getCommand(){
  bool isValid = false;
  char inputLine[50];
  char word1[20];
  char word2[20];

  while(isValid = false){
    cout << "> ";
    cin.get(inputLine, 50);
    cin.get();
    parseCommand(inputLine);
    checkValid();//error: pass in each word
  }
}

bool Parser::checkValid(Command word1, Command word2){


}

tokens* Parser::parseCommand(char* input){
  char *charPtr;
  charPtr = strtok(inputLine, " ");
  strcpy(word1, charPtr);
  charPtr = strtok(NULL, " ");
  if(charPtr != NULL){
    strcpy(word2, charPtr);
  }

}


Command Parser::showCommand(){
  //commands->showAll();


}
Parser::Parser(){
  commands = CommandWords();

}
