//header for room
#include "Items.h"
#include <vector>

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
private:
  char* description;
  char* exits;
  char* items;
  char* roomName;
  vector<Items*> *itemVtr;
};
