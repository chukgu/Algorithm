#input 시간 초과 나는 경우
import sys
input = sys.stdin.readline

#python 재귀 사용 시 기본 깊이 제한은 1000임. 그런 경우 아래와 같이 제한을 늘릴 수 있음
sys.setrecursionlimit(100000)

#python 3.7 이상은 입력 순서 유지 O
collections.OrderedDict()#python 3.6 이하는 dict 사용 시 입력 순서 유지 X


#python에서는 존재하지 않는 Key 를 조회하면 KeyError 가 발생함
collections.defaultdict(list)
collections.defaultdict(int)#를 사용하면 존재하지 않는 키를 조회할 경우, 디폴트 값 기준으로 해당 키에 대한 딕셔너리 아이템을 생성해준다.
#Ex) dict a에 {'A':5, 'B':4} 가 있을 때, a['C'] += 1 하면 에러가 아닌 {'A':5, 'B':4, 'C':1} 이 추가 됨.

#string reverse
s = 'Reverse'
reversed(s)#esreveR
s[::-1]#esreveR

lst_str = ['kang','yong','hun']
lst_num = [1,2,3]
lst = [str(i) for i in lst_num] #int형 리스트를 str형으로 바꿈
matrix = [[0 for col in range(2)] for row in range(3)]#3행 2열 리스트 생성 (모두 (0,0) 인 상태)
matrix = [[row,col] for col in range(4) for row in range(3)]#4행 3열 좌표 리스트 생성((0,0)부터 (2,3)까지)
#zip
list(zip(lst_num, lst_str)) # [(1,'kang'), (2,'yong'), (3,'hun')]
for n,v in zip (lst_num, lst_str): #풀어서 썼을 때
    print(n,v) # 1, 'kang' -> 2, 'yong' -> 3, 'hun'

#List Comprehension
[n*2 for n in range(1, 10+1) if n%2 == 1] # 홀수인 경우 2를 곱해 출력 [2,6,10,14,18]

#Dictionary Comprehension
dic = {'kang':112, 'yong':234, 'hun':183}
a = {key:value for key, value in dic.items()} #아래와 동일한 코드
# a = {}
# for key, value in dic.items():
#   a[key] = value

#lambda
a =[(1, 2), (0, 1), (5, 1), (5, 2), (3, 0)]
sorted(a, key=lambda x:x[1]) #첫번째 인자 기준 오름차순
sorted(a, key=lambda x:(x[0], -x[1]))#첫번 째 인자 기준 오름차순, 두번 째 인자 기준 내림차순
sorted(dic.items())#key 값 기준 정렬
sorted(dic.items(), key=lambda x:x[0])#위와 같음(key 값 기준 정렬)
sorted(dic.items(), reverse=True)#key 값 기준 내림차순
sorted(dic.items(), key=lambda x:x[1])#value 값 기준 정렬
sorted(dic, key=lambda x: dic[x])#value 값 기준 정렬 후 key 값들만 list로 리턴 (['yong', 'hun', 'kang'])

a = ['aa', 'b', 'ccc']
max(a, key=lambda x:len(x))#길이가 가장 긴 이름

keys = [{'key': 8}, {'key': 5}, {'key': 9}, {'key': 3}]
keys.sort(key = lambda x: x['key']) # [{'key': 3}, {'key': 5}, {'key': 8}, {'key': 9}]
filter(lambda x: x['key']<5, keys) # 'key'들의 value 기준으로 정렬
map(lambda x: x['key']+5, keys) # 모든 'key'들의 value에 5를 더함

(lambda n,m: n if n%2==0 else m)(1,3) #3

a = [1,2,3,4]
b = [10,20,30,40]
sum_ab = list(map(lambda x,y:x+y, a,b)) #[11,22,33,44]

# count
list1 = ['a','b','b']
list2 = ['a','b','c']
list1.count('a') #1

a = 'BlackMask'
a.count('k')#2
a.count('k',2,5)#1 (2~5 사이에 개수)

# Counter 함수
from collections import Counter
counter = Counter(list1)
print(counter) #Counter({'a':1, 'b':2})

counter.update(list2)
print(counter) #Counter({'a':2, 'b':3, 'c':1})

print(counter.most_common(n=2)) #가장 많이 나타난 2개 출력 - [('b',3), ('a',2)]

#deque (collections 모듈) - 스택과 큐의 기능을 모든 가짐
#deque는 list보다 속도도 더 빠름(오른쪽은 미세하게 빠르고, left는 훨씬 빠름)
from collections import deque
dq = deque() #빈 큐 만들기
dq = deque([1,2,3]) #원소가 있는 큐
dq = deque('love') #['l','o','v','e']
dq = deque(maxlen=5)#큐 최대 길이(원소가 더 많아지면 maxlen 자동 갱신 됨)

