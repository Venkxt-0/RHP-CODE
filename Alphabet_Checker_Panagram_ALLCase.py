s = input("Enter a String: ")

lower_letters = set()
upper_letters = set()

for c in s:
    if 'a' <= c <= 'z':
        lower_letters.add(c)
    elif 'A' <= c <= 'Z':
        upper_letters.add(c)

if len(lower_letters) == 26 and len(upper_letters) == 26:
    print("YES")
else:
    print("NO")
