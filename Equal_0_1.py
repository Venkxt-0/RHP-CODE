binary_str = "101010110011"

seen_indices = {0: -1}
balance = 0
max_len = 0

for idx, char in enumerate(binary_str):
    balance += 1 if char == "1" else -1

    if balance in seen_indices:
        sub_len = idx - seen_indices[balance]
        max_len = max(max_len, sub_len)
    else:
        seen_indices[balance] = idx

print(max_len)
