input()
array = input().split(' ')
final = []
for i in array:
    if i not in final:
        final.append(i)
print(len(final))
