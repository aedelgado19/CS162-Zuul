//header for command 

class Command{
public:
  char* getCommandWord();
  void setCommandWord(char* inputCommand);
  char* getSecondWord();
  void setSecondWord(char* inputSecondWord);
  bool isUnknown();
  bool hasSecondWord();
  Command(char* word1, char* word2);
private:
  char commandWord[80];
  char secondWord[80];
  
};
