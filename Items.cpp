//header for items
#include "Items.h"
#include <cstring>
char* Items::getName(){
  return name;
}

Items::Items(char* inputName){
  strcpy(name, inputName);
  
}
