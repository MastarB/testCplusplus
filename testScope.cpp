#include <iostream>
using namespace std;

int main() 
{
    int a = 1;
    int &b = a;
    {
        int a = 2;
        cout << b << endl;
    }

    return 0;
}
