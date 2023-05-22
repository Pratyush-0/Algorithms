#include <iostream>
using namespace std;
int n = 5;
int grp[5][5] = {
    {0, 3, 0, 0, 2},
    {3, 0, 5, 4, 1},
    {0, 5, 0, 2, 0},
    {0, 4, 2, 0, 3},
    {2, 1, 0, 3, 0}};
int dist[5];
int parent[5];
int mst[5];

// min distance vertex
int minDist()
{
    int min = 9999;
    int min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mst[i] == 0 && min > dist[i])
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// prim's
void primsMST(int src)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = 99999;
        parent[i] = -1;
        mst[i] = 0;
    }
    dist[src] = 0;
    // mst[src]=1;
    for (int i = 0; i < n; i++)
    {
        int key = minDist();
        mst[key] = 1;
        for (int v = 0; v < n; v++)
        {
            if (grp[key][v] != 0)
            {
                if (mst[v] == 0 && dist[v] > grp[key][v])
                {
                    dist[v] = grp[key][v];
                    parent[v] = key;
                }
            }
        }
    }
}

// display output
void showTree()
{
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << "->" << i << "  " << grp[parent[i]][i] << endl;
        }
    }
}

// main function
int main(void)
{
    primsMST(0);
    showTree();

    return 0;
}