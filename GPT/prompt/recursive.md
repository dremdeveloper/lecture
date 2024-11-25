
# 내가 한 질의 / GPT 답변

## 내가 한 질의
아래 코드 실행 시 callTrace를 출력해줘  

[요구사항]  
1. 함수 인자 및 반환값 포함  
2. │, └── 등을 활용해 호출 관계를 트리 형태로 표시  
3. 원본 코드 수정하지 말고, callTrace만 보여줘  

[코드]  
```python
def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

print(fibonacci(4))
```

---

## GPT 답변

### Call Trace (Tree Structure with Return Values)
```
fibonacci(4)
├── fibonacci(3)
├── ├── fibonacci(2)
├── ├── ├── fibonacci(1)
├── ├── ├── └── return 1
├── ├── └── fibonacci(0)
├── ├── └── └── return 0
├── ├── └── return 1
├── └── fibonacci(1)
├── └── └── return 1
├── └── return 2
└── fibonacci(2)
└── ├── fibonacci(1)
└── ├── └── return 1
└── └── fibonacci(0)
└── └── └── return 0
└── └── return 1
└── return 3
```

### 최종 반환값
- 결과값: `3`
