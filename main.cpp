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
void printWelcome();
void createRooms(vector<Room*> *roomVtr, vector<Items*> *itemVtr, Room *currentRoom);
void printHelp();
void goRoom(tokens* command, Room* currentRoom);
void quit();
void dropItem(tokens* command, Room* currentRoom, vector<Items*> *inventory);
void getItem(tokens* command, Room* currentRoom);
void printSandwichContents();
void printInventory(vector<Items*> *inventory);
bool processCommand(tokens* command, Room* currentRoom, vector<Items*> *inventory);

void quit(){
  cout << "Thank you for playing Zuulway. Quitting program now." << endl;
  
}

void printWelcome(){
  cout << "Welcome to Zuulway!" << endl;
  cout << "Zuulway takes place in a haunted sub sandwich shop that has a maze to find the ingredients." << endl;
  cout << "Type 'help' if you need help." << endl; //ALLY ADD HELP
  cout << " " << endl;
  cout << "A sad empty sandwich lays on the counter. To escape, you must add: tomatoes, mayo, jalapenos, turkey, cheese, and lettuce." << endl;
  cout << "Good luck!" << endl;
}
void getItem(tokens* command, Room* currentRoom){


}

void dropItem(tokens* command, Room* currentRoom, vector<Items*> *inventory){

}

void printSandwichContents(){


}

void createRooms(vector<Room*> *roomVtr, vector<Items*> *itemVtr, Room *currentRoom){
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
  roomVtr->push_back(Zuulway);

  //DarkRoom
  DarkRoom->setDescription((char*)("in a dark eerie room. Doesn't smell the greatest in here."));
  DarkRoom->setExits("south", Zuulway);
  DarkRoom->setExits("up", VegetableRoom);
  DarkRoom->setExits("east", EmployeeHangout);
  DarkRoom->setExits("west", Outside);
  roomVtr->push_back(DarkRoom);
  
  //employee hangout
  EmployeeHangout->setDescription((char*)("in the employee break room. Say hi to everyone!"));
  EmployeeHangout->setExits("east", BackRoom);
  EmployeeHangout->setExits("southeast", Hallway);
  EmployeeHangout->setExits("south", PuppyRoom);
  EmployeeHangout->setExits("west", DarkRoom);
  roomVtr->push_back(EmployeeHangout);
  
  //puppy room
  PuppyRoom->setDescription((char*)("in a room full of puppies! Don't question it."));
  PuppyRoom->setExits("north", EmployeeHangout);
  PuppyRoom->setExits("east", Hallway);
  PuppyRoom->setExits("south", Bathroom);
  PuppyRoom->setExits("west", Zuulway);
  roomVtr->push_back(PuppyRoom);
  
  //bathroom
  Bathroom->setDescription((char*)("in the... bathroom? Ew, get out!"));
  Bathroom->setExits("north", PuppyRoom);
  Bathroom->setExits("southwest", CheeseRoom);
  Bathroom->setExits("west", BossOffice);
  roomVtr->push_back(Bathroom);

  //boss office
  BossOffice->setDescription((char*)("in your boss's office. He doesn't look happy. You should probably leave."));
  BossOffice->setExits("north", Zuulway);
  BossOffice->setExits("east", Bathroom);
  BossOffice->setExits("southeast", CheeseRoom);
  BossOffice->setExits("west", Storage);
  roomVtr->push_back(BossOffice);
  
  //cheese room
  CheeseRoom->setDescription((char*)("in the cheese room! Here you can get cheese for your sandwich."));
  CheeseRoom->setExits("northwest", BossOffice);
  CheeseRoom->setExits("northeast", Bathroom);
  roomVtr->push_back(CheeseRoom);

  //storage
  Storage->setDescription((char*)("in the storage room. Nothing cool here."));
  Storage->setExits("north", Outside);
  Storage->setExits("west", VegetableRoom);
  Storage->setExits("east", BossOffice);
  roomVtr->push_back(Storage);

  //meat
  MeatRoom->setDescription((char*)("in the meat room. Here you can get meat for your sandwich."));
  MeatRoom->setExits("east", Storage);
  MeatRoom->setExits("northeast", WeirdRoom);
  roomVtr->push_back(MeatRoom);

  //weird room
  WeirdRoom->setDescription((char*)("in a weird room. It seems like nobody has been here in a while."));
  WeirdRoom->setExits("north", Outside);
  WeirdRoom->setExits("east", Zuulway);
  WeirdRoom->setExits("southwest", VegetableRoom);
  WeirdRoom->setExits("south", Storage);
  roomVtr->push_back(WeirdRoom);

  //outside
  Outside->setDescription((char*)("outside. What? Get back inside, you have a job to do!"));
  Outside->setExits("northwest", Spa);
  Outside->setExits("east", DarkRoom);
  Outside->setExits("south", WeirdRoom);
  roomVtr->push_back(Outside);

  //spa
  Spa->setDescription((char*)("in an indoor luxury spa. You're not sure why there's a spa in a Zuulway, but whatever!"));
  Spa->setExits("east", JalapenoRoom);
  Spa->setExits("southeast", Outside);
  roomVtr->push_back(Spa);

  //jalapeno
  JalapenoRoom->setDescription((char*)("in the jalapeno room. Here you can get all your spicy peppers for your sandwich."));
  JalapenoRoom->setExits("west", Spa);
  roomVtr->push_back(JalapenoRoom);
  
  //vegetable
  VegetableRoom->setDescription((char*)("in the vegetable room. Here you can get all your veggies!"));
  VegetableRoom->setExits("down", DarkRoom);
  VegetableRoom->setExits("east", MayonnaiseRoom);
  roomVtr->push_back(VegetableRoom);
  
  //mayo
  MayonnaiseRoom->setDescription((char*)("in the mayo room. You swim neck deep in mayo, which is kind of nasty, but the sandwich does require mayo, so you have to deal with it."));
  MayonnaiseRoom->setExits("west", VegetableRoom);
  roomVtr->push_back(MayonnaiseRoom);
  
  //hall
  Hallway->setDescription((char*)("in the hallway. Nothing cool here."));
  Hallway->setExits("northwest", EmployeeHangout);
  Hallway->setExits("north", BackRoom);
  Hallway->setExits("west", PuppyRoom);
  Hallway->setExits("down", LettuceRoom);
  roomVtr->push_back(Hallway);

  //backroom
  BackRoom->setDescription((char*)("in the back room. There are a lot of boxes, but nothing of value."));
  BackRoom->setExits("west", EmployeeHangout);
  BackRoom->setExits("south", Hallway);
  roomVtr->push_back(BackRoom);
  
  //lettuce
  LettuceRoom->setDescription((char*)("in the lettuce room. Here you can satisfy all your lettuce needs! Watch out for the e-coli."));
  LettuceRoom->setExits("up", Hallway);
  roomVtr->push_back(LettuceRoom);
  
  //items
  JalapenoRoom->setItems(new Items("jalapenos"));
  VegetableRoom->setItems(new Items("turkey"));
  CheeseRoom->setItems(new Items("cheese"));
  MayonnaiseRoom->setItems(new Items("mayo"));
  VegetableRoom->setItems(new Items("tomatoes"));
  LettuceRoom->setItems(new Items("lettuce"));  
}

