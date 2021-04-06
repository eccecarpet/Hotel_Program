#include<iostream>
#include <string>
#include<fstream>

using namespace std;



void showMenu(); //function to display menu
void roomsAvailable(int rooms_available, string hotel_rooms[]); // function to initialise room
void addNewCustomer(string customer_name, string hotel_rooms[], int new_customer_room); //funcion add new customer
string getCustomer(string hotel_rooms[], int num_room); // get customer data
void emptyRooms(string hotel_rooms[]); //function empty room
void printStatus(string hotel_rooms[]); // see status of the rooms
void displayEmptyRooms(string hotel_rooms[]); //display empty rooms
void deleteCustomer(string hotel_rooms[], string customer_name); // delete a customer 
void findCustomer(string hotel_rooms[], string customer_name); //find a customer
void storeFile(string hotel_rooms[]); // store file
void loadFile();// load file
void alphabeticalOrder(string hotel_rooms[]); //display customer in alphabetical order

struct Hotel {

	string hotel_rooms[10];
	string customer_name;
	int new_customer_room;
	int rooms_available = {};


};



int main()
{

	char continue_menu = ' ';
	char menu;

	Hotel myHotel{};



	do
	{
		showMenu();
		cin >> menu;
		switch (menu)
		{
		case'I':case 'i':
			emptyRooms(myHotel.hotel_rooms);
			break;
		case'A':case'a':
			printStatus(myHotel.hotel_rooms);
			cout << endl;
			roomsAvailable(myHotel.rooms_available, myHotel.hotel_rooms);
			cout << endl << "Please introduce number of the room and the customer." << endl;
			cout << "Customer room: ";
			cin >> myHotel.new_customer_room;
			cout << "Customer name: ";
			cin >> myHotel.customer_name;
			addNewCustomer(myHotel.customer_name, myHotel.hotel_rooms, myHotel.new_customer_room);
			cout << endl;
			printStatus(myHotel.hotel_rooms);
			break;
		case'V':case'v':
			printStatus(myHotel.hotel_rooms);
			break;
		case'E':case'e':
			displayEmptyRooms(myHotel.hotel_rooms);
			break;
		case'D':case'd':
			printStatus(myHotel.hotel_rooms);
			cout << endl << "Please introduce the customer name that you want to delete: ";
			cin >> myHotel.customer_name;
			deleteCustomer(myHotel.hotel_rooms, myHotel.customer_name);
			cout << endl;
			printStatus(myHotel.hotel_rooms);
			break;
		case'F':case'f':
			printStatus(myHotel.hotel_rooms);
			cout << endl << "Please introduce the customer name to check which room: ";
			cin >> myHotel.customer_name;
			findCustomer(myHotel.hotel_rooms, myHotel.customer_name);
			break;
		case'S':case's':
			storeFile(myHotel.hotel_rooms);
			break;
		case'L':case'l':
			loadFile();
			break;
		case'O':case'o':
			printStatus(myHotel.hotel_rooms);
			cout << endl << "Alphabetical Order: " << endl;
			alphabeticalOrder(myHotel.hotel_rooms);

			break;
		default:
			cout << menu << " Character not valid.Please try again." << endl;
			break;
		}
		cout << endl << "Do you want to continue? Press Yes(Y) or No(N): ";

		cin >> continue_menu;

	} while (continue_menu == 'Y' || continue_menu == 'y');

	return 0;
}


void showMenu()
{
	cout << "Select a character: " << endl;
	cout << "Press 'I' to initialise Rooms " << endl;
	cout << "Press 'A' to add a new customer " << endl;
	cout << "Press 'V' to view all rooms" << endl;
	cout << "Press 'E' to display empty room" << endl;
	cout << "Press 'D' to delete customer from room " << endl;
	cout << "Press 'F' to find room by customer name " << endl;
	cout << "Press 'S' to store data into file" << endl;
	cout << "Press 'L' to load data from file" << endl;
	cout << "Press 'O' to view all rooms ordered alphabetically by the main customer's name data into file " << endl;
	cout << "Thank you!" << endl << endl;
	cout << "Please Introduce a Character: ";
}

void roomsAvailable(int rooms_available, string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		if (hotel_rooms[i] == "e")
		{
			rooms_available++;
			cout << "Room " << i + 1 << " is available!" << endl;
		}
		else
			cout << "Room " << i + 1 << " is not available. Sorry." << endl;

	}
	if (rooms_available == 0)
		cout << "Sorry, there is no available rooms." << endl;

}



void addNewCustomer(string customer_name, string hotel_rooms[], int new_customer_room)
{
	if ((hotel_rooms[new_customer_room - 1] != "e") || ((new_customer_room > 10) && (new_customer_room < 1)))

		cout << "Room not available. Please try again." << endl;
	else
		hotel_rooms[new_customer_room - 1] = customer_name;
}




