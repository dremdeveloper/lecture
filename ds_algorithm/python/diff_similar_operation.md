
# 파이썬에서 유사한 동작을 하지만 성능이 다른 사례들

파이썬에서는 유사한 작업을 수행하는 여러 가지 메서드와 함수들이 있지만, 내부 구현과 시간 복잡도가 달라 성능에 차이가 날 수 있습니다. 특히 코딩 테스트에서는 작은 차이가 성능에 큰 영향을 미칠 수 있기 때문에, 각 메서드의 시간 복잡도를 이해하고 올바르게 사용하는 것이 중요합니다. 여기서는 몇 가지 대표적인 사례와 예시 코드를 설명합니다.

---

## 1. `list.pop(0)`와 `deque.popleft()`

- **동작**: 두 메서드는 모두 자료구조의 가장 왼쪽 끝 요소를 제거하고 반환합니다.
- **성능 차이**:
  - `list.pop(0)`: 리스트의 첫 요소를 제거하는 데 \( O(n) \)의 시간 복잡도가 발생합니다. 리스트는 내부적으로 요소들을 재배열하기 때문에, 제거 후 남은 요소들을 앞으로 이동시켜야 합니다.
  - `deque.popleft()`: 덱의 왼쪽 끝 요소를 제거하는 데 \( O(1) \)의 시간 복잡도로 매우 효율적입니다. 덱은 양쪽 끝에서 빠르게 요소를 추가 및 제거할 수 있도록 설계되었습니다.

```python
from collections import deque

# list pop(0)
lst = [1, 2, 3, 4]
first_element = lst.pop(0)
print(first_element, lst)  # 1 [2, 3, 4]

# deque popleft()
dq = deque([1, 2, 3, 4])
first_element = dq.popleft()
print(first_element, dq)  # 1 deque([2, 3, 4])
```

---

## 2. `in` 연산자: 리스트 vs. 셋

- **동작**: 특정 요소가 자료구조에 있는지 확인합니다.
- **성능 차이**:
  - 리스트의 `in` 연산자: 리스트는 순차 검색을 수행하므로 \( O(n) \)의 시간 복잡도를 가집니다.
  - 셋의 `in` 연산자: 셋은 해시 테이블을 기반으로 하여 평균 \( O(1) \)의 시간 복잡도로 매우 빠르게 요소를 찾을 수 있습니다.

```python
# Using 'in' with a list
lst = [1, 2, 3, 4, 5]
print(3 in lst)  # True

# Using 'in' with a set
st = {1, 2, 3, 4, 5}
print(3 in st)  # True
```

---

## 3. 문자열 연결: `+` 연산자 vs. `join()` 메서드

- **동작**: 여러 문자열을 하나의 문자열로 결합합니다.
- **성능 차이**:
  - `+` 연산자: 문자열을 `+`로 연결하면 각 연결마다 새로운 문자열을 생성해 메모리를 사용하므로 \( O(n^2) \)의 시간 복잡도가 발생할 수 있습니다.
  - `''.join()`: 리스트와 같은 반복 가능한 객체의 문자열 요소를 효율적으로 결합하는 메서드로, \( O(n) \)의 시간 복잡도를 가집니다.

```python
# Using '+' operator for string concatenation
strings = ["Hello", "world", "from", "Python"]
result = ""
for s in strings:
    result += s + " "
print(result.strip())  # "Hello world from Python"

# Using ''.join() for string concatenation
result = " ".join(strings)
print(result)  # "Hello world from Python"
```

---

## 4. 딕셔너리 키-값 쌍 반복: `for key in dict` vs. `for key, value in dict.items()`

- **동작**: 딕셔너리의 모든 키-값 쌍을 반복합니다.
- **성능 차이**:
  - `for key in dict`: 딕셔너리의 키만을 반복하며, 각 키의 값에 접근하려면 `dict[key]`로 추가 조회를 해야 합니다.
  - `for key, value in dict.items()`: `items()` 메서드를 사용하면 키와 값을 동시에 반복하여 더 효율적입니다.

```python
# Using 'for key in dict'
d = {"name": "Alice", "age": 25, "city": "New York"}
for key in d:
    print(key, d[key])

# Using 'for key, value in dict.items()'
for key, value in d.items():
    print(key, value)
```

---
