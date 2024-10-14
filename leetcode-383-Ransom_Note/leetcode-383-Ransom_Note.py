class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        letters_count: dict = {}

        for c in magazine:
            if c not in letters_count:
                letters_count[c] = 0
            letters_count[c]+=1
        # --------
        for c in ransomNote:
            if c in letters_count:
                letters_count[c]-=1
                if letters_count[c]<0:
                    return False
            else:
                return False
        return True


if __name__ == "__main__":
    ransomNote: str = "a"
    magazine: str = "b"

    res: bool = Solution().canConstruct(ransomNote, magazine)
    print(res)
