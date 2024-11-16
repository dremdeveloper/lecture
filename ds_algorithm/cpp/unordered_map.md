
# C++ Unordered Map (언오더드 맵)에 대한 설명

## 1. 컨테이너의 특징
C++의 `unordered_map`은 키-값 쌍(key-value pairs)을 저장하는 연관 컨테이너로, 요소들이 해시 테이블(hash table)을 기반으로 저장됩니다. 다음과 같은 특징을 가집니다:
- 요소는 순서가 없으며, 삽입된 순서를 유지하지 않습니다.
- 키는 고유하며, 중복되지 않습니다.
- 평균적으로 삽입, 삭제, 탐색의 시간 복잡도는 O(1)이지만, 해시 충돌이 발생할 경우 최악의 경우 O(n)까지 증가할 수 있습니다.
- 효율적인 해싱을 위해 키는 반드시 해시 가능하고 `==` 연산이 정의되어 있어야 합니다.

## 2. 제공하는 주요 메서드
C++ `unordered_map`이 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명        | 파라미터             | 시간 복잡도 | 특이사항 및 대체 가능한 메서드 | 사용 시 주의점                             |
|------------------|----------------------|-------------|-------------------------------|-------------------------------------------|
| `insert`         | `pair<Key, Value>`  | O(1)        | -                             | 중복된 키는 삽입되지 않음                  |
| `emplace`        | `key, value`        | O(1)        | `insert`보다 효율적일 수 있음  | 객체 복사가 필요하지 않음                   |
| `erase`          | `iterator`, `key`   | O(1)        | -                             | 존재하지 않는 키 삭제 시 아무 작업도 하지 않음 |
| `find`           | `key`               | O(1)        | -                             | 키가 존재하지 않으면 `end()` 반환           |
| `count`          | `key`               | O(1)        | 항상 0 또는 1 반환             | 키의 존재 여부 확인 가능                   |
| `size`           | 없음                | O(1)        | -                             | 현재 저장된 키-값 쌍의 개수를 반환          |
| `clear`          | 없음                | O(n)        | -                             | 모든 요소를 제거                            |
| `at`             | `key`               | O(1)        | `operator[]`로 대체 가능       | 키가 없으면 `std::out_of_range` 예외 발생   |
| `operator[]`     | `key`               | O(1)        | -                             | 키가 없으면 기본 생성자로 새 값 삽입        |
| `bucket_count`   | 없음                | O(1)        | -                             | 해시 테이블의 버킷 개수를 반환              |
| `load_factor`    | 없음                | O(1)        | -                             | 요소 개수와 버킷 개수의 비율 반환           |
| `rehash`         | `n`                 | O(n)        | -                             | 최소 버킷 개수를 `n` 이상으로 조정          |

## 3. 해당 컨테이너가 자주 사용되는 상황
- 정렬이 필요 없고 빠른 삽입, 삭제, 탐색이 중요한 경우
- 데이터의 중복을 허용하지 않으며, 해싱을 통해 성능을 최적화하고자 할 때
- 대량의 데이터에서 키를 기반으로 빠르게 값을 검색해야 할 때

## 4. 예시 코드

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    // unordered_map 생성
    std::unordered_map<std::string, int> scores;

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
    std::cout << "unordered_map 크기: " << scores.size() << std::endl;

    // 버킷 수 확인
    std::cout << "Bucket count: " << scores.bucket_count() << std::endl;

    // 모든 요소 제거
    scores.clear();
    std::cout << "unordered_map이 비어 있는가? " << (scores.empty() ? "Yes" : "No") << std::endl;

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
