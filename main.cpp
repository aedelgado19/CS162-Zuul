/* Author: Allison Delgado
 * Last updated: Oct 20, 2020
 * Zuul is similar to Zork. The premise of this game is that
 * you are lost in a sub shop and must find all ingredients to escape
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Parser.h"

using namespace std;

//function prototypes
void createRooms(vector<Room*>* &roomVtr, Room *&currentRoom);
void printHelp(Parser *p);
void goRoom(tokens* command, Room* &currentRoom);
void quit();
void dropItem(tokens* command, Room* &currentRoom, vector<Items*> *&inventory);
void getItem(tokens* command, Room* &currentRoom, vector<Items*> *&inventory);
void printSandwichContents();
void printInventory(vector<Items*> *inventory);
bool processCommand(tokens* command, Room* &currentRoom, vector<Items*> *&inventory, Parser *&p);

void quit(){
  cout << "Thank you for playing Zuulway. Quitting program now." << endl;
}

void getItem(tokens* command, Room* &currentRoom, vector<Items*> *&inventory){
  char* item;
  strcpy(item, command->word2);

  Items* newItem;
  newItem = currentRoom->getItem(item);
  if(newItem == NULL){
    cout << "That item is not in this room!" << endl;
  } else {
    inventory->push_back(newItem);
    currentRoom->removeItem(item);
    cout << "You picked up: " << newItem->getName() << endl;
  }
}

void dropItem(tokens* command, Room* &currentRoom, vector<Items*> *&inventory, ){
  char* item;
  strcpy(item, command->word2);
  

  Items* newItem = NULL;
  int index;
  for(int i = 0; i < inventory->size(); i++){
    if(strcmp(inventory->at(i)->getName(), item) == 0){
      newItem = inventory->at(i);
      index = i;
    }
  }

  if(newItem == NULL){
    cout << "You don't have anything like that to drop." << endl;
  } else {
    if(strcmp(currentRoom->getName(), "Zuulway") == 0){
      
    }
    currentRoom->addItem(newItem);
    inventory->erase(inventory->begin()+index);
    cout << "You dropped: " << newItem->getName() << endl;
  }
}

void createRooms(vector<Room*> *&roomVtr, Room *&currentRoom){
  Room* Zuulway = new Room((char*)("Zuulway"));
  Room* DarkRoom = new Room((char*)("DarkRoom"));
  Room* EmployeeHangout = new Room((char*)("EmployeeHangout"));
  Room* PuppyRoom = new Room((char*)("PuppyRoom"));
  Room* Bathroom = new Room((char*)("Bathroom"));
  Room* BossOffice = new Room((char*)("BossOffice"));
  Room* CheeseRoom = new Room((char*)("CheeseRoom"));
  Room* Storage = new Room((char*)("Storage"));
  Room* MeatRoom = new Room((char*)("MeatRoom"));
  Room* WeirdRoom = new Room((char*)("WeirdRoom"));
  Room* Outside = new Room((char*)("Outside"));
  Room* Spa = new Room((char*)("Spa"));
  Room* JalapenoRoom = new Room((char*)("JalapenoRoom"));
  Room* VegetableRoom = new Room((char*)("VegetableRoom"));
  Room* MayonnaiseRoom = new Room((char*)("MayonnaiseRoom"));
  Room* Hallway = new Room((char*)("Hallway"));
  Room* BackRoom = new Room((char*)("BackRoom"));
  Room* LettuceRoom = new Room((char*)("LettuceRoom"));

  //print welcome
  cout << "Welcome to Zuulway!" << endl;
  cout << "Zuulway takes place in a haunted sub sandwich shop that has a maze to find the ingredients." << endl;
  cout << "Type 'help' if you need help." << endl; 
  cout << " " << endl;
  cout << "A sad empty sandwich lays on the counter. To escape, you must add: tomatoes, mayo, jalapenos, turkey, cheese, and lettuce." << endl;
  cout << "Good luck!" << endl;
  cout << " " << endl;
  
  //Zuulway
  Zuulway->setDescription((char*)("You are in the main room of the sub shop."));
  currentRoom = Zuulway;
  Zuulway->setExits((char*)("east"), PuppyRoom);
  Zuulway->setExits((char*)("south"), BossOffice);
  Zuulway->setExits((char*)("west"), WeirdRoom);
  Zuulway->setExits((char*)("north"), DarkRoom);
  currentRoom = Zuulway;
  roomVtr->push_back(Zuulway);
  cout << Zuulway->getLongDescription() << endl;

  
  //DarkRoom
  DarkRoom->setDescription((char*)("You are in a dark eerie room. Doesn't smell the greatest in here."));
  DarkRoom->setExits((char*)("south"), Zuulway);
  DarkRoom->setExits((char*)("up"), VegetableRoom);
  DarkRoom->setExits((char*)("east"), EmployeeHangout);
  DarkRoom->setExits((char*)("west"), Outside);
  roomVtr->push_back(DarkRoom);
  
  //employee hangout
  EmployeeHangout->setDescription((char*)("You are in the employee break room. Say hi to everyone!"));
  EmployeeHangout->setExits((char*)("east"), BackRoom);
  EmployeeHangout->setExits((char*)("southeast"), Hallway);
  EmployeeHangout->setExits((char*)("south"), PuppyRoom);
  EmployeeHangout->setExits((char*)("west"), DarkRoom);
  roomVtr->push_back(EmployeeHangout);
  
  //puppy room
  PuppyRoom->setDescription((char*)("You are in a room full of puppies! Don't question it."));
  PuppyRoom->setExits((char*)("north"), EmployeeHangout);
  PuppyRoom->setExits((char*)("east"), Hallway);
  PuppyRoom->setExits((char*)("south"), Bathroom);
  PuppyRoom->setExits((char*)("west"), Zuulway);
  roomVtr->push_back(PuppyRoom);
  
  //bathroom
  Bathroom->setDescription((char*)("You are in the... bathroom? Ew, get out!"));
  Bathroom->setExits((char*)("north"), PuppyRoom);
  Bathroom->setExits((char*)("southwest"), CheeseRoom);
  Bathroom->setExits((char*)("west"), BossOffice);
  roomVtr->push_back(Bathroom);

  //boss office
  BossOffice->setDescription((char*)("You are in your boss's office. He doesn't look happy. You should probably leave."));
  BossOffice->setExits((char*)("north"), Zuulway);
  BossOffice->setExits((char*)("east"), Bathroom);
  BossOffice->setExits((char*)("southeast"), CheeseRoom);
  BossOffice->setExits((char*)("west"), Storage);
  roomVtr->push_back(BossOffice);
  
  //cheese room
  CheeseRoom->setDescription((char*)("You are in the cheese room! Here you can get cheese for your sandwich."));
  CheeseRoom->setExits((char*)("northwest"), BossOffice);
  CheeseRoom->setExits((char*)("northeast"), Bathroom);
  roomVtr->push_back(CheeseRoom);

  //storage
  Storage->setDescription((char*)("You are in the storage room. Nothing cool here."));
  Storage->setExits((char*)("north"), Outside);
  Storage->setExits((char*)("west"), VegetableRoom);
  Storage->setExits((char*)("east"), BossOffice);
  roomVtr->push_back(Storage);

  //meat
  MeatRoom->setDescription((char*)("You are in the meat room. Here you can get meat for your sandwich."));
  MeatRoom->setExits((char*)("east"), Storage);
  MeatRoom->setExits((char*)("northeast"), WeirdRoom);
  roomVtr->push_back(MeatRoom);

  //weird room
  WeirdRoom->setDescription((char*)("You are in a weird room. It seems like nobody has been here in a while."));
  WeirdRoom->setExits((char*)("north"), Outside);
  WeirdRoom->setExits((char*)("east"), Zuulway);
  WeirdRoom->setExits((char*)("southwest"), MeatRoom);
  WeirdRoom->setExits((char*)("south"), Storage);
  roomVtr->push_back(WeirdRoom);

  //outside
  Outside->setDescription((char*)("You are outside. What? Get back inside, you have a job to do!"));
  Outside->setExits((char*)("northwest"), Spa);
  Outside->setExits((char*)("east"), DarkRoom);
  Outside->setExits((char*) ("south"), WeirdRoom);
  roomVtr->push_back(Outside);

  //spa
  Spa->setDescription((char*)("You are in an indoor luxury spa. You're not sure why there's a spa in a Zuulway, but whatever!"));
  Spa->setExits((char*)("east"), JalapenoRoom);
  Spa->setExits((char*)("southeast"), Outside);
  roomVtr->push_back(Spa);

  //jalapeno
  JalapenoRoom->setDescription((char*)("You are in the jalapeno room. Here you can get all your spicy peppers for your sandwich."));
  JalapenoRoom->setExits((char*)("west"), Spa);
  roomVtr->push_back(JalapenoRoom);
  
  //vegetable
  VegetableRoom->setDescription((char*)("You are in the vegetable room. Here you can get all your veggies!"));
  VegetableRoom->setExits((char*)("down"), DarkRoom);
  VegetableRoom->setExits((char*)("east"), MayonnaiseRoom);
  roomVtr->push_back(VegetableRoom);
  
  //mayo
  MayonnaiseRoom->setDescription((char*)("You are in the mayo room. You swim neck deep in mayo, which is kind of nasty, but the sandwich does require mayo, so you have to deal with it."));
			  MayonnaiseRoom->setExits((char*)("west"), VegetableRoom);
  roomVtr->push_back(MayonnaiseRoom);
  
  //hall
  Hallway->setDescription((char*)("You are in the hallway. Nothing cool here."));
  Hallway->setExits((char*)("northwest"), EmployeeHangout);
  Hallway->setExits((char*)("north"), BackRoom);
  Hallway->setExits((char*)("west"), PuppyRoom);
  Hallway->setExits((char*)("down"), LettuceRoom);
  roomVtr->push_back(Hallway);

  //backroom
  BackRoom->setDescription((char*)("You are in the back room. There are a lot of boxes, but nothing of value."));
  BackRoom->setExits((char*)("west"), EmployeeHangout);
  BackRoom->setExits((char*)("south"), Hallway);
  roomVtr->push_back(BackRoom);
  
  //lettuce
  LettuceRoom->setDescription((char*)("You are in the lettuce room. Here you can satisfy all your lettuce needs! Watch out for the e-coli."));
  LettuceRoom->setExits((char*)("up"), Hallway);
  roomVtr->push_back(LettuceRoom);
  
  //items
  JalapenoRoom->setItems(new Items((char*)("jalapenos")));
  VegetableRoom->setItems(new Items((char*)("turkey")));
  CheeseRoom->setItems(new Items((char*)("cheese")));
  MayonnaiseRoom->setItems(new Items((char*)("mayo")));
  VegetableRoom->setItems(new Items((char*)("tomatoes")));
  LettuceRoom->setItems(new Items((char*)("lettuce")));  
}

bool processCommand(tokens* command, Room* &currentRoom, vector<Items*>* &inventory, Parser* &p,   vector<Items*> *sandwichVtr){
  bool wantToQuit = false;
  if(strcmp(command->word1, "help") == 0){
    printHelp(p);   
  }
  else if(strcmp(command->word1, "go") == 0){
    goRoom(command, currentRoom);
  }
  else if(strcmp(command->word1, "quit") == 0){
    wantToQuit = true;
  }
  else if(strcmp(command->word1, "get") == 0){
    getItem(command, currentRoom, inventory);
  }
  else if(strcmp(command->word1, "drop") == 0){
    dropItem(command, currentRoom, inventory);
  }
  else if(strcmp(command->word1, "inventory") == 0){
    printInventory(inventory);
  }
  else if(strcmp(command->word1, "sandwich") == 0){
    printSandwichContents(sandwichVtr);
  }
  return wantToQuit;
}

 //set up inventory and state what is in it
void printInventory(vector<Items*> *inventory) {
  char output[80];

  cout << "You are carrying:  " << endl;
  for(int i = 0; i < inventory->size(); i++){
    cout << inventory->at(i)->getName() << " " << endl;
  }
}

//do this after you get inventory working!!! it's basically the same.

//set up sandwich content array and state what is in it
void printSandwichContents(Vector<Items*> sandwichVtr) {
  char output[];
  for(vector<Items*>::iterator index = itemVtr->begin(); index!=itemVtr->end(); ++index){
    
    output += sandwichcontents.get(i).getDescription() + ", ";
  }
  System.out.println("The sandwich has: ");
  System.out.println(output);
}
    
//if user types help, print out these messages
void printHelp(Parser *p){
  cout << "You are lost in a haunted sub shop." << endl;
  cout << "You need to make a nice sandwich with: jalapenos, tomatoes, mayo, turkey, lettuce, and cheese. " << endl;
  cout << "Your command words are: " << endl;
  p->showCommand();
  cout << "by the way, 'sandwich' returns contents of sandwich." << endl;
}


void goRoom(tokens* command, Room* &currentRoom) {

  char* direction = command->word2;
  // Try to leave current room.
  Room* tempRoom= currentRoom->checkExits(direction);
  //  Room *nextRoom = currentRoom->getExits();
  if (tempRoom == NULL){
    cout << "There is no door!" << endl;
  }
  else {
    currentRoom = tempRoom;
    cout << currentRoom->getLongDescription() << endl;
  }
  
}

int main(){
  vector<Room*> *roomVtr = new vector<Room*>();
  vector<Items*> *sandwichVtr = new vector<Items*>();
  vector<Items*> *inventory = new vector<Items*>();

  Room* currentRoom = NULL; 
  createRooms(roomVtr, currentRoom);
  //  currentRoom = roomVtr->front();
  currentRoom->getLongDescription();
  CommandWords *cw = new CommandWords();
  Parser *p = new Parser();
  bool finished = false;
  while (finished == false){
    tokens* command = p->getCommand();
    finished = processCommand(command, currentRoom, inventory, p);
  }
  quit();
  return 0;
}
