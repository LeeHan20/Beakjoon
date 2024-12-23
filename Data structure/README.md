# 자료구조

## 스택 (stack)
- #include "stack"
- first in, last out
- 쓰면 굉장히 강력하지만 쓰기 어려움

## 큐 (queue)
- #include "queue"
- first in, first out
- bfs에서도 쓰이고 자유로운 아이디어를 구현하는 것에 자주 쓰임

## 덱 (deque)
- #include "deque"
- 앞뒤로 모두 pop과 push가 가능함
- vector에서 기능을 더 넣은 것이라고 생각하면 편함
- reverse, sort, []참조가 가능함
- 문자열 커서에 쓰이는 것 외에는 잘 안 쓰임

## 트리 (tree)
- 비정방 그래프와 같이 인접 리스트(linked list)로 구현함
- 주로 이진 트리가 자주 보이는데 할 때마다 머리아픔

## 우선순위 큐 (priority_queue)
- #include "priority_queue"
- 큐와 같이 push와 pop만 가능하지만 우선순위가 가장 높은 것이 front에 옴
- struct에서 맴버를 정의하고 operator를 정의하여 정렬 순위를 정해야 함
- heap 구조로 되어 있어 굉장히 빠르게 수행할 수 있음
- 사용자 정의 정렬이 귀찮아서 잘 안 씀

## 맵, 해시맵 (map, unordered_map)
- #include "map"
- #include "unordered_map"
- 키와 값의 자료형을 지정하여 키로 값에 접근하는 자료형
- map은 기본적으로 정렬된 상태가 보장됨
- 해시맵은 정렬이 보장되지 않고 빠른 접근이 가능함
