/**
 * **************INCOMPLETE*****************
 */
#include<iostream>
#include<vector>
int minrefill(unsigned int range, std::vector<unsigned int> x)
{
    unsigned int num_refills=0;
    unsigned int last_refill_stop=0, last_refill_idx=0, stop;
    // If distance to be covered is less than range/ capacity of tank, then number of refills would be 0
    if(x.back()< range)   
    {
        return 0;
    }
    for(unsigned int cur_pos=last_refill_idx; (cur_pos<x.size())  ; )
    {
        for(;  (x.at(cur_pos) < x.back() ) && ((x.at(cur_pos) - last_refill_stop) <= range) ; cur_pos++ )
        {
                stop=cur_pos;
                        

        }
        //std::cout<<"curposition: "<<x.at(cur_pos)<<'\n';
        //std::cout<<"stopped at: "<<x.at(stop)<<'\n';
        //If the next fuelling stop is at a greater distance than the range of the vehicle
        if(x.at(cur_pos) - x.at(stop) > range || (x.at(stop) == x.front()))
        {
            return -1;
        }
        //If the total distance is covered before the next refill
        else if(x.at(stop) == last_refill_stop) 
        {
            break;
        }
        else if(x.at(stop) < x.back())
        {
            num_refills++;
            last_refill_stop = x.at(stop);
            last_refill_idx = stop;
        }
    
        //std::cout<<"numrefills: "<<num_refills<<'\t'<<"last stop: "<<last_refill_stop<<'\n';
        
        
    }
    return num_refills;

}
int main()
{
    unsigned int total;
    std::cin>>total;
    unsigned int range;
    std::cin>>range;
    unsigned int n_stops;
    std::cin>>n_stops;
    std::vector<unsigned int> x(n_stops + 1);
    for(unsigned int i=0;i<n_stops; i++)
    {
        std::cin>>x.at(i);
    }
    //Append the stops list with the total distance to be covered as its last element/stop
    x.back() = total;
    std::cout<<minrefill(range,x)<<'\n';

        

}