#include<iostream>
#include<iomanip>
#include"elevator.h"
#include"windows.h"//to give small pause


using namespace std;

elevator::elevator() {
	//function calling 
	data();

}
void elevator::display() {
	int x;
	cout << "\n\t Floors (Buttons)\n";
	cout << " \t-----------------\n";
	//loop used which displays the elevator menu to user
	for (int i = floors; i >= basement; i -= 2) {
		x = i - 1;

		if (i == current_floor) {
			if (i == basement && i % 2 != 0) {
				cout << " \t  >|  " << setw(3) << setfill(' ') << i << "   |\n"; //arrow placed at the current floor number
			}
			else {
				cout << " \t  >|" << setw(3) << setfill(' ') << i << "  " << setw(3) << setfill(' ') << x << "| \n";
			}
		}
		else if (x == current_floor) {
			cout << " \t   |" << setw(3) << setfill(' ') << i << "  " << setw(3) << setfill(' ') << x << "|<\n";
		}

		else {
			if (i == basement && i % 2 != 0) {
				cout << " \t   |  " << setw(3) << setfill(' ') << i << "   |\n";
			}
			else {
				cout << " \t   |" << setw(3) << setfill(' ') << i << "  " << setw(3) << setfill(' ') << x << "| \n";
			}
		}
	}
	cout << " \t-----------------\n";
}
void elevator::data() {
	//General Data
	//floors
	cout << " Enter Total Number of floors of Building: ";
	cin >> floors;
	//infinite loop
	while (1) {
		//maximum floor limit is 200
		if (floors >= 0 && floors <= 200) {
			//goto statement takes the line command to exit
			goto exit;
		}
		else {
			//if wrong input, it asks the user again and again
			cout << " Wrong Input!!!Max Number of floors can be 200!!!\n";
			cout << " Enter number of floors again: ";
			cin >> floors;
		}
	}
exit:
	//Basements
	cout << " Enter the Number of Basements: ";
	cin >> base;
	//infinite loop
	while (1) {
		//maximum basement limit is 5
		if (base >= 0 && base <= 5) {
			goto exit_b;
		}
		else {
			cout << " Wrong Input!!!Max Number of Basements can be 5!!!\n";
			cout << " Enter number of Basements again: ";
			cin >> base;
		}
	}
exit_b:
	basement = -1 * base;  //shows basement as negative floors on the menu
	//Passengers
	cout << " \n <------- Welcome To E & H Elevator -------->\n";
	cout << " !!!!Elevator can hold max 5 Passengers at a time!!!!\n";
	cout << " Enter the Numbers of Passengers:  ";
	cin >> num;
	//infinite loop
	while (1) {
		if (num > 0 && num <= 5) {
			goto exit_n; //takes command to exit_n if the condition is true
		}
		else {
			cout << " Wrong Input!!!Max Number of Passengers can be 5!!!\n";
			cout << " Enter number of Passengers again: ";
			cin >> num;
		}
	}
exit_n:
	input();
}
void elevator::input() {
	display();
	cout << " Enter your Floor number: ";
	cin >> user_floor;
	check_floor();
	doors();

}
void elevator::check_floor() {

	while (1) {

		if (user_floor >= basement && user_floor <= floors) {
			goto exit_f;
		}
		else {
			cout << " Wrong Input!!!Max Number of Floors can be " << floors << " and Basements " << base << endl;
			cout << " Enter number of floor again: ";
			cin >> user_floor;
		}
	}
exit_f:
	if (1) {};//nullstatement
}
void elevator::doors() {
	if (check) {

		cout << " Doors are open!!!Waiting 3 seconds for closure of doors!!!\n";
		Sleep(3500);//Open for 3 seconds
		check = false;
		cout << " !!!Doors are Closed!!!\n";
	}
	else {
		//moving
		cout << " !!!Doors are Closing!!!\n";
		Sleep(1000);
		cout << " !!!Doors are Closed!!!\n";
		motion();
	}
}
void elevator::motion() {
	int i = current_floor;
	while (i != user_floor) {
		if (user_floor < current_floor) {
			i--;
			cout << "\t Moving Down to Floor " << i << endl;
			Sleep(1000);
		}
		else {
			i++;
			cout << "\t Moving Up to Floor " << i << endl;
			Sleep(1000);
		}
	}
	cout << " !!!Opening Doors!!!\n";
	Sleep(1000); //sleep function, its a time function which delays the next command by 1000ns
	cout << " Doors are Opened\n";
	Sleep(500);
	cout << " \n\t Hoping for a nice experience with us :)\n";
	current_floor = user_floor;
	check = true;
	doors();
	while (1) {
		summon();
	}

}
void elevator::summon() {
	//Passengers
	cout << " \n <------- Welcome To E & H Elevator -------->\n";
	cout << "\n !!!!Elevator can hold max 5 Passengers at a time!!!!\n";
	cout << " Enter the Numbers of Passengers:  ";
	cin >> num;
	//infinite loop
	while (1) {
		if (num > 0 && num <= 5) {

			goto exit_n;
		}
		else {
			cout << " Sorry!!!Our Elevator can Hold Max 5 Number of Passengers !!!\n";
			cout << " Enter number of Passengers again: ";
			cin >> num;
		}
	}
exit_n:

	input();
}