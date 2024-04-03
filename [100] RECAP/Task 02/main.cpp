#include <iostream>
using namespace std;

void assign(int *p, int *q)
{
    cin >> *p;
    cin >> *q ;
}

int main()
{
    int x, y;
    int *p = &x;
    int *q = &y;
    assign(p, q);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}
