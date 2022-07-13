arr = [int(i) for i in input().split(' ')]

prob = 0
for i in arr:
    prob += (100 - i) * (i) / sum(arr)
print(prob)
