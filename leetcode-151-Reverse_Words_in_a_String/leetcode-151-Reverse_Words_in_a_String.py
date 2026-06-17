class Solution:
    def reverseWords(self, s: str) -> str:
        words_lst: list[str] = s.strip().split(" ")
        words_lst.reverse()
        words_lst = [c for c in words_lst if c != ""]
        return " ".join(words_lst)


if __name__ == "__main__":
    s: str = "the sky is blue"
    result = Solution().reverseWords(s)
    print(result)
