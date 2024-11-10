
# 코딩 테스트 문제 분석

## 1. 문제 설명
- **문제**: 주어진 리스트에서 특정 합을 갖는 연속 부분 배열을 찾아내는 문제입니다. 이 문제는 배열에서 연속된 부분 집합을 사용하여 타겟 합에 도달하는지 확인해야 하는 문제로, 효율적인 자료구조 및 알고리즘이 필요합니다.
- **입력 예시**: `nums = [1, 2, 3, 4, 5]`, `target = 9`
- **출력 예시**: `[2, 3, 4]` (이 수들의 합이 9이므로)

---

## 2. 문제 풀이 시도 및 막힌 상황

### 2.1 내가 시도한 로직
- **로직 설명**: 모든 가능한 연속 부분 배열을 찾기 위해 두 개의 반복문을 사용하여 각 부분 배열의 합을 계산하는 방법을 시도했습니다. 배열의 시작점과 끝점을 이동하며 합을 구하고, 합이 타겟과 일치하는지 확인했습니다.
- **코드**:
  ```python
  def find_subarray(nums, target):
      for start in range(len(nums)):
          for end in range(start + 1, len(nums) + 1):
              subarray = nums[start:end]
              if sum(subarray) == target:
                  return subarray
      return []
  ```

### 2.2 막힌 부분 분석
- **문제점**: 이중 반복문을 사용하여 모든 부분 배열의 합을 계산하는 방식은 입력 배열이 커질수록 시간이 많이 소요됩니다. 시간 복잡도가 \(O(n^2)\)이 되어 최적화가 필요합니다.
- **막힌 이유**: 배열이 커질 경우 효율적이지 않으며, 시간 초과가 발생할 수 있습니다.

---

## 3. 답안 코드 및 분석

### 3.1 답안 코드
- **최적화 로직**: 슬라이딩 윈도우 기법을 사용하여 배열의 시작과 끝을 이동하며 합을 조절하는 방식으로 효율성을 개선했습니다.
- **코드**:
  ```python
  def find_subarray(nums, target):
      start = 0
      current_sum = 0
      for end in range(len(nums)):
          current_sum += nums[end]
          while current_sum > target and start < end:
              current_sum -= nums[start]
              start += 1
          if current_sum == target:
              return nums[start:end + 1]
      return []
  ```

### 3.2 막혔던 부분 해결 분석
- **해결 방법**: 이중 반복문 대신 슬라이딩 윈도우를 사용하여 현재 합이 타겟을 초과할 때마다 왼쪽 끝을 오른쪽으로 이동시키며 합을 조정하는 방식으로 최적화하였습니다.
- **효과**: 시간 복잡도가 \(O(n)\)으로 줄어들어 큰 배열에서도 효율적으로 타겟 합을 찾을 수 있습니다.

---

### 3.3 답안 코드에 사용된 자료구조 및 알고리즘 정리
- **자료구조**: 배열(Array)
- **알고리즘**: 슬라이딩 윈도우 기법
  - **특징**: 고정된 윈도우 크기를 유지하지 않고, 윈도우 크기를 동적으로 조절하면서 배열의 일부만 검사하여 목표에 도달합니다.
  - **장점**: 시간 복잡도를 줄여주며, 특정 합을 만족하는 부분 배열을 효율적으로 탐색할 수 있습니다.