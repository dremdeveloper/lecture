
# Python Counter (카운터)에 대한 설명

## 1. 컨테이너의 특징
`collections.Counter`는 Python의 표준 라이브러리에서 제공하는 컨테이너로, 요소의 개수를 효율적으로 셀 수 있도록 설계된 해시 가능 객체입니다. 다음과 같은 특징을 가집니다:
- 요소의 빈도수를 저장하는 딕셔너리의 하위 클래스입니다.
- 키는 요소, 값은 해당 요소의 개수로 저장됩니다.
- 요소의 개수를 셀 때 매우 직관적이고 유용하며, 음수 또는 0의 카운트 값도 허용됩니다.

## 2. 제공하는 주요 메서드
Python `Counter`가 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명         | 파라미터          | 시간 복잡도 | 반환값         | 특이사항 및 대체 가능한 메서드 | 사용 시 주의점                          |
|-------------------|-------------------|-------------|---------------|-------------------------------|----------------------------------------|
| `elements`        | 없음              | O(n)        | `iterator`    | -                             | 카운트 값이 1 이상인 요소만 반환         |
| `most_common`     | `n=None`         | O(n log n)  | `list[tuple]` | -                             | 가장 빈도가 높은 n개의 요소 반환         |
| `subtract`        | `iterable 또는 mapping` | O(n)   | 없음          | -                             | 카운트 값을 빼는 연산 수행              |
| `update`          | `iterable 또는 mapping` | O(n)   | 없음          | -                             | 카운트 값을 추가                        |
| `clear`           | 없음              | O(1)        | 없음          | -                             | 모든 요소와 카운트를 제거                |
| `+`, `-`, `&`, `|` | `Counter 객체`   | O(n)        | `Counter`     | -                             | 덧셈, 뺄셈, 교집합, 합집합 연산 가능      |

## 3. 해당 컨테이너가 자주 사용되는 상황
- 문자열이나 리스트에서 각 요소의 빈도수를 효율적으로 셀 때
- 데이터 분석에서 빈도 기반 통계 처리에 사용될 때
- 가장 빈도가 높은/낮은 요소를 빠르게 찾고 싶을 때

## 4. 예시 코드

```python
from collections import Counter

# 리스트에서 요소 개수 세기
data = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple']
counter = Counter(data)

# 요소 출력
print(counter)  # Output: Counter({'apple': 3, 'banana': 2, 'orange': 1})

# 가장 빈도가 높은 요소 반환
print(counter.most_common(1))  # Output: [('apple', 3)]

# 요소 개수 업데이트
counter.update(['banana', 'orange', 'orange'])
print(counter)  # Output: Counter({'apple': 3, 'banana': 3, 'orange': 3})

# 요소 감소
counter.subtract(['apple', 'orange', 'orange'])
print(counter)  # Output: Counter({'banana': 3, 'apple': 2, 'orange': 1})

# elements() 사용
print(list(counter.elements()))  # Output: ['apple', 'apple', 'banana', 'banana', 'banana', 'orange']

# 카운터 초기화
counter.clear()
print(counter)  # Output: Counter()
```
---
**Contact Me**
| 채널                        | 내용                                                          |
|-----------------------------|--------------------------------------------------------------|
| [링크드인](https://www.linkedin.com/in/ultrasuperrok/)               |  1촌 신청 환영 합니다. |
| [오픈 채팅방](https://open.kakao.com/o/gX0WnTCf)             |  코딩 테스트 및 취준 관련 소통 공간 입니다. |
| 메일                   | ultrasuperrok@gmail.com  |
| [코딩 테스트 합격자 되기 C++ 강의](https://inf.run/H9yxm) |  알고리즘 무료 개념 강의 입니다. 자료도 같이 제공 합니다. |
