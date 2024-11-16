
# C++ Map (맵)에 대한 설명

## 1. 컨테이너의 특징
C++의 맵은 키-값 쌍(key-value pairs)을 저장하는 연관 컨테이너로, 내부적으로 키를 기준으로 정렬된 상태를 유지합니다. 다음과 같은 특징을 가집니다:
- 각 키는 고유하며, 중복되지 않습니다.
- 기본적으로 오름차순으로 정렬되며, 사용자 정의 비교 함수로 정렬 기준을 변경할 수 있습니다.
- 내부적으로 레드-블랙 트리(Red-Black Tree)를 사용하여 균형을 유지합니다.
- 삽입, 삭제, 탐색의 평균 시간 복잡도는 O(log n)입니다.

## 2. 제공하는 주요 메서드
C++ 맵이 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명        | 파라미터                    | 시간 복잡도  | 반환값                         | 특이사항 및 대체 가능한 메서드  | 사용 시 주의점                                   |
|------------------|-----------------------------|--------------|--------------------------------|---------------------------------|------------------------------------------------|
| `insert`         | `pair<Key, Value>`         | O(log n)     | `pair<iterator, bool>`         | -                               | 키가 이미 존재하면 삽입되지 않음                |
| `emplace`        | `key, value`               | O(log n)     | `pair<iterator, bool>`         | `insert`보다 더 효율적일 수 있음 | 객체 복사가 필요하지 않음                       |
| `erase`          | `iterator` 또는 `key`      | O(log n)     | `size_t` (삭제된 요소 개수)     | -                               | 키가 없는 경우 아무 일도 하지 않음              |
| `find`           | `key`                      | O(log n)     | `iterator`                     | -                               | 키가 존재하지 않으면 `end()` 반환               |
| `count`          | `key`                      | O(log n)     | `size_t` (0 또는 1)            | -                               | 항상 0 또는 1 반환 (키의 존재 여부 확인 가능)   |
| `size`           | 없음                       | O(1)         | `size_t`                       | -                               | 현재 저장된 키-값 쌍의 개수를 반환              |
| `clear`          | 없음                       | O(n)         | 없음                           | -                               | 모든 요소를 제거                                |
| `at`             | `key`                      | O(log n)     | `Value&`                       | `operator[]`로 대체 가능         | 키가 없으면 `std::out_of_range` 예외 발생       |
| `operator[]`     | `key`                      | O(log n)     | `Value&`                       | -                               | 키가 없으면 기본 생성자로 새 값 삽입            |
| `begin` / `end`  | 없음                       | O(1)         | `iterator`                     | -                               | 순회(iteration)를 위한 시작 및 끝 위치 반환     |


## 3. 해당 컨테이너가 자주 사용되는 상황
- 키를 기준으로 데이터를 정렬하여 저장해야 하는 경우
- 키를 사용해 빠르게 값을 검색하고 싶을 때
- 삽입, 삭제, 탐색이 빈번하지만 정렬 상태를 유지해야 하는 경우

## 4. 예시 코드

```cpp
#include <iostream>
#include <map>

int main() {
    // 맵 생성
    std::map<std::string, int> scores;

    // 요소 삽입
    scores["Alice"] = 90;
    scores["Bob"] = 85;
    scores.insert({"Charlie", 95});

    // 요소 출력
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 특정 키 검색
    if (scores.find("Alice") != scores.end()) {
        std::cout << "Alice의 점수: " << scores["Alice"] << std::endl;
    }

    // 요소 삭제
    scores.erase("Bob");

    // 크기 확인
    std::cout << "맵 크기: " << scores.size() << std::endl;

    // 모든 요소 제거
    scores.clear();
    std::cout << "맵이 비어 있는가? " << (scores.empty() ? "Yes" : "No") << std::endl;

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
