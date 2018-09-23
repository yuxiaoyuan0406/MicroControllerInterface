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
	:take_off_time(hour)//初始化起飞时间
						//用于打印登机牌
{
}

void flight::setTime(int hour)
{
	//重新设置起飞时间
	take_off_time = hour;
}

void flight::rename(const flightName newName)
{
	//更改航班号
	name = newName;
}

bool flight::isAviliable(seatType type)
{	//根据输入的座位类型判断是否有座			/************************************************/
	for (int i = 0; i < 5; i++)				/*		这里i的值为5是因为每种座位只有五个		*/
	{										/*												*/
		int c = i + (type - 1) * 5;			/*		座位类型有对应的整型数字可以计算			*/
		if (seats_status[c] == 0)			/*		座位状态为0是未被预订						*/
			return true;					/*		只要有一个座位状态为0则返回真				*/	
	}										/*		其他情况返回假, 也就是都为1返回假			*/
	return false;							/************************************************/
}

bool flight::orderSeat(int seatNum)
{	//预定给定座位号的座位					/********************************************************/
	if (seats_status[seatNum - 1] == 0)		/*		座位号范围是1~10									*/
	{										/*		与数组编号不同									*/
		seats_status[seatNum - 1] = 1;		/*		这里在后期使用的时候要特别注意					*/
		left_seats--;						/*		如果座位状态为0, 则改为1, 并减少一个剩余座位		*/
		return true;						/*		修改完后返回真									*/
	}										/*		若座位已被预定则返回假							*/
	return false;							/********************************************************/

}

