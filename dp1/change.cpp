#include <iostream>
#include <vector>
void min_change(std::vector<unsigned int> &v, int i)
{
	std::vector<unsigned int> coins(3);
	coins={0,0,0};
	if (( i - 1) >= 0) coins.at(0) = v.at(i - 1) + 1;
	if (( i - 3) >= 0) coins.at(1) = v.at(i - 3) + 1;
	if (( i - 4) >= 0) coins.at(2) = v.at(i - 4) + 1;
	for(unsigned int k=0;k<coins.size();k++)
	{
		if(coins.at(k) == 0)	coins.at(k) = coins.at(k) - 1 ;
	}
	//std::cout<<"p: "<<coins.at(0)<<'\t'<<"q: "<<coins.at(1)<<'\t'<<"r: "<<coins.at(2)<<'\n';
	//std::cout<< (coins.at(2) < ( coins.at(0) < coins.at(1) ? coins.at(0) : coins.at(1)) ? coins.at(2) : ( coins.at(0) < coins.at(1) ? coins.at(0) : coins.at(1))); 
	v.at(i) = (coins.at(2) < ( coins.at(0) < coins.at(1) ? coins.at(0) : coins.at(1)) ? coins.at(2) : ( coins.at(0) < coins.at(1) ? coins.at(0) : coins.at(1)));
	
}
unsigned int change(unsigned int money)
{
	std::vector<unsigned int> v(money + 1);
	v.at(0) = 0;
	for(int i=1;i< v.size();i++)
	{
		//std::cout<<i<<'\n';
		min_change(v,i);

	}
	/*
	for(unsigned int k =0;k< v.size();k++)
	{
		std::cout<<v.at(k)<<'\t';
	}
	std::cout<<'\n';
	*/
	return v.back();
}
int main()
{
	unsigned int money, coins;
	std::cin>>money;
	coins = change(money);
	std::cout<<coins<<'\n';;
	return 0;
}
