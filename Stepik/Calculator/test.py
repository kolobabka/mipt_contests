def calcNextNum(x):
    return [x + 1, x * 2, x * 3]

def compare(idx, t):
    return numList[idx] <= n and numbers.setdefault(numList[idx], t)[0] > t[0]

def numbersForPrint(n, numbers):
    numList = []
    i = n
    while i > 0:
        numList.append(i)
        i = numbers[i][1]
    return numList

n = int(input())
numbers = {1: (0, 0)}
i = 1

while i < n:

    numList = calcNextNum(i)
    t = (numbers[i][0] + 1, i)

    if compare(0, t):
        numbers[numList[0]] = t

    if compare(1, t):
        numbers[numList[1]] = t

    if compare(2, t):
        numbers[numList[2]] = t

    i += 1

print(numbers[n][0])
print(*reversed(numbersForPrint(n, numbers)))
