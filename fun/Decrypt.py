eMessage = int(input("Enter encrypted message : "))
message = ""

possible = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ"
lengthMessage = 4

eMessage -= 4

def Search(string):
    with open('words.txt') as word_file:
        for word in word_file:
            if word == string:
                return true
    return 0


def Iterator(i):

    temp = ord(possible[i])
    temp2 = 0

    def Iter(i):

        tempiter = 0

        if temp == eMessage:
            print(temp)
            return

        if temp < eMessage:
            for p in range(len(possible)):
                for j in range(len(possible)):
                    for k in range(len(possible)):
                        for o in range(len(possible)):
                            if (ord(possible[p]) + ord(possible[j]) + ord(possible[k]) + ord(possible[o])) == 411:
                               
                                string = str(possible[p]) + str(possible[j]) + str(possible[k]) + str(possible[o])
                                if(Search(string)):
                                    print(string)                       
                                tempiter += 1
                        #print("K : ", k, " Value : ", str(ord(possible[k])))
                    #print("\nJ : ", j, "    J Value : ", str(ord(possible[j])))
                print("P : ", p, " Value : ", str(ord(possible[p])))

        print(tempiter)
        if (temp + 1) <= len(possible):
            Iter(temp + 1)
            print("New temp iter\n")
        
        if temp > eMessage:
            return 0

    Iter(i)

Iterator(0)
