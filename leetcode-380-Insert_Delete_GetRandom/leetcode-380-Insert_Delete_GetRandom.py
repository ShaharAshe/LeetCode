import random


class RandomizedSet:

    def __init__(self):
        self.__set_rnd = dict()
        self.__index_key_map = []

    def insert(self, val: int) -> bool:
        if val in self.__set_rnd:
            return False
        
        self.__index_key_map.append(val)
        self.__set_rnd[val] = len(self.__index_key_map)-1
        return True

    def remove(self, val: int) -> bool:
        try:
            index = self.__set_rnd.pop(val)
            if index != len(self.__index_key_map)-1:
                swift_val = self.__index_key_map[-1]
                self.__index_key_map[index] = swift_val
                self.__set_rnd[swift_val] = index
            self.__index_key_map.pop()
            return True
        except KeyError:
            return False

    def getRandom(self) -> int:
        rnd_num = random.randint(0, len(self.__index_key_map)-1)
        result = self.__index_key_map[rnd_num]
        return result


if __name__ == "__main__":
    # randomized_set = RandomizedSet()
    # print(f'{randomized_set.insert(1) = }')
    # print(f'{randomized_set.remove(2) = }')
    # print(f'{randomized_set.insert(2) = }')
    # print(f'{randomized_set.getRandom() = }')
    # print(f'{randomized_set.remove(1) = }')
    # print(f'{randomized_set.insert(2) = }')
    # print(f'{randomized_set.getRandom() = }')


    randomized_set = RandomizedSet()
    print(f'{randomized_set.remove(0) = }')
    print(f'{randomized_set.remove(0) = }')
    print(f'{randomized_set.insert(0) = }')
    print(f'{randomized_set.getRandom() = }')
    print(f'{randomized_set.remove(0) = }')
    print(f'{randomized_set.insert(0) = }')


    # randomized_set = RandomizedSet()
    # print(f'{randomized_set.insert(0) = }')
    # print(f'{randomized_set.insert(1) = }')
    # print(f'{randomized_set.remove(0) = }')
    # print(f'{randomized_set.insert(2) = }')
    # print(f'{randomized_set.remove(1) = }')
    # print(f'{randomized_set.getRandom() = }')
