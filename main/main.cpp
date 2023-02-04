#include <iostream>
using namespace std;

bool searchFor(int num, int* Arr, const int SIZE);

class Date
{
private:
	int day;
	int month;
	int year;

	Date(int d);
	Date(int d, int m);

public:
	Date();
	Date(const Date& d);
	Date(int d, int m, int y);

	void Print()const;
	void Init();

	Date& operator++(); // ++a
	Date& operator--(); // --a
	Date operator++(int); // a++
	Date operator--(int); // a--

	Date operator+(int n); // a + 10
	int operator-(const Date& d); // a - b
	Date operator-(int n); // a - 10

	Date& operator+=(int n); // a += 10
	Date& operator-=(int n); // a -= 10

	bool operator > (const Date& d); // a > b
	bool operator < (const Date& d); // a < b
	bool operator >= (const Date& d); // a >= b
	bool operator <= (const Date& d); // a <= b
	bool operator == (const Date& d); // a == b
	bool operator != (const Date& d); // a != b

	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

	void SetDay(int d);
	void SetMonth(int m);
	void SetYear(int y);

	bool checkDate();

	int operator[](int index);

	friend ostream& operator << (ostream& o, const Date& d);
	friend istream& operator >> (istream& i, Date& d);
};

Date::Date(int d)
{
	day = d;
}

Date::Date(int d, int m) :Date(d)
{
	month = m;
}


Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

Date::Date(int d, int m, int y) :Date(d, m)
{
	year = y;
}

void Date::Print()const
{
	cout << day << "." << month << "." << year << "\n";
}

void Date::Init()
{
	cout << "Enter a date (d m y):\n\n";

	cout << ">>> ";
	cin >> day >> month >> year;
}

Date& Date::operator ++()
{
	day++;
	if (!this->checkDate())
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
	return *this;
}

