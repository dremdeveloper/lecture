
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


---
   **Contact Me**
| 채널                        | 내용                                                          |
|-----------------------------|--------------------------------------------------------------|
| [링크드인](https://www.linkedin.com/in/ultrasuperrok/)               |  1촌 신청 환영 합니다. |
| [오픈 채팅방](https://open.kakao.com/o/gX0WnTCf)             |  코딩 테스트 및 취준 관련 소통 공간 입니다. |
| 메일                   | ultrasuperrok@gmail.com  |
| [코딩 테스트 합격자 되기 C++ 강의](https://inf.run/H9yxm) |  알고리즘 무료 개념 강의 입니다. 자료도 같이 제공 합니다. |
