#include "pch.h"
#include "flight.h"

flight::flight()
{
}

flight::flight(int hour)
	:take_off_time(hour)
{
}

void flight::setTime(int hour)
{
	take_off_time = hour;
}

void flight::rename(const flightName newName)
{
	name = newName;
}

bool flight::isAviliable(seatType type)
{
	for (int i = 0; i < 5; i++)
	{
		int c = i + (type - 1) * 5;
		if (seats_status[c] == 0)
			return true;
	}
	return false;
}

bool flight::orderSeat(int seatNum)
{
	if (seats_status[seatNum - 1] == 0)
	{
		seats_status[seatNum - 1] = 1;
		left_seats--;
		return true;
	}
	return false;

}

bool flight::cancelOrder(int seatNum)
{
	if (seats_status[seatNum - 1] == 0)
		return false;
	else if (seats_status[seatNum - 1] == 1)
	{
		seats_status[seatNum - 1] = 0;
		left_seats++;
		return true;
	}
	return false;
}

void flight::printBoardingPass(int seatNum)
{
	using namespace std;
	for (int i = 0; i < 25; i++)
		cout << "_";
	cout << endl;
	cout << "|\t\t\t|" << endl;
	cout << (seatNum < 5 ? "|\tfirst class\t|": "|  \tcoach\t\t|") << endl;
	cout << "|\tseat number: " << seatNum << "\t|" << endl;
	cout << "|";
	for (int i = 0; i < 23; i++)
		cout << "_";
	cout << "|" << endl;
}

void flight::printBoardingPass()
{
	for (int i = 0; i < 10; i++)
	{
		if (seats_status[i] == 1)
		{
			printBoardingPass(i + 1);
			std::cout << "\n";
		}
	}
}

void flight::printSeatStatus(ostream &out)
{
	using namespace std;
	out << "-----" << name << "-----" << endl;
	out << "take off time: " << take_off_time << endl;
	int seats = 0;
	for (int i = 0; i < 10; i++)
	{
		if (seats_status[i] == 0)
			seats++;
	}
	out << seats << " seat(s) aviliable. " << endl;

	if (isAviliable(first_class))
	{
		int first = 0;
		for (int i = 0; i < 5; i++)
		{
			if (seats_status[i] == 0)
				first++;
		}
		out << first << " first-class seat(s) aviliable. " << endl;
	}
	else
		out << "No first-class seat aviliable. " << endl;

	if (isAviliable(economy))
	{
		int econ = 0;
		for (int i = 5; i < 10; i++)
		{
			if (seats_status[i] == 0)
				econ++;
		}
		out << econ << " economy seat(s) aviliable. " << endl;
	}
	else
		out << "No economy seat aviliable. " << endl;
}

bool flight::seatStatus(int seatNum)
{
	if (seats_status[seatNum-1] == 0)
	{
		return true;
	}
	return false;
}


flight::~flight()
{
}

orderSystem::orderSystem()
{
}

orderSystem::orderSystem(int flightn, int beginTime, int emptyHour)
	:flightNum(flightn),flights(flightn)
{
	for (int i = 0; i < flightNum; i++)
	{
		(flights.data() + i)->setTime(beginTime + i * emptyHour);
		(flights.data() + i)->rename(flightName(i));
	}
}

int orderSystem::flightExist(flightName name)
{
	for (int i = 0; i < flightNum; i++)
	{
		if (flights[i].name == name)
			return i;
	}
	return -1;
}

flightName orderSystem::chooseFlight(ostream & out, istream & in)
{
	flightName choice;
	out << "Choose a flight by typing in a flight number: ";
	in >> choice;
	if (flightExist(choice)==-1)
	{
		out << "No such flight " << choice << " exist. " << endl;
		choice = chooseFlight(out, in);
		return choice;
	}

	if (flights[flightExist(choice)].isAviliable(economy) || flights[flightExist(choice)].isAviliable(first_class))
	{
		out << "Flight " << choice << " selected. " << endl;
		out << flights[flightExist(choice)];
		return choice;
	}
	else
	{
		out << "Flight " << choice << " is all booked. " << endl;
		bool willChange = like_to_change("Would you like to change another flight? (Y/n)", out, in);
		if (willChange)
		{
			choice = chooseFlight(out, in);
			return choice;
		}
		else
		{
			return errorFlag;
		}
	}
}

