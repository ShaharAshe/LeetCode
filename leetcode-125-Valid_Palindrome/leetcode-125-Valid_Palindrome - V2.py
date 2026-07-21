class Solution:
    def isPalindrome(self, s: str) -> bool:
        i_begin: int = 0
        i_end: int = len(s) - 1
        while i_begin < i_end:
            while i_begin < i_end and not s[i_begin].isalnum():
                i_begin += 1
            while i_begin < i_end and not s[i_end].isalnum():
                i_end -= 1
            if s[i_begin].lower() != s[i_end].lower():
                return False
            i_begin += 1
            i_end -= 1
        return True


if __name__ == "__main__":
    s:str = "A man, a plan, a canal: Panama"
    result = Solution().isPalindrome(s)
    print(result)
