# deque

lst_str = ['kang','yong','hun']
lst_num = [1,2,3]
lst = [str(i) for i in lst_num] #int형 리스트를 str형으로 바꿈
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
