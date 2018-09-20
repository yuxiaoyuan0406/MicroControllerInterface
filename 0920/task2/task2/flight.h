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


//һ����λ���͵�ö��
//���һ���Ǵ�����
enum seatType
{
	first_class = 1, economy, errorType
};


//������һ���߼��ǵĲ�����
//���ڸ�����λ����
seatType operator!(seatType type);

//������һ��<<������
//���������λ����
ostream &operator<<(ostream & out, seatType & type);

//������һ��>>������
//����������λ����
//ֻ������1��2
istream &operator>>(istream & in, seatType & type);

//һ������ŵ�ö������
//���һ���Ǵ�����
enum flightName
{
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, errorFlag
};

//������һ��<<������
//������������
ostream &operator<<(ostream & out, flightName & name);
//������һ��>>������
//�������뺽���
//���������д��ĸ����Сд��ĸ
istream &operator>>(istream & in, flightName & name);

//һ���������
class flight
{
private:
	//�����������ʱ��
	int take_off_time;

	//����һ������
	//���ڱ����λ״̬
	//1Ϊ�ѱ�Ԥ��, 0Ϊδ��Ԥ��
	int seats_status[10] =
	{
		0,0,0,0,0,0,0,0,0,0
	};

	//����ʣ����λ��
	int left_seats = 10;
public:
	//���������
	flightName name = A;
public:
	//�յĹ��캯��
	flight();
	
	//�������ʱ��ĳ�ʼ������
	flight(int hour);

	//���ú����������ʱ��
	void setTime(int hour);

	//���ĺ����
	void rename(flightName);

	//һ���ж�ĳ����λ�Ƿ���ʣ��ĺ���
	//��ʣ�෵��true, ���򷵻�false
	bool isAviliable(seatType type);

	//Ԥ����λ�ĺ���
	//������λ״̬����ʣ����λ����ȥ1
	bool orderSeat(int seatNum);

	//ȡ��Ԥ���ĺ���
	bool cancelOrder(int seatNum);

	//����ǻ��Ƶĺ���
	//Ҫ��������λ��
	void printBoardingPass(int searNum);

	//��������ѱ�Ԥ������λ�ĵǻ���
	void printBoardingPass();

	//�����λ״̬
	//����Ϊ�����
	void printSeatStatus(ostream &out = cout);

	//�յ���������
	~flight();
};

//������һ��<<������
//�������������λ״̬
ostream & operator<<(ostream & out, flight & obj);

//һ�����չ�˾�Ķ���
class orderSystem
{
private:
	//��������
	int flightNum;

	//������һ��vector���͵�����
	//���ڿ�����ӻ�ɾ������
	std::vector<flight> flights;
public:
	//�յĹ��캯��
	orderSystem();

	//���뺽����, ��һ�����ʱ��, ���ʱ��Ĺ��캯��
	orderSystem(int flightNum, int beginTime, int emptyHour);

	//�жϺ�����Ƿ���ڵĺ���
	//���ڷ��غ�����flights�е��±�
	//�������򷵻�-1
	int flightExist(flightName name);

	//ѡ�񺽰�ĺ���
	flightName chooseFlight(ostream & out = cout, istream & in = cin);

	//ѡ����λ�ĺ���
	int chooseSeat(flight &selectedFlight, ostream & out = cout, istream & in = cin);

	//Ԥ����λ�ĺ���
	void bookSeat(ostream & out = cout, istream & in =cin);

	//���
	void printFlightStatus(flightName name, ostream & out = cout);
	void printFlightStatus(ostream & out = cout);
	~orderSystem();
};

ostream & operator<<(ostream & out, orderSystem & system);

#endif // !FLIGHT_H
