#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set> // -> find 이용
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    unordered_set<string>s;
    for (int i = 0; i < a; ++i) {
        string input;
        cin >> input;
        s.insert(input);
    } // unordered_set setting 해놓기
      // 이러고 다른 쪽은 받으면서 find 하며 겹치는 것만 골라내기

    vector<string>result; // 겹치는 애들 받아서 사전순 정렬 해줄 vec

    for (int i = 0; i < b; ++i) {
        string input;
        cin >> input;
        if (s.find(input) != s.end()) {
            result.push_back(input);
        }
    }

    sort(result.begin(), result.end()); //사전 순 정렬

    cout << result.size() << "\n";
    for (const string& str : result) {
        cout << str << "\n";
    }
}
