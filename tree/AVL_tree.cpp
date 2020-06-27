#include <iostream>

using namespace std;

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int left = p->left ? p->left->height : 0;
    int right = p->right ? p->right->height : 0;
    return left > right ? left + 1 : right + 1;
}
struct Node * LLRotation(struct Node *p)
{
    struct Node *pl;
    struct Node *plr;
    pl = p->left;
    plr = pl->right;
    pl->right = p;
    p->left = plr;

    p->height = NodeHeight(p);  //執行完rotaion 就順便更新有變動的高度
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;   //因為希望使用Rinsert後返回的是修改的root本身, 若少了這行 會返回rl, 而root 沒有改變
    return pl;
}

struct Node * LRRotation(struct Node *p)
{
    struct Node *pl;
    struct Node *plr;

    pl = p->left;
    plr = pl->right;

    p->left = plr->right;
    pl->right = plr->left;

    plr->right = p;
    plr->left = pl;

    p->height = NodeHeight(p);   //要照順序從下到上更新
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    if(root == p)
        root = plr;
    return plr;

}
struct Node * RRRotation(struct Node *p)
{
    struct Node *pr = p->right;
    p->right = pr->left;
    pr->left = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);


    if(root == p)
        root = pr;
    return pr;
}
struct Node * RLRotation(struct Node *p)
{
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;

    if(root == p)
        root = prl;
    return prl;
}

int BalanceFactor(struct Node *p)
{
    int left = p->left ? p->left->height : 0;
    int right = p->right ? p->right->height : 0;
    return left - right;
}


struct Node *Rinsert(struct Node *p, int key) //帶入root, 回傳node
{
    struct Node *t = NULL;
    if (!p)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->left = t->right = NULL;
        t->height = 1;
        return t;
    }
    if (p->data < key)
        p->right = Rinsert(p->right, key);
    else
        p->left = Rinsert(p->right, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)
        return RLRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)
        return RRRotation(p);
    return p;
}

int main()
{

    root = Rinsert(root, 50);
    Rinsert(root, 10);
    Rinsert(root, 20);

    return 0;
}