#include<iostream>
long long hcf(long long a, long long  b)
{
	long long res=1;
	long long temp=a<b?a:b;
    for(long long i=2; i<temp;i++)
    {
        if(a % i == 0)
        {
			//std::cout<<"hai";
        	if(b % i == 0)
        	{
        			res = i;
        	}
        }
    }
    return res;
}
/**
* HCF of a and b = HCF of r and b ; where r is the remainder of a/b
*/
long long euclidhcf(long long a, long long  b)
{
	long long high=a>b?a:b;
	long long low=a<b?a:b;


	if(low == 0)
	{
		return high;
	}
	else
	{
		high %= low;
		//std::cout<<low<<'\t';
		euclidhcf(low, high);
	}
	
}




int main()
{
    long long a;
    long long b;
    // std::cout<<"Enter two numbers"<<'\n';
    std::cin>>a>>b;
  	//std::cout<<hcf(a,b);
  	std::cout<<euclidhcf(a,b)<<'\n';  
}
