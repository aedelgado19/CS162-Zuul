#include "Parser.h"
#include "string.h"
#include <cstring>
#include <iostream>
using namespace std;

//taken from cplusplus.com
tokens* Parser::getCommand(){
  bool isValid = false;
  char inputLine[50];
  char word1[20];
  char word2[20];
  tokens *mytoken = NULL;

  while(isValid == false){
    cout << "> ";
    cin.get(inputLine, 50);
    cin.get();
    mytoken = parseCommand(inputLine);
    isValid = checkValid(mytoken);
     cout << isValid << endl;
  }
  //command is valid
  
  return mytoken;
}

bool Parser::checkValid(tokens* mytoken){

  //go commands
  if(strcmp(mytoken->word1, "go") == 0){
    if(strcmp(mytoken->word2, "north") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "east") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "south") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "west") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "up") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "down") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "northeast") == 0){
      return true;
    }
    
    else if(strcmp(mytoken->word2, "southeast") == 0){
      return true;
    }
    
    else if(strcmp(mytoken->word2, "southwest") == 0){
      return true;
    }
    
    else if(strcmp(mytoken->word2, "northwest") == 0){
      return true;
    }
 
    else{
      cout << "Second word not valid" << endl;
      return false;
    }
  }

  //quit
  if(strcmp(mytoken->word1, "quit") == 0){
    return true;
  }
  //help
  if(strcmp(mytoken->word1, "help") == 0){
    return true;
  }
  //get
  if(strcmp(mytoken->word1, "get") == 0){
    if(strcmp(mytoken->word2, "jalapenos") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "turkey") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "cheese") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "mayo") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "mayonnaise") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "tomatoes") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "lettuce") == 0){
      return true;
    }
    else {
      cout << "get what?" << endl;
      return false;
    }   
  }
  //drop items
  if(strcmp(mytoken->word1, "drop") == 0){
    if(strcmp(mytoken->word2, "jalapenos") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "turkey") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "cheese") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "mayo") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "mayonnaise") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "tomatoes") == 0){
      return true;
    }
    else if(strcmp(mytoken->word2, "lettuce") == 0){
      return true;
    }
    else {
      cout << "drop what?" << endl;
      return false;
    }
  }
  //inventory
  if(strcmp(mytoken->word1, "inventory") == 0){
    return true;
  }
  if(strcmp(mytoken->word1, "sandwich") == 0){
    return true;
  }
  
  if(strcmp(mytoken->word1, "eat") == 0){
    cout << "no, you cannot eat anything, it's not lunch time!" << endl;
    return false;
  }
  cout << "unknown command." << endl;
  return false;
}

tokens* Parser::parseCommand(char* inputLine){

  char *charPtr;
  tokens *mytoken = new tokens;
  charPtr = strtok(inputLine, " ");
  if(charPtr !=  NULL){
    strcpy(mytoken->word1, charPtr);
  } else {
    strcpy(mytoken->word1, "invalid");
  }

  charPtr = strtok(NULL, " ");
  if(charPtr != NULL){
    strcpy(mytoken->word2, charPtr);
  } else {
    strcpy(mytoken->word2, "invalid");
  }
  return mytoken;
}


tokens* Parser::showCommand(){
  commands.showAll();

}
Parser::Parser(){
  commands = CommandWords();

}
