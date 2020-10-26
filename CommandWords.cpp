//command words
#include "CommandWords.h"
#include <iostream>
#include <cstring>

using namespace std;

void CommandWords::getCommands(){


}

bool CommandWords::isCommand(char* inputCommand){
  for(int i = 0; i < sizeof(validCommands); i++){
    if(strcmp(inputCommand, validCommands[i]) == 0){
      return true;
    }
  }
  return false;
}

CommandWords::CommandWords(){


}

void CommandWords::showAll(){
  for(int i = 0; i < 7; i++) {
    cout << validCommands[i] << "  " << endl;
  }
  cout << " " << endl;
	
}
