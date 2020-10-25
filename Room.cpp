//rooms
#include "Room.h"
#include <iostream>
#include <cstring>
using namespace std;

char* Room::getDescription(){


}

void Room::setDescription(char* inputDescription){


}

char* Room::getExits(){
  

}

void Room::setExits(char* inputExits){


}

char* Room::getItems(){


}

void Room::setItems(char* inputItems){
  
  
}

char* Room::getShortDescription(){
  return description;
}

char* Room::getLongDescription(){
  //this doesn't work
  char str[100] = "You are ";
  char desc[100] = description;
  char exit[100] = getExitString();

  strcat(str, desc);
  strcat(str, exit);
  return str;
}

char* Room::getExitString(){
  char returnString[100] = "Exits:";
  char items[] = "\nItems in this room:\n";
  //for( put iterator here
  strcat(returnString, items);
  //strcat(returnString, getItems());
  return returnString;
}
