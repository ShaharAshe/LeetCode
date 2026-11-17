class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagram_sublists: dict[str, list[str]] = {}
        for word in strs:
            key: str = "".join(sorted(word))
            if key not in anagram_sublists:
                anagram_sublists[key] = []
            anagram_sublists[key].append(word)
        return list(anagram_sublists.values())


if __name__ == "__main__":
    strs: list[str] = ["eat","tea","tan","ate","nat","bat"]

    result = Solution().groupAnagrams(strs)
    print(result)
