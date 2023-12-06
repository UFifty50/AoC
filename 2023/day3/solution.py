with open('input.txt', 'r') as f:
    # ensure all rows begin and end with a dot
    engine = [f".{row}." for row in f.read().split('\n')]

def getAdjacent(row, col):
    partNumbers = set()
    offsets = ((-1, -1), (-1, 0), (-1, 1), (0, -1), 
               (0, 1), (1, -1), (1, 0), (1, 1))            
    for x, y in offsets:
        if engine[row + x][col + y].isdigit():
            leftPos = rightPos = col + y
            while engine[row + x][leftPos - 1].isdigit():
                leftPos -= 1
            while engine[row + x][rightPos + 1].isdigit():
                rightPos += 1
            partNumbers.add(int(engine[row+x][leftPos:rightPos+1]))
    return partNumbers

def partsList():
    parts = []
    for row, rowVal in enumerate(engine):
        for col, symbol in enumerate(rowVal):
            if not symbol.isdigit() and symbol != '.':
                parts.append((symbol, getAdjacent(row, col)))
    return parts

# part 1
print(sum(sum(nums) for _, nums in partsList()))

# part 2
total = 0
for symbol, nums in partsList():
    if symbol == '*' and len(nums) == 2:
        total += nums.pop() * nums.pop()
print(total)
