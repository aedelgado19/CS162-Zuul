//header for Parser.cpp
#include "Command.h"
#include "CommandWords.h"
class Parser{
public:	
  Command getCommand();
  Command showCommand();
  Parser();

private:
  CommandWords commands;

};


