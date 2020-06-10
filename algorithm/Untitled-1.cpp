#include<vector>
#include<string>
using namespace std;
typedef struct item
{
    string name;
    int benefit;
    int weight;
    int cp;
    item( string name,int benefit,int weight):name(name), benefit(benefit),weight(weight)
    {
        cp = int(benefit / weight);
    }
}item;

template<class T>
vector<item> BackPack(vector<T> &list, int cap, __int8 mode)
{

}


int main()
{
    vector<item> items{
        {"A",4,4500},
        {"B",5,5700},
        {"C",2,2250},
        {"D",1,1100},
        {"E",6,6700},
    };

}