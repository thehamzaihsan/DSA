#include <iostream>
using namespace std;

class Cube
{
    int x;

public:
    void CubeMe(int *a)
    {
        x = *a;
        *a = x * x * x;
    }
};

int main()
{
    Cube c;
    int x;
    cout << "Enter a number: ";
    cin >> x;
    c.CubeMe(&x);
    cout << x << endl;
    return 0;
}