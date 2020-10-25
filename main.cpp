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
#include "CommandWords.h"
#include "Command.h"
#include "Items.h"

using namespace std;

void printWelcome();
void createRooms();


void printWelcome(){
  cout << "Welcome to Zuulway!" << endl;
  cout << "Zuulway takes place in a haunted sub sandwich shop that has a maze to find the ingredients." << endl;
  cout << "Type 'help' if you need help." << endl; //ALLY ADD HELP
  cout << " " << endl;
  cout << "A sad empty sandwich lays on the counter. To escape, you must add: tomatoes, mayo, jalapenos, turkey, cheese, and lettuce." << endl;
  cout << "Good luck!" << endl;
}

void createRooms(vector<Room*> *RoomVtr){
  Room* Zuulway = new Room();
  Zuulway->setDescription((char*)("in the main room of the sub shop."));
  


  Room* DarkRoom = new Room();
  DarkRoom->setDescription((char*)("in a dark eerie room. Doesn't smell the greatest in here."));


  Room* EmployeeHangout = new Room();
  EmployeeHangout->setDescription((char*)("in the employee break room. Say hi to everyone!"));



  Room* PuppyRoom = new Room();
  PuppyRoom->setDescription((char*)("in a room full of puppies! Don't question it."));


 
  Room* Bathroom = new Room();
  Bathroom->setDescription((char*)("in the... bathroom? Ew, get out!"));


  Room* BossOffice = new Room();
  BossOffice->setDescription((char*)("in your boss's office. He doesn't look happy. You should probably leave."));

  Room* CheeseRoom = new Room();
  CheeseRoom->setDescription((char*)("in the cheese room! Here you can get cheese for your sandwich."));


  Room* Storage = new Room();
  Storage->setDescription((char*)("in the storage room. Nothing cool here."));


  Room* MeatRoom = new Room();
  MeatRoom->setDescription((char*)("in the meat room. Here you can get meat for your sandwich."));


  Room* WeirdRoom = new Room();
  WeirdRoom->setDescription((char*)("in a weird room. It seems like nobody has been here in a while."));


  Room* Outside = new Room();
  Outside->setDescription((char*)("outside. What? Get back inside, you have a job to do!"));


  Room* Spa = new Room();
  Spa->setDescription((char*)("in an indoor luxury spa. You're not sure why there's a spa in a Zuulway, but whatever!"));


  Room* JalapenoRoom = new Room();
  JalapenoRoom->setDescription((char*)("in the jalapeno room. Here you can get all your spicy peppers for your sandwich."));


  Room* VegetableRoom = new Room();
  VegetableRoom->setDescription((char*)("in the vegetable room. Here you can get all your veggies!"));


  Room* MayonnaiseRoom = new Room();
  MayonnaiseRoom->setDescription((char*)("in the mayo room. You swim neck deep in mayo, which is kind of nasty, but the sandwich does require mayo, so you have to deal with it."));


  Room* Hallway = new Room();
  Hallway->setDescription((char*)("in the hallway. Nothing cool here."));



  Room* BackRoom = new Room();
  BackRoom->setDescription((char*)("in the back room. There are a lot of boxes, but nothing of value."));



  Room* LettuceRoom = new Room();
  LettuceRoom->setDescription((char*)("in the lettuce room. Here you can satisfy all your lettuce needs! Watch out for the e-coli."));
}

bool processCommand(Command command){
  bool wantToQuit = false;
  
  
  //illegal commands
  if(command.isUnknown()) {
    cout << "I don't know what you mean..." << endl;
    return false;
  }

  //  CommandWords *cwPtr;
  //legal commands
  char commandWord[] = cwPtr->getCommandWord();
  if (strcmp(commandWord, "help") == 0) {
    printHelp();
  }
  else if(strcmp(commandWord, "go") == 0) {
    goRoom(command);
  }
  else if (strcmp(commandWord, "quit") == 0){
    wantToQuit = quit(command);
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
  return wantToQuit;
}

 //set up inventory and state what is in it
void printInventory(Vector<Items*> itemVtr) {
  Items* iPtr;
  char output[80];
  char desc[80];
  for(vector<Items*>::iterator index = itemVtr->begin(); index!=itemVtr->end(); ++index){
    desc = iPtr->getDescription(); 
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
  ptr->showCommands();
}

/** 
 * Try to go to one direction. If there is an exit, enter the new
 * room, otherwise print an error message.
 */
void goRoom(Command command) {
  Command *cPtr;
  if(cPtr->hasSecondWord() == false) {
    // if there is no second word, we don't know where to go...
    cout << "Go where?" << endl;
    return;
  }
  
  char direction[] = command->getSecondWord();
      
  // Try to leave current room.
  Room nextRoom = currentRoom.getExit(direction);
  
  if (nextRoom == NULL)
    cout << "There is no door!" << endl;
  else {
    currentRoom = nextRoom;
    cout << cPtr->getLongDescription();
  }
}

    
//take item from room and remove it from the current room
    private void getItem(Command command) 
    {
      if(!command.hasSecondWord()) {
	// if there is no second word, we don't know what to get...
	System.out.println("Get what?");
	return;
      }

      String item = command.getSecondWord();

      // Try to leave current room.
      Item newItem = currentRoom.getItem(item);

      if (newItem == null)
	System.out.println("That item isn't here! ");
      else {
	inventory.add(newItem);
	currentRoom.removeItem(item);
	System.out.println("You picked up: " + item);
      }
    }

    
    
//take item out of inventory
    private void dropItem(Command command) 
    {
      if(!command.hasSecondWord()) {
	// if there is no second word, we don't know what to drop...
	System.out.println("Drop what?");
	return;
      }

      String item = command.getSecondWord();

      // Try to leave current room.
      Item newItem = null;
      int index = 0;
      for (int i = 0; i < inventory.size(); i++) {
	if (inventory.get(i).getDescription().equals(item)) {
	  newItem = inventory.get(i);
	  index = i;
	}
      }
        
        
      if (newItem == null)
	System.out.println("That isn't in your inventory. ");
       
        
      else {
	//if you drop an item into the room Zuulway, then it gets dropped into the sandwich
	//item is now accounted for in the array for sandwich items
	if (currentRoom == Zuulway) {
	  System.out.println("You have dropped " + item + " onto the sandwich");
	  sandwichcontents.add(newItem);
	  currentRoom.removeItem(item);
	  printSandwichContents();
	}
        
       
	inventory.remove(index);
	currentRoom.setItem(new Item(item));
	System.out.println("You dropped: " + item);
            
      }
    }
        
     
/**
 * "Quit" was entered. Check the rest of the command to see
 * whether we really quit the game. Return true, if this command
 * quits the game, false otherwise.
 */
    
    private boolean quit(Command command) 
    {
      if(command.hasSecondWord()) {
	System.out.println("Quit what?");
	return false;
      }
      else {
	return true;  // signal that we want to quit
      }
    }


//determine if the user has won or not
	private boolean win() {
	  //the user wins if the amount of things in the sandwich equals 6
	  if (sandwichcontents.size() == 6) {
	    System.out.println("You have successfully made the sandwich! Good job!");
	    return true;
			
	  }
	  return false;
	}
}







int main(){
  vector<Room*> roomVtr;
  vector<Items*> itemVtr;
  vector<Items*> sandwichVtr;
  printWelcome();
 

  return 0;
}
