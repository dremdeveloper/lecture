
# C++ Unordered Set (언오더드 셋)에 대한 설명

## 1. 컨테이너의 특징
C++의 `unordered_set`은 고유한 값을 저장하는 연관 컨테이너로, 요소들이 해시 테이블(hash table)을 기반으로 저장됩니다. 다음과 같은 특징을 가집니다:
- 요소는 순서가 없으며, 삽입된 순서를 유지하지 않습니다.
- 중복된 값을 허용하지 않습니다.
- 평균적으로 삽입, 삭제, 탐색의 시간 복잡도는 O(1)이지만, 해시 충돌이 발생할 경우 최악의 경우 O(n)까지 증가할 수 있습니다.
- 효율적인 해싱을 위해 요소는 반드시 해시 가능하고 `==` 연산이 정의되어 있어야 합니다.

## 2. 제공하는 주요 메서드
C++ `unordered_set`이 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명        | 파라미터           | 시간 복잡도 | 반환값         | 특이사항 및 대체 가능한 메서드 | 사용 시 주의점                             |
|------------------|--------------------|-------------|---------------|-------------------------------|-------------------------------------------|
| `insert`         | `value`           | O(1)        | `pair<iterator, bool>` | -                             | 중복된 값은 삽입되지 않음                  |
| `emplace`        | `value`           | O(1)        | `pair<iterator, bool>` | `insert`보다 효율적일 수 있음  | 객체 복사가 필요하지 않음                   |
| `erase`          | `iterator`, `value` | O(1)      | `size_t`      | -                             | 존재하지 않는 값을 삭제해도 에러 없음       |
| `find`           | `value`           | O(1)        | `iterator`    | -                             | 값이 존재하지 않으면 `end()` 반환           |
| `count`          | `value`           | O(1)        | `size_t` (0 또는 1) | -                             | 값의 존재 여부 확인 가능                   |
| `size`           | 없음              | O(1)        | `size_t`      | -                             | 현재 저장된 요소의 개수를 반환              |
| `clear`          | 없음              | O(n)        | 없음          | -                             | 모든 요소를 제거                            |
| `begin` / `end`  | 없음              | O(1)        | `iterator`    | -                             | 순회(iteration)를 위한 시작 및 끝 위치 반환 |

## 3. 해당 컨테이너가 자주 사용되는 상황
- 정렬이 필요 없고 빠른 삽입, 삭제, 탐색이 중요한 경우
- 데이터의 중복을 허용하지 않으며, 해싱을 통해 성능을 최적화하고자 할 때
- 대량의 데이터에서 고유한 값을 빠르게 관리해야 할 때

## 4. 예시 코드

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    // unordered_set 생성
    std::unordered_set<int> numbers;

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

    // 요소 삭제
    numbers.erase(15);

    // 크기 확인
    std::cout << "unordered_set 크기: " << numbers.size() << std::endl;

    // 버킷 수 확인
    std::cout << "Bucket count: " << numbers.bucket_count() << std::endl;

    // 모든 요소 제거
    numbers.clear();
    std::cout << "unordered_set이 비어 있는가? " << (numbers.empty() ? "Yes" : "No") << std::endl;

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
