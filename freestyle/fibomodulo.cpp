#include<iostream>
unsigned long long  get_pisano_period(unsigned long long m)
{
    unsigned long long a=0,b=1,c=a+b;
    for(unsigned long long i = 0; ; i++)
    {
        c = (a+b) % m;
        a=b;
        b=c;
        if(a == 0 && b ==1)
        {
            
            //std::cout<<i+1<<'\n';

            return i+1;
        }
    }
}
unsigned long long fibomodulom(unsigned long long n, unsigned long long m)
{
    unsigned long long a=0,sum=1,temp2,period;
    period = get_pisano_period(m);
    unsigned long long remainder = n % period ;

    //std::cout<<remainder<<'\n';
    for (unsigned long long  i=0;i < remainder - 1 ; i++)
    {
        temp2 = sum;
        sum = sum + a;
        a=temp2;
    }
    return sum % m ;

}
int main()
{
    unsigned long long n, m;
    std::cin>>n>>m;
	std::cout<<fibomodulom(n,m)<<'\n';
    
}
