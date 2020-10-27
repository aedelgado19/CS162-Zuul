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
//#include "CommandWords.h"
//#include "Command.h"
//#include "Items.h"
#include "Parser.h"

using namespace std;

void printWelcome();
void createRooms(vector<Room*> *RoomVtr, vector<Items*> *itemVtr, Room *&currentRoom);
void printHelp();
void goRoom(Command command, Room currentRoom);
void quit(Command command);
void dropItem(Command command);
void getItem(Command command);
void printSandwichContents();
void printInventory();


void printWelcome(){
  cout << "Welcome to Zuulway!" << endl;
  cout << "Zuulway takes place in a haunted sub sandwich shop that has a maze to find the ingredients." << endl;
  cout << "Type 'help' if you need help." << endl; //ALLY ADD HELP
  cout << " " << endl;
  cout << "A sad empty sandwich lays on the counter. To escape, you must add: tomatoes, mayo, jalapenos, turkey, cheese, and lettuce." << endl;
  cout << "Good luck!" << endl;
}
void getItem(Command command){


}


void printSandwichContents(){


}

void createRooms(vector<Room*> *RoomVtr, vector<Items*> *itemVtr, Room *&currentRoom){
  Room* Zuulway = new Room();
  Room* DarkRoom = new Room();
  Room* EmployeeHangout = new Room();
  Room* PuppyRoom = new Room();
  Room* Bathroom = new Room();
  Room* BossOffice = new Room();
  Room* CheeseRoom = new Room();
  Room* Storage = new Room();
  Room* MeatRoom = new Room();
  Room* WeirdRoom = new Room();
  Room* Outside = new Room();
  Room* Spa = new Room();
  Room* JalapenoRoom = new Room();
  Room* VegetableRoom = new Room();
  Room* MayonnaiseRoom = new Room();
  Room* Hallway = new Room();
  Room* BackRoom = new Room();
  Room* LettuceRoom = new Room();


  //Zuulway
  Zuulway->setDescription((char*)("in the main room of the sub shop."));
  currentRoom = Zuulway;
  Zuulway->setExits("east", PuppyRoom);
  Zuulway->setExits("south", BossOffice);
  Zuulway->setExits("west", WeirdRoom);
  Zuulway->setExits("north", DarkRoom);
  RoomVtr->push_back(Zuulway);

  //DarkRoom
  DarkRoom->setDescription((char*)("in a dark eerie room. Doesn't smell the greatest in here."));
  DarkRoom->setExits("south", Zuulway);
  DarkRoom->setExits("up", VegetableRoom);
  DarkRoom->setExits("east", EmployeeHangout);
  DarkRoom->setExits("west", Outside);
  RoomVtr->push_back(DarkRoom);
  
  //employee hangout
  EmployeeHangout->setDescription((char*)("in the employee break room. Say hi to everyone!"));
  EmployeeHangout->setExits("east", BackRoom);
  EmployeeHangout->setExits("southeast", Hallway);
  EmployeeHangout->setExits("south", PuppyRoom);
  EmployeeHangout->setExits("west", DarkRoom);
  RoomVtr->push_back(EmployeeHangout);
  
  //puppy room
  PuppyRoom->setDescription((char*)("in a room full of puppies! Don't question it."));
  PuppyRoom->setExits("north", EmployeeHangout);
  PuppyRoom->setExits("east", Hallway);
  PuppyRoom->setExits("south", Bathroom);
  PuppyRoom->setExits("west", Zuulway);
  RoomVtr->push_back(PuppyRoom);
  
  //bathroom
  Bathroom->setDescription((char*)("in the... bathroom? Ew, get out!"));
  Bathroom->setExits("north", PuppyRoom);
  Bathroom->setExits("southwest", CheeseRoom);
  Bathroom->setExits("west", BossOffice);
  RoomVtr->push_back(Bathroom);

  //boss office
  BossOffice->setDescription((char*)("in your boss's office. He doesn't look happy. You should probably leave."));
  BossOffice->setExits("north", Zuulway);
  BossOffice->setExits("east", Bathroom);
  BossOffice->setExits("southeast", CheeseRoom);
  BossOffice->setExits("west", Storage);
  RoomVtr->push_back(BossOffice);
  
  //cheese room
  CheeseRoom->setDescription((char*)("in the cheese room! Here you can get cheese for your sandwich."));
  CheeseRoom->setExits("northwest", BossOffice);
  CheeseRoom->setExits("northeast", Bathroom);
  RoomVtr->push_back(CheeseRoom);

  //storage
  Storage->setDescription((char*)("in the storage room. Nothing cool here."));
  Storage->setExits("north", Outside);
  Storage->setExits("west", VegetableRoom);
  Storage->setExits("east", BossOffice);
  RoomVtr->push_back(Storage);

  //meat
  MeatRoom->setDescription((char*)("in the meat room. Here you can get meat for your sandwich."));
  MeatRoom->setExits("east", Storage);
  MeatRoom->setExits("northeast", WeirdRoom);
  RoomVtr->push_back(MeatRoom);

  //weird room
  WeirdRoom->setDescription((char*)("in a weird room. It seems like nobody has been here in a while."));
  WeirdRoom->setExits("north", Outside);
  WeirdRoom->setExits("east", Zuulway);
  WeirdRoom->setExits("southwest", VegetableRoom);
  WeirdRoom->setExits("south", Storage);
  RoomVtr->push_back(WeirdRoom);

  //outside
  Outside->setDescription((char*)("outside. What? Get back inside, you have a job to do!"));
  Outside->setExits("northwest", Spa);
  Outside->setExits("east", DarkRoom);
  Outside->setExits("south", WeirdRoom);
  RoomVtr->push_back(Outside);

  //spa
  Spa->setDescription((char*)("in an indoor luxury spa. You're not sure why there's a spa in a Zuulway, but whatever!"));
  Spa->setExits("east", JalapenoRoom);
  Spa->setExits("southeast", Outside);
  RoomVtr->push_back(Spa);

  //jalapeno
  JalapenoRoom->setDescription((char*)("in the jalapeno room. Here you can get all your spicy peppers for your sandwich."));
  JalapenoRoom->setExits("west", Spa);
  RoomVtr->push_back(JalapenoRoom);
  
  //vegetable
  VegetableRoom->setDescription((char*)("in the vegetable room. Here you can get all your veggies!"));
  VegetableRoom->setExits("down", DarkRoom);
  VegetableRoom->setExits("east", MayonnaiseRoom);
  RoomVtr->push_back(VegetableRoom);
  
  //mayo
  MayonnaiseRoom->setDescription((char*)("in the mayo room. You swim neck deep in mayo, which is kind of nasty, but the sandwich does require mayo, so you have to deal with it."));
  MayonnaiseRoom->setExits("west", VegetableRoom);
  RoomVtr->push_back(MayonnaiseRoom);
  
  //hall
  Hallway->setDescription((char*)("in the hallway. Nothing cool here."));
  Hallway->setExits("northwest", EmployeeHangout);
  Hallway->setExits("north", BackRoom);
  Hallway->setExits("west", PuppyRoom);
  Hallway->setExits("down", LettuceRoom);
  RoomVtr->push_back(Hallway);

  //backroom
  BackRoom->setDescription((char*)("in the back room. There are a lot of boxes, but nothing of value."));
  BackRoom->setExits("west", EmployeeHangout);
  BackRoom->setExits("south", Hallway);
  RoomVtr->push_back(BackRoom);
  
  //lettuce
  LettuceRoom->setDescription((char*)("in the lettuce room. Here you can satisfy all your lettuce needs! Watch out for the e-coli."));
  LettuceRoom->setExits("up", Hallway);
  RoomVtr->push_back(LettuceRoom);
  
  //items
  JalapenoRoom->setItems(new Items("jalapenos"));
  VegetableRoom->setItems(new Items("turkey"));
  CheeseRoom->setItems(new Items("cheese"));
  MayonnaiseRoom->setItems(new Items("mayo"));
  VegetableRoom->setItems(new Items("tomatoes"));
  LettuceRoom->setItems(new Items("lettuce"));  
}

  bool processCommand(Command command){
  bool wantToQuit = false;
  
  /*  
  //illegal commands
  if(command.isUnknown()) {
    cout << "I don't know what you mean..." << endl;
    return false;
  }

  Command *cwPtr = new Command();
  //legal commands
  char commandWord[] = cwPtr->getCommandWord();
  if (strcmp(commandWord, "help") == 0) {
    printHelp();
  }
  else if(strcmp(commandWord, "go") == 0) {
    //goRoom(command, currentRoom);
  }
  else if (strcmp(commandWord, "quit") == 0){
    if(wantToQuit == true){
      quit(command);
    }
  }
  else if (strcmp(commandWord, "get") == 0){
    getItem(command);
  }
  else if (strcmp(commandWord, "drop") == 0){
    dropItem(command);
  }
  else if (strcmp(commandWord, "inventory") == 0){
    printInventory();
  }
  else if (strcmp(commandWord, "sandwich") == 0){
    printSandwichContents();
  }
  return wantToQuit;*/
}
  
 //set up inventory and state what is in it
