lines: list = []
with open('input.txt') as f:
    lines = f.read().split("\n\n")
    lines = [line.split('\n') for line in lines]


# part 1    
seeds = {int(seed):int(seed) for seed in lines[0][0].split(':')[1].split()}
maps = lines[1:]
for m in maps:
	for seed in seeds.keys():
		f = False
		seedVal = seeds[seed]
		for line in m[1:]:
			d, s, r = [int(x) for x in line.split()]
			if seedVal >= s and seedVal < (s + r) and f == False:
				seeds[seed] = d + (seedVal - s)
				f = True

print(min(s for s in seeds.values()))


# part 2

