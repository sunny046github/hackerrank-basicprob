def getRecord(s):
    highest_score = 0
    lowest_score = 0
    count_highest = 0
    count_lowest = 0
    for i in range(len(s)):
        if i == 0:
            highest_score = lowest_score = s[i]
        elif s[i] > highest_score:
            highest_score = s[i]
            count_highest += 1
        elif s[i] < lowest_score:
            lowest_score = s[i]
            count_lowest += 1
    
    return count_highest, count_lowest

n = int(input().strip()) #iMIGRTnt if it is not working you can use this.
s = list(map(int, input().strip().split(' ')))
result = getRecord(s)
print (" ".join(map(str, result)))