string getCustomer(string hotel_rooms[], int num_room)
{
	string customer_name = " ";
	for (int i = 0; i < 10; i++)
	{
		if (i == num_room && hotel_rooms[i] != "e")
		{
			customer_name = hotel_rooms[i];
		}
	}
	return customer_name;
}


void emptyRooms(string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		hotel_rooms[i] = "e";
		cout << "Room - " << i + 1 << " -> " << hotel_rooms[i] << endl;
	}

}


void printStatus(string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Room - " << i + 1 << " -> " << hotel_rooms[i] << endl;
	}
}


void displayEmptyRooms(string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		if (hotel_rooms[i] == "e")
		{
			cout << "Room - " << i + 1 << " -> " << hotel_rooms[i] << endl;
		}
	}
}


void deleteCustomer(string hotel_rooms[], string customer_name)
{
	int i = 0;
	bool find = false;
	while (!find && i < 10)
	{
		if (hotel_rooms[i] == customer_name)
		{
			hotel_rooms[i] = "e";
			find = true;
		}
		else if (i == 9 && find == false)
			cout << endl << "Customer doesn't exist on our hotel. Please search existent customer." << endl;

		i++;

	}
}


void findCustomer(string hotel_rooms[], string customer_name)
{
	int i = 0;
	bool find = false;
	while (!find && i < 10)
	{
		if (hotel_rooms[i] == customer_name)
		{
			cout << endl << "Room - " << i + 1 << " --> " << hotel_rooms[i] << endl;
			find = true;
		}
		else if (i == 9 && find == false)
			cout << endl << "Customer doesn't exist in our hotel. Please introduce a existent customer." << endl;

		i++;

	}

}



void storeFile(string hotel_rooms[])
{
	ofstream myfile;
	myfile.open("rooms.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << "Room - " << i + 1 << " --> " << hotel_rooms[i] << endl;

	}
	myfile.close();
}



void loadFile()
{
	string s;
	ifstream myfile;
	myfile.open("rooms.txt");
	while (getline(myfile, s))
	{
		cout << s << endl;
	}
	myfile.close();
}




void alphabeticalOrder(string hotel_rooms[])
{
	string temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (hotel_rooms[j] < hotel_rooms[i])
			{
				temp = hotel_rooms[i];
				hotel_rooms[i] = hotel_rooms[j];
				hotel_rooms[j] = temp;
			}
		}
		cout << hotel_rooms[i] << endl;
	}
}



