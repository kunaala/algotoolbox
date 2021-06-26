#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void printmat(std::vector<std::vector<unsigned int>> d)
{
	for(unsigned int i=0;i<d.size();i++)
	{
		for(unsigned int j=0;j<d.at(i).size();j++)	std::cout<<d[i][j]<<'\t';
		std::cout<<'\n';
	}
}
std::vector<unsigned int> populate(std::vector<std::vector<unsigned int>> &d, unsigned int i, unsigned int j)
{
	std::vector<unsigned int> p(4);
	p.at(0) = (d.at(i)).at(j-1) + 1;	//insertion
	p.at(1) = (d.at(i-1)).at(j) + 1;	//deletion
	p.at(2) = (d.at(i-1)).at(j-1) + 1;	//mismatch
	p.at(3) = (d.at(i-1)).at(j-1);
	return p;

}
unsigned int distance(std::string str1, std::string str2)
{
	std::vector<unsigned int> vr((str2.size() + 1),0), p;
	std::vector<std::vector<unsigned int>> d((str1.size() + 1),vr);
	for(unsigned int i =0; i<d.size();i++)	(d.at(i)).at(0) = i;
	for(unsigned int j =0; j<vr.size();j++)	(d.at(0)).at(j) = j;
	for(unsigned int i=1; i<d.size();i++)
	{
		for(unsigned int j =1; j<vr.size();j++)	
		{
			p = populate(d, i, j); 
			if(str1.at(i-1) == str2.at(j-1))	(d.at(i)).at(j) = std::min({p.at(0), p.at(1), p.at(3)});
			else (d.at(i)).at(j) = std::min({p.at(0), p.at(1), p.at(2)});
	
		}
	}
	//printmat(d);
	
	return (d.at(d.size() -1).at(vr.size() -1));
}
int main()
{
	std::string str1, str2;
	std::cin>>str1>>str2;
	
	unsigned int d = distance(str1, str2);
	std::cout<<d<<'\n';
	return 0;
}
