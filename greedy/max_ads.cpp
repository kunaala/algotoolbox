/**
 * **************INCOMPLETE*****************
 */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
int max_profit(std::vector<int> a,std::vector<int> b )
{
    unsigned int i, j, imax=0, jmax=0;
    int sum=0;
    
    
    while(a.size() != 0)
    {
        
        if(a.size() == 1)
        {
            sum += a.at(0) *  b.at(0);
            break;
        }
        for( i=0, imax=0; i< a.size(); i++)
        {
            
            if(a.at(i) > a.at(imax))
            {
                imax = i;
                
                
            }

        }   
        for(j=0, jmax=0; j< b.size(); j++)
        {
    
            if(b.at(j) > b.at(jmax))
            {
                jmax = j;
            }       
        }
        sum += b.at(jmax) * a.at(imax);
        // std::cout<<"jmax:"<<b.at(jmax)<<'\t'<<"imax: "<<a.at(imax)<<'\t'<<"sum: "<<sum<<'\n';

        a.erase(a.begin() + imax);
        b.erase(b.begin() + jmax);


    }
        



    return sum;
}
int max_profit_new(std::vector<int> a,std::vector<int> b )
{
    int sum=0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for(unsigned int i=0; i!=a.size(); i++)
    {
        sum += a.at(i) * b.at(i);
    }
    return sum;
}

int main()
{
    unsigned int n;
    // while( true)
    // {
    // n = rand() % 100 + 1;
    std::cin>>n;
    std::vector<int> a(n),b(n);
    for(unsigned int i=0;i<n; i++)
    {
        std::cin>>a.at(i);
    }
    for(unsigned int j=0; j<n; j++)
    {
        std::cin>>b.at(j);
    }
    // for(unsigned int i=0;i<n; i++)
    // {
    //     a.at(i) = (rand() % 60) -50;
    // }
    // for(unsigned int j=0; j<n; j++)
    // {
    //     b.at(j) = (rand() % 60) -50;
    // }
    // int sum1 = max_profit(a,b), sum2 = max_profit_new(a,b);
    // if( sum1 == sum2)
    // {
    //     std::cout<<"passed of"<<'\n';
    // }
    // else
    // {
    //     for(unsigned int j=0; j<n; j++)
    //     {
    //         std::cout<<a.at(j)<<'\t';
    //     }
    //     std::cout<<'\n';
    //     for(unsigned int j=0; j<n; j++)
    //     {
    //         std::cout<<a.at(j)<<'\t';
    //     }
    //     std::cout<<'\n';
    //     std::cout<<"error! sum1: "<<sum1<<'\t'<<"sum2: "<<sum2<<'\n';
    //     return -1;
    // }
    // }
    std::cout<<max_profit(a,b)<<'\n';
    //std::cout<<max_profit_new(a,b)<<'\n';

    return 0;
}