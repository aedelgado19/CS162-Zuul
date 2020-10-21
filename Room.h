//header for room

class Room {
public:
  char* getDescription();
  void setDescription(char* inputDescription);
  char* getExits();
  void setExits(char* inputExits);
  char* getItems();
  void setItems(char* inputItems);
  
private:
  char* description;
  char* exits;
  char* items;
};
