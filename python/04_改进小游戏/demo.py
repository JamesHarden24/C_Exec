import random

secrect = random.randint(1, 10)

print('------------Rookie.com-------------------')
num = 3  #每个人有三次机会
while num > 0:  
    temp = input("不妨猜一下小甲鱼现在心里想的是哪个数字:")
    guess = int(temp)
    if guess == secrect:
        print("我艹，你是小甲鱼心里的蛔虫吗？！")
        print("哼，猜中了也没有奖励！")
        num = 0
    else:
        if guess > secrect:
            print('哥，大了，大了')
        else:
            print('嘿，小了，小了')
        num = num - 1
print("游戏结束，不玩了^_^")