bool flight::cancelOrder(int seatNum)
{	//取消座位预定
	//本函数未使用, 可用于后期增加功能
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
{	//打印登机牌
	using namespace std;
	for (int i = 0; i < 25; i++)
		out << "_";																//输出边框
	out << endl;
	out << "|\t\t\t|" << endl;													//输出一个空行, 美观
	out << "|\tFlight Number: " << this->name << "\t|" << endl;					//输出航班号
	out << (seatNum < 5 ? "|\tfirst class\t|": "|  \tcoach\t\t|") << endl;		//输出座位类型
	out << "|\tseat number: " << seatNum << "\t|" << endl;						//输出座位号
	out << "|";
	for (int i = 0; i < 23; i++)
		out << "_";
	out << "|" << endl;
}

void flight::printBoardingPass(ostream & out)	//没有给定座位号信息则打印所有已被预定的登机牌
{	//打印登机牌
	//函数在系统中尚未调用
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
{	//输出所有座位状态
	using namespace std;
	out << "-----" << name << "-----" << endl;			//先输出航班号
	out << "take off time: " << take_off_time << endl;	//然后输出起飞时间
	int seats = 0;										//声明一个计量座位的变量, 实际上可以用flight::left_seats代替
	for (int i = 0; i < 10; i++)						//但我想再数一遍
	{													//其实应该对比一下
		if (seats_status[i] == 0)
			seats++;
	}
	out << seats << " seat(s) aviliable. " << endl;

	if (isAviliable(first_class))
	{
		int first = 0;									//这里数一下有几个头等舱座位
		for (int i = 0; i < 5; i++)
		{
			if (seats_status[i] == 0)
				first++;
		}
		out << first << " first-class seat(s) aviliable. " << endl;
	}
	else												//没有就输出没有
		out << "No first-class seat aviliable. " << endl;

	if (isAviliable(economy))
	{
		int econ = 0;									//这里同理
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

bool flight::seatStatus(int seatNum)					//判断单个座位的状态
{	//座位号与数组编号有差异, 需注意
	if (seats_status[seatNum-1] == 0)
	{
		return true;
	}
	return false;
}


flight::~flight()
{	//空的析构函数
}

orderSystem::orderSystem()
{	//空的构造函数
}

orderSystem::orderSystem(int flightn, int beginTime, int emptyHour)
	:flightNum(flightn),flights(flightn)
	//初始化了飞机数量, 同时初始化vector
{
	for (int i = 0; i < flightNum; i++)
	{
		(flights.data() + i)->setTime(beginTime + i * emptyHour);		//设置起飞时间
		(flights.data() + i)->rename(flightName(i));					//设置航班号
	}
}

int orderSystem::flightExist(flightName name)
{	//判断航班号是否存在
	//后期配合取消航班方法使用
	for (int i = 0; i < flightNum; i++)
	{
		if (flights[i].name == name)
			return i;					//存在则返回这个航班在vector中的位置
	}
	return -1;							//航班不存在返回-1
}

flightName orderSystem::chooseFlight(ostream & out, istream & in)
{	//挑选座位的函数
	//需要做交互
	//希望后期可以做成gui
	flightName choice;													//用于返回的航班号
	out << "Choose a flight by typing in a flight number: ";
	in >> choice;
	if (flightExist(choice)==-1)										//如果交互输入的航班号不存在则重新调用自己
	{
		out << "No such flight " << choice << " exist. " << endl;
		choice = chooseFlight(out, in);
		return choice;													//然后返回
	}

	if (flights[flightExist(choice)].isAviliable(economy) || flights[flightExist(choice)].isAviliable(first_class))
	{																	//这里有座则返回所选航班号
		out << "Flight " << choice << " selected. " << endl;
		out << flights[flightExist(choice)];
		return choice;
	}
	else
	{
		out << "Flight " << choice << " is all booked. " << endl;		//如果所选航班无座了询问是否要换航班
		bool willChange = like_to_change("Would you like to change another flight? (Y/n)", out, in);
		if (willChange)													//换的话调用自己, 然后返回
		{
			choice = chooseFlight(out, in);
			return choice;
		}
		else
		{																//不换就返回错误标记
			return errorFlag;											//错误标记可以在系统中判断使用
		}
	}
}

int orderSystem::chooseSeat(flight & selectedFlight, ostream & out, istream & in)
{	//选座函数
	//存在交互
	out << "Please input a seat type (1 for first class, 2 for economy): " << endl;
	seatType selectedType;												//座位类型, 返回用
	in >> selectedType;
	if (selectedFlight.isAviliable(selectedType) == false)				//所选航班这个座位号无座则询问是否更换座位类型
	{
		out << "Current seat type's all been booked. \n";
		bool willChange = like_to_change("Would you like to change your seat type? (Y/n)", out, in);
		if (willChange)													//要更换就换一手
		{
			selectedType = !selectedType;								//这里取逻辑非运算, 后面重载的
		}
		else
		{
			return -1;													//哥们不想换就不换了, 返回个-1拉倒
		}																//后期主进程可以判断用
	}

	for (int i = 0; i < 5; i++)											//前面的过程已经保证了选的座位类型必然有座
	{
		if (selectedFlight.seatStatus(i + 1 + (selectedType - 1) * 5))	//座位是随机分配, 那就从头开始挨着哪个算哪个
		{
			return i + 1;												//注意座位号是1~10, 这和数组编号不一样
		}
	}

	out << "This flight's all been booked. \n";							//这是为了让所有的分支都有返回值
	return -2;															//但理论上这个不应该出现, 所以本来是返回-1改成了-2
}

int orderSystem::bookSeat(ostream & out, istream &in)
{	//定座位的函数
	//把前面的选航班选座的函数集成一下
	flightName selectedFlightNumber = chooseFlight(out, in);				//先选航班

	if (selectedFlightNumber == errorFlag)									//航班号出来是错误标记位则返回-1
		return -1;

	flight & selectedFlight = flights[flightExist(selectedFlightNumber)];	//声明了一个航班航班的引用, 调用了寻找航班在vector中位置的函数
	//flight & selectedFlight = *(flights.data() + flightExist(selectedFlightNumber));
																			//感觉这里用指针好像更合适一点
																			//事实证明并没有, 大家都是一样的令人匪夷所思
	int selectedSeat = chooseSeat(selectedFlight, out, in);					//这里调用了选座函数

	if (selectedSeat == -1 || selectedSeat == -2)							//这里判断一下错误类型
		return -2;

	selectedFlight.orderSeat(selectedSeat);									//结束之后预定选定航班的选定座位
	selectedFlight.printBoardingPass(selectedSeat);							//然后输出登机牌
	return 0;																//要进行到这里前面必然没有出现错误, 返回0
}

void orderSystem::printFlightStatus(flightName name, ostream & out)
{	//输出某个航班的座位状态到流
	out << flights[name];
}

void orderSystem::printFlightStatus(ostream & out)
{	//如果上面那个函数没有给定航班号就把所有航班状态都输出
	for (int i = 0; i < flightNum; i++)
	{
		//printFlightStatus(out, flightName(i));
		out << this->flights[i];
	}
}

int orderSystem::DEBUG()
{	//这是调试时用的函数
	//可以在内部调用私有方法来构造特殊情况
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
{	//启动系统函数
	out << "______________________________\nWelcome to flight order system. \n";
	out << *this;						//输出所有航班状态
	while (1)							//死循环
	{
		this->bookSeat(out, in);
	}
	return 0;
}

orderSystem::~orderSystem()
{	//空的析构函数
}

bool like_to_change(const string & msg, ostream & out, istream & in)
{	//是否更换选择的函数
	//第一个输入参量是提示信息
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
	}											//如果输入字符不符合要求则调用自身重新输入
	return like_to_change(msg, out, in);
}

seatType operator!(seatType type)
{	//重载了逻辑非运算符
	switch (type)
	{
	case first_class:				//非头等舱 = 经济舱
		return economy;
	case economy:					//非经济舱 = 头等舱
		return first_class;
	default:						//其他情况就是错误标记位
		return errorType;
	}
}

ostream & operator<<(ostream & out, seatType & type)
{	//重载了输出座位类型的操作符
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
{	//重载了输入座位类型的操作符
	int input;
	in >> input;
	switch (input)
	{
	case 1:
		type = first_class;				//输入1就是头等舱
		break;
	case 2:
		type = economy;					//输入2就是经济舱
		break;
	default:							//输入错误会发出警告并要求重新输入
		cout << "!!!INPUT SEAT TYPE ERROR!!!\n";
		cout << "Please type in seat type again. \n";
		in >> type;
		break;
	}
	// TODO: 在此处插入 return 语句
	return in;
}

ostream & operator<<(ostream & out, flightName & name)
{	//重载了输出航班号的操作符
	if (name == errorFlag)
		out << "Error flight number\n";
	else
		out << char('A' + name);		//运算很简单, 就是单字符加上一个整型数
	// TODO: 在此处插入 return 语句
	return out;
}

istream & operator>>(istream & in, flightName & name)
{	//重载了输入座位类型的操作符
	char input;								//声明了一个输入用的容器
	in >> input;
	if (input >= 'A' && input <= 'Z')		//输入是大写字母
	{
		name = flightName(input - 'A');		//减去A就是对应的编号
	}
	else if (input >= 'a' && input <= 'z')	//输入小写字母
	{
		name = flightName(input - 'a');		//减去a就是对应编号
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
{	//重载了输出航班的操作符
	using namespace std;
	obj.printSeatStatus(out);
	// TODO: 在此处插入 return 语句
	return out;
}

ostream & operator<<(ostream & out, orderSystem & system)
{	//重载了输出航班系统的操作符
	system.printFlightStatus(out);
	// TODO: 在此处插入 return 语句
	return out;
}