dq.append('m') #오른쪽 끝에 항목 추가
dq.pop()#오른쪽 끝에 항목 가져오면서 삭제
dq.appendleft('l')#왼쪽에서 'l' 입력
dq.popleft()#왼쪽 끝에서 항목 가져오면서 삭제
dq.extend('you')#오른쪽으로 확장 (['l','o','v','e','y','o','u'])
dq.extendleft('l')#왼쪽으로 확장
dq.reverse()#내용을 좌우 반전 ['l','o','v','e'] -> ['e','v','o','l']
dq.rotate()#가장 오른쪽 데이터를 pop해서 appendleft 함 -> ['e','l','o','v']
dq.rotate(2)#인자 수 만큼 회전 ['l','o','v','e'] -> ['v','e','l','o']
dq.clear()#모든 원소 삭제
dq.count('x')#원소 중 'x'의 개수 리턴
len(dq)#원소 수 알아내기
#list 처럼 사용(deque)
dq[2]='n' #['l','o','v','e'] -> ['l','o','n','e']
dq.insert(0,'k')#첫번 째 항목에 'k' 추가
dq.remove('k')#'k'항목 삭제
dq.copy()#deque의 *shallow copy(얕은 복사)를 만듬

#PriroityQueue (우선순위 큐 - 우선순위가 가장 높은 데이터를 먼저 삭제하는 자료구조)
#리스트는 삽입시간 O(1) 과 삭제시간 O(N) 이지만, 힙을 이용하면 삽입시간 O(logN) 삭제시간 O(logN)을 유지할 수 있다
from queue import PriorityQueue
que = PriorityQueue() #빈 우선순위 큐 만들기
que = PriorityQueue(maxsize=8)#최대 길이 설정
que.put(4)
que.put(1)
que.put(7)
que.put(3)
que.get()#1
que.get()#3
que.get()#4
que.get()#7

que.put((3, 'Apple'))
que.put((1, 'Banana'))
que.put((2, 'Cherry'))
print(que.get()[1])  # Banana
print(que.get()[1])  # Cherry
print(que.get()[1])  # Apple

que.qsize()#큐 사이즈 반환
que.empty()#큐가 비어있으면 True, 아니면 False 반환
que.full()#큐가 가득차있으면 True, 아니면 False 반환

#Heapq - 우선순위 큐 활용을 위한 heapq (힙이란 원래 완전이진트리를 기본으로 한 자료구조)
#python 에서의 heapq 모듈을 최소 힙 자료구조를 제공(최대 힙 X)
import heapq
lst = [4,1,7,3,8,5]
heapq.heapify(lst)#[1,3,5,4,8,7] - heapify() 함수를 활용하면 기존의 List도 최소 힙 정렬을 유지하는 힙(리스트)

heap = [] #python에서의 최소 힙 생성은 따로 없으며, 그냥 List를 생성하여 활용하면 됨
heapq.heappush(heap, 4)
heapq.heappush(heap, 1)
heapq.heappush(heap, 7)
heapq.heappush(heap, 3)#[1,3,7,4] - 이진트리구조로 데이터가 들어가 있음
heapq.heappop(heap)#1
heap[0]#최소 값을 삭제하지 않고 단순히 읽기만 할 때
#K번째 최소값이나 최대값을 효율적으로 구할 수 있음 - K번째 최소값을 구하기 위해서는 heappop() 함수를 K번 호출하면 됨

nums = [4,1,7,3,8,5]
for num in nums:
    heapq.heappush(heap, (-num, num)) # (우선 순위, 값) - heapq 모듈은 최소 힙 기능만 있어서 최대 힙(max heap)으로 활용하려면 - 값의 튜플을 활용

while heap:
    heapq.heappop((heap)[1]) # index 1출력

#2가지 이상의 값을 넣어야할 때는 튜플을 이용하면 됨
heapq.heappush(heap, (1,0))
heapq.heappush(heap, (2,8))
heapq.heappush(heap, (2,1))
heapq.heappush(heap, (4,7))
heapq.heappush(heap, (2,9))
heapq.heappush(heap, (8,3))
heapq.heappush(heap, (8,1))
heapq.heappop(heap)#(1,0), (2,1), (2,8), (2,9), (4,7), (8,1), (8,3)

#shallow copy // deep copy 차이
#shallow copy(얕은 복사)
# - 값에 대한 메모리가 더 할당되는 것이 아닌 기존 값의 메모리 주소를 공유
# - list의 경우 리스트 자체뿐만 아니라 리스트 내 요소들도 같은 주소를 공유
foo = [0,1,2]
bar = foo
foo[0] = 9 #bar - [9,1,2]
id(foo), id(bar) #동일한 주소 값이 나옴

#deep copy(깊은 복사)
import copy
foo = [0,1,2]
bar = copy.deepcopy(foo)
foo[0]=123 #foo - [123,1,2] // bar - [0,1,2]
id(foo), id(bar) #주소값이 다름

