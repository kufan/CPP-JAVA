#include "BTree.h"

// 创建二叉树
TBTree* Init_BTree() {
	TBTree* tree = NULL;

	tree = (TBTree*)malloc(sizeof(TBTree));
	if (NULL == tree) {
		perror("malloc");
		return NULL;
	}

	tree->root = NULL;
	tree->size = 0;

	return tree;
}


// 插入操作 在 tree 这棵树中，插入一个 dt 的节点
// pos 标记路径(二进制形式标记)，  cnt 走几步    flag 左/右
int Insert_BTree(TBTree* tree, BTreeNode* dt, unsigned int pos, int cnt, int flag) {
	if (NULL == tree) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	int bit = 0;   // 怎么走

	BTreeNode* parent = NULL;
	BTreeNode* pCur   = tree->root;

	dt->left  = NULL;
	dt->right = NULL;

	// 寻找插入点
	while (cnt > 0 && pCur != NULL) {
		bit = pos & 1;
		pos = pos >> 1;

		parent = pCur;  // 记录父节点
		if (bit == BT_LEFT) {
			pCur = pCur->left;
		} else if(bit == BT_RIGHT) {
			pCur = pCur->right;
		}

		cnt--;
	}

	if (flag == BT_LEFT) {
		dt->left  = pCur;
	} else if(flag == BT_RIGHT){
		dt->right = pCur;
	}

	if (parent != NULL) {
		if (bit == BT_LEFT) {
			parent->left = dt;
		} else {
			parent->right = dt;
		}
	} else {
		// 如果起始时没有根，则 dt 成为根
		tree->root = dt;
	}

	tree->size++;

	return 0;
}

// root 所指向的节点当作根
// 统计这个根下面有多少个节点
// 被 static 修饰的变量，就是静态变量
// 被 static 修饰的函数，就是静态函数(方法)
static int Recursive_Count(BTreeNode* root) {
	int ret = 0;

	if (root != NULL) {
		ret = Recursive_Count(root->left) + Recursive_Count(root->right) + 1;
	}

	return ret;
}

// 删除操作: 删除被 pos 和 cnt 确定出来的那个节点
BTreeNode* Delete_BTree(TBTree* tree, unsigned int pos, int cnt) {
	if (NULL == tree) {
		return NULL;
	}

	BTreeNode* ret = NULL;
	int bit = 0;   // 指路

	BTreeNode* parent = NULL;
	BTreeNode* pCur = tree->root;

	while (cnt > 0 && pCur != NULL) {
		bit = pos & 1;
		pos = pos >> 1;

		parent = pCur;
		if (bit == BT_LEFT) {
			pCur = pCur->left;
		} else if(bit == BT_RIGHT) {
			pCur = pCur->right;
		}

		cnt--;
	}

	if (parent != NULL) {
		if (bit == BT_LEFT) {
			parent->left = NULL;
		} else if(bit == BT_RIGHT) {
			parent->right = NULL;
		}
		
	} else {
		tree->root = NULL;
	}

	ret = pCur;

	// 更新树中节点数目时，一定要留意
	// 被删除节点后面的所有子结点，也会被同时删除
	// 统计被删除的所有节点
	tree->size = tree->size - Recursive_Count(ret);
	
	return ret;
}

// 得到指定位置的节点
BTreeNode* GetNode_BTree(TBTree* tree, unsigned int pos, int cnt) {
	if (NULL == tree) {
		return NULL;
	}

	BTreeNode* ret = NULL;
	int bit = 0;   // 指路

	BTreeNode* parent = NULL;
	BTreeNode* pCur = tree->root;

	while (cnt > 0 && pCur != NULL) {
		bit = pos & 1;
		pos = pos >> 1;

		parent = pCur;
		if (bit == BT_LEFT) {
			pCur = pCur->left;
		}
		else if (bit == BT_RIGHT) {
			pCur = pCur->right;
		}

		cnt--;
	}

	ret = pCur;

	return ret;
}

// 获得根节点
BTreeNode* Root_BTree(TBTree* tree) {
	if (NULL == tree) {
		return NULL;
	}

	return tree->root;
}

// 获得树中节点个数
int GetSize_BTree(TBTree* tree) {
	if (NULL == tree) {
		return -1;
	}

	return tree->size;
}


static int Recursive_Height(BTreeNode* root) {
	int ret = 0;

	if (root != NULL) {
		int lh = Recursive_Height(root->left);
		int rh = Recursive_Height(root->right);

		// 三目运算符
		ret = ((lh > rh) ? lh : rh) + 1;
	}

	return ret;
}

// 计算树的高度
int Height_BTree(TBTree* tree) {
	if (NULL == tree) {
		return -1;
	}

	int ans = Recursive_Height(tree->root);

	return ans;
}


static int Recursive_Degree(BTreeNode* root) {
	if (root == NULL) {
		return -2;
	}

	int ret = 0;
	if (root->left != NULL) {
		ret++;
	}
	if (root->right != NULL) {
		ret++;
	}

	if (ret == 1) {
		// 要么只有左子树，要么只有右子树
		int ld = Recursive_Degree(root->left);
		int rd = Recursive_Degree(root->right);

		if (ret < ld) {
			ret = ld;
		}
		if (ret < rd) {
			ret = rd;
		}
	}

	return ret;
}

// 计算树的度
int Degree_BTree(TBTree* tree) {
	if (NULL == tree) {
		return -1;
	}
	
	int ret = Recursive_Degree(tree->root);

	return ret;
}


static void Recursive_Display(BTreeNode* root, BTREEPRINT pFunc, int format, int gap, char div) {
	if (root != NULL && pFunc != NULL) {
		for (int i = 0; i < format; i++) {
			printf("%c", div);
		}
		pFunc(root);
		printf("\n");

		if (root->left != NULL || root->right != NULL) {
			Recursive_Display(root->left, pFunc, format + gap, gap, div);
			Recursive_Display(root->right, pFunc, format + gap, gap, div);
		}
	} else {
		for (int i = 0; i < format; i++) {
			printf("%c", div);
		}
		printf("\n");
	}
	
}

// 二叉树的打印
// 不知道数据会是什么样子的，也就无法打印
// 因此此时需要用户提供一个打印函数供我们调用，这个函数就叫做 回调函数
// 为了可以顺利回调用户实现的打印函数，我们必须手动指定打印函数的格式
// 借助指定 函数指针类型 的方式指定的
int Display_BTree(TBTree* tree, BTREEPRINT pFunc, int gap, char div) {
	if (NULL == tree) {
		return -1;
	}
	if (NULL == pFunc) {
		return -2;
	}

	Recursive_Display(tree->root, pFunc, 0, gap, div);

	return 0;
}

// 清空树
int Clear_BTree(TBTree* tree) {
	if (NULL == tree) {
		return -1;
	}

	tree->root = NULL;
	tree->size = 0;

	return 0;
}

// 销毁树
int Destroy_BTree(TBTree* tree) {
	if (NULL == tree) {
		return -1;
	}

	if (tree != NULL) {
		free(tree);
		tree = NULL;
	}
	
	return 0;
}