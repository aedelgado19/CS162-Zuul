//rooms
#include "Room.h"
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <map>
#include <cstddef>
using namespace std;

void Room::setDescription(char* inputDescription){
  strcpy(description, inputDescription);

}

Room* Room::checkExits(char* inputDirection){
  unordered_map<char*, Room*>:: iterator index;
  Room *nextRoom = NULL;
  for (index = roomExits.begin(); index != roomExits.end(); index++) {
    if (strcmp(index->first, inputDirection) ==0) {
      cout << "\nYou head " << inputDirection << " to " << index->second->getRoom() << endl;
      nextRoom = index->second;
    }
  }
  return nextRoom;
}

void Room::setExits(char* direction, Room* inputExits){
  roomExits.insert(make_pair(direction, inputExits));
}
/*
char* Room::getItems(){


}*/

void Room::setItems(Items* inputItems){
  itemVtr->push_back(inputItems);
  
}

char* Room::getLongDescription(){
  char* output = new char[100];
  strcpy(output, getRoom());
  strcat(output, "\n");
  strcat(output, description);
  strcat(output, "\n");
  strcat(output, getExitString());
  return output;
}

//got from cplusplus.com
char* Room::getExitString(){
  unordered_map< char*, Room*>:: iterator index;
  strcpy(exitString, "Exits in this room: \n");
  for (index = roomExits.begin(); index != roomExits.end(); index++) {
    //cout << index->first << " " << endl;
    strcat(exitString, index->first);
    strcat(exitString, "\n");
  }
  strcat(exitString, "Items in this room: ");
  
  if(strcmp(getItems(), "") == 0){
    strcat(exitString, "no items.");
  } else {
    strcat(exitString, " ");
    strcat(exitString, getItems());
  }
  return exitString;
}

char* Room::getRoom(){

  return roomName;
}

Room::Room(char* inputRoomName){
  itemVtr = new vector<Items*>();
  strcpy(roomName, inputRoomName);
}
