
# C++에서 유사한 동작을 하지만 성능이 다른 사례들

C++에서도 유사한 작업을 수행하는 여러 가지 메서드와 함수들이 있지만, 내부 구현과 시간 복잡도가 달라 성능에 차이가 날 수 있습니다. 특히 알고리즘 최적화와 같은 경우 성능을 고려한 올바른 메서드 선택이 중요합니다. 여기서는 몇 가지 대표적인 사례와 예시 코드를 설명합니다.

---

## 1. `std::vector::erase()`와 `std::deque::pop_front()`

- **동작**: 두 메서드는 모두 자료구조의 가장 앞쪽 요소를 제거합니다.
- **성능 차이**:
  - `std::vector::erase()`: 벡터의 첫 요소를 제거하는 데 \( O(n) \)의 시간 복잡도가 발생합니다. 벡터는 내부적으로 요소들을 재배열하기 때문에, 제거 후 남은 요소들을 앞으로 이동시켜야 합니다.
  - `std::deque::pop_front()`: 덱의 왼쪽 끝 요소를 제거하는 데 \( O(1) \)의 시간 복잡도로 매우 효율적입니다. 덱은 양쪽 끝에서 빠르게 요소를 추가 및 제거할 수 있도록 설계되었습니다.

```cpp
#include <iostream>
#include <vector>
#include <deque>

int main() {
    // Using vector erase()
    std::vector<int> vec = {1, 2, 3, 4};
    vec.erase(vec.begin());
    for (int v : vec) std::cout << v << " "; // 2 3 4

    std::cout << std::endl;

    // Using deque pop_front()
    std::deque<int> dq = {1, 2, 3, 4};
    dq.pop_front();
    for (int d : dq) std::cout << d << " "; // 2 3 4

    return 0;
}
```

---

## 2. `std::find()`와 `std::unordered_set::find()`

- **동작**: 특정 요소가 자료구조에 있는지 확인합니다.
- **성능 차이**:
  - `std::find()`: 벡터나 리스트에서 순차 검색을 수행하므로 \( O(n) \)의 시간 복잡도를 가집니다.
  - `std::unordered_set::find()`: 해시 테이블을 기반으로 하여 평균 \( O(1) \)의 시간 복잡도로 매우 빠르게 요소를 찾을 수 있습니다.

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // For std::find

int main() {
    // Using std::find with a vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    if (std::find(vec.begin(), vec.end(), 3) != vec.end()) {
        std::cout << "3 found in vector" << std::endl;
    }

    // Using std::unordered_set find()
    std::unordered_set<int> uset = {1, 2, 3, 4, 5};
    if (uset.find(3) != uset.end()) {
        std::cout << "3 found in unordered_set" << std::endl;
    }

    return 0;
}
```

---

## 3. 문자열 연결: `+=` 연산자 vs. `std::ostringstream`

- **동작**: 여러 문자열을 하나의 문자열로 결합합니다.
- **성능 차이**:
  - `+=` 연산자: 문자열을 `+=`로 연결하면 각 연결마다 새로운 문자열을 생성해 메모리를 사용하므로 \( O(n^2) \)의 시간 복잡도가 발생할 수 있습니다.
  - `std::ostringstream`: 효율적으로 문자열을 결합하는 클래스이며 \( O(n) \)의 시간 복잡도를 가집니다.

```cpp
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    // Using += operator for string concatenation
    std::vector<std::string> strings = {"Hello", "world", "from", "C++"};
    std::string result;
    for (const auto& s : strings) {
        result += s + " ";
    }
    std::cout << result << std::endl; // "Hello world from C++ "

    // Using std::ostringstream for string concatenation
    std::ostringstream oss;
    for (const auto& s : strings) {
        oss << s << " ";
    }
    std::cout << oss.str() << std::endl; // "Hello world from C++ "

    return 0;
}
```

---

## 4. `std::map` 검색과 `std::unordered_map` 검색

- **동작**: 특정 키가 자료구조에 있는지 확인합니다.
- **성능 차이**:
  - `std::map`: 이진 검색 트리를 기반으로 하여 \( O(\log n) \)의 시간 복잡도를 가집니다.
  - `std::unordered_map`: 해시 테이블을 기반으로 하여 평균 \( O(1) \)의 시간 복잡도를 가집니다.

```cpp
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    // Using std::map
    std::map<std::string, int> map = {{"Alice", 25}, {"Bob", 30}, {"Eve", 22}};
    if (map.find("Bob") != map.end()) {
        std::cout << "Bob found in map" << std::endl;
    }

    // Using std::unordered_map
    std::unordered_map<std::string, int> umap = {{"Alice", 25}, {"Bob", 30}, {"Eve", 22}};
    if (umap.find("Bob") != umap.end()) {
        std::cout << "Bob found in unordered_map" << std::endl;
    }

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

