# part 1
lines: str
with open("input.txt") as f:
    lines = f.readlines()

games = {}

for line in lines:
    reds = set()
    greens = set()
    blues = set()
    game = line.split(";")
    gameID = int(game[0].split(" ")[1].strip(":"))
    game[0] = game[0].split(": ")[1]
    for g in game:
        x = g.strip().split(", ")
        for n in x:
            num = int(n.split(" ")[0])
            colour = n.split(" ")[1]
            match colour:
                case "red":
                    reds.add(num)
                case "green":
                    greens.add(num)
                case "blue":
                    blues.add(num)

    largestRed = max(reds)
    largestGreen = max(greens)
    largestBlue = max(blues)

    if largestRed <= 12 and largestGreen <= 13 and largestBlue <= 14:
        games[gameID] = (largestRed, largestGreen, largestBlue)

print(sum(games.keys()))

# part 2
power = 0
for r, g, b in games.values():
    power += r * g * b

print(power)
