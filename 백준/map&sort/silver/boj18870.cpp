#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    vector<pair<int,int>>nums;

    int N;
    cin >> N;
   
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        nums.push_back({ a,i }); //원래 index를 기억할 용도로 pair로 저장
    }                            //setting -> 수들 모두 받기

    sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
        }); // 값 기준으로 정렬

    int prev = nums[0].first; // 그 전의 값들과 비교하는 용도
                              // 같으면 같은 수를 다르면 +1의 수를 first에 저장해주기

    nums[0].first = 0;
    for (int i = 1; i < N; ++i) {
        if (prev == nums[i].first) {
            nums[i].first = nums[i - 1].first;
        }
        // 그 전의 (scale-down 전) 값과 비교하여 같으면 (scale-down 후) 값을 그대로 받기
        else {
            prev = nums[i].first;
            nums[i].first = nums[i - 1].first + 1;
        }
        // 그 전의 (scale-down 전) 값과 비교하여 다르면 (scale-down 후) 값+1 을 받기

    }

    // 이후 pair.first에는 scale down 된 값이
    //      pair.second에는 처음 입력 받았을 때의 위치가 저장되어있음
    
    sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        }); // 입력 index 기준으로 정렬
    
    for (pair<int,int> p:nums) {
        cout << p.first << " ";
    }
}

