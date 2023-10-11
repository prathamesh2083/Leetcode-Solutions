class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {

        vector<int> start, end;
        int n = flowers.size();
        int lday = 0;

        for (int i = 0; i < n; i++)
        {
            start.push_back(flowers[i][0]);  // store start of each flower
            end.push_back(flowers[i][1] + 1);  // store end of each flower
            lday = max(lday, max(flowers[i][0], flowers[i][1]));
        }

        sort(start.begin(), start.end());  // sort start days
        sort(end.begin(), end.end());   // sort end days

        for (int i = 0; i < people.size(); i++)
        {
            int day = people[i];
            auto it = upper_bound(start.begin(), start.end(), day);
            int bloomed = 0;
            int ind = it - start.begin();  // count number of flowers have started bloomin at day
            bloomed = ind;

            int stopped = 0;    // count number of flowers have ended blooming at day
            auto stp = upper_bound(end.begin(), end.end(), day);
            ind = stp - end.begin();
            stopped = ind;

            people[i] = bloomed - stopped;  // number of flowers blooming at day = bloomed-stopped
        }
        return people;
    }
};
