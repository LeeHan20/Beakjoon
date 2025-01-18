# 자료구조

## 스택 (stack)
- #include "stack"
- first in, last out
- 재귀를 스택으로 완전히 바꿀 수 있음 (재귀 함수는 내부적으로 함수 호출 스택을 사용기 때문임)

## Monotonic stack
- 단조 증가 스택의 경우 스택이 항상 오름차순으로 유지
- 스택에 삽입될 값이 스택의 최상단 값보다 작거나 같은 경우에만 추가
- 후위 표기식에서 스택을 쓰는 것과 유사
- 선형 시간 내에 해결 가능
- 스택을 이용하여 문제를 해결하는 일반적인 방법

## 큐 (queue)
- #include "queue"
- first in, first out
- bfs에서도 쓰이고 자유로운 아이디어를 구현하는 것에 자주 쓰임

## 덱 (deque)
- #include "deque"
- 앞뒤로 모두 pop과 push가 가능함
- 그냥 vector에서 queue 기능을 더 넣은 것
- reverse, sort, []참조가 가능함

## 트리 (tree)
- 비정방 그래프와 같이 인접 리스트(linked list)로 구현함
- 사이클이 존재하지 않기 때문에 visited 배열을 설정하지 않고 부모 노드로만 가지 않으면 됨
- 이론적인 부분이 많음

## 우선순위 큐 (priority_queue)
- #include "queue"
- queue 헤더에 포함되어 있음
- 큐와 같이 push와 pop만 가능하지만 우선순위가 가장 높은 것이 front에 옴
- struct에서 맴버를 정의하고 operator를 정의하여 정렬 순위를 정해야 함
- heap 구조로 되어 있어 작업을 빠르게 수행

## 맵, 해시맵 (map, unordered_map)
- #include "map"
- #include "unordered_map"
- 키와 값의 자료형을 지정하여 키로 값에 접근하는 자료형
- map은 기본적으로 정렬된 상태가 보장됨
- 해시맵은 정렬이 보장되지 않고 빠른 접근이 가능함
