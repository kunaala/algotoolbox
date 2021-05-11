#include<iostream>
#include<vector>
//std::vector<unsigned int> 
void sorter(std::vector<unsigned int> v)
{   
    unsigned int n=v.size();
    unsigned int pivot = v.at(n/2), lp = n/2 -1, rp = n/2 +1;
    std::vector<unsigned int> s(n);
    s.at(n/2) = pivot;
   
    for(unsigned int i=0; i< n;i++)
    {
        if(v.at(i) < pivot && lp !=0)
        {
            s.at(lp) = v.at(i);
            lp--;
        }
        else  if (v.at(i) > pivot && rp < n)
        {
            s.at(rp) = v.at(i);
            rp++;
        }
    }

    for(unsigned int i=0; i<n;i++)
    {
       
        std::cout<<s.at(i)<<'\t';
    }


}
int main()
{
    std::cout<<"enter size of the list"<<'\n';
    unsigned int n;
    std::cin>>n;
    std::cout<<"Enter its elements"<<'\n';
    std::vector<unsigned int> v(n), s(n);
    for(unsigned int i=0; i<n;i++)
    {
        std::cin>>v.at(i);
    }
    sorter(v);


}