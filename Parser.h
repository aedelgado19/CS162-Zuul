//header for Parser.cpp

#include "CommandWords.h"

struct tokens{
  char word1[20];
  char word2[20];
};

class Parser{
public:	
  tokens* getCommand();
  void showCommand();
  bool checkValid(tokens* mytoken);
  tokens* parseCommand(char* input);
  Parser();
private:
  CommandWords commands;

};


