#include<iostream>
void fibonacciseries(unsigned long long a, unsigned long long  sum, unsigned long long n)
{
    unsigned long long temp;
    for(unsigned long long i=0; i<n-2;i++)
    {
        temp=sum;
        sum=sum+a;
        a=temp;
        std::cout<<sum<<'\t';
    }
}

unsigned long long fibonum(unsigned long long n)
{
	unsigned long long temp,a=0,sum=1;
	if(n<2)
	{
		sum=n;
		return sum;	
	}
	else
	{
		for(unsigned long long i=0;i<n-1;i++)
	    {
			temp=sum;
	    	sum=sum+a;
	    	a=temp;
	    }
    	//std::cout<<sum<<'\n';
    	return sum;
	}

}

unsigned long long fiborecur(unsigned long long n)
{
	unsigned long long sum;
	if(n<2)
	{
		sum=n;	
	}
	else
	{
		sum=fiborecur(n-1) + fiborecur(n-2);
	}
    return sum;
}

int main()
{
    unsigned long long n;
    // bool opt;
    // long long a=0;
    // long long sum=1;
    // std::cout<<"0:Fibonacci series; 1: Fibonacci number"<<'\n';
    // std::cin>>opt;
    // if(opt==0)
    // {
        // std::cout<<"Enter the number of terms"<<'\n';
        // std::cin>>n;
        // if(n<2)
        // {
            // std::cout<<a<<'\t'<<sum<<'\t';
        // }
        // else
        // {
            // std::cout<<a<<'\t'<<sum<<'\t';
            // fibonacciseries(a,sum,n);
        // }
    // }
    // else
    // {
        // std::cout<<"Enter the term index"<<'\n';
        std::cin>>n;
        // if(n<2)
        // {
            // std::cout<<n<<'\t';
        // }
        // else
        // {
			std::cout<<fibonum(n)<<'\n';
			 //std::cout<<fiborecur(n)<<'\n';	
					
        // }
    // }

    

    
}
