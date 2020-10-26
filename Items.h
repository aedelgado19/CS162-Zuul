//header for Items.cpp
#include <iostream>

class Items{
public:
  char* getName();
  void setName(char* inputName);
  char* getDescription();
  Items();
private:
  char* name;
  char* desc;
};

