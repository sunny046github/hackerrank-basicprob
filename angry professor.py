t = int(input())

for _ in range(t):
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))

	cnt = 0
	for x in arr:
		if x <= 0:
			cnt += 1
	if cnt >= k:
		print("NO")
	else:
		print("YES")
