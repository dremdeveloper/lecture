
# 프롬프트 엔지니어링 - 팩트 체크

## 1. 답변에 출저를 포함해달라고 했을때 이점
출처를 포함하면 답변의 신뢰성을 높이고, 학습자가 원문이나 관련 정보를 더 깊이 탐구할 수 있습니다. 출처와 링크를 통해 최신 정보와 권위 있는 자료에 접근이 가능하며, 해당 주제에 대한 깊은 이해를 돕습니다.

## 2. 질의
**질의:** 파이썬의 immutable 개념에 대해 설명해. 해당 답변을 할 때 참조한 데이터의 출처 및 링크를 같이 공유해.

## 3. 답변
파이썬에서 **immutable(불변성)** 이란, 객체가 생성된 후 그 값을 변경할 수 없는 특성을 의미합니다. 대표적인 예로 **int**, **float**, **str**, **tuple** 등이 있습니다. 불변 객체는 값 자체를 변경하는 것이 불가능하기 때문에, 새로운 값이 필요할 때마다 새로운 객체가 생성됩니다. 이렇게 하면 불변 객체는 메모리 관리와 프로그램의 안전성 측면에서 유리한 점이 있습니다.

### 예시:
```python
x = "Hello"
print(id(x))  # x의 id 출력
x = x + " World"
print(id(x))  # 새로운 객체가 생성되어 id가 달라짐
```

이 코드에서 `x`의 값이 변경될 때, 기존 객체가 아닌 새로운 객체가 생성됩니다.

### 출처 및 링크
- [Python Documentation on Immutable Types](https://docs.python.org/3/)