void printInventory(vector<Items*> itemVtr) {
  Items* iPtr;
  char output[80];
  char desc[80];
  for(vector<Items*>::iterator index = itemVtr.begin(); index!=itemVtr.end(); ++index){
    // desc = iPtr->getDescription(); 
  }
  cout << "You are carrying:  " << endl;
  cout << desc;
}


//do this after you get inventory working!!! it's basically the same.
/*    
//set up sandwich content array and state what is in it
void printSandwichContents(Vector<Items*> sandwichVtr) {
  char output[];
  for(vector<Items*>::iterator index = itemVtr->begin(); index!=itemVtr->end(); ++index){
    
    output += sandwichcontents.get(i).getDescription() + ", ";
  }
  System.out.println("The sandwich has: ");
  System.out.println(output);
  }*/
    
//if user types help, print out these messages
void printHelp(){
  Parser *ptr;
  cout << "You are lost in a haunted sub shop." << endl;
  cout << "You need to make a nice sandwich with: jalapenos, tomatoes, mayo, turkey, lettuce, and cheese. " << endl;
  cout << "Your command words are: " << endl;
  ptr->showCommand();
}

/*
void goRoom(Command command, Room currentRoom) {
  //Command *cPtr = new Command();
  //if(cPtr->hasSecondWord() == false) {
    // if there is no second word, we don't know where to go...
    cout << "Go where?" << endl;
    return;
  }
  
  char direction[] = cPtr->getSecondWord();
      
  // Try to leave current room.
  Room nextRoom = currentRoom.getExits(direction);
  
  if (&nextRoom == NULL){
    cout << "There is no door!" << endl;
  }
  else {
    //currentRoom = nextRoom;
    //    cout << cPtr->getLongDescription();
  }
  }*/

int main(){
  Room* currentRoom;
  vector<Room*> roomVtr;
  vector<Items*> itemVtr;
  vector<Items*> sandwichVtr;
  vector<Items*> *inventory;
  CommandWords *cw = new CommandWords();
  Parser *p = new Parser();
  printWelcome();
  bool finished = false;
  while (finished == false){
    Command command = p->getCommand();
  }

  return 0;
}
