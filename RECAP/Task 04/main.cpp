#include <iostream>
using namespace std;

class Counter
{
private:
    int count;

public:
    Counter();
    ~Counter(){};
    void countUp()
    {
        count++;
    }
    void displayCount()
    {
        cout << "Count: " << count << endl;
    }
};

Counter::Counter()
{
    count = 0;
}

int main()
{
    Counter c1, c2, c3, c4;
    c1.countUp();
    c2.countUp();
    c1.displayCount();
    c3.displayCount();
    c4.displayCount();
}