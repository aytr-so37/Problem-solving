### Brainstorming
- a*b mod c == ( a mod c * b mod c ) mod c 인 점 이용하기
- L 이 **50이상**인 subtask를 만족 시키려면 $31^{49}$ mod 1234567891의 연산이 필요함
  &rarr; `ull` 선언으로 오버플로우 방지
- 소문자 &rarr; `int`로 변환할 때 `chr-'a'+1` 이용 :)


```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

int main()
{
    int r = 31;
    ull mod = 1234567891;

    vector<ull>v(50);
    v[0] = 1;
    for (int i = 1; i < 50; ++i) {
        v[i] = v[i - 1] * 31 % mod;
    }  // mod 된 값을 미리 setting

        int L;
    string input;
    cin >> L >> input;

    ull result = 0;

    for (int i = 0; i < L; ++i) {
        int a = input[i] - 'a' + 1; // 알파벳 값
        result += a * v[i] % mod;
    }

    cout << result % mod << "\n";
}
```

