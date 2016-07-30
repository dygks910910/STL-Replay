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
	
	//현재시간을 입력받아서 지금까지 흐른 시간을 리턴
	const float& getNowTime(const chrono::system_clock::time_point& tp);
	const chrono::system_clock::time_point& getStart() { return tpStart; }

};

