s, n = map(int, input().split())

A = []
while len(A) < s:
    A.extend(map(int, input().split()))

B = []
while len(B) < n:
    B.extend(map(int, input().split()))

A.sort()
B.sort()

a, b = s - 1, n - 1
count = 0

while a >= 0 and b >= 0:
    if B[b] <= 2 * A[a]:
        count += 1
        a -= 1
    b -= 1

print(count)
