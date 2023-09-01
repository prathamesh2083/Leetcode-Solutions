class Solution
{
public:
    int candy(vector<int> &ratings)
    {

        int n = ratings.size();
        int candies = 0;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {ratings[i], i};  // map rating with its index in vector v
        }

        sort(v.begin(), v.end()); // sort v according to rating

        vector<int> cad(n, 1);  // create a vector in which we are going to store number of candies given to ith child

        int rating = v[0][1];
        int k = 0;
        while (k < n && v[k][0] == rating)
        {                                    // give 1 candy to all children having minimum rating
            k++;
        }


        for (int i = k; i < n; i++)
        {
            // for each next rating if child having rating greater than neighbours then give (1+maximum of number of candies given to neighbours) 
            int lef, rig;
            lef = v[i][1] - 1;
            rig = v[i][1] + 1;
            if ((lef >= 0 && ratings[lef] < ratings[v[i][1]]) || (rig < n && ratings[rig] < ratings[v[i][1]]))
            {

                int val1 = 0, val2 = 0;
                if (lef >= 0 && ratings[lef] < ratings[v[i][1]])
                {
                    val1 = cad[lef];
                }
                if (rig < n && ratings[rig] < ratings[v[i][1]])
                {
                    val2 = cad[rig];
                }

                cad[v[i][1]] = 1 + max(val1, val2);
            }
        }


        for (int i = 0; i < n; i++)
        {

            candies += cad[i];  // add numbers of candies given to all children
        }
        return candies;
    }
};
