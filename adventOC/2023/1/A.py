sum = 0
try:
    while True:
        i = input()
        n = 0
        v = []
        o = sum
        for c in list(i):
            try:
                v.append(int(c))
            except ValueError:
                pass
        print(v)
        sum += v[0] * 10
        sum += v[len(v)-1]
except Exception as e:
    print(sum)
        
