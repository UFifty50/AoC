import re

# part 1
with open("input.txt") as f:
    sumVals = 0

    for line in f.readlines():
        digits = []
        for c in line:
            if c.isdigit():
                digits.append(int(c))
        sumVals += digits[0] * 10 + digits[-1]

    print(sumVals)

# part 2
numberMapping = {
    'zero': 0,
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9
}

with open("input.txt") as f:
    sumVals = 0

    for line in f.readlines():
        digits = []
        reStr = r'(?=(one|two|three|four|five|six|seven|eight|nine|\d))'
        rePattern = re.compile(reStr)
        for w in rePattern.findall(line):
            if w.isdigit():
                digits.append(int(w))
            elif w in numberMapping:
                digits.append(numberMapping[w])
        sumVals += digits[0] * 10 + digits[-1]

    print(sumVals)
