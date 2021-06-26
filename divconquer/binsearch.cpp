#include<iostream>
#include<vector>
std::vector<int> recur_search(std::vector<int> v,unsigned int low, unsigned int high, std::vector<int> key)
{
	std::vector<int> pos(key.size());
	for(unsigned int k=0;k<key.size(); k++)
	{
		if(v.size() == 0)
    		{ 
        		pos.at(k) = low-1;
    		}
    		else
   		{
        		unsigned int mid = low + (high-low)/2;
        		if(v.at(mid) == key.at(k))
        		{
            			pos.at(k) = mid;       
        		}		 
        		else if (v.at(mid) < key.at(k))
        		{
            			if((mid+1) <= high)
            			{
                			//pos.at(k) = recur_search(v, mid + 1, high, key);
            			}
        		}
        		else 
        		{
             			if((mid-1) >= low)
            			{
                			//pos.at(k) = recur_search(v, low, mid -1, key);
            			}
            
        		}
    		}
	}
	return pos;
}

std::vector<int> iter_search(std::vector<int> v, std::vector<int> key)
{
    	std::vector<int> pos(key.size());
	int temp;
	for(unsigned int k=0;k<key.size(); k++)
	{
		//std::cout<<key.at(k)<<'\n';
		unsigned int low=0, high = v.size() - 1;
		for(;high >= low;)
    		{
        		unsigned mid = low + (high-low)/2;
			//std::cout<<"mid: "<<mid<<'\n';
        		if(v.at(mid) == key.at(k))
        		{
            			//temp = mid;
				pos.at(k)=mid;
				//std::cout<<"temp:"<<temp<<'\n';
				break;
        		}
        		else if ((v.at(mid) < key.at(k)) && (mid+1) <= high)
        		{
            			low = mid + 1;
        		}
        		else if ((v.at(mid) > key.at(k)) && (mid-1) >= low)
        		{
            			high = mid - 1;
        		}
			if(v.at(mid) == v.at(low))
			{
				pos.at(k) = -1;	
				break;
				//pos.at(k) = -1;
			}
			if(v.at(mid) == v.at(high))
			{	
				pos.at(k)= -1 ;
				break;
			}
		}
		//std::cout<<"key: "<<key.at(k)<<'\t'<<"is at "<<pos.at(k)<<'\n';

	}
	return pos;
}

int main()
{
   	unsigned int n,m;
    	std::cin>>n;
    //unsigned int low,high;
    //std::cin>>low>>high;
    	std::vector<int> v(n);
    /** 
     * The list must be sorted
     */
    	for(unsigned int i=0; i< n; i++)
    	{
        	std::cin>>v.at(i);
    	} 
    	std::cin>>m;
    	std::vector<int> key(m), pos(m);
    	for(unsigned int i=0;i<m;i++)
	{ 
		std::cin>>key.at(i);
	}
	pos=iter_search(v, key);
    	for( unsigned int i=0; i<m;i++)
    	{
	    std::cout<<pos.at(i)<<'\t';
    	}

    
}