bool processCommand(tokens* command, Room* currentRoom, vector<Items*> *inventory){
  bool wantToQuit = false;
  if(strcmp(command->word1, "help") == 0){
    printHelp();   
  }
  else if(strcmp(command->word1, "go") == 0){
    goRoom(command, currentRoom);
  }
  else if(strcmp(command->word1, "quit") == 0){
    wantToQuit = true;
  }
  else if(strcmp(command->word1, "get") == 0){
    getItem(command, currentRoom);
  }
  else if(strcmp(command->word1, "drop") == 0){
    dropItem(command, currentRoom, inventory);
  }
  else if(strcmp(command->word1, "inventory") == 0){
    printInventory(inventory);
  }
  else if(strcmp(command->word1, "sandwich") == 0){
    printSandwichContents();
  }
  return wantToQuit;
}

 //set up inventory and state what is in it
void printInventory(vector<Items*> *inventory) {
  Items* iPtr;
  char output[80];
  char desc[80];
  for(vector<Items*>::iterator index = inventory->begin(); index!=inventory->end(); ++index){
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


void goRoom(tokens* command, Room* currentRoom) {
  
  char* direction = command->word2;
      
  // Try to leave current room.
  /*
  Room nextRoom = currentRoom.getExits(direction);
  
 if (&nextRoom == NULL){
    cout << "There is no door!" << endl;
  }
  else {
    currentRoom = nextRoom;
    cout << cPtr->getLongDescription();
  }
  */
}

int main(){

  vector<Room*> *roomVtr;
  vector<Items*> *itemVtr;
  vector<Items*> sandwichVtr;
  vector<Items*> *inventory;
  Room* currentRoom = roomVtr->front();
  createRooms(roomVtr, itemVtr, currentRoom);
  currentRoom->getLongDescription();
  CommandWords *cw = new CommandWords();
  Parser *p = new Parser();
  printWelcome();
  bool finished = false;
  while (finished == false){
    tokens* command = p->getCommand();
    finished = processCommand(command, currentRoom, inventory);
  }
  quit();
  return 0;
}
