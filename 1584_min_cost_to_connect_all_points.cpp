class Solution
{
public:
     vector<int> parent;
    vector<int> size;
    void make(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int find1(int v)
    {
        if (parent[v] == v)
        {
            return parent[v];
        }
        return parent[v] = find1(parent[v]);
    }
    void Union(int a, int b)
    {
        a = find1(a);
        b = find1(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int createMst(int n, vector<pair<int, pair<int, int>>> &v, int sz)
    {
        int totalCost = 0;
       
        for (int i = 0; i < n; i++)
        {
            make(i);
        }

        for (int i = 0; i < sz; i++)
        {
           
            int wt = v[i].first;
            int x = v[i].second.first;
            int y = v[i].second.second;

            if (find1(x) == find1(y))
            {

                continue;
            }
         

            Union(x, y);
            totalCost += wt;
        }
         
         for(int i=0;i<n;i++){
            if(find1(i) != find1(0))
                return INT_MAX;
        }   
        return totalCost;
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {

       vector<pair<int,pair<int,int>>>v;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = 0;
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);   // find the distance between two points and push distance along with points in v
               
                v.push_back({dist,{i,j}});
            }
        }
         parent.resize(n + 1);
        size.resize(n + 1);
        sort(v.begin(),v.end());  // sort v in ascending order
        return createMst(points.size(),v,v.size());
       
    }
};
