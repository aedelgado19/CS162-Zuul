//header for room
#include <iostream>
#include "Items.h"
#include <vector>
#include <unordered_map>
using namespace std;


class Room {
public:
  void setDescription(char* inputDescription);
  char* getExits();
  void setExits(char* direction, Room* inputExits);
  char* getItems();
  void setItems(Items* inputItems);
  char* getLongDescription();
  char* getExitString();
  char* getRoom();
  Room(char* inputRoomName);
private:
  char description[200];
  char* items;
  char roomName[50];
  unordered_map<char*, Room*> *roomExits;
  vector<Items*> *itemVtr;
};
