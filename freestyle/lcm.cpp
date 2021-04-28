#include<iostream>

unsigned long long lcm(unsigned long long a, unsigned long long  b)
{
	unsigned long long high=a>b?a:b;
	unsigned long long low=a<b?a:b;
	if(a == 0  || b == 0 )
	{
		std::cout<<"Smart kid!! , LCM for 0 is better undefined"<<'\n';
		return  0;
	}
	
	if(high % low == 0)
	{
		return high;
	}
	else
	{
		for(int i=2;;i++)
		{
			if(((high * i) % low )== 0 )
			{
				return high * i;
			}
		}
	}
	

	
}




int main()
{
    long long a;
    long long b;
    // std::cout<<"Enter two numbers"<<'\n';
    std::cin>>a>>b;
  	//std::cout<<hcf(a,b);
  	std::cout<<lcm(a,b)<<'\n';  
}
