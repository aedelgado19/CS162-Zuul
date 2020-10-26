//header for Items.cpp
#include <iostream>

class Items{
public:
  char* getName();
  void setName(char* inputName);
  char* getDescription();
  Items(char* inputName);
private:
  char* name;
  char* desc;
};

