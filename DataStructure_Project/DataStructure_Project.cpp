// DataStructure_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//malek saleem saeed sous 
//12323344
#include <iostream>
#include "Hotel_header.h"
using namespace std;

int main()
{
	Hotel hotel("Grand Hotel");
	
	Reservation R1("Masa", 8, 5, 1);

	Room Room1;
	Room1.addReservation(R1);
	
	
	

	
	
	Reservation R2("Ali", 7, 2, 1);
	Reservation R3("Ahmed", 3, 4, 1);
	Reservation R4("Alice", 1, 4, 1);
	Reservation R5("Raya", 10, 2, 2);
	Reservation R6("Omar", 7, 4, 2);
	
	Room Room2;
	Room2.addReservation(R2);
	Room* Room3;
	Room3 = new Room;
	Room3->addReservation(R3);
	Room Room4;
	Room4.addReservation(R4);
	Room Room5;
	Room5.addReservation(R5);
	Room Room6;
	Room6.addReservation(R6);

	hotel = hotel+ Room1;
	hotel = hotel + Room2;
	hotel = hotel + *Room3;
	hotel = hotel + Room4;
	hotel = hotel + Room5;
	hotel = hotel + Room6;

	delete Room3; 
	
	//Hotel hotel2("Palestine Hotel");
	//hotel2 = hotel - Room2;

	cout << hotel;
	cout << endl;
	display_reverse_floor(hotel, 1);//problem in copy constructor
	//cout << hotel2;
	
	
	
	
	
	return 0;
	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
