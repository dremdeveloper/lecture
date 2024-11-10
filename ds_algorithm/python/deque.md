
# 파이썬 덱(Deque) 개념과 활용

파이썬의 덱(Deque, Double-Ended Queue)은 양쪽 끝에서 요소를 추가하거나 제거할 수 있는 양방향 큐입니다. 덱은 `collections` 모듈의 `deque` 클래스를 사용하여 구현할 수 있으며, 리스트와 비슷하지만 특정 작업에서 더 효율적입니다.

## 1. 덱을 많이 활용하는 경우

덱은 다음과 같은 상황에서 자주 사용됩니다.

- **양쪽 끝에서 요소를 삽입/삭제해야 할 때**: 덱은 리스트와 달리 양쪽 끝에서의 삽입과 삭제가 매우 빠르기 때문에, 이러한 작업이 필요한 경우 유용합니다.
- **큐나 스택을 구현할 때**: 덱은 양방향에서 요소를 추가하고 제거할 수 있어 큐(FIFO)나 스택(LIFO)으로 쉽게 사용할 수 있습니다.
- **순차적인 데이터 처리**: 덱은 양쪽에서 데이터를 처리할 때 유용하며, 특히 슬라이딩 윈도우 알고리즘이나 데이터 스트림 처리가 필요한 경우 효과적입니다.

---

## 2. 덱에서 자주 활용되는 메서드

| 메서드               | 반환값           | 시간 복잡도       | 동작 설명 |
|----------------------|------------------|-------------------|-----------|
| `append()`           | `None`          | \( O(1) \)       | 덱의 오른쪽 끝에 요소 추가 |
| `appendleft()`       | `None`          | \( O(1) \)       | 덱의 왼쪽 끝에 요소 추가 |
| `pop()`              | 요소            | \( O(1) \)       | 덱의 오른쪽 끝 요소 제거 및 반환 |
| `popleft()`          | 요소            | \( O(1) \)       | 덱의 왼쪽 끝 요소 제거 및 반환 |
| `extend()`           | `None`          | \( O(k) \)       | 덱의 오른쪽 끝에 다른 반복 가능한 객체 추가 |
| `extendleft()`       | `None`          | \( O(k) \)       | 덱의 왼쪽 끝에 다른 반복 가능한 객체 추가 |
| `rotate()`           | `None`          | \( O(n) \)       | 덱의 요소를 회전하여 위치 변경 |
| `clear()`            | `None`          | \( O(n) \)       | 덱의 모든 요소 제거 |

---

## 3. 메서드 활용 예시

### 예제 1: `append()`와 `pop()`
```python
from collections import deque

# append()와 pop() 사용 예시
dq = deque([1, 2, 3])
dq.append(4)
print(dq)  # deque([1, 2, 3, 4])

last_element = dq.pop()
print(last_element)  # 4
print(dq)            # deque([1, 2, 3])
```

### 예제 2: `appendleft()`와 `popleft()`
```python
# appendleft()와 popleft() 사용 예시
dq = deque([1, 2, 3])
dq.appendleft(0)
print(dq)  # deque([0, 1, 2, 3])

first_element = dq.popleft()
print(first_element)  # 0
print(dq)             # deque([1, 2, 3])
```

### 예제 3: `extend()`와 `rotate()`
```python
# extend()와 rotate() 사용 예시
dq = deque([1, 2, 3])
dq.extend([4, 5])
print(dq)  # deque([1, 2, 3, 4, 5])

dq.rotate(2)
print(dq)  # deque([4, 5, 1, 2, 3])
```

---

## 4. 덱을 사용하지 말아야 하는 경우

덱은 특정 상황에서 효율적이지만, 모든 경우에 적합한 것은 아닙니다. 다음과 같은 경우에는 덱 대신 다른 자료구조를 고려하는 것이 좋습니다.

- **임의의 위치에 접근할 필요가 있을 때**: 덱은 양쪽 끝에서의 삽입과 삭제에 최적화되어 있지만, 임의의 인덱스로 접근하는 데에는 비효율적입니다. 특정 위치의 요소를 빈번하게 조회하거나 수정해야 한다면 리스트가 더 적합합니다.