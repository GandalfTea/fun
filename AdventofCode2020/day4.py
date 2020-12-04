from Passports import passports
from example_invalid import passports_ex

passports = passports.split("\n\n")


def val_check(crit, e, exp_val):
    if crit in e:
        if int(e[1]) in exp_val:
            return True
    return False

exp_byr = range(1920,2003)
exp_iyr = range(2010, 2021)
exp_eyr = range(2020, 2031)
exp_hgt_cm = range(150, 194)
exp_hgt_in = range(59, 77)
exp_hcl = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
exp_ecl = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]

answer = 0
for i in passports:
    #print(i)
    temp = ""
    i = i.replace("\n"," ")
    i = i.split(" ")
    temp = 0

    print("i : ", i, "\n")
    for e in i:
        e = e.split(":")
        print("e[1] : ", e[1])
        
        if val_check("byr", e, list(exp_byr)):
                temp += 1
                print("byr")
        if val_check("iyr", e, list(exp_iyr)):
                temp += 1
                print("iyr")
        if val_check("eyr", e, list(exp_eyr)):
                temp += 1
                print("eyr")
        if "hgt" in e:
            if "cm" in e[1]:
                a = 0
                if e[1][0:3].isdigit(): 
                    a = (int(e[1][0:3]))
                    if a in list(exp_hgt_cm):    
                        temp += 1
                        print("hgt_cm")
            elif "in" in e[1]:
                if e[1][0:3].isdigit():
                    continue
                if e[1][0:2].isdigit():
                    a = int(e[1][0:2])
                    if a in list(exp_hgt_in):
                        temp += 1
                        print("hgt_in")
        if "hcl" in e:
            a = 0 
            if e[1][0] != '#':
                continue
            if len(e[1][1:]) == 6:
                for ch in e[1][1:]:
                    if ch in list(exp_hcl):
                        a += 1
                if a == 6:
                        temp += 1
                        print("hcl")
        if "ecl" in e:
            if e[1] in exp_ecl:
                temp += 1
                print("ecl")
        
        if "pid" in e:
            if len(e[1]) == 9:
                temp += 1
                print("pid")


    print("\ntemp : ", temp)
    if temp == 7:
        answer +=1
print(answer)
