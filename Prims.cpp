#include <iostream>
using namespace std;
int n = 6;
int grp[6][6] = {
    {0, 7, 0, 8, 0, 0},
    {7, 0, 6, 3, 0, 0},
    {0, 6, 0, 4, 2, 5},
    {8, 3, 4, 0, 3, 0},
    {0, 0, 2, 3, 0, 2},
    {0, 0, 5, 0, 2, 0}};
int dist[100];
int parent[100];
int mst[100];

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
    parent[src] = src;
    for (int i = 0; i < n; i++)
    {
        int cur_vet = minDist();
        mst[cur_vet] = 1;
        for (int v = 0; v < n; v++)
        {
            if (grp[cur_vet][v])
            {
                if (mst[v] == 0 && dist[v] > grp[cur_vet][v])
                {
                    dist[v] = grp[cur_vet][v];
                    parent[v] = cur_vet;
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
        cout << "EDGE   " << char('A' + parent[i]) << "---" << char('A' + i) << "->" << dist[i] << endl;
    }
}

// main function
int main(void)
{
    primsMST(0);
    showTree();

    return 0;
}
