class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        groups: dict[tuple[int, ...], list[str]] = {}
        for word in strs:
            count: list[int] = [0]*26
            for char in word:
                count[ord(char)-ord("a")] += 1
            signature: tuple[int, ...] = tuple(count)
            if signature not in groups:
                groups[signature] = []
            groups[signature].append(word)
        return list(groups.values())


if __name__ == "__main__":
    strs: list[str] = ["eat","tea","tan","ate","nat","bat"]

    result = Solution().groupAnagrams(strs)
    print(result)
