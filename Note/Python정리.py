lst_str = ['kang','yong','hun']
lst_num = [1,2,3]
lst = [str(i) for i in lst_num] #int형 리스트를 str형으로 바꿈
matrix = [[0 for col in range(2)] for row in range(3)]#3행 2열 리스트 생성 (모두 (0,0) 인 상태)
matrix = [[row,col] for col in range(4) for row in range(3)]#4행 3열 좌표 리스트 생성((0,0)부터 (2,3)까지)
#zip
list(zip(lst_num, lst_str)) # [(1,'kang'), (2,'yong'), (3,'hun')]
for n,v in zip (lst_num, lst_str): #풀어서 썼을 때
    print(n,v) # 1, 'kang' -> 2, 'yong' -> 3, 'hun'

#lambda
a = [(1, 2), (0, 1), (5, 1), (5, 2), (3, 0)]
dic = {'kang':112, 'yong':234, 'hun':183}
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
list1.count('a') #2

a = 'BlackMask'
a.count('k')#2
a.count('k',2,5)#1 (2~5 사이에 개수)

# Counter 함수
from collections import Counter
counter = Counter(list1)
print(counter) #Counter({'a':2, 'b':1})

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
dq.count(x)#원소 중 x의 개수 리턴
len(dq)#원소 수 알아내기
#list 처럼 사용(deque)
dq[2]='n' #['l','o','v','e'] -> ['l','o','n','e']
dq.insert(0,'k')#첫번 째 항목에 'k' 추가
dq.remove('k')#'k'항목 삭제
dq.copy()#deque의 *shallow copy(얕은 복사)를 만듬

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



#순열 - nPr = n * (n-1) * ... * (n-r+1)
from itertools import permutations
items = ['A','B','C','D']
list(map(''.join, permutations(items))) #item의 모든 원소를 가지고 순열을 만듬
list(map(''.join, permutations(items,2))) #2개의 원소를 가지고 만듬 -> ['AB', ...]
a=[]
for i in list(permutations(items,2)):#풀어서 썼을 때
    a.append(i)

#조합 - 순서대로 나열 X, 뽑기만 하는 경우 (nCr = n! / r!(n-r)!)
from itertools import combinations
list(map(''.join, combinations(items,1))) #조합은 수도 반드시 넘겨야 함
list(map(''.join, combinations(items,2))) #['AB','AC' ...]

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
