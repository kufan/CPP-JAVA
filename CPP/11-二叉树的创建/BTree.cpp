#include "BTree.h"

// ����������
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


// ������� �� tree ������У�����һ�� dt �Ľڵ�
// pos ���·��(��������ʽ���)��  cnt �߼���    flag ��/��
int Insert_BTree(TBTree* tree, BTreeNode* dt, unsigned int pos, int cnt, int flag) {
	if (NULL == tree) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	int bit = 0;   // ��ô��

	BTreeNode* parent = NULL;
	BTreeNode* pCur   = tree->root;

	dt->left  = NULL;
	dt->right = NULL;

	// Ѱ�Ҳ����
	while (cnt > 0 && pCur != NULL) {
		bit = pos & 1;
		pos = pos >> 1;

		parent = pCur;  // ��¼���ڵ�
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
		// �����ʼʱû�и����� dt ��Ϊ��
		tree->root = dt;
	}

	tree->size++;

	return 0;
}

// root ��ָ��Ľڵ㵱����
// ͳ������������ж��ٸ��ڵ�
// �� static ���εı��������Ǿ�̬����
// �� static ���εĺ��������Ǿ�̬����(����)
static int Recursive_Count(BTreeNode* root) {
	int ret = 0;

	if (root != NULL) {
		ret = Recursive_Count(root->left) + Recursive_Count(root->right) + 1;
	}

	return ret;
}

// ɾ������: ɾ���� pos �� cnt ȷ���������Ǹ��ڵ�
BTreeNode* Delete_BTree(TBTree* tree, unsigned int pos, int cnt) {
	if (NULL == tree) {
		return NULL;
	}

	BTreeNode* ret = NULL;
	int bit = 0;   // ָ·

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

	// �������нڵ���Ŀʱ��һ��Ҫ����
	// ��ɾ���ڵ����������ӽ�㣬Ҳ�ᱻͬʱɾ��
	// ͳ�Ʊ�ɾ�������нڵ�
	tree->size = tree->size - Recursive_Count(ret);
	
	return ret;
}

// �õ�ָ��λ�õĽڵ�
BTreeNode* GetNode_BTree(TBTree* tree, unsigned int pos, int cnt) {
	if (NULL == tree) {
		return NULL;
	}

	BTreeNode* ret = NULL;
	int bit = 0;   // ָ·

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

// ��ø��ڵ�
BTreeNode* Root_BTree(TBTree* tree) {
	if (NULL == tree) {
		return NULL;
	}

	return tree->root;
}

// ������нڵ����
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

		// ��Ŀ�����
		ret = ((lh > rh) ? lh : rh) + 1;
	}

	return ret;
}

// �������ĸ߶�
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
		// Ҫôֻ����������Ҫôֻ��������
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

// �������Ķ�
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

// �������Ĵ�ӡ
// ��֪�����ݻ���ʲô���ӵģ�Ҳ���޷���ӡ
// ��˴�ʱ��Ҫ�û��ṩһ����ӡ���������ǵ��ã���������ͽ��� �ص�����
// Ϊ�˿���˳���ص��û�ʵ�ֵĴ�ӡ���������Ǳ����ֶ�ָ����ӡ�����ĸ�ʽ
// ����ָ�� ����ָ������ �ķ�ʽָ����
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

// �����
int Clear_BTree(TBTree* tree) {
	if (NULL == tree) {
		return -1;
	}

	tree->root = NULL;
	tree->size = 0;

	return 0;
}

// ������
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