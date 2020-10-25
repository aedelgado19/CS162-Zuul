//header for room
#include "Item.h"
class Room {
public:
  char* getDescription();
  void setDescription(char* inputDescription);
  char* getExits();
  void setExits(char* inputExits);
  char* getItems();
  void setItems(char* inputItems);
  char* getShortDescription();
  char* getLongDescription();
  char* getExitString();
  
private:
  char* description;
  char* exits;
  char* items;
};
