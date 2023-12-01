sum = 0
try:
    while True:
        i = input()
        oi = i
        if i == '':
            break
        n = 0
        v = []
        o = sum
        
        translation = {
            "one": "1",
            "two": "2",
            "three": "3",
            "four": "4",
            "five": "5",
            "six":"6",
            "seven": "7",
            "eight":"8",

            "nine": "9"
        }
        print(i)
        for j in range(len(i)):
            for word in translation:
                if i[j:].startswith(word):
                    i = i.replace(word, word +translation[word], 1)

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
    raise e
        
print(sum)
