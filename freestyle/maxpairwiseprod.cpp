#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<time.h>

long long maxpairprod(const std::vector<int> v)
{
    unsigned int max=1; 
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>=v[max])
        {
            max=i;
            //std::cout<<max<<'\n';
        }
    }
    
    unsigned int max2 = 1;
    for(int j=0;j<v.size();j++)
    {
        
        if(j != max && v[j]>=v[max2])
        {
            max2=j; 
        }
    }
    // std::cout<<max<<'\t'<<max2<<'\n';
    return (long long)v[max] * v[max2];
}
// long long maxpairquick(std::vector<int> v)
// {
	    // std::sort(v.begin(), v.end());
	    // return (long long)v.back() * v[v.size()-2];
// 
// }
int main()
{
    std::vector<int> v;
    int n;
    // srand(time(NULL));
    std::cin>>n;
    // while(true)
    // {
    	// n = rand() % 1000 + 2;
    	// long long temp1,temp2 ;
    for(int i=0;i<n;i++)
    {
        int temp;
        std::cin>>temp;
        v.push_back(temp);
    }
	    // for(int i=0;i<n;i++)
	    // {
	        // long long  temp;
	        // temp = rand() % 10000;
// 
	        // v.push_back(temp);
	    // }
	 std::cout<<maxpairprod(v)<<'\n';
	   	

	   	
	   
	    
		// if(maxpairprod(v) == maxpairquick(v) )
		// {
			// std::cout<<"passed OK"<<'\n';
			// for(int i=0;i<n;i++)
		  	// {
		  		// std::cout<<v[i]<<'\t';
		  	// }
	   		// std::cout<<'\n';
		// }
		// else
		// {
			// std::cout<<"error"<<'\t'<<"Bruteforce"<<'\t'<<maxpairquick(v)<<'\t'<<"fast"<<'\t'<<maxpairprod(v)<<'\n';
			// for(int i=0;i<n;i++)
	   		// {
	   		// std::cout<<v[i]<<'\t';
	   		// }
	   		// std::cout<<'\n';
// 
			// break;
		// }
	
	
	// }
}