int orderSystem::chooseSeat(flight &selectedFlight, ostream & out, istream & in)
{
	out << "Please input a seat type (1 for first class, 2 for economy): " << endl;
	seatType selectedType;
	in >> selectedType;
	if (selectedFlight.isAviliable(selectedType) == false)
	{
		out << "Current seat type's all been booked. \n";
		bool willChange = like_to_change("Would you like to change? (Y/n)", out, in);
		if (willChange)
		{
			selectedType = !selectedType;
		}
		else
		{
			return -1;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (selectedFlight.seatStatus(i + 1 + (selectedType - 1) * 5))
		{
			return i + 1;
		}
	}

	out << "This flight's all been booked. \n";
	return -1;
}

int orderSystem::bookSeat(ostream & out, istream &in)
{
	flightName selectedFlightNumber = chooseFlight(out, in);

	if (selectedFlightNumber == errorFlag)
		return -1;

	flight & selectedFlight = flights[flightExist(selectedFlightNumber)];
	int selectedSeat = chooseSeat(selectedFlight, out, in);

	if (selectedSeat == -1)
		return -1;

	selectedFlight.orderSeat(selectedSeat);
	selectedFlight.printBoardingPass(selectedSeat);
	return 0;
}

void orderSystem::printFlightStatus(flightName name, ostream & out)
{
	out << flights[name];
}

void orderSystem::printFlightStatus(ostream & out)
{
	for (int i = 0; i < flightNum; i++)
	{
		//printFlightStatus(out, flightName(i));
		out << this->flights[i];
	}
}

int orderSystem::DEBUG()
{
	/*
	for (int i = 0; i < 10; i++)
	{
		this->flights[0].orderSeat(i + 1);
	}
	*/
	while (1)
	{
		this->bookSeat();
	}
	return 0;
}

int orderSystem::system_begin(ostream & out, istream & in)
{
	out << "______________________________\nWelcome to flight order system. \n";
	out << *this;
	while (1) 
	{
		this->bookSeat(out, in);
	}
	return 0;
}

orderSystem::~orderSystem()
{
}

bool like_to_change(const string & msg, ostream & out, istream & in)
{
	out << msg << endl;
	char choice;
	in >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		return true;
	}
	else if (choice == 'n' || choice == 'N')
	{
		return false;
	}
	return like_to_change(msg, out, in);
}

seatType operator!(seatType type)
{
	switch (type)
	{
	case first_class:
		return economy;
	case economy:
		return first_class;
	default:
		return errorType;
	}
}

ostream & operator<<(ostream & out, seatType & type)
{
	switch (type)
	{
	case first_class:
		out << "first class";
		break;
	case economy:
		out << "economy";
		break;
	default:
		break;
	}
	// TODO: 在此处插入 return 语句
	return out;
}

istream & operator>>(istream & in, seatType & type)
{
	int input;
	in >> input;
	switch (input)
	{
	case 1:
		type = first_class;
		break;
	case 2:
		type = economy;
		break;
	default:
		cout << "!!!INPUT SEAT TYPE ERROR!!!\n";
		cout << "Please type in again. " << endl;
		in >> type;
		break;
	}
	// TODO: 在此处插入 return 语句
	return in;
}

ostream & operator<<(ostream & out, flightName & name)
{
	out << char('A' + name);
	// TODO: 在此处插入 return 语句
	return out;
}

istream & operator>>(istream & in, flightName & name)
{
	char input;
	in >> input;
	if (input >= 'A' && input <= 'Z')
	{
		name = flightName(input - 'A');
	}
	else if (input >= 'a'&& input <= 'z')
	{
		name = flightName(input - 'a');
	}
	else
	{
		cout << "!!!INPUT ERROR!!!\n" << "NO SUCH FLIGHT NUMBER" << endl;
		cout << "PLEASE TYPE IN AGAIN\n";
		in >> name;
	}
	// TODO: 在此处插入 return 语句
	return in;
}

ostream & operator<<(ostream & out, flight & obj)
{
	using namespace std;
	obj.printSeatStatus(out);
	// TODO: 在此处插入 return 语句
	return out;
}

ostream & operator<<(ostream & out, orderSystem & system)
{
	system.printFlightStatus(out);
	// TODO: 在此处插入 return 语句
	return out;
}
