x = int(input())
n = 1

for _ in range(x):
    for _ in range(x):
        if (n % 10 == 0):
            n += 1
        print(n % 10, end=" ")
        n += 1
    print()