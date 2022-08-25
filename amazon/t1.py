s=input().strip()
n=len(s)
d=[0]*(26)
count=1
for i in range(n):
	if d[ord(s[i])-ord('a')]>0:
		count+=1
		d[ord(s[i])-ord('a')]=1
	else:
		d[ord(s[i])-ord('a')]+=1
print(count)			