Date& Date::operator --() // --a
{
	day--;
	if (day < 1)
	{
		month--;
		if (month < 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else
		{
			switch (month)
			{
			case 4:
			case 6:
			case 9:
			case 11:
				day = 30;
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				day = 31;
				break;
			default:
				if (year % 4 != 0)
					day = 28;
				else
					day = 29;
				break;
			}
		}
	}
    return *this;
}

Date Date::operator ++(int) // a++
{
	Date temp(this->day, this->month, this->year);

	day++;
	if (!this->checkDate())
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

	return temp;
}

Date Date::operator --(int) // a--
{
	Date temp(this->day, this->month, this->year);

	day--;
	if (day < 1)
	{
		month--;
		if (month < 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else
		{
			switch (month)
			{
			case 4:
			case 6:
			case 9:
			case 11:
				day = 30;
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				day = 31;
				break;
			default:
				if (year % 4 != 0)
					day = 28;
				else
					day = 29;
				break;
			}
		}
	}

    return temp;
}

Date Date::operator +(int n)
{
	Date tmp(day, month, year);
	tmp.day += n;
	switch (tmp.month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (tmp.day > 30)
		{
			tmp.day -= 30;
			tmp.month++;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (tmp.day > 31)
		{
			tmp.day -= 31;
			tmp.month++;
		}
		break;
	default:
		if (tmp.year % 4 != 0 && tmp.day > 28)
		{
			tmp.day -= 28;
			tmp.month++;
		} 
		else if (year % 4 == 0 && day > 29)
		{
			tmp.day -= 29;
			tmp.month++;
		}
		break;
	}
	if (tmp.month > 12)
	{
		tmp.month = 1;
		tmp.year++;
	}
	return tmp;
}

int Date::operator -(const Date& d)
{
	Date tmp(day, month, year);
	tmp.day -= d.day;
	tmp.month -= d.month;
	tmp.year -= d.year;
	switch (tmp.month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (tmp.day > 30)
		{
			tmp.day += 30;
			tmp.month--;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (tmp.day > 31)
		{
			tmp.day += 31;
			tmp.month--;
		}
		break;
	default:
		if (tmp.year % 4 != 0 && tmp.day > 28)
		{
			tmp.day += 28;
			tmp.month--;
		}
		else if (tmp.year % 4 == 0 && tmp.day > 29)
		{
			tmp.day += 29;
			tmp.month--;
		}
		break;
	}
	if (tmp.month < 1)
	{
		tmp.month = 12;
		tmp.year--;
	}
	return tmp.day;
}

Date Date::operator -(int n)
{
	Date tmp(day, month, year);
	tmp.day -= n;
	switch (tmp.month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (tmp.day > 30)
		{
			tmp.day += 30;
			tmp.month--;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (tmp.day > 31)
		{
			tmp.day += 31;
			tmp.month--;
		}
		break;
	default:
		if (tmp.year % 4 != 0 && tmp.day > 28)
		{
			tmp.day += 28;
			tmp.month--;
		}
		else if (tmp.year % 4 == 0 && tmp.day > 29)
		{
			tmp.day += 29;
			tmp.month--;
		}
		break;
	}
	if (tmp.month < 1)
	{
		tmp.month = 12;
		tmp.year--;
	}
	return tmp;
}

Date& Date::operator+=(int n)
{
	day += n;
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
		{
			day -= 30;
			month++;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31)
		{
			day -= 31;
			month++;
		}
		break;
	default:
		if (year % 4 != 0 && day > 28)
		{
			day -= 28;
			month++;
		}
		else if (year % 4 == 0 && day > 29)
		{
			day -= 29;
			month++;
		}
		break;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
	return *this;
}

Date& Date::operator-=(int n)
{
	day -= n;
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
		{
			day += 30;
			month--;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31)
		{
			day += 31;
			month--;
		}
		break;
	default:
		if (year % 4 != 0 && day > 28)
		{
			day += 28;
			month--;
		}
		else if (year % 4 == 0 && day > 29)
		{
			day += 29;
			month--;
		}
		break;
	}
	if (month < 1)
	{
		month = 12;
		year--;
	}
	return *this;
}

bool Date::operator > (const Date& d) 
{
	if (year > d.year)
	{
		return true;
	}
	else if (year == d.year) 
	{
		if (month > d.month) 
		{ 
			return true; 
		}
		else if (month == d.month) 
		{
			if (day > d.day) 
			{ 
				return true; 
			}
		}
	}
	return false;
}

bool Date::operator < (const Date& d)
{
	if (year < d.year) 
	{
		return true;
	}
	else if (year == d.year) 
	{
		if (month < d.month) 
		{
			return true; 
		}
		else if (month == d.month) 
		{
			if (day < d.day) 
			{ 
				return true;
			}
		}
	}
	return false;
}

bool Date::operator >= (const Date& d)
{
	if (year > d.year) 
	{
		return true;
	}
	else if (year == d.year) 
	{
		if (month > d.month)
		{ 
			return true; 
		}
		else if (month == d.month) 
		{
			if (day > d.day || day == d.day) 
			{
				return true; 
			}
		}
	}
	return false;
}

bool Date::operator <= (const Date& d) 
{
	if (year < d.year) 
	{ 
		return true; 
	}
	else if (year == d.year) 
	{
		if (month < d.month) 
		{ 
			return true; 
		}
		else if (month == d.month)
		{
			if (day < d.day || day == d.day) 
			{
				return true; 
			}
		}
	}
	return false;
}

bool Date::operator == (const Date& d) 
{
	if (day == d.day && month == d.month && year == d.year)
		return true;
	return false;
}

bool Date::operator != (const Date& d) 
{
	if (day == d.day && month == d.month && year == d.year) 
		return false;
	return true;
}

ostream& operator << (ostream& o, const Date& d)
{
	o << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
	return o;
}

istream& operator >> (istream& i, Date& d)
{
	cout << "Enter a date (10 12 2023): ";
	i >> d.day >> d.month >> d.year;
	return i;
}

int Date::GetDay()const
{
	return day;
}

int Date::GetMonth()const
{
	return month;
}

int Date::GetYear()const
{
	return year;
}

void Date::SetDay(int d)
{
	day = d;
}

void Date::SetMonth(int m)
{
	month = m;
}

void Date::SetYear(int y)
{
	year = y;
}

bool Date::checkDate()
{
	if (month != 2)
	{
		switch (month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
				return false;
			break;
		default:
			if (day > 31)
				return false;
			break;
		}
	}
	else if (year % 4 != 0 && day > 28)
	{
		return false;
	}
	else if (year % 4 == 0 && day > 29)
	{
		return false;
	}
}

int Date::operator[](int index)
{
	switch (index)
	{
	case 0:
		return day;
	case 1:
		return month;
	case 2:
		return year;
	default:
		throw "Incorrect index :(\n";
	}
}

int main()
{
	Date obj1(31, 12, 2022);
	Date obj2(3, 1, 2023);

	cout << "Date:\t";
	cout << obj1 << "\n";

	cout << "++Date:\t";
	++obj1;
	cout << obj1 << "\n";

	cout << "Date++:\t";
	obj1++;
	cout << obj1 << "\n";

	cout << "--Date:\t";
	--obj1;
	cout << obj1 << "\n";

	cout << "Date--:\t";
	obj1--;
	cout << obj1 << "\n\n";

	cout << obj1 << " + 15:\t";
	obj1 = obj1 + 15;
	cout << obj1 << "\n";

	cout << obj1 << " - " << obj2 << ":\t" << obj1 - obj2 << "\n";

	cout << obj1 << " - 10:\t\t" << obj1 - 10 << "\n";

	cout << obj1 << " += 26:\t";
	obj1 += 26;
	cout << obj1 << "\n";

	cout << obj1 << " -= 6:\t\t";
	obj1 -= 6;
	cout << obj1 << "\n\n";

	cout << boolalpha << "3.12.2023 > 4.5.2023: "
		<< (Date(3, 12, 2023) > Date(4, 5, 2023)) << "\n";

	cout << boolalpha << "5.7.2022 < 4.5.2022: "
		<< (Date(5, 7, 2022) < Date(4, 5, 2022)) << "\n";

	cout << boolalpha << "3.12.2023 >= 4.5.2023: "
		<< (Date(3, 12, 2023) >= Date(4, 5, 2023)) << "\n";

	cout << boolalpha << "5.7.2022 <= 5.7.2022: "
		<< (Date(5, 7, 2022) <= Date(5, 7, 2022)) << "\n";

	cout << boolalpha << "3.12.2023 == 4.5.2023: "
		<< (Date(3, 12, 2023) == Date(4, 5, 2023)) << "\n";

	cout << boolalpha << "3.12.2023 != 4.5.2023: "
		<< (Date(3, 12, 2023) != Date(4, 5, 2023)) << "\n\n";

	cout << obj1 << "\nDate[0]: " << obj1[0]
		<< "\nDate[1]: " << obj1[1]
		<< "\nDate[2]: " << obj1[2] << "\n";
}

bool searchFor(int num, int* Arr, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (num == Arr[i])
			return true;
	}
	return false;
}
