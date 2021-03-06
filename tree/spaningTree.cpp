#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#define MAX 9999
#define I INT_MAX
using namespace std;

struct edge
{
    int start, end, cost;
} E[1000];
bool operator<(edge e1, edge e2)
{
    return e1.cost < e2.cost;
}
tuple<int, int> my_make_tuple(int n1, int n2)
{
    int tempint;
    if (n1 > n2)
    {
        tempint = n1;
        n1 = n2;
        n2 = tempint;
    }
    tuple<int, int> temp(n1, n2);
    return temp;
}

vector<tuple<unsigned int, unsigned int>> make_vector_tuple_fromInput(const string &input)
{
    unsigned short i = 0;
    unsigned int temp1 = MAX, temp2 = MAX;

    vector<tuple<unsigned int, unsigned int>> result;
    result.reserve(20);

    for (char c : input)
    {
        if (isdigit(c))
        {
            if (temp1 != MAX)
                temp2 = c - '0';
            else
                temp1 = c - '0';
            i++;
        }
        if (i % 2 == 0 & i != 0)
        {
            cout << temp1 << " store temp " << temp2 << endl;
            result.push_back(make_tuple(temp1, temp2));
            i = 0;
            temp1 = temp2 = MAX;
        }
    }
    return result;
}

template <typename T, int M, int N>
void prim(T (&adj)[M][N], int start)
{
    vector<int> visited;
    visited.reserve(M);
    visited.resize(0);
    visited.push_back(start);
    cout << start << "\t";
    for (int i = 0; i < N; i++)
    {
        int min = MAX;
        int temp_point = -1;
        for (int v_point : visited)
        {
            for (int j = 0; j < N; j++)
            {
                auto it = find(visited.begin(), visited.end(), j);
                if (it == visited.end())
                {
                    if (adj[v_point][j] < min)
                    {
                        min = adj[v_point][j];
                        temp_point = j;
                    }
                }
            }
        }
        if (temp_point == -1)
            break;
        visited.push_back(temp_point);
        cout << temp_point << "\t";
    }
}

template <typename T, int M, int N>
void Kruskal(T (&adj)[M][N], int start)
{
    int set[N] = {-1};
    int include[N] = {-1};
}

void join(int v1, int v2, int *set)
{
    if (set[v1] < set[v2])
    {
        set[v1] += set[v2];
        set[v2] = v1;
    }
    else
    {
        set[v2] += set[v1];
        set[v1] = v2;
    }
}

int find(int u, int *set)
{
    int v = 0;
    int x = u;
    while(set[x] > 0)
        x = set[x];
    while(u!=x)
    {
        v = set[u] ;
        set[u] = x;
        u = v;
    }
    return x;
}

template <typename T, int M>
vector<edge> transform_arry_to_edge(T (&arr)[M][M])
{
    vector<edge> result;
    result.reserve(M);
    for (int i = 0; i < M; i++)
        for (int j = i + 1; j < M; j++)
        {
            if (arr[i][j] < INT_MAX)
            {
                struct edge e1 = {
                    i, j, arr[i][j]};
                result.push_back(e1);
            }
        }
    return result;
}

void test()
{
    set<tuple<int, int>> test1;

    test1.insert(my_make_tuple(2, 3));
    test1.insert(my_make_tuple(2, 3));
    for (auto it = test1.begin(); it != test1.end(); ++it)
        cout << "\t" << get<0>(*it) << "  " << get<1>(*it) << endl;
}

bool compare_tuple(const tuple<unsigned int, unsigned int> &t1, const tuple<unsigned int, unsigned int> &t2)
{
    return get<0>(t1) < get<0>(t2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    struct edge test[10] = {0};
    // vector<vector<*Node>> graph
    // vector<vector<int>> graph(10);
    // graph[0].push_back(2);
    // graph[0].push_back(3);
    // cout << graph[0].size()<< endl;
    // cout << graph.capacity()<< endl;
    // cout << graph[0].capacity()<< endl;

    // vector<int> row;
    // row.assign(10, -1);
    // vector<vector<int>> graph;
    // graph.assign(10, row);
    // graph[0][0] = 1;
    // graph.at(0).at(1) = 2;
    // graph.at(0).at(2) = 3;
    // vector<tuple<unsigned int, unsigned int>> rowt;
    // rowt.assign(20, tuple(1, 1));
    // vector<vector<tuple<unsigned int, unsigned int>>> result;
    // result.assign(20, rowt);
    // for (auto i = graph[0].begin(); i != graph[0].end(); i++)
    //     cout << *i << endl;

    // cout << "test tuple " << get<0>(make_tuple(1, 2)) << endl;
    // cout << "test tuple " << get<1>(make_tuple(1, 2)) << endl;

    // cout << "test tuple " << get<0>(result[0][0])<< endl;

    // vector<tuple<unsigned int, unsigned int>> result = make_vector_tuple_fromInput("(1,0) (2,3) (5,6) (1,4)");
    // for (tuple<unsigned int, unsigned int> temp : result)
    // {
    //     cout << get<0>(temp) <<"  "<<get<1>(temp)<<endl;
    // }
    // sort(result.begin(), result.end(), compare_tuple);
    // for (tuple<unsigned int, unsigned int> temp : result)
    // {
    //     cout << get<0>(temp) <<"  "<<get<1>(temp)<<endl;
    // }

    int cost[][8] =
        {{I, I, I, I, I, I, I, I},
         {I, I, 25, I, I, I, 5, I},
         {I, 25, I, 12, I, I, I, 10},
         {I, I, 12, I, 8, I, I, I},
         {I, I, I, 8, I, 16, I, 14},
         {I, I, I, I, 16, I, 20, 18},
         {I, 5, I, I, I, 20, I, I},
         {I, I, 10, I, 14, 18, I, I}};
    prim(cost, 1);
    int edge[9][3] = {{1, 2, 28}, {1, 6, 10}, {2, 3, 16}, {2, 7, 14}, {3, 4, 12}, {4, 5, 22}, {4, 7, 18}, {5, 6, 25}, {5, 7, 24}};

    return 0;
}
