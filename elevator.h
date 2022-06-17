#include<iostream>
#include<iomanip>
#include"windows.h"//to give small pause


using namespace std;
//class declared
class elevator {
	//private data members. Cannot be accessed by subclasses or outside class
private:
	int floors;
	int base = 0;  //initalized with a 0 to avoid taking garbage values
	int basement;
	int num;
	int user_floor;
	int current_floor = 0;
	bool check = false;

public:
	elevator();
	void display();
	void data();



	//User input
	void input();

	//this function checks at which floor the user is right now
	void check_floor();

	//Doors
	void doors();

	//motion
	void motion();

	void summon();


};