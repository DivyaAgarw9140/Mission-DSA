#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long pre[n],F[n],i;
        for(i=0;i<n;i++)
            cin>>F[i];
        pre[0] = F[0];
        for(i=1;i<n;i+=1)
            pre[i] = F[i] + pre[i-1];
        int count[111]= {0};
        count[0] = 1;
        for(i=0;i<n;i++)
            count[pre[i]%k]++;
        long sum=0;
        for(i=0;i<=110;i++)
            sum += count[i]*(count[i] -1)/2;
        cout<<sum<<endl;
    }
    return 0;
}
