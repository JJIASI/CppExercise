#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <sstream>
#include <utility>
#include <cstring>
#include "Date.h"

using namespace std;

// constructor
// overloaded by additional argument data type.

// defaule constructor
Date::Date()
{
    DefaultFormat();
}

//copy constructor
Date::Date(const Date &aDate)
{
    cout << "copy constructor called\n";
    m_day = aDate.m_day;
    m_mon = aDate.m_mon;
    m_year = aDate.m_year;
    m_weekday = aDate.m_weekday;
    if (aDate.m_activity != nullptr)
    {
        SetActivity(aDate.m_activity);
    }
}

//move constructor
Date::Date(Date &&aDate)
{
    cout << "move constructor called\n";
    m_day = aDate.m_day;
    m_mon = aDate.m_mon;
    m_year = aDate.m_year;
    m_weekday = aDate.m_weekday;
    m_activity = aDate.m_activity;
    aDate.m_activity = nullptr;
}

// ISO format constructor
Date::Date(string yy, string mm, string dd)
{
    // SetISOFormat(yy, mm, dd);
    SetDate(yy, dd, mm);
}

// US format constructor
Date::Date(string mm, string dd, string yy, int a)
{
    // SetUSFormat(mm, yy, dd);
    SetDate(yy, dd, mm);
}

//String format constructor
Date::Date(string mm, string dd, string yy, char b)
{
    int mon_ind{GetIndMon(mm)};
    if (mon_ind != 0)
    {
        SetDate(yy, dd, "NoMonth", mon_ind);
    }
    else
    {
        cout << "Wrong month name" << endl
             << endl;
    }
}

//int format constructor
Date::Date(int yy, int mm, int dd)
{
    SetIntFormat(yy, mm, dd);
}

// data type conversion constructor
Date::Date(unsigned int days)
{
    AddDays(days - 1);
}
// destructor
Date::~Date()
{
    cout << "destructor called\n";
    if (m_activity != nullptr)
    {
        delete[] m_activity;
        m_activity = nullptr;
    }
};

string Date::USFormat()
{
    ostringstream ss;
    ss << setw(2) << setfill('0') << m_mon << "/"
       << setw(2) << setfill('0') << m_day << "/"
       << setw(4) << setfill('0') << m_year
       << " " << m_weekday;
    if (m_activity == nullptr)
    {
        return ss.str();
    }
    else
    {
        return ss.str() + ", " + m_activity;
    }
}

string Date::ISOFormat()
{
    ostringstream ss;
    ss << setw(4) << setfill('0') << m_year << "/"
       << setw(2) << setfill('0') << m_mon << "/"
       << setw(2) << setfill('0') << m_day
       << " " << m_weekday;
    if (m_activity == nullptr)
    {
        return ss.str();
    }
    else
    {
        return ss.str() + ", " + m_activity;
    }
}

string Date::StringFormat()
{
    ostringstream ss;
    ss << months[m_mon - 1] << " "
       << setw(2) << setfill('0') << m_day << ","
       << setw(4) << setfill('0') << m_year
       << " " << m_weekday;
    if (m_activity == nullptr)
    {
        return ss.str();
    }
    else
    {
        return ss.str() + ", " + m_activity;
    }
}

// string month
string Date::months[12] = {"January", "February", "March", "April",
                           "May", "June", "July", "August", "September", "October", "November", "December"};

// month day
int Date::days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Date::SetDate(string yy, string dd, string mm, int mon_ind)
{
    if (mm == "NoMonth")
    {
        if (CheckFormat("01", yy, dd))
        {
            // set members
            int year_tmp = atoi(yy.c_str());
            int mon_tmp = mon_ind;
            int day_tmp = atoi(dd.c_str());
            return SetIntFormat(year_tmp, mon_tmp, day_tmp);
        }
        else
        {
            InvalidSet();
            return false;
        }
    }
    else
    {
        if (CheckFormat(mm, yy, dd))
        {
            // set members
            int year_tmp = atoi(yy.c_str());
            int mon_tmp = atoi(mm.c_str());
            int day_tmp = atoi(dd.c_str());
            return SetIntFormat(year_tmp, mon_tmp, day_tmp);
        }
        else
        {
            InvalidSet();
            return false;
        }
    }
}

// int format member function
bool Date::SetIntFormat(int yy, int mm, int dd)
{

    // set members
    if (CheckDate(yy, mm, dd))
    {
        m_year = yy;
        m_mon = mm;
        m_day = dd;
        GetWeekday();
        return true;
    }
    else
    {
        InvalidSet();
        return false;
    }
}

void Date::InvalidSet()
{
    DefaultFormat();
    cout << "Set as default format.\n";
}

// Default format member function
void Date::DefaultFormat()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // set members
    m_year = timeinfo->tm_year + 1900;
    m_mon = timeinfo->tm_mon + 1;
    m_day = timeinfo->tm_mday;
    GetWeekday();
}

