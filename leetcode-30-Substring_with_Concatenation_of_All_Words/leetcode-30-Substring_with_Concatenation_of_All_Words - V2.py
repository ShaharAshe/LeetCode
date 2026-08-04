from collections import deque


class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        letters_count: int = len(words[0])
        concatenated_letter_count: int = len(words)*letters_count

        word_appearance_map: dict[str, int] = {}
        for word in words:
            if word not in word_appearance_map:
                word_appearance_map[word] = 0
            word_appearance_map[word] += 1

        result: list = []
        for i in range(letters_count):
            word_count_map: dict[str, int] = word_appearance_map.copy()
            window = deque()
            window_len: int = 0
            for j in range(i, len(s), letters_count):
                word: str = s[j:j+letters_count:]
                if len(word) != letters_count:
                    continue
                window.append(word)
                if word in word_count_map:
                    word_count_map[word] -= 1
                    if word_count_map[word] >= 0:
                        window_len += 1
                    else:
                        window_len -= 1
                if len(window) > len(words):
                    prev: str = window.popleft()
                    if prev in word_count_map:
                        word_count_map[prev] += 1
                        if word_count_map[prev] <= 0:
                            window_len += 1
                        else:
                            window_len -= 1
                if window_len == len(words):
                    result.append(j-(concatenated_letter_count-letters_count))
        return result


if __name__ == "__main__":
    s: str = "barfoothefoobarman"
    words: list[str] = ["foo","bar"]
    result = Solution().findSubstring(s, words)
    print(result)
