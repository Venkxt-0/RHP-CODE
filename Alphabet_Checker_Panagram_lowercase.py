s = input("Enter a String: ")

letters = set()

for c in s:
    if 'a' <= c <= 'z':
        letters.add(c)

if len(letters) == 26:
    print("YES")
else:
    print("NO")
