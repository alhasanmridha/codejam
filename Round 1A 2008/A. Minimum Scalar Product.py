t=int(input())
for nt in range(1,t+1):
    n=int(input())
    v1=map(int,input().split())
    v2=map(int,input().split())
    v1=sorted(v1)
    v2=sorted(v2,reverse=True)
    ans=0
    for i in range(n):
        ans+=v1[i]*v2[i];
    print('Case #',nt,': ',ans,sep='')
