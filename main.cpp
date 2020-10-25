/* Author: Allison Delgado
 * Last updated: Oct 20, 2020
 * Zuul is similar to Zork. The premise of this game is that
 * you are lost in a sub shop and must find all ingredients to escape
 */

#include <iostream>
#include <cstring>
#include <vector>
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

void createRooms(){
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


int main(){
  vector<Room*> roomVtr;
  vector<Items*> itemVtr;
  printWelcome();
  
  



  return 0;
}
