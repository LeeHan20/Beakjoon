# 정수론

## 에라스토테네스의 채
- 일정 범위 내의 소수를 빠르게 구할 수 있음
- 기본 버전이 있고 최적화 버전이 있음
- for(int i = 0; i * i < goal; i++)

## 누적 합

![image](https://github.com/user-attachments/assets/c2664db9-35a4-45ed-962b-05c319684644)

- 이전의 결과를 가지고 다음 결과를 저장하는 것
- 점화식이 기본 원리

## 슬라이딩 윈도우

![image](https://github.com/user-attachments/assets/af28f3ce-6269-43b2-a0fa-9d3dbab93c4d)
- 기본적으로 1차원 백터에서 탐색할 경우 해당 범위 내에서의 값을 수행함
- 범위는 index를 넣은 deque으로 구현하는 것이 일반적
- for문 내의 변수로 범위를 조정함
