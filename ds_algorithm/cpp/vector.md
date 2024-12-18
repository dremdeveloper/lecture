
# C++ Vector (벡터)에 대한 설명

## 1. 컨테이너의 특징
C++의 벡터는 동적 배열(dynamic array)을 구현한 STL(Standard Template Library) 컨테이너입니다. 다음과 같은 특징을 가집니다:
- 크기가 가변적으로 조정되며, 요소들은 메모리상에서 연속적으로 저장됩니다.
- 임의 접근(Random Access)이 가능하며, 배열처럼 인덱스를 이용한 접근이 빠릅니다.
- 요소의 추가/삭제가 용이하며, 내부적으로 메모리를 자동으로 관리합니다.
- 크기 조정 과정에서 재할당이 발생할 수 있습니다.

## 2. 제공하는 주요 메서드
C++ 벡터가 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명           | 파라미터                     | 시간 복잡도  | 반환값         | 특이사항 및 대체 가능한 메서드 | 사용 시 주의점                              |
|---------------------|------------------------------|--------------|---------------|--------------------------------|---------------------------------------------|
| `push_back`         | `value`                     | Amortized O(1) | 없음          | 리스트와 비교해 더 빠른 임의 접근 제공  | 공간 재할당 발생 시 느려질 수 있음           |
| `pop_back`          | 없음                        | O(1)         | 없음          | -                              | 마지막 요소 제거                             |
| `insert`            | `iterator, value`           | O(n)         | `iterator`    | -                              | 중간 삽입 시 비효율적                        |
| `erase`             | `iterator`                 | O(n)         | `iterator`    | -                              | 삭제 이후 요소들이 재배치됨                  |
| `size`              | 없음                        | O(1)         | `size_t`      | -                              | 현재 저장된 요소의 개수를 반환               |
| `capacity`          | 없음                        | O(1)         | `size_t`      | -                              | 할당된 메모리 크기를 반환                    |
| `clear`             | 없음                        | O(n)         | 없음          | -                              | 모든 요소 제거, capacity는 유지됨             |

## 3. 해당 컨테이너가 자주 사용되는 상황
- 요소의 임의 접근이 필요하면서, 크기를 동적으로 조정해야 하는 경우
- 기존 배열보다 더 높은 수준의 메모리 관리와 유연성을 제공받고자 할 때
- 데이터를 순차적으로 삽입/삭제하면서도 성능을 유지하고자 할 때

## 4. 예시 코드

```cpp
#include <iostream>
#include <vector>

int main() {
    // 벡터 생성
    std::vector<int> numbers = {1, 2, 3};

    // 요소 추가
    numbers.push_back(4);
    numbers.push_back(5);

    // 요소 출력
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 특정 위치에 요소 삽입
    numbers.insert(numbers.begin() + 1, 10);

    // 요소 삭제
    numbers.erase(numbers.begin());  // 첫 번째 요소 삭제

    // 크기 및 용량 확인
    std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;

    // 모든 요소 제거
    numbers.clear();
    std::cout << "After clear, size: " << numbers.size() << std::endl;

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
