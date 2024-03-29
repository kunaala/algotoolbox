#include<iostream>
#include<vector>
#include<cstdlib>
//std::vector<unsigned int>
std::vector<int>& swapper(std::vector<int> &v, unsigned int id1, unsigned int id2)
{
	int temp;
	temp=v.at(id1);
	v.at(id1) = v.at(id2);
	v.at(id2) = temp;
	return v;
}
unsigned int partition(std::vector<int> &v, unsigned int l, int r)
{
	unsigned int pivot = l;// + (rand() % (r - l) );
//    	std::cout<<"pivot: "<<pivot<<"r:"<<r<<'\n';
	unsigned int j=l;
	for(unsigned int i=l+1;i<=r;i++)
	{
		if(v.at(i) <= v.at(l)) 
		{
			j++;
			v = swapper(v,i,j);
		}

	}
	for(unsigned int i=0; i<v.size();i++)
    	{
        	std::cout<<v.at(i)<<'\t';
	}
	std::cout<<"before swapping"<<'\n';
	v = swapper(v,j,l);
    	for(unsigned int i=0; i<v.size();i++)
    	{
        	std::cout<<v.at(i)<<'\t';
	}
	std::cout<<"after swapping"<<'\n';
	
	//v = swapper(v, j, l);
	return j;
	
}
std::vector<int> sorter(std::vector<int> &v, unsigned int l, int r)
{   
	int m;
	//std::cout<<"l: "<<l<<'\t'<<"r: "<<r<<'\n';	
	while(l < r && r > 0 )
	{
		//std::cout<<"l: "<<l<<'\t'<<"r: "<<r<<'\n';	
		
		m=partition(v, l, r);
		//std::cout<<"m: "<<m<<'\n';
		if( (m-l) <= (r-m) )
		{
			std::cout<<"recursion"<<'\n';
			sorter(v, l, m-1);
			l = m + 1;
		}
		else 
		{
			sorter(v, m+1, r);
			r = m - 1;
		}
		
		//std::cout<<"sorter printing: "<<'\n';
		/*for(unsigned int i=0; i<v.size();i++)
    		{
        		std::cout<<v.at(i)<<'\t';
    		}
		std::cout<<'\n';
		*/
	}
	return v;
	
}
int main()
{
    	//std::cout<<"enter size of the list"<<'\n';
    	unsigned int n;
    	std::cin>>n;
    	//std::cout<<"Enter its elements"<<'\n';
    	std::vector<int> v(n);
    	for(unsigned int i=0; i<n;i++)
    	{
        	std::cin>>v.at(i);
    	}
    	v=sorter(v,0,n-1);
	for(unsigned int i=0; i<v.size();i++)
    	{
		std::cout<<v.at(i)<<'\t';
	}
	std::cout<<'\n';
	return 0;

}
