
# C++ Priority Queue (우선순위 큐)에 대한 설명

## 1. 컨테이너의 특징
C++의 `priority_queue`는 최대 힙(max-heap)을 기본으로 구현된 우선순위 큐 컨테이너입니다. 다음과 같은 특징을 가집니다:
- 가장 높은 우선순위를 가진 요소가 항상 큐의 맨 앞에 위치합니다.
- 기본적으로 최대 힙으로 동작하며, 사용자 정의 비교 함수를 통해 최소 힙(min-heap)으로도 사용 가능합니다.
- 내부적으로 힙(heap)을 구현하기 위해 벡터(std::vector)를 사용합니다.
- 삽입과 삭제의 시간 복잡도는 O(log n)입니다.

## 2. 제공하는 주요 메서드
C++ 우선순위 큐가 제공하는 주요 메서드들을 아래와 같은 표로 정리했습니다.

| 메서드 명        | 파라미터         | 시간 복잡도  | 반환값         | 특이사항 및 대체 가능한 메서드 | 사용 시 주의점                             |
|------------------|------------------|--------------|---------------|-------------------------------|-------------------------------------------|
| `push`           | `value`         | O(log n)     | 없음          | -                             | 요소를 힙에 추가                           |
| `emplace`        | `arguments`     | O(log n)     | 없음          | `push`보다 효율적일 수 있음    | 객체 복사가 필요하지 않음                   |
| `pop`            | 없음            | O(log n)     | 없음          | -                             | 가장 높은 우선순위의 요소 제거              |
| `top`            | 없음            | O(1)         | `const T&`    | -                             | 가장 높은 우선순위의 요소 반환              |
| `empty`          | 없음            | O(1)         | `bool`        | -                             | 큐가 비어 있는지 여부 반환                  |
| `size`           | 없음            | O(1)         | `size_t`      | -      

## 3. 해당 컨테이너가 자주 사용되는 상황
- 우선순위가 높은 작업을 먼저 처리해야 하는 작업 스케줄링
- 가장 크거나 가장 작은 값의 반복적인 검색 및 삭제가 필요한 경우
- 다익스트라 알고리즘 등 그래프 기반 알고리즘에서 효율적인 큐 관리가 필요한 경우

## 4. 예시 코드

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 기본 최대 힙 (default: max-heap)
    std::priority_queue<int> maxHeap;

    // 요소 삽입
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    // 가장 큰 요소 확인
    std::cout << "Max element: " << maxHeap.top() << std::endl;

    // 요소 제거
    maxHeap.pop();

    // 나머지 요소 출력
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    // 최소 힙 (min-heap) 구현
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 요소 삽입
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    // 최소 힙 요소 출력
    std::cout << "Min-heap elements: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

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
