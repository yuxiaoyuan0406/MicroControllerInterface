/*
 * Author:	Yu Xiaoyuan
 * Time:	2018-9-20 18:17:04
 * Email:	yuxiaoyuan0406@hotmail.com
*/

#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H
#include <vector>
#include <iostream>

using namespace std;


//一个座位类型的枚举
//最后一个是错误标记
enum seatType
{
	first_class = 1, economy, errorType
};


//重载了一个逻辑非的操作符
//用于更换座位类型
seatType operator!(seatType type);

//重载了一个<<操作符
//用于输出座位类型
ostream &operator<<(ostream & out, seatType & type);

//崇再乐一个>>操作符
//用于输入座位类型
//只能输入1或2
istream &operator>>(istream & in, seatType & type);

//一个航班号的枚举类型
//最后一个是错误标记
enum flightName
{
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, errorFlag
};

//重载了一个<<操作符
//用于输出航班号
ostream &operator<<(ostream & out, flightName & name);
//重载了一个>>操作符
//用于输入航班号
//可以输入大写字母或者小写字母
istream &operator>>(istream & in, flightName & name);

//一个航班的类
class flight
{
private:
	//声明航班起飞时间
	int take_off_time;

	//声明一个数组
	//用于标记座位状态
	//1为已被预订, 0为未被预定
	int seats_status[10] =
	{
		0,0,0,0,0,0,0,0,0,0
	};

	//声明剩余座位数
	int left_seats = 10;
public:
	//声明航班号
	flightName name = A;
public:
	//空的构造函数
	flight();
	
	//输入起飞时间的初始化函数
	flight(int hour);

	//设置航班对象的起飞时间
	void setTime(int hour);

	//更改航班号
	void rename(flightName);

	//一个判断某类座位是否有剩余的函数
	//有剩余返回true, 否则返回false
	bool isAviliable(seatType type);

	//预订座位的函数
	//更改座位状态并将剩余座位数减去1
	bool orderSeat(int seatNum);

	//取消预订的函数
	bool cancelOrder(int seatNum);

	//输出登机牌的函数
	//要求输入座位号
	void printBoardingPass(int searNum);

	//输出所有已被预定的座位的登机牌
	void printBoardingPass();

	//输出座位状态
	//参数为输出流
	void printSeatStatus(ostream &out = cout);

	//空的析构函数
	~flight();
};

//重载了一个<<操作符
//用于输出航班座位状态
ostream & operator<<(ostream & out, flight & obj);

//一个航空公司的对象
class orderSystem
{
private:
	//航班数量
	int flightNum;

	//声明了一个vector类型的数组
	//后期可以添加或删除航班
	std::vector<flight> flights;
public:
	//空的构造函数
	orderSystem();

	//输入航班数, 第一班起飞时间, 间隔时间的构造函数
	orderSystem(int flightNum, int beginTime, int emptyHour);

	//判断航班号是否存在的函数
	//存在返回航班在flights中的下标
	//不存在则返回-1
	int flightExist(flightName name);

	//选择航班的函数
	flightName chooseFlight(ostream & out = cout, istream & in = cin);

	//选择座位的函数
	int chooseSeat(flight &selectedFlight, ostream & out = cout, istream & in = cin);

	//预订座位的函数
	void bookSeat(ostream & out = cout, istream & in =cin);

	//输出
	void printFlightStatus(flightName name, ostream & out = cout);
	void printFlightStatus(ostream & out = cout);
	~orderSystem();
};

ostream & operator<<(ostream & out, orderSystem & system);

#endif // !FLIGHT_H
