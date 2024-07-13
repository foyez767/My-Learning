def solve():
    n = int(input())
    names = []

    for i in range(1, n + 1):
        s = input()
        names.append(s)

    score = [[] for _ in range(n)]
    no_of_rounds = []
    to_be_cnt = []

    for i in range(n):
        x = int(input())
        no_of_rounds.append(x)
        v = [0] * (x + 1)
        score[i] = v

    for i in range(1, n + 1):
        x = int(input())
        to_be_cnt.append(x)

    disqualified_status = {}

    for i in range(n):
        batti = True

        for j in range(1, no_of_rounds[i] + 1):
            score[i][j] = int(input())

            if score[i][j] < 0:
                batti = False

        disqualified_status[i] = batti

        score[i].sort()
        score[i] = [sum(score[i][:j + 1]) for j in range(no_of_rounds[i])]

    valid_list = []  # [(score, names, id)]

    for i in range(n):
        if disqualified_status[i]:
            r = no_of_rounds[i]
            l = 0

            if no_of_rounds[i] > to_be_cnt[i]:
                l = no_of_rounds[i] - to_be_cnt[i]

            obtained_score = score[i][r] - score[i][l]

            valid_list.append((obtained_score, names[i], i))

    valid_list.sort(key=lambda x: (x[0], x[1]))

    if not valid_list:  # if there is no valid participants
        print("Deception knows no bounds; it is an art mastered by all!")
        return

    rank = {}  # {id: (rank, score)}
    ra = 1
    scr, nam, ide = valid_list[0]
    rank[ide] = (ra, scr)

    for k in range(1, len(valid_list)):
        scr, nam, ide = valid_list[k]
        scr2, nam2, ide2 = valid_list[k - 1]

        if scr == scr2 and nam == nam2:
            rank[ide] = (ra, scr)
        else:
            ra += 1
            rank[ide] = (ra, scr)

    for i in range(n):
        if not disqualified_status[i]:
            print(f"Disqualified {names[i]}")
        else:
            r, scr = rank[i]
            print(f"{r} {names[i]} {scr}")


def main():
    t = 1
    # t = int(input())
    for i in range(1, t + 1):
        solve()


if __name__ == "__main__":
    main()
