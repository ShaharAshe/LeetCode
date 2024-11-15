class Solution:
    def isValid(self, s: str) -> bool:
        parentheses = {
            "open":['(', '{', '[']
        }
        stack = []
        
        for c in s:
            if c in parentheses["open"]:
                stack.append(c)
            elif stack and ((stack[-1] == '(' and c == ')') or (stack[-1] == '[' and c == ']') or (stack[-1] == '{' and c == '}')):
                stack.pop()
            else:
                return False
        else:
            if stack:
                return False
        return True


if __name__ == "__main__":
    s = "()"
    res = Solution().isValid(s)

    print(res)