// check char in string is digit
bool Date::CheckDigit(string digit_str)
{
    for (char &c : digit_str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// check function
bool Date::CheckFormat(string mm, string yy, string dd)
{

    if (!CheckDigitLength(2, mm, "month (MM)"))
    {
        return false;
    }
    if (!CheckDigitLength(4, yy, "year (YYYY)"))
    {
        return false;
    }
    if (!CheckDigitLength(2, dd, "day (DD)"))
    {
        return false;
    }
    return true;
}

bool Date::CheckDigitLength(int len, string digit, const char *date_type)
{
    if (digit.length() != len)
    {
        cout << "Wrong" << date_type << "length!" << endl
             << endl;
        return false;
    }
    else
    {
        if (!CheckDigit(digit))
        {
            cout << date_type << "had invalid value." << endl
                 << endl;
            return false;
        }
    }
    return true;
}

// get month value as int -> 1-12
// if bad month input -> 0
int Date::GetIndMon(string mm)
{
    for (int i = 0; i < 12; i++)
    {
        if (months[i] == mm)
            return i + 1;
    }

    return 0;
}

// date check
bool Date::CheckDate(int year_tmp, int mon_tmp, int day_tmp)
{

    // year check
    if (year_tmp < 1970)
    {
        cout << "Invalid! years <1970  !" << endl;
        return false;
    }

    if (mon_tmp > 12 && mon_tmp <= 0)
    {
        cout << "Invalid! month > 12 !" << endl;
        return false;
    }

    // Leap year check and days check
    if (mon_tmp == 2 && IsLeapYear(year_tmp))
    {
        if (day_tmp > 29)
        {
            cout << "Invalid days!" << endl;
            return false;
        }
    }
    else
    {
        if (day_tmp > days[mon_tmp - 1] || day_tmp <= 0)
        {
            cout << "Invalid days!" << endl;
            return false;
        }
    }
    return true;
}

bool Date::IsLeapYear(int year_tmp)
{
    if (((year_tmp % 4) == 0 && (year_tmp % 100) != 0) || (year_tmp % 400) == 0)
        return true;
    return false;
}

void Date::GetWeekday()
{
    time_t rawtime;
    struct tm *timeinfo;
    const char *weekdays[] = {"Sunday", "Monday",
                              "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};

    // initialize struct of timeinfo with localtime
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    timeinfo->tm_mday = m_day;
    timeinfo->tm_mon = m_mon - 1;
    timeinfo->tm_year = m_year - 1900;
    mktime(timeinfo);
    m_weekday = weekdays[timeinfo->tm_wday];
}

Date Date::AddDays(int add_days)
{
    time_t rawtime;
    struct tm *timeinfo;
    // initialize struct of timeinfo
    rawtime = (time_t)0;
    timeinfo = gmtime(&rawtime);

    // set tm
    timeinfo->tm_mday = m_day + add_days;
    timeinfo->tm_mon = m_mon - 1;
    timeinfo->tm_year = m_year - 1900;
    mktime(timeinfo);

    // set members
    m_year = timeinfo->tm_year + 1900;
    m_mon = timeinfo->tm_mon + 1;
    m_day = timeinfo->tm_mday;
    GetWeekday();

    return *this;
}

__int64 Date::GetNums() const
{
    time_t rawtime;
    struct tm *timeinfo;
    rawtime = (time_t)0;
    timeinfo = gmtime(&rawtime);

    timeinfo->tm_mday = m_day;
    timeinfo->tm_mon = m_mon - 1;
    timeinfo->tm_year = m_year - 1900;
    rawtime = mktime(timeinfo);

    return rawtime;
}

//overloaded greater than operator
bool Date::operator>(const Date &aDate) const
{
    return this->GetNums() > aDate.GetNums();
};

//overloaded less than operator
bool Date::operator<(const Date &aDate) const
{
    return this->GetNums() < aDate.GetNums();
};

//overloaded equality operator
bool Date::operator==(const Date &aDate) const
{
    return this->GetNums() == aDate.GetNums();
};

// overloaded adding operator
Date Date::operator+(unsigned int days) const
{
    return Date(*this).AddDays(days);
};

// overloaded preincrement operator
Date &Date::operator++()
{
    this->AddDays(1);
    return *this;
};

// overloaded postincrement operator
const Date Date::operator++(int)
{
    Date tmp(*this);
    this->AddDays(1);
    return tmp;
};

// move assignment operator
Date &Date::operator=(Date &&aDate)
{
    if (this != &aDate)
    {
        delete[] m_activity;
        m_activity = aDate.m_activity;
        aDate.m_activity = nullptr;

        m_day = aDate.m_day;
        m_mon = aDate.m_mon;
        m_year = aDate.m_year;
        m_weekday = aDate.m_weekday;
    }

    return *this;
};

// asignment operator
Date& Date::operator=(const Date& aDate)
{
    m_day = aDate.m_day;
    m_mon = aDate.m_mon;
    m_year = aDate.m_year;
    m_weekday = aDate.m_weekday;
    if (aDate.m_activity != nullptr)
    {
        SetActivity(aDate.m_activity);
    }
    return *this;
};

const char *Date::GetActivity()
{
    return m_activity;
};

void Date::SetActivity(const char *text)
{
    if (m_activity != nullptr)
    {
        delete[] m_activity;
    }
    size_t length{strlen(text) + 1};
    m_activity = new char[length];
    strcpy_s(m_activity, length, text);
};