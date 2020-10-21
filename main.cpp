/* Author: Allison Delgado
 * Last updated: Oct 20, 2020
 * Zuul is similar to Zork. The premise of this game is that
 * you are lost in a sub shop and must find all ingredients to escape
 */

#include <iostream>
#include <cstring>
#include <vector>
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
  Zuulway = new Room();
  DarkRoom = new Room();
  EmployeeHangout = new Room();
  PuppyRoom = new Room();
  Bathroom = new Room();
  BossOffice = new Room();
  CheeseRoom = new Room();
  Storage = new Room();
  MeatRoom = new Room();
  WeirdRoom = new Room();
  Outside = new Room();
  Spa = new Room();
  JalapenoRoom = new Room();
  VegetableRoom = new Room();
  MayonnaiseRoom = new Room();
  Hallway = new Room();
  BackRoom = new Room();
  LettuceRoom = new Room();
}


int main(){
  vector<Room*> roomVtr;
  vector<Items*> itemVtr;
  printWelcome();
  
  



  return 0;
}
