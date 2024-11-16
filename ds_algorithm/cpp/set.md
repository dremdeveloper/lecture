
# C++ Set (셋)에 대한 설명

## 1. 컨테이너의 특징
C++의 `set`은 중복되지 않는 고유한 요소를 저장하는 연관 컨테이너입니다. 다음과 같은 특징을 가집니다:
- 요소는 자동으로 정렬된 상태를 유지합니다.
- 내부적으로 레드-블랙 트리(Red-Black Tree)를 사용하여 균형 이진 탐색 트리 형태로 구현됩니다.
- 삽입, 삭제, 탐색의 시간 복잡도는 O(log n)입니다.
- 키와 값의 개념이 동일하며, 요소 자체가 키 역할을 합니다.

## 2. 제공하는 주요 메서드
C++ `set`이 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명        | 파라미터             | 시간 복잡도  | 특이사항 및 대체 가능한 메서드 | 사용 시 주의점                             |
|------------------|----------------------|--------------|-------------------------------|-------------------------------------------|
| `insert`         | `value`             | O(log n)     | -                             | 중복된 값은 삽입되지 않음                  |
| `emplace`        | `value`             | O(log n)     | `insert`보다 더 효율적일 수 있음 | 객체 복사가 필요하지 않음                   |
| `erase`          | `iterator`, `value` | O(log n)     | -                             | 존재하지 않는 값을 삭제해도 에러 없음       |
| `find`           | `value`             | O(log n)     | -                             | 값이 존재하지 않으면 `end()` 반환           |
| `count`          | `value`             | O(log n)     | 항상 0 또는 1 반환             | 값의 존재 여부 확인 가능                   |
| `size`           | 없음                | O(1)         | -                             | 현재 저장된 요소의 개수를 반환              |
| `clear`          | 없음                | O(n)         | -                             | 모든 요소를 제거                            |
| `begin` / `end`  | 없음                | O(1)         | -                             | 순회(iteration)를 위한 시작 및 끝 위치 반환 |
| `lower_bound`    | `value`             | O(log n)     | -                             | 주어진 값 이상의 첫 번째 요소 반환          |
| `upper_bound`    | `value`             | O(log n)     | -                             | 주어진 값 초과의 첫 번째 요소 반환          |

## 3. 해당 컨테이너가 자주 사용되는 상황
- 데이터의 중복을 허용하지 않으면서 정렬된 상태를 유지하고 싶을 때
- 삽입, 삭제, 탐색이 빈번한 상황에서 정렬된 데이터를 유지해야 할 때
- 범위 기반 쿼리(예: 특정 값 이상 또는 초과)를 처리해야 할 때

## 4. 예시 코드

```cpp
#include <iostream>
#include <set>

int main() {
    // set 생성
    std::set<int> numbers;

    // 요소 삽입
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(15);

    // 중복 요소 삽입 시도
    numbers.insert(10);  // 삽입되지 않음

    // 요소 출력
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 특정 값 검색
    if (numbers.find(15) != numbers.end()) {
        std::cout << "15가 존재합니다." << std::endl;
    }

    // 범위 기반 검색
    auto it = numbers.lower_bound(15);
    if (it != numbers.end()) {
        std::cout << "15 이상의 첫 번째 값: " << *it << std::endl;
    }

    // 요소 삭제
    numbers.erase(15);

    // 크기 확인
    std::cout << "set의 크기: " << numbers.size() << std::endl;

    // 모든 요소 제거
    numbers.clear();
    std::cout << "set이 비어 있는가? " << (numbers.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

---
**Contact Me**
| 채널                        | 내용                                                          |
|-----------------------------|--------------------------------------------------------------|
| [링크드인](https://www.linkedin.com/in/ultrasuperrok/)               |  1촌 신청 환영 합니다. |
| [오픈 채팅방](https://open.kakao.com/o/gX0WnTCf)             |  코딩 테스트 및 취준 관련 소통 공간 입니다. |
| 메일                   | ultrasuperrok@gmail.com  |
| [코딩 테스트 합격자 되기 C++ 강의](https://inf.run/H9yxm) |  알고리즘 무료 개념 강의 입니다. 자료도 같이 제공 합니다. |
