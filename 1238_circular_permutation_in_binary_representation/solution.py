class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        init_list = list()
        fin_list = list()
        index = 0
        for i in range(pow(2,n)):
            i ^= (i >> 1)
            binary = bin(i)[2:]
            init_list.append(int(binary,2))
        for i, v in enumerate(init_list):
            if v == start:
                index = i
        l = len(init_list)
        while(1):
            fin_list.append(init_list[index])
            index = (index + l - 1) % l
            if len(fin_list) == l:
                break
        return fin_list
