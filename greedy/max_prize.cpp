#include<iostream>
#include<vector>
void prize_distro(unsigned int n)
{
    
    std::vector<unsigned int> places;
    for(unsigned int i=1; (n >= i); i++)
    {
        places.push_back(i);
        n -=i;
        //std::cout<<n<<'\n';
    }
    places.back() += n;
    std::cout<<places.size()<<'\n';
    for(unsigned int i=0; i< places.size(); i++)
    {
        std::cout<<places.at(i)<<'\t';
    }
    std::cout<<'\n';
}

int main()
{
    unsigned int n;
    std::cin>>n;
    prize_distro(n);
    return 0;
}

