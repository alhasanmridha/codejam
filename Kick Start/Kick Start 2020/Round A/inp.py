import string,random
N=10000
print(2)
for _ in range(2):
    print(100,2)
    for i in range(100):
        inp=''.join(random.choices(string.ascii_uppercase, k=N))
        print(inp)

