class Solution
{
public:
    vector<string> path;
    void solve(map<string, vector<string>> &graph, string current)
    {

        while (!graph[current].empty())
        {

            string t = graph[current].back();
            graph[current].pop_back();
            solve(graph, t);
        }
        path.push_back(current);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {

        map<string, vector<string>> graph; // creating graph using map
        int n = tickets.size();

        for (int i = 0; i < n; i++)
        {
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }

        for (auto it = graph.begin(); it != graph.end(); it++)
        {
            sort(it->second.begin(), it->second.end(),greater<string>());   // sort in decending order 
            
        }

        solve(graph, "JFK"); // start from "JFK" airport

        reverse(path.begin(), path.end()); 
       

        return path;
    }
};
