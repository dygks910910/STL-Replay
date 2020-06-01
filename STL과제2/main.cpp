#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include"Timer.h"
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;

wostream& operator<<(wostream& os, const list<wchar_t>& v);
wistream& operator>> (wistream& is, list<pair<double, list<wchar_t>>>& v);
wostream& operator<<(wostream& os, const list<pair<double, list<wchar_t>>>& v);

void main()
{
	std::locale::global(std::locale(""));

	CTimer timer; // 시간정보를 리턴하는객체.
	wchar_t a=NULL;
	int menuSell = 0;
	double tempTime = 0;
	list<wchar_t> v;
	list<pair<double, list<wchar_t>>> v_replayData;
	
	wstring tempstring{};
	wofstream out;
	wifstream in;

	//재생을 위한 이터레이터
	list<pair<double, list<wchar_t>>>::iterator replayer_iterator;
	

	while (1) {
		cout << "MENU" << endl;
		cout << "1.REC" << endl;
		cout << "2.REPLAY" << endl;
		cout << "3.MYREPLAY" << endl;
		cout << "입력"; cin >> menuSell;

		system("cls");
		switch (menuSell)
		{
		case 1:
			timer.setStartTime(chrono::system_clock::now());
			while (1)
			{
				a = _getwch();
				v.emplace_back(a);
				if (a == L'\r')
					tempstring += L'\n';
				else if (a == L'\b')
				{
					if (tempstring.size() >= 1)
					{
						tempstring.pop_back();

					}
					if (v.size() > 1)
					{
						v.pop_back();
						v.pop_back();
					}
				}
				else
					tempstring += a;
				if (a == L'\x1b')
				{
					out.open(L".\\과제2.txt", wios::out| wios::trunc);
					out << v_replayData;
					tempstring.clear();
					out.close();
					if (v_replayData.size() != 0)
					{
						v_replayData.clear();
					}
					if (v.size() != 0)
					{
						v.clear();
					}
					tempstring.clear();
					break;
				}
				tempTime = timer.getNowTime(chrono::system_clock::now());
				v_replayData.push_back(make_pair(tempTime, v));
				system("cls");
				wcout << tempstring;

			}
			break;
		case 2:
			in.open(L".\\과제2.txt", wios::in);
			if (v_replayData.size() != 0)
			{
				v_replayData.clear();
				v_replayData.erase(v_replayData.begin(), v_replayData.end());
			}
			if (v.size() != 0)
			{
				v.clear();
			}
			while (!in.eof())
			{
				in >> v_replayData;
			}
			//cout << v_replayData;
			timer.setStartTime(chrono::system_clock::now());

			/*for (auto p = v_replayData.begin(); p != v_replayData.end(); ++p)
			{
				tempTime = timer.getNowTime(chrono::system_clock::now());
				if ((*p).first > tempTime)
				{
					cout << (*p).second;
				}
			}*/
			replayer_iterator = v_replayData.begin();
			while (replayer_iterator != v_replayData.end())
			{
				tempTime = timer.getNowTime(chrono::system_clock::now());
				if ((*replayer_iterator).first < tempTime)
				{
					system("cls");
					wcout << (*replayer_iterator).second;
					replayer_iterator++;
				}

			}
			in.close();
			system("cls");
			break;
		case 3:
			in.open(L".\\과제2.txt", wios::in);
			if (v_replayData.size() != 0)
			{
				v_replayData.clear();
				v_replayData.erase(v_replayData.begin(), v_replayData.end());
			}
			if (v.size() != 0)
			{
				v.clear();
			}
			while (!in.eof())
			{
				in >> v_replayData;
			}
			//cout << v_replayData;
			timer.setStartTime(chrono::system_clock::now());

			/*for (auto p = v_replayData.begin(); p != v_replayData.end(); ++p)
			{
			tempTime = timer.getNowTime(chrono::system_clock::now());
			if ((*p).first > tempTime)
			{
			cout << (*p).second;
			}
			}*/
			replayer_iterator = v_replayData.begin();
			while (replayer_iterator != v_replayData.end())
			{
				tempTime = timer.getNowTime(chrono::system_clock::now());
				if ((*replayer_iterator).first < tempTime)
				{
					system("cls");
					wcout << (*replayer_iterator).second;
					replayer_iterator++;
				}

			}
			in.close();
			system("cls");
			break;
		default:
			break;
			menuSell = 0;
		}
		/*for(int i = 0 ; i < 10 ; ++i)
		{
			a = getch();
			v.emplace_back(a);
		}
		for (auto p = v.begin(); p != v.end(); ++p)
		{
			cout << *p;
		}
		cout << endl;
	*/
	/*ofstream out("과제2.txt");
	out << timer.getNowTime(chrono::system_clock::now())<<" ";
	out << v << '\n' ;
	out << timer.getNowTime(chrono::system_clock::now()) << " ";
	out << v;
	cout << v.size();

	out.close();*/

	/*ifstream in("과제2.txt");
	v.clear();
	while (!in.eof())
	{
		in >> v;
	}*/
	}
}


wostream& operator<<(wostream& os, const list<wchar_t>& v)
{
	// TODO: 여기에 return 문을 삽입합니다.
	for (auto p = v.begin(); p != v.end(); ++p)
	{
		os << *p;
	}
	return os;
}

wistream& operator>>(wistream& is, list<pair<double, list<wchar_t>>>& v)
{
	wchar_t temp;
	double tempTime;
	list<wchar_t> tempVector;
	is >> tempTime;
	//cout << "시간" << tempTime << endl;
	while (is.good())
	{
		temp = is.get();
		if (temp == -1)
			break;
		else if (temp == L'\r')
		{
			tempVector.emplace_back(L'\n');
		}
		else if (temp == L'\n')
			break;
		else
			tempVector.emplace_back(temp);
	}
	if (tempVector.size() != 0)
		v.emplace_back(tempTime, tempVector);
	//cout << v << endl;
	return is;
}
wostream& operator<<(wostream& os, const list<pair<double, list<wchar_t>>>& v)
{
	// TODO: 여기에 return 문을 삽입합니다.
	for (auto p = v.begin(); p != v.end(); ++p)
	{
		os << (*p).first << " " << (*p).second << "\n";
	}
	return os;
}
