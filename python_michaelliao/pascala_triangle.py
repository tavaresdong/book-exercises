
def pascal_triangle(level):
    lst, rd = [1], 0
    while rd < level:
        yield lst
        lst2 = [lst[0]]
        i, j = 0, 1
        while i < len(lst) and j < len(lst):
            lst2.append(lst[i] + lst[j])
            i, j = i + 1, j + 1
        lst2.append(lst[-1])
        lst = lst2
        rd = rd + 1
    


triangle5 = pascal_triangle(5)
for lst in triangle5:
    print (lst)
