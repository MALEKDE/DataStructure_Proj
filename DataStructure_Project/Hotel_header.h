#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Reservation {
public:
	string guestName;
	int roomNumber;
	int duration;
	int floorNumber;
		//….
	Reservation(string = "inknown", int = 0, int = 0, int =0);
	Reservation(const Reservation&);
	
};

class Room {
public:

	bool occupied;
	Reservation reservation;
	Room* roomNext;
	// ….
	Room( Reservation = Reservation(), bool = false, Room* = NULL);
	//Room(const Room&);
	
	void addReservation(Reservation);
};

class Floor {

public:
	string name;
	Room* rooms;
	Floor* nextFloor;
	int roomsnum = 1;
	Floor(string = "floor 1", Floor* = NULL, int = 1, Room* = new Room());
	//Floor( const Floor&);
	~Floor();
	int getroomslength();
	Room* getroom(int);
	//void sort();
	//
};

class Hotel {
private:

	string hotelName;
	Floor* floors;
	int numFloors = 1;
public:

	Hotel(string = "hotel", Floor* = new Floor(), int = 1);
	//Hotel(const Hotel&);
	~Hotel();
	int getnumfloors();
	void setname(string name);
	friend Hotel operator+(Hotel  ,Room );
	friend Hotel operator-(Hotel, const Room);
	friend Hotel operator+=(Hotel, Room);
	friend Hotel operator+( Hotel , Reservation );
	friend void operator << (ostream &out, Hotel a);
	friend void operator >> (istream& in, Hotel a);

	friend void	display_reverse_floor(const Hotel&, int);//problem in copy constructor
    Hotel operator = (Hotel);
	int getfloorslength();
	Floor* getfloor(int);
	bool checkifroomexist(Reservation);
			
};

Room* addsortedroom(Room*, Room*);