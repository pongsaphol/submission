import math

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

def unique(s):
	ulist = []
	for x in s:
		if x not in ulist:
			ulist.append(x)
	ulist.sort()
	return ulist

def solve():
	m, n = map(int, input().split(" "))
	arr = map(int, input().split(" "))
	s = []
	ptr = -1
	gval = 0
	for i in range(n-1):
		if arr[i] == arr[i+1]:
			continue
		ptr = i
		val = gcd(arr[i], arr[i+1])
		gval = val
		s.append(val)
	ss = []
	for z in s:
		ss.append(z)
	for x in arr:
		for z in s:
			if x % z == 0 and x != z:
				ss.append(x/z)

	LP = dict()
	zzz = unique(ss)
	for i in range(26):
		LP[zzz[i]] = chr(i + ord('A'))
	ans = ""
	arr[ptr] = arr[ptr] / gval
	arr[ptr+1] = arr[ptr+1] / gval
	ans = str(LP[gval])
	for i in range(ptr+1, n):
		ans = ans + str(LP[arr[i]])
		if i != n-1:
			arr[i+1] = arr[i+1] / arr[i]
	for i in range(ptr, -1, -1):
		ans = str(LP[arr[i]]) + ans
		if i != 0:
			arr[i-1] = arr[i-1] / arr[i]
	return ans

tc = int(input())
for i in range(tc):
	print("Case #" + str(i+1) + ": " + solve())
