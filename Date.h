#include <string>

using namespace std;

class Date
{
public:
	// constructor
	// overloaded by additional argument data type.
	//default
	Date();
	//copy constructor
	Date(const Date&);
	
	// ISO format constructor
	explicit Date(string yy, string mm, string dd);

	// US format constructor
	explicit Date(string mm, string dd, string yy, int a);

	//String format constructor
	explicit Date(string mm, string dd, string yy, char b);

	//int format constructor
	explicit Date(int yy, int mm, int dd);

	// move constructor 
	Date(Date&&);

	// data type conversion constructor
	Date(unsigned int days);
	// destructor
	~Date();

	// overload operator
	bool operator >(const Date& aDate) const;
	bool operator <(const Date& aDate) const; 
	bool operator ==(const Date& aDate) const;  
	// Date Date:: operator +(const Date& aDate) const;
	Date operator +(unsigned int days) const;  
	Date& operator ++ ();
	const Date operator ++(int);
	Date& operator=(Date&&);
	Date& operator=(const Date&);

	__int64 GetNums() const;
	string USFormat();
	string ISOFormat();
	string StringFormat();
	Date AddDays(int add_days);
	const char* GetActivity();
	void SetActivity(const char* text);

private:
	// Specifying the data members of date as private.
	int m_day{ 1 };
	int m_mon{ 1 };
	int m_year{ 1970 };
	const char* m_weekday{};
	char* m_activity{};
	// string month
	static string months[12];

	// month day
	static int days[12];

	bool SetIntFormat(int yy, int mm, int dd);
	
	bool SetDate(string yy, string dd, string mm, int mon_ind=0);
	
	void InvalidSet();

	// Default format member function
	void DefaultFormat();

	// check char in string is digit
	bool CheckDigit(string digit_str);

	// check function
	bool CheckFormat(string mm, string yy, string dd);


	bool CheckDigitLength(int len, string digit,const char* date_type);

	// get month value as int -> 1-12
	// if bad month input -> 0
	int GetIndMon(string mm);

	// date check
	bool CheckDate(int m_year_tmp, int m_mon_tmp, int m_day_tmp);

	void GetWeekday();

	bool IsLeapYear(int m_year_tmp);

};