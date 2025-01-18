# 그래프 이론

## 무방향 그래프

![image](https://github.com/user-attachments/assets/71303f02-7879-44c6-92cb-3ea026addb0c)

- 인접 리스트를 통해 구현
- 탐색 시에 visited 백터가 필요함
- vector<vector<int>>

## 2차원 그래프

![image](https://github.com/user-attachments/assets/414ec2af-dde6-429f-ae17-fa6d7c5edd49)

- 2차원 백터로 구현
- bfs와 dfs를 이용하여 탐색
- visited를 사용하거나 map을 직접 수정함

## Dijkstra

![image](https://github.com/user-attachments/assets/07f8b2cc-b7f2-40e5-bce0-beff0f9e5b99)

- priority queue를 이용하여 구현
- 가중치가 있는 그래프에서 최단 경로를 보장함
- previous vector를 사용하거나 dp table을 이용해 경로를 추적할 수 있음
