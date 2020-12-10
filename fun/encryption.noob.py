
sInput = input(" : ")

n = 5
split_string = []
for index in range(0, len(sInput), n):
    split_string.append(sInput[index : index + n])

print(len(split_string[len(split_string) - 1]))

if len(split_string[len(split_string) - 1]) < 5:
    print("This shit is working")

