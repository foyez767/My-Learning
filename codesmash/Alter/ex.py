import sys

def solve():
    n = int(input())

    if n % 2 == 0:
        for i in range(2, 2 * n + 1, 2):
            print(i, end=" ")
        print()
    else:
        for i in range(1, n + 1):
            print(i, end=" ")
        print()

if __name__ == "__main__":
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        solve()
