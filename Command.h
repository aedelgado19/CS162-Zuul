//header for command 

class Command{
public:
  char* getCommandWord();
  void setCommandWord(char* inputCommand);
  char* getSecondWord();
  void setSecondWord(char* inputSecondWord);
  bool isUnknown();
  bool hasSecondWord();
  
private:
  char commandWord[];
  char secondWord[];
  
};
