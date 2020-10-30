//header for Items.cpp
#include <iostream>

class Items{
public:
  char* getName();
  Items(char* inputName);
private:
  char name[20];
};

