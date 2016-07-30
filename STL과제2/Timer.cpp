#include "Timer.h"
#include<iostream>


CTimer::CTimer()
{
}


CTimer::~CTimer()
{
}
const float& CTimer::getNowTime(const chrono::system_clock::time_point& tp)
{
	return (tp - tpStart).count()*0.0000001f;
}
