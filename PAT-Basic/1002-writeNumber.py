s = input()
a = 0

for i in s:
    a += int(i)

a_s = str(a)

ping_dict = {'0': 'ling', '1': 'yi', '2': 'er', '3': 'san',
             '4': 'si', '5': 'wu', '6': 'liu', '7': 'qi', '8': 'ba', '9': 'jiu'}

result = ''
for i in a_s:
    result = result + ping_dict[i] + ' '

print(result[:-1])
