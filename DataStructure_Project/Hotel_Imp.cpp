#include "Hotel_header.h"
#include <iostream>
#include <string>
#include <stack>

Hotel::Hotel(string name, Floor* f, int x) {

	hotelName = name;
	floors = f;
	numFloors = x;
	
}

/*Remember to uncomment the prototype from header file
Hotel::Hotel(const Hotel& a)
{
	hotelName = a.hotelName;
	floors = new Floor(*a.floors);//problem that we didnt copy all floors(this is shallow copy not deep)
	numFloors = a.numFloors;
}

Floor::Floor(const Floor& a)
{
	name = a.name;
	rooms = new Room(*a.rooms);//problem that we didnt copy all rooms(this is shallow copy not deep)
	nextFloor = a.nextFloor;
	roomsnum = a.roomsnum;

}

Room::Room(const Room& a)
{
	occupied = a.occupied;
	reservation = a.reservation;
	roomNext = a.roomNext;
}
*/

Hotel::~Hotel()
{
	//delete floors;
}




int Hotel::getnumfloors()
{
	return numFloors;
}

void Hotel::setname(string name)
{
	hotelName = name;
}



Hotel operator+(Hotel a, Room b)
{


	if (b.reservation.floorNumber <= a.getfloorslength()) {//check if floor exist

		//floor exist
		Floor* p;
		p = a.getfloor(b.reservation.floorNumber);

		if (a.checkifroomexist(b.reservation))//check if room exist
		{
			//room sxist
			p->getroom(b.reservation.roomNumber)->addReservation(b.reservation);
		}
		else {
			//room does not exist

			if (p->rooms->occupied == false) {

				p->rooms->addReservation(b.reservation);

			}
			else
			{
				Room* p1;
				Room* p2;
				p1 = p2 = p->rooms;

				while (p2 != NULL)
				{
					p1 = p2;
					p2 = p2->roomNext;
				}
				Room* newroom = new Room();
				//p1->roomNext = newroom;
				newroom->addReservation(b.reservation);
				p->rooms = addsortedroom(p->rooms, newroom);

			}
		}

	}
	else
	{
		//floor does not exist
		Floor* p;
		p = a.floors;
		Floor* newfloor = new Floor();
		p->nextFloor = newfloor;
		newfloor->name = "floor " + to_string(a.getfloorslength());

		if (newfloor->rooms->occupied == false) {

			newfloor->rooms->addReservation(b.reservation);

		}
		else
		{
			Room* p1;
			Room* p2;
			p1 = p2 = newfloor->rooms;

			while (p2 != NULL)
			{
				p1 = p2;
				p2 = p2->roomNext;
			}
			Room* newroom = new Room();
			newroom->addReservation(b.reservation);
			newfloor->rooms = addsortedroom(newfloor->rooms, newroom);
		}

	}

	return a;
	
	
}

Hotel operator-(Hotel a,const Room b)
{
	
	if (!a.checkifroomexist(b.reservation)) //check if the room exist	
		return a;

	//room exist
	 a.getfloor(b.reservation.floorNumber)->getroom(b.reservation.roomNumber)->occupied = false;
	
	

	

	return a;
}

Hotel operator+=(Hotel a, Room b) {

	if (b.reservation.floorNumber <= a.getfloorslength()) {//check if floor exist

		//floor exist
		Floor* p;
		p = a.getfloor(b.reservation.floorNumber);

		if (a.checkifroomexist(b.reservation))//check if room exist
		{
			//room sxist
			p->getroom(b.reservation.roomNumber)->addReservation(b.reservation);
		}
		else {
			//room does not exist

			if (p->rooms->occupied == false) {

				p->rooms->addReservation(b.reservation);

			}
			else
			{
				Room* p1;
				Room* p2;
				p1 = p2 = p->rooms;

				while (p2 != NULL)
				{
					p1 = p2;
					p2 = p2->roomNext;
				}
				Room* newroom = new Room();
				p1->roomNext = newroom;
				newroom->addReservation(b.reservation);

			}
		}

	}
	else
	{
		//floor does not exist
		Floor* p;
		p = a.floors;
		Floor* newfloor = new Floor();
		p->nextFloor = newfloor;
		newfloor->name = "floor " + to_string(a.getfloorslength());

		if (newfloor->rooms->occupied == false) {

			newfloor->rooms->addReservation(b.reservation);

		}
		else
		{
			Room* p1;
			Room* p2;
			p1 = p2 = newfloor->rooms;

			while (p2 != NULL)
			{
				p1 = p2;
				p2 = p2->roomNext;
			}
			Room* newroom = new Room();
			p2 = newroom;
			p1->roomNext = p2;
			newroom->addReservation(b.reservation);

		}

	}

	return a;
	

	return a;

}

Hotel operator+(Hotel a, Reservation b)
{

	if (b.floorNumber <= a.getfloorslength()) {//check if floor exist

		//floor exist
		Floor* p;
		p = a.getfloor(b.floorNumber);

		if (a.checkifroomexist(b))//check if room exist
		{
			//room sxist
			p->getroom(b.roomNumber)->addReservation(b);
		}
		else {
		   //room does not exist
			
			if (p->rooms->occupied == false) {

				p->rooms->addReservation(b);

			}
			else
			{
				Room* p1;
				Room *p2;
				p1 = p2 = p->rooms;

				while (p2 != NULL)
				{
					p1 = p2;
					p2 = p2->roomNext;
				}
				Room* newroom = new Room();
				p1->roomNext = newroom;
				newroom->addReservation(b);

			}
		}

	}
	else
	{
		//floor does not exist
		Floor* p;
		p = a.floors;
		Floor* newfloor = new Floor();
		p->nextFloor = newfloor;
		newfloor->name = "floor " + to_string(a.getfloorslength());

		if (newfloor->rooms->occupied == false) {

			newfloor->rooms->addReservation(b);

		}
		else
		{
			Room* p1;
			Room* p2;
			p1 = p2 = newfloor->rooms;

			while (p2 != NULL)
			{
				p1 = p2;
				p2 = p2->roomNext;
			}
			Room* newroom = new Room();
			p1->roomNext = newroom;
			newroom->addReservation(b);

		}

	}

	return a;
}

