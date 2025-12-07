# Graph Theory

## 무방향 그래프 (non-directed)

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

## Topological Sorting (위상정렬)

- non-cycle, directed gragh에서 edge의 연결에 따라 일렬로 정렬하는 것
- indegree(들어오는 간선의 수)를 관리하며 정렬시킬 수 있음
- 임계 간선은 dist[u] + cost[u, v] = dist[v]를 만족시키는 간선인데 이것으로 리버스 그래프를 통해 경로를 추적할 수 있음

## Network Flow 
<img width="600" height="300" alt="image" src="https://github.com/user-attachments/assets/e3f98ff4-d7dd-485a-bac8-2e07956812bc" />

- ![내용정리](https://github.com/LeeHan20/univ_studying/edit/main/sophomore%20autumn%20semester/algorithm/week%2014%20%3A%20%EA%B0%9C%EB%85%90)
- ford-fulkerson -> edmonds-karp
- 이분 매칭, disjoint path 등등... 매우 유용하게 사용할 수 있음
- 한 번만 구현하면 활용처가 굉장히 많음
