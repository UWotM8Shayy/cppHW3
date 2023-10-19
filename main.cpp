

#include <iostream>
#include "Trip.h"
using namespace std;

bool IsEmpty(int size);
void Print(Trip* arr, int size);
void EditTrip(Trip* arr, int size);
Trip* AddTrip(Trip* arr, int size);

void main()
{
	int option;
	Trip* arr = new Trip[0];
	int size = 0;
	do
	{
		cout << "Please Select an Option : \n1. Print Trips \n2. Edit Trip \n3. Add Trip \n4. Exit" << endl;;
		cin >> option;
		switch (option)
		{
		case 1:
			Print(arr, size);
			break;
		case 2:
			EditTrip(arr, size);
			break;
		case 3:
			arr = AddTrip(arr, size);
			size++;
			break;
		case 4:
			cout << "bye bye!" << endl;
			break;
		default:
			cout << "invalid option" << endl;
			break;
		}
		


	} while (option != 4);
}

bool isEmpty(int size)
{
	return size == 0;
}


void Print(Trip* arr, int size) {
	if (isEmpty(size)) {
		cout << "No trips to display." << endl;
		return;
	}

	for (int i = 0; i < size; ++i) {
		cout << "Trip " << i + 1 << ":" << endl;
		arr[i].printTrip();
		cout << endl;
	}
}

void EditTrip(Trip* arr, int size) {
	if (isEmpty(size)) {
		cout << "No trips to edit." << endl;
		return;
	}

	int tripNumber;
	cout << "Enter the trip number you want to edit: ";
	cin >> tripNumber;

	bool found = false;
	int tripIndex = -1;

	for (int i = 0; i < size; ++i) {
		if (arr[i].getTripNumber() == tripNumber) {
			found = true;
			tripIndex = i;
			break;
		}
	}

	if (found) {
		int choice;
		do {
			cout << "Editing Trip " << tripNumber << ":" << endl;
			cout << "1. Edit Trip Number\n2. Edit Destination\n3. Edit Date\n4. Back to Main Menu\n";
			cin >> choice;

			switch (choice) {
			case 1: {
				int newTripNumber;
				cout << "Enter new trip number: ";
				cin >> newTripNumber;
				arr[tripIndex].setTripNumber(newTripNumber);
				cout << "Trip number updated." << endl;
				break;
			}
			case 2: {
				cin.ignore(); 
				string newDestination;
				cout << "Enter new destination: ";
				getline(cin, newDestination);
				arr[tripIndex].setDestination(newDestination);
				cout << "Destination updated." << endl;
				break;
			}
			case 3: {
				int newDay, newMonth, newYear;
				cout << "Enter new date (day month year): ";
				cin >> newDay >> newMonth >> newYear;
				Date newDate(newDay, newMonth, newYear);
				arr[tripIndex].setDate(newDate);
				cout << "Date updated." << endl;
				break;
			}
			case 4:
				break;
			default:
				cout << "Invalid choice." << endl;
			}

		} while (choice != 4);
	}
	else {
		cout << "Trip number not found." << endl;
	}
}







Trip* AddTrip(Trip* arr, int size) {
	int tripNumber;
	string destination;
	Date date;

	cout << "Enter trip number: ";
	cin >> tripNumber;

	cin.ignore();
	cout << "Enter destination: ";
	getline(cin, destination);

	int day, month, year;
	cout << "Enter date (day month year): ";
	cin >> day >> month >> year;
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);

	
	Trip newTrip(tripNumber, destination, date);

	
	Trip* newArr = new Trip[size + 1];
	for (int i = 0; i < size; ++i) {
		newArr[i] = arr[i];
	}
	newArr[size] = newTrip;

	delete[] arr; 
	return newArr; 
}
