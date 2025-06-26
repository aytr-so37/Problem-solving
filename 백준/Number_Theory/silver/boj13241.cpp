#include<iostream>
 
using namespace std;
using ull=unsigned long long;
 
ull divide(ull x, ull y)
{
    if (x % y == 0)
        return y;
    else
        return divide(y, x % y);
}
 
int main()
{
  
    ull A, B;
 

    cin >> A >> B;
    if (A >= B)
    {
        cout << A  / divide(A, B) * B << "\n";
    }
    else cout << A / divide(B, A) * B << "\n"; 

}
