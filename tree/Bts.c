#include "./Bts.h"


int main()
{
	int temp;
	Nptr tree = NULL;
	// Mqueue Mq = (Mqueue)calloc(1, sizeof(struct queue));
	while(scanf("%d", &temp) == 1)
	{
		tree = Insert(temp, tree);
	}
	// FindLeftRightHeight(tree);
	// FindLeftRightHeight(tree->left);
	// FindLeftRightHeight(tree->right);
	FindAllBalance(tree);
	return 0;
}
