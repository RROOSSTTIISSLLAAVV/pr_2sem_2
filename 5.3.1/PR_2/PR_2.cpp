
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();

private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	double percent = 0;
	if (this != nullptr)
	{
		percent = 100.0 * ((double)this->reserved / this->capacity);
		printf("Flight %d: %d/%d (%d%%) seats taken", this->id, this->reserved, this->capacity, (int)percent);
	}
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}


int main() {

	int reserved = 0,
		capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();





	return 0;
}


