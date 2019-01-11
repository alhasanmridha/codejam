#include<bits/stdc++.h>
using namespace std;

int M = 1000000007;
long long int gcd_extended(long long int a,long long int b, long long int *x, long long int *y){
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}

	long long int x1,y1;
	long long int g=gcd_extended(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;

	return g;
}
long long int fact(long long int a){
	if(a==0)
		return 1;
	return ((a%M)*(fact(a-1)%M))%M;
}

long long int mod_inverse(long long int a){
	long long int x,y;
	long long int g=gcd_extended(a,M,&x,&y);
	return (x+M)%M;
}
long long int comb(long long int n, long long int m){
	return fact(n)*mod_inverse(fact(m)*fact(n-m));
}

int main(){
	int t,n,m;
	cin>>t;
	long long int tempCount = 0;
	for(int Case=1;Case<=t;Case++){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			tempCount += comb(m,i)*(fact(2*n-m+i)*pow(2,m-i)-tempCount);
		}
		cout<<((fact(2*n)-tempCount)%M+M)%M<<"\n";
	}
	return 0;
}
