 
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//initialise functions and pass paramethers

void showMenu(); //function to display menu
void roomsAvailable(int roomAvailable, string hotelRooms[]); // function to initialise room
void enterNewCustomer(string customerName, string hotelRooms[], int newCustomerRoom); //funcion add new customer
string getCustomer(string hotelRooms[], int nRoom); // get customer data
void emptyRooms(string hotelRooms[]); //function empty room
void printStatus(string hotelRooms[]); // see status of the rooms
void displayEmptyRooms(string hotelRooms[]); //display empty rooms
void deleteCustomer(string hotelRooms[], string customerName); // delete a customer 
void findCustomer(string hotelRooms[], string customerName); //find a customer
void storeFile(string hotelRooms[]); // store file
void loadFile();// load file
void alphabeticalOrder(string hotelRooms[]); //display customer in alphabetical order

struct Hotel {

	string hotelRooms[10];
	string customerName;
	int newCustomerRoom;
	int roomsAvailable = {};


};



int main()
{

	char backtoMenu = ' ';
	char Menu;

	Hotel myHotel{}; // struct



	do
	{
		showMenu();
		cin >> Menu;
		switch (Menu)
		{
		case'I':case 'i':
			emptyRooms(myHotel.hotelRooms);
			break;
		case'A':case'a':
			printStatus(myHotel.hotelRooms);
			cout << endl;
			roomsAvailable(myHotel.roomsAvailable, myHotel.hotelRooms);
			cout << endl << "Please introduce number of the room and the customer." << endl;
			cout << "Customer room: ";
			cin >> myHotel.newCustomerRoom;
			cout << "Customer name: ";
			cin >> myHotel.customerName;
			enterNewCustomer(myHotel.customerName, myHotel.hotelRooms, myHotel.newCustomerRoom);
			cout << endl;
			printStatus(myHotel.hotelRooms);
			break;
		case'V':case'v':
			printStatus(myHotel.hotelRooms);
			break;
		case'E':case'e':
			displayEmptyRooms(myHotel.hotelRooms);
			break;
		case'D':case'd':
			printStatus(myHotel.hotelRooms);
			cout << endl << "Please introduce the customer name that you want to delete: ";
			cin >> myHotel.customerName;
			deleteCustomer(myHotel.hotelRooms, myHotel.customerName);
			cout << endl;
			printStatus(myHotel.hotelRooms);
			break;
		case'F':case'f':
			printStatus(myHotel.hotelRooms);
			cout << endl << "Please introduce the customer name to check which room: ";
			cin >> myHotel.customerName;
			findCustomer(myHotel.hotelRooms, myHotel.customerName);
			break;
		case'S':case's':
			storeFile(myHotel.hotelRooms);
			break;
		case'L':case'l':
			loadFile();
			break;
		case'O':case'o':
			printStatus(myHotel.hotelRooms);
			cout << endl << "Alphabetical Order: " << endl;
			alphabeticalOrder(myHotel.hotelRooms);

			break;
		default:
			cout << Menu << " Character not valid. Please try again." << endl;
			break;
		}
		cout << endl << "Do you want to continue? Press Yes(Y) or No(N): ";

		cin >> backtoMenu;

	} while (backtoMenu == 'Y' || backtoMenu == 'y');

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


// once the menu is displayed the user will be asked to select a choice. each choice will run the code within the function which describe the user request
void roomsAvailable(int rooms_available, string hotel_rooms[]) //initialise rooms
{
	for (int i = 0; i < 10; i++)
	{
		if (hotel_rooms[i] == "e") //if each room is empty store 'e'
		{
			rooms_available++;
			cout << "Room " << i + 1 << " is available!" << endl; //rooms_availble, i++ same as i+1
		}
		else
			cout << "Room " << i + 1 << " is not available. Sorry." << endl;

	}
	if (rooms_available == 0) // rooms are all busy, meaning the user stored data in each element of the array so no room is available 
		cout << "Sorry, there is no available rooms." << endl;

}



void enterNewCustomer(string customerName, string hotelRooms[], int newCustomerRoom) // function to add new customer into room
{
	if ((hotelRooms[newCustomerRoom - 1] != "e") || ((newCustomerRoom > 10) && (newCustomerRoom < 1))) //if each new customer room has not been initialised add new customer name

		cout << "Room not available. Please try again." << endl;
	else
		hotelRooms[newCustomerRoom - 1] = customerName;
}




string getCustomer(string hotelRooms[], int nRoom) // store data customer into room 
{
	string customer_name = " ";
	for (int i = 0; i < 10; i++) //go through each element of array 
	{
		if (i == nRoom && hotelRooms[i] != "e") // if room has not been initialised, store customer name in it
		{
			customer_name = hotelRooms[i];
		}
	}
	return customer_name;
}


void emptyRooms(string hotelRooms[]) //empty room 
{
	for (int i = 0; i < 10; i++) // go through each room
	{
		hotelRooms[i] = "e";
		cout << "Room - " << i + 1 << " -> " << hotelRooms[i] << endl;
	}

}


void printStatus(string hotelRooms[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Room - " << i + 1 << " -> " << hotelRooms[i] << endl;
	}
}


void displayEmptyRooms(string hotelRooms[])
{
	for (int i = 0; i < 10; i++)
	{
		if (hotelRooms[i] == "e")
		{
			cout << "Room - " << i + 1 << " -> " << hotelRooms[i] << endl;
		}
	}
}


void deleteCustomer(string hotelRooms[], string customerName)
{
	int i = 0;
	bool find = false;
	while (!find && i < 10)
	{
		if (hotelRooms[i] == customerName)
		{
			hotelRooms[i] = "e";
			find = true;
		}
		else if (i == 9 && find == false)
			cout << endl << "Customer doesn't exist on our hotel. Please search existent customer." << endl;

		i++;

	}
}


void findCustomer(string hotelRooms[], string customerName)
{
	int i = 0;
	bool find = false;
	while (!find && i < 10)
	{
		if (hotelRooms[i] == customerName)
		{
			cout << endl << "Room - " << i + 1 << " --> " << hotelRooms[i] << endl;
			find = true;
		}
		else if (i == 9 && find == false)
			cout << endl << "Customer doesn't exist in our hotel. Please introduce an existent customer." << endl;

		i++;

	}

}



void storeFile(string hotelRooms[])
{
	ofstream myfile;
	myfile.open("rooms.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << "Room - " << i + 1 << " --> " << hotelRooms[i] << endl;

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




void alphabeticalOrder(string hotelRooms[])
{
	string temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (hotelRooms[j] < hotelRooms[i])
			{
				temp = hotelRooms[i];
				hotelRooms[i] = hotelRooms[j];
				hotelRooms[j] = temp;
			}
		}
		cout << hotelRooms[i] << endl;
	}
}
