graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5]
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]
visited = [False] * 9

#bfs
bfs(graph, 1, visited)
from collections import deque
def bfs(graph, start, visited):
    #Queue 구현을 위해 deque 라이브러리 사용
    q = deque([start])
    #현재 노드 방문 처리
    visited[start] = True

    while q:
        #Queue에서 하나의 원소를 뽑기
        v = q.popleft()
        print(v, end=' ')

        for i in graph[v]:
            if not visited[i]:
                q.append(i)
                visited[i] = True

def bfs(graph, start_node):
    visited = {x: False for x in graph}
    answer = [start_node]
    queue = deque([])

    queue.append(start_node)
    visited[start_node] = True

    while queue:
        current_node = queue.popleft()

        for node in graph[current_node]:
            if not visited[node]:
                visited[node] = True
                queue.append(node)
                answer.append(node)

    return answer

#dfs(재귀 사용)
dfs(graph, 1, visited)
def dfs(graph, v, visited):
    #현재 노드를 방문 처리
    visited[v] = True
    print(v, end=' ')
    answer.append(v)

    #현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
    
    return answer

#dfs(Stack 사용)
def dfs(graph, start):
    visited = list()#dict로 바꾸면 조회 시 속도 향상 -> visited = dict()
    stack = list()
    stack.append(start)

    while stack:
        node = stack.pop()
        if node not in visited:#if not visited[node]:
            visited.append(node)#visited[node] = True
            stack.extend(graph[node])
    
    return visited.keys()

#이진탐색(Binary Search)
def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return None

#파라메트릭 서치(Parametric Search)
#-이진탐색과 다르게 주어진 일련의 값들이 아니라 주어진 범위 내에서 원하는 값 또는 원하는 조건에 가장 일치하는 값을 찾아내는 알고리즘
#-Binary Search + YES/NO Problem (최적화 문제를 결정 문제로 바꾸어 푸는 것)
def parametric_search(arr, target):
    n = len(arr)
    if(n == 0):
        return 1
    left = 0
    right = n-1
    while(left < right):
        mid = (1+right) // 2
        if(arr[m] > target):
            right = mid - 1
        else:
            left = mid

    if(arr[left] == target):
        return left
    return -1#찾지 못한 경우