##순열 - nPr = n * (n-1) * ... * (n-r+1)
from itertools import permutations
items = ['A','B','C','D']
list(map(''.join, permutations(items))) #item의 모든 원소를 가지고 순열을 만듬
list(map(''.join, permutations(items,2))) #2개의 원소를 가지고 만듬 -> ['AB', ...]
a=[]
for i in list(permutations(items,2)):#풀어서 썼을 때
    a.append(i)

#조합 - 순서대로 나열 X, 뽑기만 하는 경우 (nCr = n! / r!(n-r)!)
from itertools import combinations
list(map(''.join, combinations(items,1))) #조합은 수도 반드시 넘겨야 함(List가 문자열인 경우)
list(map(''.join, combinations(items,2))) #['AB','AC' ...]
list(combinations(items,2)) #list가 숫자이면 이렇게도 가능. 다만, [(0, 1), (0, 2), (1, 2)] 외부는 리스트, 내부는 튜플 형태


#곱집합 - 여러 집합들 간에 하나씩 뽑아 조합을 만들 수 있는 모든 수를 말함
from itertools import product
a=[1,2,3]
b=['a','b','c']
list(product(a,b)) #[(1,'a'), (1,'b'), (1,'c'), .... , (3,'c')]

# 최대 공약수, 최소 공배수
from math import gcd
x = 2
y = 3
gcd(x,y) #최대 공약수

x * y // gcd(x,y) #최소 공배수 (// - 몫(나누기 후 소수 이하 버림))
# 참고 : ** - 거듭제곱

divmod(5,3) #몫과 나머지를 한 번에 구할 때 (1,2)

import math
math.ceil(12.2)#올림 - 13
math.floor(12.2)#내림 - 12
math.trunc(12.6)#버림 - 12
round(0.466666, 4)#4번째 자리에서 반올림 - 0.4667

# out of index 피하는 방법
if a[-1:] == [i]:

# 문자열 알파벳 모두 소문자로, 대문자로 변경, 반전
islower(), isupper(), swapcase()

# 아스키->문자, 문자->아스키
chr(), ord()

# 알파벳으로만 되어있는지, 숫자로만 되어있는지 참,거짓 반환
isalpha(), isdigit()

# 자리 수(인자 값) 만큼 0으로 채움 
"123".zfill(5) 은 "00123" 반환
# 자리 수(첫번째 인자 값) 만큼 두번째 인자값으로 채움 
"123".rjust(5, "a") 은 "aa123" 반환

# 문자열의 첫글자만 대문자로 변경, 문자열의 모든 단어들의 첫글자를 대문자로 변경
capitalize(), title()
# 문자열 대치 'a'를 'b'로 바꾸는데 2번째까지만 바꿈
replace('a','b',2)

#비트연산
bin(13) #10진수 13을 2진수로 변환 '0b1101'
int('1101', 2) #2진수로 된 문자열 1101을 10진수로 변환

bin(0b1101 & 0b1001)    # 비트 AND => '0b1001'
13 & 9                  # 비트 AND => 9
bin(0b1101 | 0b1001)    # 비트 OR  => '0b1101'
13 | 9                  # 비트 OR  => 13
bin(0b1101 ^ 0b1001)    # 비트 XOR => '0b100'
13 ^ 9                  # 비트 XOR => 4
bin(~0b1101)            # 비트 NOT => '-0b1110'
~13                     # 비트 NOT => -14

0b0011 << 2    # 비트를 왼쪽으로 2번 시프트 => '0b1100' (=12)
0b1100 >> 2    # 비트를 오른쪽으로 2번 시프트 => '0b11' (3)

#a &= b (a와 b의 비트를 AND 연산한 후 결과를 a에 할당)
#a |= b (a와 b의 비트를 OR 연산한 후 결과를 a에 할당)
#a ^= b (a와 b의 비트를 XOR 연산한 후 결과를 a에 할당)
#a <<= b(a의 비트를 b번 왼쪽으로 이동시킨 후 결과를 a에 할당)
#a >>= b(a의 비트를 b번 오른쪽으로 이동시킨 후 결과를 a에 할당)


#집합 자료형 (set - 순서가 없고, 중복이 불가능함)
s1 = {1,2,3,4,5}
#값 추가
s1.add(6) #{1,2,3,4,5,6}
#다중 값 추가
s1.update([7,8,9]) #{1,2,3,4,5,6,7,8,9}
#삭제
s1.remove(9) #{1,2,3,4,5,6,7,8}

s1 = {1,2,3,4,5}
s2 = {4,5,6,7}
#set 합집합
s1 | s2 #{1,2,3,4,5,6,7}
s1.union(s2) #{1,2,3,4,5,6,7}
#set 교집합
s1 & s2 #{4,5}
s1.intersection(s2) #{4,5}
#set 차집합
s1 - s2 #{1,2,3}
s1.difference(s2) #{1,2,3}
#set 대칭 차집합
s1 ^ s2 #{1,2,3,6,7}
s1.symmetric_difference(s2) #{1,2,3,6,7}