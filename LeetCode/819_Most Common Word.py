import collections
import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
        #words = [word for word in re.sub(r'[^\w]', ' ', paragraph).lower().split() if word not in banned] - 한줄 코드
        words = []
        for word in re.sub('[^\w]', ' ', paragraph).lower().split():#[^\w] -> 단어 문자만. 즉, 단어 문자가 아닌 모든 문자를 공백으로 치환
            if word not in banned:
                words.append(word)
        
        counts = collections.defaultdict(int)
        for word in words:
            counts[word] += 1
        
        return max(counts, key=lambda x: counts[x]) 
        #return max(counts.keys(), key=lambda x: counts[x]) -> Key 값 중 최대 (위와 동일)
        #return max(counts.values()) -> value 값 중 최대

        '''
        카운터 함수 이용법 - #most_common(1) 은 가장 많이 나오는 단어 첫번째를 추출 - [('ball', 2)]
        counts = collections.Counter(words)
        return counts.most_common(1)[0][0] 
        '''

if __name__ == "__main__":
    s = Solution()
    print(s.mostCommonWord(paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]))
    print(s.mostCommonWord(paragraph = "a.", banned = []))