# 색종이와 공예 / Gold 5
 
## 시간 제한, 메모리 제한
1 초	, 1024 MB	

## 풀이 정보
2024/12/23 

3130KB, 120ms

## 문제
준성이는 색종이를 가위로 자르고 남은 색종이 조각들로 뭘 할지 생각해 보았다.

군 생활 동안 열심히 고민해 본 결과, 색종이를 다시 이어붙여 색종이 공예품을 만들기로 했다!

준성이가 색종이를 이어 붙일 때는 다음과 같은 규칙을 따른다.

각 색종이 조각들은 변과 변을 맞대고 있으며, 일부 또는 전체가 겹치지 않는다.
이어 붙어진 색종이 조각들은 2차원 상에서 세로 길이가 
$N$, 가로 길이가 
$M$인 빈틈없는 직사각형 모양이다.
이때, 각 색종이 조각들이 모두 가로 길이와 세로 길이가 정수인 빈틈없는 직사각형 모양이라면 예쁜 색종이 공예품이라고 한다.
준성이는 열심히 만든 색종이 공예품을 당신에게 자랑하기 위해 보여줬다.

"ㅎㅎ 예쁘지?"

왠지 준성이가 기분이 좋아 보이는 것이 맘에 안 든다... 준성이가 만든 색종이 공예품을 보고 예쁘지 않다면 놀려주도록 하자!

## 입력
첫째 줄에 색종이 공예품의 세로 길이 
$N$, 가로 길이 
$M$이 공백을 두고 주어진다. 
$(1 \leq N,M \leq 1\,000)$ 

다음 
$N$개의 줄에 걸쳐 알파벳 대문자로 이루어진 길이가 
$M$인 문자열이 주어진다.

상하좌우로 인접한 두 알파벳이 같다면 서로 같은 색종이 조각이고, 그렇지 않다면 서로 다른 색종이 조각이다.

알파벳 하나의 세로 길이와 가로 길이는 모두 
$1$이며, 주어지는 숫자는 모두 정수다.

## 출력
입력으로 주어진 색종이 공예품이 예쁘다면 dd를 입력하고, 그렇지 않다면 BaboBabo를 출력한다.

## 출처
University > 한양대학교 ERICA 캠퍼스 > Zero One Algorithm Contest 2022 E번

## 알고리즘 분류
그래프 이론

그래프 탐색

애드 혹

너비 우선 탐색
