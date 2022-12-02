import os
import requests
from dotenv import load_dotenv
load_dotenv()


if os.getenv("AOC_KEY") is None:
    raise OSError("AOC_KEY not set in environment")

day = int(input("Enter the day: "))
rq = requests.get(
    f'https://adventofcode.com/2022/day/{day}/input',
    cookies = {
        "session": os.getenv("AOC_KEY")
    }
)

if rq.status_code == 404:
    print(f'Day {day} unavailable')
    exit(1)

os.mkdir(f'day-{day}')
with open(f'day-{day}/input.txt', 'w+') as f:
    f.write(rq.text)
