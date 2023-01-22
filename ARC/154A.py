N = int(input())
a = list(input())
b = list(input())
for i in range(N):
	if ord(a[i]) < ord(b[i]):
		a[i], b[i] = b[i], a[i]
a = int(''.join(a))
b = int(''.join(b))
print((a*b) % 998244353)