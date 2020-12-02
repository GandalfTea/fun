from Passwards_day2 import input


pri = input.split("\n")

answer = 0
answer1 = 0
for pas in pri:
    a = pas.split(None)
    temp = a[0].split("-", 1)
    num1 = int(temp[0])
    num2 = int(temp[1])
    
    letter = a[1].split(":", 1)[0]
    
    # Prob 1
    f = 0
    for let in a[2]:
        if let == letter:
            f +=1
    if f >= num1 and f <= num2:
        answer += 1
    
    # Prob 2
    if a[2][num1 - 1 ] == letter or a[2][num2 - 1] == letter:
        if a[2][num1 - 1] != a[2][num2 - 1]:
            #print(letter, " : ", a[2][num1 - 1], a[2][num2 - 1])
            answer1 += 1


print(answer)
print(answer1)

