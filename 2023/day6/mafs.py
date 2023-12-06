from math import floor, ceil, sqrt
t = 30
d = 200

f = floor(
    (t + sqrt(t**2 - 4*d))
    /2
    )

c = ceil(
    (t - sqrt(t**2 - 4*d))
    /2
    )

x = 6
print(f"d is {'even' if d % 2 == 0 else 'odd'}")
#ans = (floor((t+sqrt(t**2 - 4*d))/2)-floor((t-sqrt(t**2 - 4*d))/2))-1
ans = (1+sqrt(1+8*d))/2
print(ans)

#print(f-c+1)
