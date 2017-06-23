def factorical(n):
    if n == 1:
        return 1
    else:
        return n * factorical(n-1)

number = int(input('请输入一个正整数：'))
result = factorical(number)
print('%d 的阶乘是 %d' % (number, result))
