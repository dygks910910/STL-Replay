#pragma once
#include<string>
#include<vector>
#include<iostream>
class CData
{
	double m_dTime;
	std::string m_sValue;
	int m_iStrLength;
public:
	CData(const double& t, const std::vector<char>& v);
	CData(const double& t, const std::vector<char>& v,const char& sequnce);

	CData(const double& t, char* v);

	~CData();
	void setData(const double& t, const std::vector<char>& v);
	
	int getLen()const { return m_iStrLength; }
	double getTime() const { return m_dTime; }const 
	std::string getValue()const { return m_sValue; };
	//const char& getEscape() { return m_escapeSequens; }
};

