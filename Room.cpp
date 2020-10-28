//rooms
#include "Room.h"
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

char* Room::getDescription(){


}

void Room::setDescription(char* inputDescription){


}

char* Room::getExits(){
 

}

void Room::setExits(char* direction, Room* inputExits){
  roomExits->insert({direction, inputExits});

}

char* Room::getItems(){


}

void Room::setItems(Items* inputItems){
  itemVtr->push_back(inputItems);
  
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

//got from cplusplus.com
char* Room::getExitString(){
  char returnString[100];
  strcpy(returnString, "Exits in this room: ");
  for(unordered_map<char*, Room*>::iterator index = this->roomExits->begin(); index != roomExits->end(); ++index){
    strcat(returnString, " ");
    strcat(returnString, index->first);
  }
  /*strcat(returnString, "Items in this room: ");
  
  if(strcmp(getItems(), "") == 0){
    strcat(returnString, "no items.");
  } else {
    strcat(returnString, " ");
    strcat(returnString, getItems());
    }*/
  return returnString;
}

char* Room::getRoom(){

  return roomName;
}

Room::Room(){
  roomExits = new unordered_map<char*, Room*>();

}
