file = open('i', 'r').read().strip().split('\n')
arr = [int(i) for i in file]
count = 0

for i in range(1, len(arr)):
  if arr[i] > arr[i-1]:
    count += 1

print(count)
