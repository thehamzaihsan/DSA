#include <iostream>
using namespace std;

int main()
{
    char str1[] = "Defined as an array";
    const char *str2 = "Defined as a pointer";
    cout << str1 << endl;
    cout << str2 << endl;
    // str1++;
    str2++;
    cout << str2 << endl;
}
