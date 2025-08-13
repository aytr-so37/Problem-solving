
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using vi = vector<int>;

void recursion(string,int,int);
bool isValid(string);
int L, C;
vector<char>v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> L >> C;
    // L:length C: c개의 문자
    v.resize(C);
    for (int i = 0; i < C; ++i) {
        char a; cin >> a;
        v[i] = a;
    }// set

    sort(v.begin(), v.end());

    recursion("", 0 , 0);

    return 0;
}

void recursion(string chosed, int idx, int depth) {
    if (depth == L) {
        if (isValid(chosed)) {
            cout << chosed << "\n";
        }
    }
    else {
        for (int i = idx; i < C; ++i) {
            string t = chosed;
            t += v[i];
            recursion(t, i + 1, depth + 1);
        }
    }
}

bool isValid(string s) {
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            a++;
        }
        else b++;
        if (a >= 1 && b >= 2) {
            return true;
        }
    }
    return false;
}
