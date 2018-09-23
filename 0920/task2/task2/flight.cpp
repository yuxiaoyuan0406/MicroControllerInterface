/*
 * Author:	Yu Xiaoyuan
 * Time:	2018-9-23 22:36:46
 * Email:	yuxiaoyuan0406@hotmail.com
*/

#include "pch.h"
#include "flight.h"

flight::flight()
{
}

flight::flight(int hour)
	:take_off_time(hour)//��ʼ�����ʱ��
						//���ڴ�ӡ�ǻ���
{
}

void flight::setTime(int hour)
{
	//�����������ʱ��
	take_off_time = hour;
}

void flight::rename(const flightName newName)
{
	//���ĺ����
	name = newName;
}

bool flight::isAviliable(seatType type)
{	//�����������λ�����ж��Ƿ�����			/************************************************/
	for (int i = 0; i < 5; i++)				/*		����i��ֵΪ5����Ϊÿ����λֻ�����		*/
	{										/*												*/
		int c = i + (type - 1) * 5;			/*		��λ�����ж�Ӧ���������ֿ��Լ���			*/
		if (seats_status[c] == 0)			/*		��λ״̬Ϊ0��δ��Ԥ��						*/
			return true;					/*		ֻҪ��һ����λ״̬Ϊ0�򷵻���				*/	
	}										/*		����������ؼ�, Ҳ���Ƕ�Ϊ1���ؼ�			*/
	return false;							/************************************************/
}

bool flight::orderSeat(int seatNum)
{	//Ԥ��������λ�ŵ���λ					/********************************************************/
	if (seats_status[seatNum - 1] == 0)		/*		��λ�ŷ�Χ��1~10									*/
	{										/*		�������Ų�ͬ									*/
		seats_status[seatNum - 1] = 1;		/*		�����ں���ʹ�õ�ʱ��Ҫ�ر�ע��					*/
		left_seats--;						/*		�����λ״̬Ϊ0, ���Ϊ1, ������һ��ʣ����λ		*/
		return true;						/*		�޸���󷵻���									*/
	}										/*		����λ�ѱ�Ԥ���򷵻ؼ�							*/
	return false;							/********************************************************/

}

