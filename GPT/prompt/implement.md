
# 내가 한 질의 / GPT 답변

## 내가 한 질의
아래 코드의 목적은 30세 이상인 사람만 필터링 하는거야  

[요구사항]  
1. 아래 코드에서 주석 처리된 부분을 완성해서 코드를 완성시켜줘  
2. 작성한 부분은 내용을 설명해주고, 최종코드도 작성해줘  

[코드]  
```python
# 입력 데이터
data = [
    {"name": "Alice", "age": 25},
    {"name": "Bob", "age": 30},
    {"name": "Charlie", "age": 35},
]

filtered_data = []  # data에서 filtered_data에 30세 이상인 경우만 필터링 되어야함

names = []  # filtered_data에서 이름만 뽑아서 names에 저장
print(names)
```

---

## GPT 답변

### 작성한 부분 설명

1. **30세 이상 필터링**
   - `filtered_data`를 완성하기 위해 `list comprehension`을 사용하여 `age`가 30 이상인 항목만 필터링합니다.
   - `if` 조건을 활용하여 데이터 구조를 유지한 채 조건을 적용합니다.

2. **이름만 추출**
   - `names` 리스트를 완성하기 위해 `filtered_data`에서 `name` 키의 값을 가져옵니다.
   - `list comprehension`을 사용하여 간결하고 효율적으로 구현합니다.

---

### 최종 코드

```python
# 입력 데이터
data = [
    {"name": "Alice", "age": 25},
    {"name": "Bob", "age": 30},
    {"name": "Charlie", "age": 35},
]

# 30세 이상 필터링
filtered_data = [person for person in data if person["age"] >= 30]

# 이름만 추출
names = [person["name"] for person in filtered_data]

print(names)
```

---

### 코드 실행 결과
- 출력: `['Bob', 'Charlie']`

---

### 추가적인 조언

1. **리스트 컴프리헨션 활용**  
   리스트 컴프리헨션은 간결하고 효율적이며 가독성을 높입니다. 조건부 필터링과 데이터 추출에 적합합니다.

2. **확장 가능성**  
   - 향후 복잡한 필터 조건이 추가될 경우, 함수로 분리하여 재사용성을 높일 수 있습니다.
  
---
   **Contact Me**
| 채널                        | 내용                                                          |
|-----------------------------|--------------------------------------------------------------|
| [링크드인](https://www.linkedin.com/in/ultrasuperrok/)               |  1촌 신청 환영 합니다. |
| [오픈 채팅방](https://open.kakao.com/o/gX0WnTCf)             |  코딩 테스트 및 취준 관련 소통 공간 입니다. |
| 메일                   | ultrasuperrok@gmail.com  |
| [코딩 테스트 합격자 되기 C++ 강의](https://inf.run/H9yxm) |  알고리즘 무료 개념 강의 입니다. 자료도 같이 제공 합니다. |

