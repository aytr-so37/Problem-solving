# Problem-solving

##### 빠른 입출력
```cpp
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
```

##### 1인 비트 개수 세기
```cpp
int countBits(int x) {
	int count = 0;
	while (x) {
		count += (x & 1);
		x >>= 1;
	}
	return count;
}
```