bool flight::cancelOrder(int seatNum)
{	//ȡ����λԤ��
	//������δʹ��, �����ں������ӹ���
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

void flight::printBoardingPass(int seatNum, ostream & out)
{	//��ӡ�ǻ���
	using namespace std;
	for (int i = 0; i < 25; i++)
		out << "_";																//����߿�
	out << endl;
	out << "|\t\t\t|" << endl;													//���һ������, ����
	out << "|\tFlight Number: " << this->name << "\t|" << endl;					//��������
	out << (seatNum < 5 ? "|\tfirst class\t|": "|  \tcoach\t\t|") << endl;		//�����λ����
	out << "|\tseat number: " << seatNum << "\t|" << endl;						//�����λ��
	out << "|";
	for (int i = 0; i < 23; i++)
		out << "_";
	out << "|" << endl;
}

void flight::printBoardingPass(ostream & out)	//û�и�����λ����Ϣ���ӡ�����ѱ�Ԥ���ĵǻ���
{	//��ӡ�ǻ���
	//������ϵͳ����δ����
	for (int i = 0; i < 10; i++)
	{
		if (seats_status[i] == 1)
		{
			printBoardingPass(i + 1, out);
			std::cout << "\n";
		}
	}
}

void flight::printSeatStatus(ostream &out)
{	//���������λ״̬
	using namespace std;
	out << "-----" << name << "-----" << endl;			//����������
	out << "take off time: " << take_off_time << endl;	//Ȼ��������ʱ��
	int seats = 0;										//����һ��������λ�ı���, ʵ���Ͽ�����flight::left_seats����
	for (int i = 0; i < 10; i++)						//����������һ��
	{													//��ʵӦ�öԱ�һ��
		if (seats_status[i] == 0)
			seats++;
	}
	out << seats << " seat(s) aviliable. " << endl;

	if (isAviliable(first_class))
	{
		int first = 0;									//������һ���м���ͷ�Ȳ���λ
		for (int i = 0; i < 5; i++)
		{
			if (seats_status[i] == 0)
				first++;
		}
		out << first << " first-class seat(s) aviliable. " << endl;
	}
	else												//û�о����û��
		out << "No first-class seat aviliable. " << endl;

	if (isAviliable(economy))
	{
		int econ = 0;									//����ͬ��
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

bool flight::seatStatus(int seatNum)					//�жϵ�����λ��״̬
{	//��λ�����������в���, ��ע��
	if (seats_status[seatNum-1] == 0)
	{
		return true;
	}
	return false;
}


flight::~flight()
{	//�յ���������
}

orderSystem::orderSystem()
{	//�յĹ��캯��
}

orderSystem::orderSystem(int flightn, int beginTime, int emptyHour)
	:flightNum(flightn),flights(flightn)
	//��ʼ���˷ɻ�����, ͬʱ��ʼ��vector
{
	for (int i = 0; i < flightNum; i++)
	{
		(flights.data() + i)->setTime(beginTime + i * emptyHour);		//�������ʱ��
		(flights.data() + i)->rename(flightName(i));					//���ú����
	}
}

int orderSystem::flightExist(flightName name)
{	//�жϺ�����Ƿ����
	//�������ȡ�����෽��ʹ��
	for (int i = 0; i < flightNum; i++)
	{
		if (flights[i].name == name)
			return i;					//�����򷵻����������vector�е�λ��
	}
	return -1;							//���಻���ڷ���-1
}

flightName orderSystem::chooseFlight(ostream & out, istream & in)
{	//��ѡ��λ�ĺ���
	//��Ҫ������
	//ϣ�����ڿ�������gui
	flightName choice;													//���ڷ��صĺ����
	out << "Choose a flight by typing in a flight number: ";
	in >> choice;
	if (flightExist(choice)==-1)										//�����������ĺ���Ų����������µ����Լ�
	{
		out << "No such flight " << choice << " exist. " << endl;
		choice = chooseFlight(out, in);
		return choice;													//Ȼ�󷵻�
	}

	if (flights[flightExist(choice)].isAviliable(economy) || flights[flightExist(choice)].isAviliable(first_class))
	{																	//���������򷵻���ѡ�����
		out << "Flight " << choice << " selected. " << endl;
		out << flights[flightExist(choice)];
		return choice;
	}
	else
	{
		out << "Flight " << choice << " is all booked. " << endl;		//�����ѡ����������ѯ���Ƿ�Ҫ������
		bool willChange = like_to_change("Would you like to change another flight? (Y/n)", out, in);
		if (willChange)													//���Ļ������Լ�, Ȼ�󷵻�
		{
			choice = chooseFlight(out, in);
			return choice;
		}
		else
		{																//�����ͷ��ش�����
			return errorFlag;											//�����ǿ�����ϵͳ���ж�ʹ��
		}
	}
}

int orderSystem::chooseSeat(flight & selectedFlight, ostream & out, istream & in)
{	//ѡ������
	//���ڽ���
	out << "Please input a seat type (1 for first class, 2 for economy): " << endl;
	seatType selectedType;												//��λ����, ������
	in >> selectedType;
	if (selectedFlight.isAviliable(selectedType) == false)				//��ѡ���������λ��������ѯ���Ƿ������λ����
	{
		out << "Current seat type's all been booked. \n";
		bool willChange = like_to_change("Would you like to change your seat type? (Y/n)", out, in);
		if (willChange)													//Ҫ�����ͻ�һ��
		{
			selectedType = !selectedType;								//����ȡ�߼�������, �������ص�
		}
		else
		{
			return -1;													//���ǲ��뻻�Ͳ�����, ���ظ�-1����
		}																//���������̿����ж���
	}

	for (int i = 0; i < 5; i++)											//ǰ��Ĺ����Ѿ���֤��ѡ����λ���ͱ�Ȼ����
	{
		if (selectedFlight.seatStatus(i + 1 + (selectedType - 1) * 5))	//��λ���������, �Ǿʹ�ͷ��ʼ�����ĸ����ĸ�
		{
			return i + 1;												//ע����λ����1~10, ��������Ų�һ��
		}
	}

	out << "This flight's all been booked. \n";							//����Ϊ�������еķ�֧���з���ֵ
	return -2;															//�������������Ӧ�ó���, ���Ա����Ƿ���-1�ĳ���-2
}

int orderSystem::bookSeat(ostream & out, istream &in)
{	//����λ�ĺ���
	//��ǰ���ѡ����ѡ���ĺ�������һ��
	flightName selectedFlightNumber = chooseFlight(out, in);				//��ѡ����

	if (selectedFlightNumber == errorFlag)									//����ų����Ǵ�����λ�򷵻�-1
		return -1;

	flight & selectedFlight = flights[flightExist(selectedFlightNumber)];	//������һ�����ຽ�������, ������Ѱ�Һ�����vector��λ�õĺ���
	//flight & selectedFlight = *(flights.data() + flightExist(selectedFlightNumber));
																			//�о�������ָ����������һ��
																			//��ʵ֤����û��, ��Ҷ���һ�������˷�����˼
	int selectedSeat = chooseSeat(selectedFlight, out, in);					//���������ѡ������

	if (selectedSeat == -1 || selectedSeat == -2)							//�����ж�һ�´�������
		return -2;

	selectedFlight.orderSeat(selectedSeat);									//����֮��Ԥ��ѡ�������ѡ����λ
	selectedFlight.printBoardingPass(selectedSeat);							//Ȼ������ǻ���
	return 0;																//Ҫ���е�����ǰ���Ȼû�г��ִ���, ����0
}

void orderSystem::printFlightStatus(flightName name, ostream & out)
{	//���ĳ���������λ״̬����
	out << flights[name];
}

void orderSystem::printFlightStatus(ostream & out)
{	//��������Ǹ�����û�и�������žͰ����к���״̬�����
	for (int i = 0; i < flightNum; i++)
	{
		//printFlightStatus(out, flightName(i));
		out << this->flights[i];
	}
}

int orderSystem::DEBUG()
{	//���ǵ���ʱ�õĺ���
	//�������ڲ�����˽�з����������������
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
{	//����ϵͳ����
	out << "______________________________\nWelcome to flight order system. \n";
	out << *this;						//������к���״̬
	while (1)							//��ѭ��
	{
		this->bookSeat(out, in);
	}
	return 0;
}

orderSystem::~orderSystem()
{	//�յ���������
}

bool like_to_change(const string & msg, ostream & out, istream & in)
{	//�Ƿ����ѡ��ĺ���
	//��һ�������������ʾ��Ϣ
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
	}											//��������ַ�������Ҫ�������������������
	return like_to_change(msg, out, in);
}

seatType operator!(seatType type)
{	//�������߼��������
	switch (type)
	{
	case first_class:				//��ͷ�Ȳ� = ���ò�
		return economy;
	case economy:					//�Ǿ��ò� = ͷ�Ȳ�
		return first_class;
	default:						//����������Ǵ�����λ
		return errorType;
	}
}

ostream & operator<<(ostream & out, seatType & type)
{	//�����������λ���͵Ĳ�����
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
	// TODO: �ڴ˴����� return ���
	return out;
}

istream & operator>>(istream & in, seatType & type)
{	//������������λ���͵Ĳ�����
	int input;
	in >> input;
	switch (input)
	{
	case 1:
		type = first_class;				//����1����ͷ�Ȳ�
		break;
	case 2:
		type = economy;					//����2���Ǿ��ò�
		break;
	default:							//�������ᷢ�����沢Ҫ����������
		cout << "!!!INPUT SEAT TYPE ERROR!!!\n";
		cout << "Please type in seat type again. \n";
		in >> type;
		break;
	}
	// TODO: �ڴ˴����� return ���
	return in;
}

ostream & operator<<(ostream & out, flightName & name)
{	//�������������ŵĲ�����
	if (name == errorFlag)
		out << "Error flight number\n";
	else
		out << char('A' + name);		//����ܼ�, ���ǵ��ַ�����һ��������
	// TODO: �ڴ˴����� return ���
	return out;
}

istream & operator>>(istream & in, flightName & name)
{	//������������λ���͵Ĳ�����
	char input;								//������һ�������õ�����
	in >> input;
	if (input >= 'A' && input <= 'Z')		//�����Ǵ�д��ĸ
	{
		name = flightName(input - 'A');		//��ȥA���Ƕ�Ӧ�ı��
	}
	else if (input >= 'a' && input <= 'z')	//����Сд��ĸ
	{
		name = flightName(input - 'a');		//��ȥa���Ƕ�Ӧ���
	}
	else
	{
		cout << "!!!INPUT ERROR!!!\n" << "NO SUCH FLIGHT NUMBER" << endl;
		cout << "PLEASE TYPE IN AGAIN\n";
		in >> name;
	}
	// TODO: �ڴ˴����� return ���
	return in;
}

ostream & operator<<(ostream & out, flight & obj)
{	//�������������Ĳ�����
	using namespace std;
	obj.printSeatStatus(out);
	// TODO: �ڴ˴����� return ���
	return out;
}

ostream & operator<<(ostream & out, orderSystem & system)
{	//�������������ϵͳ�Ĳ�����
	system.printFlightStatus(out);
	// TODO: �ڴ˴����� return ���
	return out;
}
