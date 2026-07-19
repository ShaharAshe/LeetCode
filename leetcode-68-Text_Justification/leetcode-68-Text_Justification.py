class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        result: list[str] = []
        line: list[str] = []
        line_len: int = 0
        word_i: int = 0
        while word_i < len(words):
            if (len(line) + line_len + len(words[word_i])) <= maxWidth:
                line.append(words[word_i])
                line_len += len(words[word_i])
                word_i += 1
            else:
                spaces_placeholders: int = len(line) - 1
                spaces_total: int = maxWidth - line_len
                if spaces_placeholders == 0:
                    line[len(line)-1] += ' ' * spaces_total
                else:
                    spaces_sharing: int = spaces_total // spaces_placeholders
                    for i in range(len(line)-1):
                        line[i] += ' ' * spaces_sharing
                        spaces_total -= spaces_sharing
                    if spaces_total != 0:
                        for i in range(len(line)-1):
                            if spaces_total == 0:
                                break
                            line[i] += ' '
                            spaces_total -= 1
                build_len_result: str = "".join(line)
                result.append(build_len_result)
                line = []
                line_len = 0
        else:
            spaces_total: int = maxWidth - line_len
            for i in range(len(line)-1):
                line[i] += ' '
                spaces_total -= 1
            if spaces_total != 0:
                line[len(line)-1] += ' ' * spaces_total
            build_len_result: str = "".join(line)
            result.append(build_len_result)
        return result


if __name__ == "__main__":
    words: list[str] = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth: int = 16
    result = Solution().fullJustify(words, maxWidth)
    print(result)
