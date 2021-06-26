#include <iostream>
#include <vector>
void maximize(std::vector<unsigned int> val, std::vector<unsigned int> w, unsigned int total)
{
	std::vector<unsigned int> sol(total+1, 0);
	unsigned int temp;
	
	for(unsigned int k=1;k<=total;k++)
	{
		for(unsigned int i=0;i<w.size();i++)
		{	
			if(w.at(i) <= k)
			{	
				temp = sol.at(k - w.at(i)) + val.at(i);  
				if(temp > sol.at(k))	sol.at(k) = temp;
			}
		}
	}
	//for(unsigned int i=0;i<sol.size();i++)	std::cout<<sol.at(i)<<'\t';
	//std::cout<<'\n';

	std::cout<<sol.back()<<'\n';
}

int main()
{
	unsigned int total,n;
	std::cin>>total>>n;	//total = total weight of knapsack; n = number of items
	std::vector<unsigned int> val(n), w(n) ;
	for(unsigned int i=0;i<n;i++)	std::cin>>val.at(i);
	for(unsigned int i=0;i<n;i++)	std::cin>>w.at(i);
	maximize(val,w,total);

	return 0;

}
