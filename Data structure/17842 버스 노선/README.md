# 버스 노선 / Gold 2
 
## 시간 제한	메모리 제한	
1 초	512 MB	

## 제출 정보
2025/3/14

18264KB, 120ms
## 문제
울산광역시는 큰 도시라 고도로 발달했으면서도 복잡한 교통 체계를 가지고 있다. 울산광역시의 교통 체계는 정류장(정점)과 그 정류장을 잇는 도로(간선)들로 나타낼 수 있다. 정류장과 도로를 모은 그래프는 순환하는 경로가 발생하지 않는 형태이며, 서로 다른 두 정류장을 잇는 경로는 항상 만들 수 있다. 즉, 트리 모양이다.

이번에 교통과에 취직한 윤표는 버스 노선이 너무 많다고 생각해 이를 정리하기로 마음먹었다. 과감하게도, 윤표는 기존에 있던 버스 노선들을 모두 없애 버리고 버스 노선들을 새롭게 구성하려고 한다. 각각의 버스 노선은 다음과 같이 정의할 수 있다.

출발 정류장과 도착 정류장이 있다.
출발 정류장에서 도착 정류장에 가기까지 몇 개의 정류장을 정해진 순서대로 경유할 수 있다. 경유지의 수에는 제한이 없으며, 아무 정류장도 경유하지 않고 출발지에서 도착지로 바로 갈 수도 있다. 물론, 경유지를 지나가는 순서도 윤표가 정할 수 있다.
어떤 버스 노선이 K개의 정류장을 방문하고, 방문하는 정류장들을 순서대로 정류장 1, 정류장 2, … ,정류장 K라고 할 때, 정류장 i(1 ≤ i ≤ K-1)와 정류장 i+1 사이에는 도로가 존재해야 한다. 이때 정류장 i와 i+1을 잇는 도로는 이 버스 노선이 지나가는 도로라고 부른다.
같은 정류장을 여러 번 방문해서는 안된다. 즉, 출발지와 도착지, 그리고 모든 경유지는 다른 정류장이어야 한다.
윤표는 모든 도로에 적어도 하나 이상의 버스 노선이 지나가도록 버스 노선을 구성하고 싶다. (도로에서 노선이 지나가는 방향은 어떤 방향도 상관없다.) 또한, 윤표는 버스 노선의 개수가 최소화되기를 원한다. 윤표를 도와, 모든 도로에 적어도 하나 이상의 버스 노선이 지나가도록 할 때 버스 노선의 최소 개수를 구하는 프로그램을 작성하자.

## 입력
첫 번째 줄에 정류장의 수 N(2 ≤ N ≤ 200,000)가 주어지며 정류장은 0부터 N-1까지 고유한 번호를 가진다.

두 번째 줄부터 N번째 줄까지 도로로 연결된 두 정류장 쌍이 주어진다. 같은 도로가 여러 번 주어지지 않는다.

## 출력
버스 노선을 정리했을 때 노선의 최소 개수를 출력한다.

## 출처
University > UNIST > 제 1회 UNIST 알고리즘 프로그래밍 경시대회 Uni-CODE E번

## 알고리즘 분류

그리디 알고리즘

트리
