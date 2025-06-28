#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int c1 = a1 * b2 + a2 * b1;
    int c2 = a2 * b2;
    
    int both = (c1 > c2) ? gcd(c1, c2) : gcd(c2, c1);
    cout << c1 / both << " " << c2 / both;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
