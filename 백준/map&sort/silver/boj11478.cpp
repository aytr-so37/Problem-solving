#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
using namespace std;

int main()
{
    string a; cin >> a;// 주어진 string
    unordered_set<string>v;


    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size() - i; ++j) {
            string temp=a.substr(j,i+1);
            if(v.find(temp)==v.end()){
                v.insert(temp);
            }
        }
    }

    cout << v.size();

}
