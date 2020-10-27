//header for Parser.cpp
#include "Command.h"
#include "CommandWords.h"

struct tokens{
  char word1[20];
  char word2[20];
};

class Parser{
public:	
  Command getCommand();
  Command showCommand();
  bool checkValid(tokens* mytoken);
  tokens* parseCommand(char* input);
  Parser();
private:
  CommandWords commands;

};


