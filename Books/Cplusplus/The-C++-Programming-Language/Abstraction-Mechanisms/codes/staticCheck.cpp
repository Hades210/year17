// file : staticCheck.cpp

#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	Date(int dd = 0, int mm = 0, int yy = 0);
	static void set_default(int dd, int mm, int yy);

	friend ostream& operator<< (ostream& o, const Date& date);
private:
	int d, m, y;
	static Date default_date;
};

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : default_date.d;
	m = mm ? mm : default_date.m;
	y = yy ? yy : default_date.y;
}

Date Date::default_date{8,1,1992};
void Date::set_default(int d, int m, int y)
{
	default_date = {d,m,y};
}

ostream& operator<< (ostream& o, const Date& date)
{
	o<<date.y<<"-"<<date.m<<"-"<<date.d<<endl;
	return o;
}

int main()
{
	Date d;
	cout<<d;
	Date::set_default(8,11,1991);
	Date dd;
	cout<<dd;
	return 0;
}