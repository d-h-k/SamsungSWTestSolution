#include <stdio.h>

int a[1000001];
int main()
{
    long long sum=0;
    long long n, gamdok, bugamdok;
    scanf("%lld", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%lld %lld", &gamdok, &bugamdok);
    for(int i=0; i<n;++i)
    {
        sum++;
        if(a[i] <=gamdok)
            continue;
        a[i] -=gamdok;
        if(a[i]<bugamdok)
            sum++;
        else
        {
            if(a[i]%bugamdok==0)
                sum+=a[i]/bugamdok;
            else
                sum+=(a[i]/bugamdok)+1;
        }
    }
    printf("%lld\n", sum);
}
