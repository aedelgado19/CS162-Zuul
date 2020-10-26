//take in commands
#include "Command.h"
#include <iostream>
#include <cstring>

#pragma once

char* Command::getCommandWord(){
  return commandWord;
}
void Command::setCommandWord(char* inputCommand){
  strcpy(commandWord, inputCommand);

}
char* Command::getSecondWord(){
  return secondWord;
}

void Command::setSecondWord(char* inputSecondWord){
  strcpy(secondWord, inputSecondWord);
}

bool Command::isUnknown(){
  return false;
}

bool Command::hasSecondWord(){
  return false;

}
Command::Command(char* word1, char* word2){
  strcpy(commandWord, word1);
  strcpy(secondWord, word2);
}

