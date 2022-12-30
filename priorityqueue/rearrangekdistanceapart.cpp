class Solution {
    struct comparator{
    bool operator()(pair<char,int> &a,pair<char,int> &b)
        {
            return a.second<b.second;
        }
    };
    public: 
        string rearrangeString(string &s, int k) {
        unordered_map<char,int> mp;
        priority_queue<pair<char,int>,vector<pair<char,int>>,comparator> hp;
        for(char ch:s)
            mp[ch]+=1;
        for(pair<char,int> p:mp)
            hp.push(p);
        string res="";
        queue<pair<char,int>> q;
        while(!hp.empty())
        {
            pair<char,int> p=hp.top();
            hp.pop();
            res.push_back(p.first);
            p.second-=1;
            q.push(p);
            if(q.size()==k)
            {
                pair<char,int> qp=q.front();
                q.pop();
                if(qp.second!=0)
                    hp.push(qp);
            }
        }
        if(res.size()==s.size())
            return res;
        else
            return "";
    }
};