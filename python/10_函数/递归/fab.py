#'菲波那切数列的实现'
def fab(n):
    n1 = 1
    n2 = 1
    n3 = 1

    if n < 1:
        print('输入的值有误')
        return -1

    while (n-2) > 0:
        n3 = n2 + n1
        n1 = n2
        n2 = n3
        n -= 1

    return n3

print(fab(10))
