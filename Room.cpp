//rooms
#include "Room.h"
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

void Room::setDescription(char* inputDescription){
  strcpy(description, inputDescription);

}

Room* Room::checkExits(char* inputDirection){
  unordered_map<char*, Room*> *mymap = roomExits;
  auto junk = roomExits["north"];

  
}

void Room::setExits(char* direction, Room* inputExits){
  roomExits->insert({direction, inputExits});
}

char* Room::getItems(){


}

void Room::setItems(Items* inputItems){
  itemVtr->push_back(inputItems);
  
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
  
  strcpy(exitString, "Exits in this room: ");
  for(unordered_map<char*, Room*>::iterator index = this->roomExits->begin(); index != roomExits->end(); ++index){
    strcat(exitString, " ");
    strcat(exitString, index->first);
  }
  /*strcat(returnString, "Items in this room: ");
  
  if(strcmp(getItems(), "") == 0){
    strcat(returnString, "no items.");
  } else {
    strcat(returnString, " ");
    strcat(returnString, getItems());
    }*/
  return exitString;
}

char* Room::getRoom(){

  return roomName;
}

Room::Room(char* inputRoomName){
  roomExits = new unordered_map<char*, Room*>();
  itemVtr = new vector<Items*>();
  cout << "in room constructor" << endl;
  strcpy(roomName, inputRoomName);
}
