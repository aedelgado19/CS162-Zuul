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
  tokens *mytoken = NULL;

  while(isValid == false){
    cout << "> ";
    cin.get(inputLine, 50);
    cin.get();
    parseCommand(inputLine);
    checkValid(mytoken);
  }
}

bool Parser::checkValid(tokens* mytoken){


}

tokens* Parser::parseCommand(char* inputLine){
  char *charPtr;
  tokens *mytoken = new tokens;
  charPtr = strtok(inputLine, " ");
  strcpy(mytoken->word1, charPtr);
  charPtr = strtok(NULL, " ");
  if(charPtr != NULL){
    strcpy(mytoken->word2, charPtr);
  } else {
    strcpy(mytoken->word2, "invalid");
  }
  return mytoken;
}


Command Parser::showCommand(){
  //commands->showAll();


}
Parser::Parser(){
  commands = CommandWords();

}
