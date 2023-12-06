from typing import Callable, List, Dict, Tuple
from math import prod


# denotes the sum from n=start to stop of expression
def sigma(start: int, stop: int, expression: Callable[[int], int]) -> int:
    return sum(expression(i) for i in range(start, stop + 1))


# part 1
# {gameNo: (time, distance)}
lines: List[str] = []
with open('input.txt', 'r') as f:
    lines = [line.strip() for line in f.readlines()]

times = lines[0].split(":")[1].strip().split()
distances = lines[1].split(":")[1].strip().split()
games: List[Tuple[int, int]] = []

for i in range(len(times)):
    games.append((int(times[i]), int(distances[i])))

errorMargins: List[int] = []
for (T, D) in games:
    errorMargins.append(sigma(1, T-1, lambda t: 1 if (T*t-t**2) > D else 0))

print(f"Part 1: {prod(errorMargins)}")

# part 2
time = int(lines[0].split(":")[1].strip().replace(" ", ""))
distance = int(lines[1].split(":")[1].strip().replace(" ", ""))
errorMargin: int = sigma(1, time-1, lambda t: 1 if (time*t-t**2) > distance else 0)

print(f"Part 2: {errorMargin}")
