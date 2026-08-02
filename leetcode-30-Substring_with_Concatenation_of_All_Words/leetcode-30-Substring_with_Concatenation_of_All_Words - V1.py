class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        letters_count: int = len(words[0])
        concatenated_letter_count: int = len(words)*letters_count

        word_appearance_map: dict[str, int] = {}
        for word in words:
            if word not in word_appearance_map:
                word_appearance_map[word] = 0
            word_appearance_map[word] += 1

        result: list[int] = []
        for i in range(len(s)-concatenated_letter_count+1):
            word_appirance_map_check: dict[str, int] = word_appearance_map.copy()
            for j in range(len(words)):
                split_word: str = s[i+(j*letters_count):i+((j+1)*letters_count):]
                if split_word in word_appirance_map_check:
                    word_appirance_map_check[split_word] -= 1
                    if word_appirance_map_check[split_word] == 0:
                        word_appirance_map_check.pop(split_word)
                else:
                    break
            else:
                if len(word_appirance_map_check) == 0:
                    result.append(i)
        return result


if __name__ == "__main__":
    s: str = "barfoothefoobarman"
    words: list[str] = ["foo","bar"]
    result = Solution().findSubstring(s, words)
    print(result)
