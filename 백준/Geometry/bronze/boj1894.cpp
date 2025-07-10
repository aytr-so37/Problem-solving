#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    while (1) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (cin.eof() == true) break;
        
        

        double rx = 0, ry = 0;
        if (x1 == x2 && y1 == y2) {
            rx = x3 + x4 - x1;
            ry = y3 + y4 - y1;
        }
        else if (x1 == x3 && y1 == y3) {
            rx = x2 + x4 - x1;
            ry = y2 + y4 - y1;
        }
        else if (x1 == x4 && y1 == y4) {
            rx = x2 + x3 - x1;
            ry = y2 + y3 - y1;
        }
        else if (x2 == x3 && y2 == y3) {
            rx = x1 + x4 - x2;
            ry = y1 + y4 - y2;
        }
        else if (x2 == x4 && y2 == y4) {
            rx = x1 + x3 - x2;
            ry = y1 + y3 - y2;
        }
        else if (x3 == x4 && y3 == y4) {
            rx = x1 + x2 - x3;
            ry = y1 + y2 - y3;
        }
        cout << setprecision(3) << fixed;
        cout << rx << " " << ry << "\n";
    }
}
