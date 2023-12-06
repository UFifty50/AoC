from typing import List


def totalWinningNums(winningNums: List[str], ourNums: List[str]) -> int:
    total = 0
    for winningNum in winningNums:
        if winningNum.isdigit() and winningNum in ourNums:
            total += 1
    return total

cards: list = []
with open("input.txt") as f:
    cards = f.readlines()
cards = [card.split(": ")[1].strip().split(" | ") for card in cards]


# Part 1
winnings = []

# for each card, check if any of the winning numbers are in our numbers
# first winning number is worth 1 (2^0), and each subsequent number raises the power by 1
for card in cards:
    winningNums: List[str] = [num.strip() for num in card[0].split(" ")]
    ourNums: List[str] = [num.strip() for num in card[1].split(" ")]
    exp = totalWinningNums(winningNums, ourNums) -1
            
    cardVal = 2 ** exp if exp > -1 else 0 # anything ^0 is 1
    winnings.append(cardVal)

print(sum(winnings))


# part 2
ans = [1] * len(cards)

for idx, card in enumerate(cards):
    winningNums: List[str] = [num.strip() for num in card[0].split(" ")]
    ourNums: List[str] = [num.strip() for num in card[1].split(" ")]
    cardsToGet = totalWinningNums(winningNums, ourNums)
    
    for i in range(1, cardsToGet+1):
        if idx+i in range(len(ans)):
            ans[idx+i] += ans[idx]

print(sum(ans))
