""" -- Id = 9 -- """

def isPalindrome(x: int) -> bool:
    if x<=9 and 0<=x:
        return True
    elif x < 0 or x%10 == 0:
        return False
    
    right_x = 0

    while right_x < x:
        right_x *= 10
        right_x += x%10
        if right_x == x or (right_x == x//10):
            return True
        x //= 10
    return False
        

if __name__ == '__main__':
    print(isPalindrome(88888))
    print(isPalindrome(121))
    print(isPalindrome(-121))
    print(isPalindrome(10))
    print(isPalindrome(-101))
    print(isPalindrome(0))
    print(isPalindrome(11))
    print(isPalindrome(1001))
    print(isPalindrome(1000021))
    print(isPalindrome(1000022))
