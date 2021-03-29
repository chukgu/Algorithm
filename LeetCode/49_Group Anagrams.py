import collections

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagrams = collections.defaultdict(list)

        for word in strs:
            anagrams[''.join(sorted(word))].append(word)
        
        return anagrams.values()

if __name__ == "__main__":
    s = Solution()
    print(s.groupAnagrams(strs = ["eat","tea","tan","ate","nat","bat"]))
    print(s.groupAnagrams(strs = [""]))
    print(s.groupAnagrams(strs = ["a"]))