message = input(str("message : "))
eMessage = " "
eInt = 0

# En 1
for i in range(len(message)):
    eInt += ord(message[i])

eInt += len(message)

# En 2
for i in range(len(message) - 1, 0, -1):
    if(message[i] != " "):
        eMessage += message[i]
        eMessage += str(ord(message[i]))
        eMessage += str(len(message))
    else:
        continue

print("Encryption 1 : ", eInt)
print("Encryption 2 :", eMessage)
