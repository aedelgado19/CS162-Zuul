//header for Items.cpp
#include <iostream>

// note: there are no item descriptions because lettuce is lettuce
// and isn't really worthy of a description

class Items{
public:
  char* getName();
  Items(char* inputName); //constructor to name items
private:
  char name[20]; //store name variable
};

