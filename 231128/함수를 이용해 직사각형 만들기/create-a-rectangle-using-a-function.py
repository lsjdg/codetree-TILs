def print_rect(n, m):
    for _ in range(n):
        print("1" * m)

rows, cols = tuple(map(int, input().split()))
print_rect(rows, cols)