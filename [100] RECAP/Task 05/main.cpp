#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    void setTime(int h, int m, int s);
    void printTime();
};

void Time::setTime(int h, int m, int s)
{
    hour = 0;
    minute = 0;
    second = 0;
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::printTime()
{
    cout << "Time: " << hour << ":" << minute << ":" << second << endl;
}

void Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
}

int main()
{
    Time t;
    cout << "Time before setting values: ";
    t.printTime();
    t.setTime(10, 30, 45);
    cout << "Time after setting valid values: ";
    t.printTime();
    t.setTime(25, 70, 80);
    cout << "Time after setting invalid values: ";
    t.printTime();

    return 0;
}