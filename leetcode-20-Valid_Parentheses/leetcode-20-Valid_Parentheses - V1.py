class Solution:
    def isValid(self, s: str) -> bool:
        parentheses = {
            "open":['(', '{', '['],
            "close":[')', '}', ']']
        }
        stack = []
        
        s_len = len(s)
        c_i = 0
        while c_i < s_len:
            while c_i < s_len and s[c_i] in parentheses["open"]:
                stack.append(s[c_i])
                c_i+=1
            if stack:
                while stack and c_i < s_len and s[c_i] in parentheses["close"]:
                    if (stack[-1] == '(' and s[c_i] == ')') or (stack[-1] == '[' and s[c_i] == ']') or (stack[-1] == '{' and s[c_i] == '}'):
                        stack.pop()
                        c_i+=1
                    else:
                        return False
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
