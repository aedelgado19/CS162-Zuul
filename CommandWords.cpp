//command words
#include "CommandWords.h"
#include <iostream>
#include <cstring>

using namespace std;

void setCommands(){
 
}


void getCommands(){


}

bool isCommand(char* inputCommand){
  for(int i = 0; i < sizeof(validCommands); i++){
    if(strcmp(inputCommand, validCommands[i]) == 0){
      return true;
    }
  }
  return false;
}

CommandWords::CommandWords(){


}
