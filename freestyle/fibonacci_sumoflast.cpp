/**
 * **************INCOMPLETE*****************
 */
#include<iostream>

int fibolast(unsigned long long n)
{
	int temp,a=0,sum=1;
	if(n<2)
	{
		sum=n;
		return sum;	
	}
	else
	{
		for( unsigned long long i=0;i<n-1;i++)
	    {
			temp=sum % 10;
	    	sum=(sum+a) % 10;
	    	a=temp;
	    }
    	//std::cout<<sum<<'\n';
    	return sum % 10;
	}

}

int main()
{
    unsigned long long n;
    std::cin>>n;

	std::cout<<fibolast(n)<<'\n';
			 	


    
    
}
