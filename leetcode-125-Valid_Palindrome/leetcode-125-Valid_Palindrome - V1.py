class Solution:
    def isPalindrome(self, s: str) -> bool:
        s_lst: list = [c.lower() for c in s if c.isalnum()]
        
        for s_i, e_i in zip(range((len(s_lst)//2)),range((len(s_lst)-1),(len(s_lst)//2)-1,-1)):
            if s_lst[s_i] != s_lst[e_i]:
                return False
        return True
    

if __name__ == "__main__":
    s:str = "A man, a plan, a canal: Panama"
    res:bool = Solution().isPalindrome(s)
    print(res)
