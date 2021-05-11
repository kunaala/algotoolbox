/**
 * **************INCOMPLETE*****************
 */
#include<iostream>
#include<vector>
unsigned int mingroups(std::vector<float> ages)
{
    unsigned int num_groups=1;
    float groupflag = ages.at(0);
    for( unsigned int i=0;i<ages.size();i++)
    {   
        
        if ( std::abs( ages[i] - groupflag ) <= 1)
        {
            continue;
        }
        else
        {
            num_groups +=1;
            groupflag = ages[i];
        }
    }
    return  num_groups;
} 
int main()
{
    std::cout<<"enter number of children"<<'\n';
    unsigned int n;
    std::cin>>n;
    std::vector<float> ages(n);
    for(std::vector<float>::iterator itr=ages.begin();itr < ages.end() ; itr++)
    {
        std::cin>>*itr;
        
    }
    std::cout<<mingroups(ages)<<'\n';

}