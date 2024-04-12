#include <bits/stdc++.h>
using namespace std;
float a[1000],b[1000],c,t=0,t1=0;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];   t+=a[i];}
    float k=t/n;
    for(int i=1;i<=n;i++)t1+=(a[i]-k)*(a[i]-k);
    cout<<fixed<<setprecision(2)<<t1+1/n;
    return 0;
}

