/*
1801. Number of Orders in the Backlog

You are given a 2D integer array orders, where each orders[i] = [pricei, amounti, orderTypei] denotes that amounti orders have been placed of type orderTypei at the price pricei. 
The orderTypei is:
0 if it is a batch of buy orders, or
1 if it is a batch of sell orders.
Note that orders[i] represents a batch of amounti independent orders with the same price and order type. All orders represented by orders[i] will be placed before all orders represented by orders[i+1] for all valid i.

There is a backlog that consists of orders that have not been executed. The backlog is initially empty. When an order is placed, the following happens:

If the order is a buy order, you look at the sell order with the smallest price in the backlog. If that sell order's price is smaller than or equal to the current buy order's price, they will match and be executed, and that sell order will be removed from the backlog. Else, the buy order is added to the backlog.
Vice versa, if the order is a sell order, you look at the buy order with the largest price in the backlog. If that buy order's price is larger than or equal to the current sell order's price, they will match and be executed, and that buy order will be removed from the backlog. Else, the sell order is added to the backlog.
Return the total amount of orders in the backlog after placing all the orders from the input. Since this number can be large, return it modulo 109 + 7.
*/

class Solution {
    class order{
        public:
        int price;
        long long int amt;
        int typ;
        order(vector<int> a)
        {
            this->price = a[0];
            this->amt = a[1];
            this->typ = a[2];
        }
    };
    struct comparator_min{
        bool operator()(order a,order b)
        {
            return b.price<a.price;
        }
    };
    struct comparator_max{
        bool operator()(order a,order b)
        {
            return b.price>a.price;
        }
    };
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<order,vector<order>,comparator_min> sell;
        priority_queue<order,vector<order>,comparator_max> buy;
        long long int rem=0;
        for(vector v:orders)
        { 
            order a(v);
            if(a.typ==0)
            {
                if(sell.empty())
                    buy.push(a);
                else{
                    while(a.amt>0 && sell.size()>0 && sell.top().price<=a.price)
                    {
                        order p=sell.top();
                        sell.pop();
                        if(p.amt<=a.amt)
                        {
                            a.amt-=p.amt;
                        }
                        else
                        {
                            p.amt-=a.amt;
                            sell.push(p);
                            a.amt=0;
                        }
                    }
                    if(a.amt!=0)
                        buy.push(a);
                }
            }
            else if(a.typ==1)
            {
                if(buy.empty())
                    sell.push(a);
                else
                {
                    while(a.amt>0 && buy.size()>0 && buy.top().price>=a.price)
                    {
                        order p=buy.top();
                        buy.pop();
                        if(p.amt<=a.amt)
                        {
                            a.amt-=p.amt;
                        }
                        else
                        {
                            p.amt-=a.amt;
                            buy.push(p);
                            a.amt=0;
                        }
                    }
                    if(a.amt!=0)
                        sell.push(a);
                }
            }
        }
        while(!buy.empty())
            {
                rem+=buy.top().amt;
                buy.pop();
            }
        while(!sell.empty())
            {
                rem+=sell.top().amt;
                sell.pop();
            }
        return rem%1000000007;
    }
    
};