/* #include<iostream>
#include <string>
#include<fstream>

using namespace std;

void showMenu();
void roomsAvailable(int rooms_available, string hotel_rooms[]);
void addNewCustomer(string customer_name, string hotel_rooms[], int new_customer_room);
string getCustomer(string hotel_rooms[], int num_room);
void emptyRooms(string hotel_rooms[]);
void printStatus(string hotel_rooms[]);
void displayEmptyRooms(string hotel_rooms[]);
void deleteCustomer(string hotel_rooms[], string customer_name);
void findCustomer(string hotel_rooms[], string customer_name);
void storeFile(string hotel_rooms[]);
void loadFile();
void alphabeticalOrder(string hotel_rooms[]);


int main()
{

	string hotel_rooms[10];
	string customer_name;
	int new_customer_room;
	int rooms_available = {};
	char continue_menu = ' ';
	char menu;


	do
	{
		showMenu();
		cin >> menu;
		switch (menu)
		{
		case'I':case 'i':
			emptyRooms(hotel_rooms);
			break;
		case'A':case'a':
			printStatus(hotel_rooms);
			cout << endl;
			roomsAvailable(rooms_available, hotel_rooms);
			cout << endl << "Please introduce number of the room and the customer." << endl;
			cout << "Customer room: ";
			cin >> new_customer_room;
			cout << "Customer name: ";
			cin >> customer_name;
			addNewCustomer(customer_name, hotel_rooms, new_customer_room);
			cout << endl;
			printStatus(hotel_rooms);
			break;
		case'V':case'v':
			printStatus(hotel_rooms);
			break;
		case'E':case'e':
			displayEmptyRooms(hotel_rooms);
			break;
		case'D':case'd':
			printStatus(hotel_rooms);
			cout << endl << "Please introduce the customer name that you want to delete: ";
			cin >> customer_name;
			deleteCustomer(hotel_rooms, customer_name);
			cout << endl;
			printStatus(hotel_rooms);
			break;
		case'F':case'f':
			printStatus(hotel_rooms);
			cout << endl << "Please introduce the customer name to check which room: ";
			cin >> customer_name;
			findCustomer(hotel_rooms, customer_name);
			break;
		case'S':case's':
			storeFile(hotel_rooms);
			break;
		case'L':case'l':
			loadFile();
			break;
		case'O':case'o':
			printStatus(hotel_rooms);
			cout << endl << "Alphabetical Order: " << endl;
			alphabeticalOrder(hotel_rooms);

			break;
		default:
			cout << menu << " Character not valid.Please try again." << endl;
			break;
		}
		cout << endl << "Do you want to continue? Press Yes(Y) or No(N): ";

		cin >> continue_menu;

	} while (continue_menu == 'Y' || continue_menu == 'y');

	return 0;
}


void showMenu()
{
	cout << "Select a character: " << endl;
	cout << "Press 'I' to initialise Rooms " << endl;
	cout << "Press 'A' to add a new customer " << endl;
	cout << "Press 'V' to view all rooms" << endl;
	cout << "Press 'E' to display empty room" << endl;
	cout << "Press 'D' to delete customer from room " << endl;
	cout << "Press 'F' to find room by customer name " << endl;
	cout << "Press 'S' to store data into file" << endl;
	cout << "Press 'L' to load data from file" << endl;
	cout << "Press 'O' to view all rooms ordered alphabetically by the main customer's name data into file " << endl;
	cout << "Thank you!" << endl << endl;
	cout << "Please Introduce a Character: ";
}

void roomsAvailable(int rooms_available, string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		if (hotel_rooms[i] == "e")
		{
			rooms_available++;
			cout << "Room " << i + 1 << " is available!" << endl;
		}
		else
			cout << "Room " << i + 1 << " is not available. Sorry." << endl;

	}
	if (rooms_available == 0)
		cout << "Sorry, there is no available rooms." << endl;

}



void addNewCustomer(string customer_name, string hotel_rooms[], int new_customer_room)
{
	if ((hotel_rooms[new_customer_room - 1] != "e") || ((new_customer_room > 10) && (new_customer_room < 1)))

		cout << "Room not available. Please try again." << endl;
	else
		hotel_rooms[new_customer_room - 1] = customer_name;
}




string getCustomer(string hotel_rooms[], int num_room)
{
	string customer_name = " ";
	for (int i = 0; i < 10; i++)
	{
		if (i == num_room && hotel_rooms[i] != "e")
		{
			customer_name = hotel_rooms[i];
		}
	}
	return customer_name;
}


void emptyRooms(string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		hotel_rooms[i] = "e";
		cout << "Room - " << i + 1 << " -> " << hotel_rooms[i] << endl;
	}

}


void printStatus(string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Room - " << i + 1 << " -> " << hotel_rooms[i] << endl;
	}
}


void displayEmptyRooms(string hotel_rooms[])
{
	for (int i = 0; i < 10; i++)
	{
		if (hotel_rooms[i] == "e")
		{
			cout << "Room - " << i + 1 << " -> " << hotel_rooms[i] << endl;
		}
	}
}


void deleteCustomer(string hotel_rooms[], string customer_name)
{
	int i = 0;
	bool find = false;
	while (!find && i < 10)
	{
		if (hotel_rooms[i] == customer_name)
		{
			hotel_rooms[i] = "e";
			find = true;
		}
		else if (i == 9 && find == false)
			cout << endl << "Customer doesn't exist on our hotel. Please search existent customer." << endl;

		i++;

	}
}


void findCustomer(string hotel_rooms[], string customer_name)
{
	int i = 0;
	bool find = false;
	while (!find && i < 10)
	{
		if (hotel_rooms[i] == customer_name)
		{
			cout << endl << "Room - " << i + 1 << " --> " << hotel_rooms[i] << endl;
			find = true;
		}
		else if (i == 9 && find == false)
			cout << endl << "Customer doesn't exist in our hotel. Please introduce a existent customer." << endl;

		i++;

	}

}



void storeFile(string hotel_rooms[])
{
	ofstream myfile;
	myfile.open("rooms.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << "Room - " << i + 1 << " --> " << hotel_rooms[i] << endl;

	}
	myfile.close();
}



void loadFile()
{
	string s;
	ifstream myfile;
	myfile.open("rooms.txt");
	while (getline(myfile, s) )
	{
		cout << s << endl;
	}
	myfile.close();
}




void alphabeticalOrder(string hotel_rooms[])
{
	string temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (hotel_rooms[j] < hotel_rooms[i])
			{
				temp = hotel_rooms[i];
				hotel_rooms[i] = hotel_rooms[j];
				hotel_rooms[j] = temp;
			}
		}
		cout << hotel_rooms[i] << endl;
	}
}

//end plain program version







*/