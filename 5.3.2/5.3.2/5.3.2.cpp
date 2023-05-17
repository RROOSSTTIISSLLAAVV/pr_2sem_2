
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	void add(int n);
	void cancel(int n);
	void set_reserved(int n);
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus() // Вывод информации о занятых местах
{
	double percent = 0;
	if (this != nullptr)
	{
		percent = 100.0 * ((double)this->reserved / this->capacity); 
		printf("Flight %d: %d/%d (%d%%) seats taken\n", this->id, this->reserved, this->capacity, (int)percent);
	}
}

void FlightBooking::set_reserved(int reserved)
{
	if (reserved < 0) 
	{
		cout << "Cannot perform this operation \n";
		this->reserved = 0;
	}
	else if ((double)reserved / this->capacity > 1.05) 
	{
		cout << "Cannot perform this operation \n";
		this->reserved = (int)this->capacity * 1.05;
	}
	else
		this->reserved = reserved;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
		this->id = id;
		this->capacity = capacity;
		this->set_reserved(reserved);
}
void FlightBooking::add(int n)
{
	if (n > 0)
	{
		this->set_reserved(this->reserved + n);
	}
	else cout << "\nError number \n";
}
void FlightBooking::cancel(int n)
{
	if (n > 0)
	{
	this->set_reserved(this->reserved - n);
	}
	else cout << "\nError number \n";
}


int main() {

	int capacity = 0, reserved = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	string command;
	booking.printStatus();
	while (true)
	{
		cout << "Enter a command: ";
		cin >> command;
		if (command == "quit")
			break;
		int numb;
		if (command == "add")
		{
			cout << "Enter the number: ";
			cin >> numb;
			booking.add(numb);
			booking.printStatus();
		}
		else if (command == "cancel")
		{
			cout << "Enter the number: ";
			cin >> numb;
			booking.cancel(numb);
			booking.printStatus();
		}
		else
		{
			cout << "\nundefined\n";
		}
	}

	return 0;
}


