from Boarding_passes import passes

passes = passes.split("\n")

def split(split_list, rows_index, i, index, max_val):
    #print(i[index])
    if index == max_val:
        return split_list[0]
    h = int(rows_index/2)
    if i[index] == "F" or i[index] == "L": b = split_list[:h]
    if i[index] == "B" or i[index] == "R": b = split_list[h:]
    index += 1
    return split(b,h,i,index, max_val)   

raw_answers = []  
answers = []
for i in passes:

    index = 0
    seats_e = 7
    rows_index = 128
    seats_index = 8
    rows = list(range(128))
    seats = list(range(0,8))

    raw_answers.append([split(rows, rows_index, i, index, 7), split(seats, seats_index, i, seats_e, 10)])

for i in raw_answers:
    answers.append(i[0]*8+i[1])

answers.sort()

for i in range(len(answers)-1):
    if answers[i]+1 != answers[i+1]:
        print(answers[i], answers[i+1])