void operator<<(ostream& out, Hotel a)
{

	
	out << "Hotel Room Status For " << a.hotelName << endl;
	Floor* p = a.getfloor(1);//get the head of floors
	for(int i = 0; i < a.getfloorslength(); i++) {

		
		out << p->name << ": " << endl;
		//sort floor before cout
		//p->sort();
		Room* r;
		r = p->rooms;
		for (int j = 0; j < p->getroomslength(); j++)
		{
				//check if room avalable
			if (r->occupied == false) {
				//avalabile
				out << "Room " << r->reservation.roomNumber << ": avalabile"<<endl;
				r = r->roomNext;
			}
			else
			{
				out << "Room " << r->reservation.roomNumber << ": " << "occupied by " << r->reservation.guestName << "(Duration: " << r->reservation.duration << " Days )";
				r = r->roomNext;
				out << endl;
			}
		}

		p = p->nextFloor;
		out << endl;

	}

}

void operator>>(istream& in, Hotel a)
{


}

Hotel Hotel::operator=(Hotel a)
{
	hotelName = a.hotelName;
	floors = a.floors;
	numFloors = numFloors;
	
	Hotel b;
	b.hotelName = hotelName;
	b.floors = floors;
	b.numFloors = numFloors;

	return b;
}

int Hotel::getfloorslength() {

	Floor* p;
	p = floors;
	int c = 1;
	while (p->nextFloor!= NULL)
	{
		p = p->nextFloor;
		c++;
	}

	return c;
}

Floor* Hotel::getfloor(int a) {

  	 a--;
	 Floor* p;
	 p = floors;
	
	int c = 0;
	while (c != a && p->nextFloor != NULL)
	{
		p = p->nextFloor;
		c++;
	}

	return p;
}

bool Hotel::checkifroomexist(Reservation res)
{
	int c = 1;
	Floor* p;
	p = floors;
	while (c != res.floorNumber)
	{
		c++;
		p = p->nextFloor;
	}

	Room* p1;
	p1 = p->rooms;
	for (int i = 0; i < p->getroomslength(); i++)
	{
		if (p1->reservation.roomNumber == res.roomNumber) {
			return true;
		}
		else
		{
			p1 = p1->roomNext;
		}
	}

	return false;
	
	

}



Reservation::Reservation(string name , int roomnum, int dur, int floornum) {

	guestName = name;
	roomNumber = roomnum;
	duration = dur;
	floorNumber = floornum;

}

Reservation::Reservation(const Reservation& a)
{
	guestName = a.guestName;
	roomNumber = a.roomNumber;
	duration = a.duration;
	floorNumber = a.floorNumber;
}

void Room::addReservation(Reservation res) {

	reservation = res;
	occupied = true;

}

Room::Room( Reservation b, bool a, Room* c) {

	occupied = a;
	roomNext = c;
	reservation = b;
}





Floor::Floor(string a, Floor* c, int d, Room* b)
{
	name = a;
	rooms = b;
	nextFloor =c;
	roomsnum = d;

}




Floor::~Floor()
{
	delete rooms;
}

int Floor::getroomslength() {

	Room* p;
	p = rooms;
	int c = 0;
	while (p != NULL)
	{
		p = p->roomNext;
		c++;
	}
	
	return c;

}

Room* Floor::getroom(int c)
{

	//write it to search by room number 
	
	Room* p;
	p = rooms;
	
	while (p != NULL)
	{

		if (p->reservation.roomNumber == c) {

			return p;
		}
		else {
		
		  p = p->roomNext;
		}
		
	}
	return p;
	
}

void display_reverse_floor(const Hotel& h, int floornum)
{
	stack<Room*> s1;
	Hotel a = h;
	cout << "Hotel Room Status For " << h.hotelName << endl;
	Floor* p = a.getfloor(floornum);//get the head of floors
	


		cout << p->name << ": " << endl;
		//sort floor before cout
		//p->sort();
		Room* r;
		r = p->rooms;
		for (int j = 0; j < p->getroomslength(); j++)
		{
			s1.push(r);
			r = r->roomNext;
		}

		for (int k = 0; k < s1.size(); k++)
		{

			//check if room avalable
			if (s1.top()->occupied == false) {
				//avalabile
				cout << "Room " << r->reservation.roomNumber << ": avalabile" << endl;
				s1.pop();
			}
			else
			{
				cout << "Room " << s1.top()->reservation.roomNumber << ": " << "occupied by " << s1.top()->reservation.guestName << "(Duration: " << s1.top()->reservation.duration << " Days )";
				s1.pop();
				cout << endl;
			}
		}

		
		cout << endl;

	

}

Room* addsortedroom(Room* head, Room* n) {//to add rooms ascending
	Room* p1;
	Room* p2;
	p1 = p2 = head;
	while (p1 != NULL)
	{
		if (n->reservation.roomNumber < head->reservation.roomNumber) {//first room
		
			n->roomNext = head;
			return n;
		}
		else
		{
			p1 = p2;
			p2 = p2->roomNext;
			if (n->reservation.roomNumber < p2->reservation.roomNumber) {
			
				p1->roomNext = n;
				n->roomNext = p2;
				return head;
			}

		}
		
		
		
	}

	p1->roomNext = n;
	n->roomNext = NULL;
	return head;
}
