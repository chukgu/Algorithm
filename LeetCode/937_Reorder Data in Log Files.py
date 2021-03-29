import re

class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:
        let, num = [], []
        for log in logs:
            if(log.split(' ')[1].isalpha()):
                let.append(log)
            else:
                num.append(log)
        
        let.sort(key=lambda x: (x.split(' ')[1:], x.split(' ')[0]))
        return let + num

if __name__ == "__main__":
    s = Solution()
    print(s.reorderLogFiles(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))
    print(s.reorderLogFiles(["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]))