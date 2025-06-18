### 1. What is Hashing

- **Hashing**은 데이터를 **특정 규칙에 따라 고정된 크기의 값**(**해시값**)으로 변환하는 방식이다.
- 사용하는 함수는 **해시 함수**라 한다.

1. 데이터 &rarr; 해시함수 &rarr; 고정된 크기의 값(숫자 등)
2. 같은 입력 == 항상 같은 해시 값 출력
3. 해시 값은 배열의 인덱스처럼 사용되기도 한다.

### 2. How to use

### 3. Relevant syntax ( C++ )
- `unordered_map` &rarr; Key-Value 쌍 저장
   : `python`의 `dictionary`와 동일
- `unordered_set` &rarr; 중복 없는 원소 저장
내부적으로 Hash를 사용하는 자료구조
