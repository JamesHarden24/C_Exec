def factorial(n):
    result = n
    for i in range(1, n):
        result *= i
    return result

number = int(input('请输入一个正整数：'))
result = factorial(10)
print(result)
