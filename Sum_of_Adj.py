rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

print("Enter elements of matrix: ")
matrix = []
for i in range(rows):
    matrix.append([int(x) for x in input().split()])

targetir, targetic = map(int, input("Enter the input row and col index: ").split())

offsets = [
    (-1, -1), (-1, 0), (-1, 1),
    (0, -1),           (0, 1),
    (1, -1),  (1, 0),  (1, 1)
]

adjisum = 0
for dr, dc in offsets:
    adjir, adjic = targetir + dr, targetic + dc
    if 0 <= adjir < rows and 0 <= adjic < cols:
        adjisum += matrix[adjir][adjic]

print(f"AdjSum : {adjisum}")
