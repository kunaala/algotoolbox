#include <iostream>
#include <vector>
void printfn(std::vector<std::vector<unsigned int>> sol)
{
	for(unsigned int i=0;i<sol.size();i++)
	{
		for(unsigned int j=0;j<sol[i].size();j++)	std::cout<<(sol.at(i)).at(j)<<'\t';
		std::cout<<'\n';
	}
}
unsigned int maximize( std::vector<unsigned int> w, unsigned int total)
{
	std::vector<unsigned int> vr(total +1, 0);
	std::vector<std::vector<unsigned int>> sol(w.size() , vr);
	unsigned int temp;
	for(unsigned int i=1;i<sol.size();i++)
	{
		for(unsigned int k =1; k<sol[i].size();k++)
		{
			//std::cout<<"weight i"<<w.at(i)<<'\t'<<"total k"<<k<<'\n';
			(sol.at(i)).at(k) = (sol.at(i-1)).at(k);
			if(w.at(i) <= k)
			{
				temp = (sol.at(i-1)).at(k - w.at(i)) + w.at(i);
				if((temp > (sol.at(i)).at(k)))	(sol.at(i)).at(k) = temp;
			}
		}
	}
	return (sol.at(w.size() - 1)).at(total);
	//printfn(sol);
	
}

int main()
{
	unsigned int total,n;
	std::cin>>total>>n;	//total = total weight of knapsack; n = number of items
	std::vector<unsigned int> w((n + 1),0) ;
	for(unsigned int i=1;i<w.size();i++)	std::cin>>w.at(i);
	std::cout<<maximize(w,total)<<'\n';

	return 0;

}
