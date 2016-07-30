#include "Data.h"
#include<iterator>

CData::CData(const double& t, const std::vector<char>& v) :m_dTime(t)
{
	//std::copy(v.begin(), v.end(), m_sValue);

	std::string temp;

	for (auto p = v.begin(); p != v.end(); ++p)
	{
		temp += (*p);
	}
	m_sValue = temp;
	m_iStrLength = v.size();
}


CData::~CData()
{
}
void CData::setData(const double& t, const std::vector<char>& v)
{
	m_dTime = t;
	std::string temp;
	for (auto p = v.begin(); p != v.end(); ++p)
	{
		temp += (*p);
	}
	m_sValue = temp;
	m_iStrLength = v.size();
	//m_escapeSequens = NULL;

}
CData::CData(const double& t, char* v)
{
	std::string temp;
	m_sValue = v;
	m_iStrLength = strlen(v);
	//m_escapeSequens = NULL;
}
CData::CData(const double& t, const std::vector<char>& v, const char& sequnce)
{
	m_dTime = t;
	std::string temp;
	for (auto p = v.begin(); p != v.end(); ++p)
	{
		temp += (*p);
	}
	m_sValue = temp;
	m_iStrLength = v.size();
	//m_escapeSequens = sequnce;
}
