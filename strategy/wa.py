def solution(record):
    # 1. cmd, uid, name을 저장할 배열을 정의합니다.
    logs = []
    
    # 2. 입력된 메시지를 logs에 저장합니다.
    for line in record:
        parts = line.split()
        
        if len(parts) == 3: 
            logs.append([parts[0], parts[1], parts[2]])
        else:
            logs.append([parts[0], parts[1], None])
        
  # 3. logs를 역순으로 순회하며 각 uid의 최종 닉네임을 logs에 저장합니다.
    for i in range(len(logs)):
        cmd, uid, name = logs[i]
        if cmd == 'Enter' or cmd == 'Change':
            # 동일한 uid를 가진 이전 로그의 final_name을 업데이트합니다.
            for j in range(i, -1, -1):
                if logs[j][1] == uid :
                    logs[j][2] = name
                                    
                
    # 4. logs를 순회하며 답을 구성합니다.
    answer = []
    for cmd, uid, name in logs:
        if cmd == 'Enter':
            answer.append(f"{name}님이 들어왔습니다.")
        elif cmd == 'Leave':
            answer.append(f"{name}님이 나갔습니다.")
        # 'Change' 명령은 출력하지 않습니다.    
    
    return answer
        
        
print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))
print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan", "Leave uid1234"]))
        
#['Prodo님이 들어왔습니다.', 'Ryan님이 들어왔습니다', 'Prodo님이 나갔습니다.', 'Prodo님이 들어왔습니다.']
#['Prodo님이 들어왔습니다.', 'Ryan님이 들어왔습니다.', 'Prodo님이 나갔습니다.', 'Prodo님이 들어왔습니다.', 'None님이 나갔습니다.']
