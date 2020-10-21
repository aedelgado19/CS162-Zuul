//header for command 

class Command{
public:
  char* getCommandWord();
  char* getSecondWord();
  bool isUnknown();
  bool hasSecondWord();
  
private:
  char commandWord[];
  char secondWord[];
  
};
