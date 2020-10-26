//header for room
#include "Items.h"
#include <vector>

using namespace std;
vector<Items*> itemVtr;

class Room {
public:
  char* getDescription();
  void setDescription(char* inputDescription);
  char* getExits();
  void setExits(char* direction, Room* inputExits);
  char* getItems();
  void setItems(char* inputItems);
  char* getShortDescription();
  char* getLongDescription();
  char* getExitString();
  char* getRoom();
private:
  char* description;
  char* exits;
  char* items;
  char* roomName;
};
