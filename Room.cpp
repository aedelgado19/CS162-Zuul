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

void Room::setExits(char* direction, Room* inputExits){


}

char* Room::getItems(){


}

void Room::setItems(char* inputItems){
  
  
}

char* Room::getShortDescription(){
  return description;
}

char* Room::getLongDescription(){
  char* output = new char[100];
  strcpy(output, getRoom());
  strcat(output, description);
  strcat(output, getExitString());
  return output;
}

char* Room::getExitString(){
  char returnString[100] = "Exits:";
  char items[] = "\nItems in this room:\n";
  //for( put iterator here
  strcat(returnString, items);
  //strcat(returnString, getItems());
  return returnString;
}

char* Room::getRoom(){

  return roomName;
}
