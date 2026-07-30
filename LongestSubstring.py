s1 = input("Enter string1: ")
s2 = input("Enter string2: ")

m, n = len(s1), len(s2)
dp = [[0] * (n + 1) for _ in range(m + 1)]
max_len = 0
end_pos = 0

for i in range(1, m + 1):
    for j in range(1, n + 1):
        if s1[i - 1] == s2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
            if dp[i][j] > max_len:
                max_len = dp[i][j]
                end_pos = i

longest_substring = s1[end_pos - max_len : end_pos]
print(f"Longest Substring: '{longest_substring}'")
