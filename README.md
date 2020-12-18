# Data Structure HW1 - Container Class (MyIntVector)

## class MyIntVector

### 0. Private Member Variables - Private 멤버 변수

```C++
- int* data;            // Dynamic Allocate
- size_t allocated;     // Total Allocated Size
- size_t used;          // Used Size
```

### 1. Constructor - 생성자

```C++
- MyIntVector(size_t init_allocated = DF_CAPACITY);
  // Default Constructor
- MyIntVector(const MyIntVector& v);
  // Copy Constructor
```

### 2. Destructor - 소멸자

```C++
- ~MyIntVector();
```

### 3. Assignment Operator Overriding - 대입 연산자 오버라이딩

```C++
- MyIntVector& operator=(const MyIntVector& v);
```

### 4. Member Functions

```C++
- void push_back(int new_entry);
- void pop_back();
- void reserve(size_t new_capacity);
- size_t capacity() const;
- size_t size() const;
- bool is_empty() const;
- void clear();
```

### 5. Operator Overriding - 연산자 오버라이딩

```C++
- void operator+=(const MyIntVector& addend);
- int& operator[](size_t index);
- int& operator[](size_t index) const;
- MyIntVector operator+(const MyIntVector& v) const;
- MyIntVector operator-(const MyIntVector& v) const;
- int operator\*(const MyIntVector& v) const;
- bool operator==(const MyIntVector& v) const;
- MyIntVector operator-() const;
- void operator()(int num);
```

---

## Review

### 1. 클래스 사용자가 클래스 헤더파일만 보고도 클래스를 사용 가능하도록 Precondition과 Postcondition 작성

- Precondition: 함수 호출 시 충족되어야 하는 선행 조건
- Postcondition: Precondition을 만족하여 함수 호출 시,
  도출되는 정상적인 결과

### 2. 클래스 구현시에 가능한 경우, Precondition을 체크하는 것이 바람직함

- assert() 함수 사용, 사용자가 잘못된 입력을 한 경우 재입력 요구 등

### 3. 동적 할당을 이용한 경우, 다음 3가지 멤버함수를 필수적으로 구현할 것

- Copy Constructor - 복사 생성자
  > 객체를 Deep Copy(깊은 복사)하여 Data Sharing 방지
- Destructor - 소멸자
- Assignment Operator Overriding - 대입 연산자 오버라이딩
  > 객체를 Deep Copy(깊은 복사)하여 Data Sharing 방지  
  > 함수 반환형을 객체 reference(&)로 하여 Chaining 연산 가능하도록 함

### 4. Vector 클래스

- Linear Data Structure (선형 자료구조)
- 내부적으로 동적 할당으로 구현된 Dynamic Array 컨테이너
- capacity(할당된 전체 용량)가 넘어가면, 자동으로 reserve 함
- push_back(), pop_back()으로 배열의 뒤부터 삽입, 삭제 가능
- 배열과 마찬가지로 [] 연산 가능
