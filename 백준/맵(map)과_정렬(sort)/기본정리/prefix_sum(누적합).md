#### 1. what is prefix sum
- `prefix` 는 *시작부터 특정 지점까지* 의 의미를 가지고 있다.
  따라서, `prefix sum`은 흔히 말하는 `누적 합`을 말한다.
- `누적 합`은 배열의 구간의 합을 빠르게 구할 수 있도록 구현해 놓는 것을 말한다.

#### 2. implementation
vector로 구현하면서 맨 앞 요소를 0을 집어넣어준다.
&rarr; `1-based-index`로 올려주는 겸, $S[j]-S[i-1]$를 구현해줄 겸

##### 단순 for문으로

```cpp
vector<int> my_array = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int a,b;
cin>>a>>b; // 1-based-index라 가정
int prefix_sum=0;
for(int i=a-1;i<b;++i){
  prefix_sum += i;
}
cout<<prefix_sum<<"\n";
```

##### prefix sum 구현

```cpp
vector<int> my_array = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
vector<int> pre(my_array.size()+1,0);
for(int i=1;i<=my_array.size();++i){
  pre[i]=pre[i-1]+my_array[i-1];
} // 이건 좀 복잡해 보이지만 애초에 수를 받을 때부터 구현해주면 된다.

int a,b;
cin>>a>>b;
int prefix_sum=pre[b]-pre[a-1];
cout<<prefix_sum<<"\n";
```

- 시간 복잡도 상으로 보면
  - 단순 for문으로 구현하였을 땐 $O(n)$
  - prefix sum을 구현해주었을 땐 $O(1)$

