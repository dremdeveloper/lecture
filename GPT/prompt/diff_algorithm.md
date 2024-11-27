
# 내가 한 질의 / GPT 답변

## 내가 한 질의
N Queen 알고리즘을 완전탐색으로 풀었을 때랑 백트래킹으로 풀었을 때 코드를 Python으로 작성해줘  
이후, 성능 차이를 시뮬레이션하여 그래프로 보여줘 그리고 왜 이런 차이가 발생했는지 분석해  

[필수 사항]  
1. 시간복잡도 측면에서 분석  
2. 코드 레벨로 어떤 부분에서 연산횟수 차이가 많이 나게 되었는지 분석  
3. 각 알고리즘의 연산횟수 추이가 잘 나타나도록 그래프의 x, y값 선정  

---

## GPT 답변

### 완전탐색 (Brute Force)
```python
def n_queens_brute_force(n):
    def is_valid(board):
        row = len(board)
        for i in range(row):
            if board[i] == board[-1] or abs(board[i] - board[-1]) == row - i:
                return False
        return True

    def solve(board=[]):
        if len(board) == n:
            solutions.append(board[:])
            return
        for i in range(n):
            board.append(i)
            if is_valid(board):
                solve(board)
            board.pop()

    solutions = []
    solve()
    return len(solutions)
```

---

### 백트래킹 (Backtracking)
```python
def n_queens_backtracking(n):
    def solve(row, diagonals, anti_diagonals, cols):
        if row == n:
            return 1
        solutions = 0
        for col in range(n):
            diag = row - col
            anti_diag = row + col
            if col in cols or diag in diagonals or anti_diag in anti_diagonals:
                continue
            cols.add(col)
            diagonals.add(diag)
            anti_diagonals.add(anti_diag)
            solutions += solve(row + 1, diagonals, anti_diagonals, cols)
            cols.remove(col)
            diagonals.remove(diag)
            anti_diagonals.remove(anti_diag)
        return solutions

    return solve(0, set(), set(), set())
```

---

### 성능 시뮬레이션
두 알고리즘의 성능을 비교하기 위해 실행 시간을 측정합니다.

```python
import time
import matplotlib.pyplot as plt

def measure_execution_time():
    brute_force_times = []
    backtracking_times = []
    n_values = range(4, 12)  # N 값 증가

    for n in n_values:
        # Brute Force
        start_time = time.time()
        n_queens_brute_force(n)
        brute_force_times.append(time.time() - start_time)

        # Backtracking
        start_time = time.time()
        n_queens_backtracking(n)
        backtracking_times.append(time.time() - start_time)

    return n_values, brute_force_times, backtracking_times

# 실행 시간 측정
n_values, brute_force_times, backtracking_times = measure_execution_time()

# 결과 그래프
plt.figure(figsize=(10, 6))
plt.plot(n_values, brute_force_times, label="Brute Force", marker="o")
plt.plot(n_values, backtracking_times, label="Backtracking", marker="s")
plt.xlabel("N (Number of Queens)")
plt.ylabel("Execution Time (seconds)")
plt.title("N-Queens Algorithm Performance Comparison")
plt.legend()
plt.grid()
plt.show()
```

---

### 분석

1. **시간복잡도**:
   - **Brute Force**: \(O(n!)\) - 모든 가능한 배치를 시도합니다.
   - **Backtracking**: 평균적으로 \(O(n!)\)보다 훨씬 적은 연산을 수행합니다. 유효하지 않은 경로를 조기에 종료하기 때문입니다.

2. **코드 레벨 차이**:
   - 완전탐색에서는 `is_valid` 함수가 호출되는 모든 경우를 확인합니다. 비효율적인 탐색 경로도 포함됩니다.
   - 백트래킹은 `cols`, `diagonals`, `anti_diagonals`를 활용하여 유효하지 않은 경로를 미리 차단

3. **결과 시각화**:
   - 그래프는 `N`의 증가에 따라 두 알고리즘의 실행 시간 차이가 점진적으로 벌어지는 것을 보여줍니다.
   - 완전탐색은 기하급수적으로 시간이 증가하는 반면, 백트래킹은 훨씬 더 효율적으로 동작합니다.


---

### 결과 분석
![output (3)](https://github.com/user-attachments/assets/23e3d595-c9dc-4222-9344-a2ae1c8ae941)

#### 실행 시간 결과
- **Bruteforce**:  
  실행 시간은 \(N=4\)부터 급격히 증가하며, \(N=8\)에서 약 0.127초를 기록.  
  완전탐색 방식은 가능한 모든 경우의 수를 생성하고 유효성을 검사하므로, 입력 크기 \(N\)이 커질수록 연산량이 기하급수적으로 증가합니다.

- **Backtracking**:  
  실행 시간은 비교적 완만하게 증가하며, \(N=8\)에서 약 0.004초를 기록.  
  유망하지 않은 경로를 미리 차단하는 방식으로 탐색 공간을 크게 줄입니다.

#### 시간 복잡도 분석
- **Bruteforce**:  
  - 모든 가능한 순열을 생성 후 검증하므로 시간 복잡도는 \(O(N!)\)입니다.  
  - 각 순열에 대해 유효성을 검사하는 데 \(O(N^2)\)가 추가되어 전체 복잡도는 \(O(N! \cdot N^2)\)로 매우 큽니다.

- **Backtracking**:  
  - 백트래킹은 유망한 경우에만 탐색을 진행하므로 평균적으로 \(O(N!)\)보다 훨씬 효율적입니다.  
  - 정확한 시간 복잡도는 경우에 따라 다르지만, 실험적으로 \(O(k^N)\) (\(k < N\)) 수준으로 관찰됩니다.

#### 그래프 해석
- Bruteforce 방식은 \(N=8\)에서도 이미 실용적이지 않은 시간이 소요되는 반면, Backtracking은 효율적으로 실행됩니다.  
- 탐색 공간을 줄이는 백트래킹의 우수성이 시뮬레이션 결과와 그래프를 통해 명확히 나타납니다.

---

### 결론
Bruteforce는 작은 입력에서는 동작하지만, 입력 크기가 증가하면 실용적이지 않습니다. 반면, Backtracking은 탐색 공간을 줄이는 전략으로 훨씬 효율적으로 동작하며, 실용적으로 사용 가능한 방법임을 확인할 수 있습니다.
**Contact Me**
| 채널                        | 내용                                                          |
|-----------------------------|--------------------------------------------------------------|
| [링크드인](https://www.linkedin.com/in/ultrasuperrok/)               |  1촌 신청 환영 합니다. |
| [오픈 채팅방](https://open.kakao.com/o/gX0WnTCf)             |  코딩 테스트 및 취준 관련 소통 공간 입니다. |
| 메일                   | ultrasuperrok@gmail.com  |
| [코딩 테스트 합격자 되기 C++ 강의](https://inf.run/H9yxm) |  알고리즘 무료 개념 강의 입니다. 자료도 같이 제공 합니다. |
