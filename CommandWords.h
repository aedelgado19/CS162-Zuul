//header for CommandWords.cpp

class CommandWords {
private:
 char validCommands[7][50] = {
    "go", "quit", "help", "get", "drop", "inventory", "sandwich"};

public:
  void setCommands();
  void getCommands();
  bool isCommand(char* inputCommand);

  CommandWords();

};
