data = open(0).read().split()

if data:
    n = int(data[0])
    k = int(data[1])
    q = int(data[2])

    MAX_TEMP = 200000
    diff = [0] * (MAX_TEMP + 2)

    idx = 3
    for _ in range(n):
        l = int(data[idx])
        r = int(data[idx + 1])
        diff[l] += 1
        diff[r + 1] -= 1
        idx += 2

    pref = [0] * (MAX_TEMP + 2)
    active_recipes = 0
    for i in range(1, MAX_TEMP + 1):
        active_recipes += diff[i]
        pref[i] = pref[i - 1] + (1 if active_recipes >= k else 0)

    output = []
    for _ in range(q):
        a = int(data[idx])
        b = int(data[idx + 1])
        output.append(str(pref[b] - pref[a - 1]))
        idx += 2

    print("\n".join(output))
