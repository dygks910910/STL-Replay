#pragma once
#include<chrono>
using namespace std;
class CTimer
{
private:
	chrono::system_clock::time_point tpStart;

public:
	CTimer();
	~CTimer();
	void setStartTime(const chrono::system_clock::time_point& tp) { tpStart = tp; }
	
	//����ð��� �Է¹޾Ƽ� ���ݱ��� �帥 �ð��� ����
	const float& getNowTime(const chrono::system_clock::time_point& tp);
	const chrono::system_clock::time_point& getStart() { return tpStart; }

};

