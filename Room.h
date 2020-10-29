//header for room
#include <iostream>
#include "Items.h"
#include <vector>
#include <unordered_map>
using namespace std;


class Room {
public:
  char* getDescription();
  void setDescription(char* inputDescription);
  char* getExits();
  void setExits(char* direction, Room* inputExits);
  char* getItems();
  void setItems(Items* inputItems);
  char* getShortDescription();
  char* getLongDescription();
  char* getExitString();
  char* getRoom();
  Room(char* inputRoomName);
private:
  char* description;
  char* items;
  char* roomName;
  unordered_map<char*, Room*> *roomExits;
  vector<Items*> *itemVtr;
};
