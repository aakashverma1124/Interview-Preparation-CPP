#include<bits/stdc++.h>
using namespace std;

class AlienDictionary {
public:
    static void buildGraph(int n, int k, vector<string>& words, map<char, vector<char>>& graph, unordered_map<char, int>& indegree) {
        
        for(char i = 'a'; i < 'a' + k; i++) {
            vector<char> v;
            graph[i] = v;
            indegree[i] = 0;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            string curr_word = words[i];
            string next_word = words[i + 1];
            for(int j = 0; j < min(curr_word.size(), next_word.size()); j++) {
                if(curr_word[j] != next_word[j]) {
                    graph[curr_word[j]].push_back(next_word[j]);
                    indegree[next_word[j]] += 1;
                    break;
                }
            }
        }  
    }

    static string findOrder(int n, int k, vector<string>& words) {
        map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
        AlienDictionary::buildGraph(n, k, words, graph, indegree);
        
        queue<char> q;
        for(auto pair : indegree) {
            if(pair.second == 0) {
                q.push(pair.first);
            }
        }

        string sortedOrder;
        while(!q.empty()) {
            char currNode = q.front();
            sortedOrder.push_back(currNode);
            q.pop();
            for(auto nbr : graph[currNode]) {
                indegree[nbr] -= 1;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if(sortedOrder.size() == k) return sortedOrder;
        else return "";
    }
};


int main() {
    int n = 3, k = 2;
    vector<string> words{"a", "ab", "b"};
    cout << AlienDictionary::findOrder(n, k, words);
    return 0;
}        