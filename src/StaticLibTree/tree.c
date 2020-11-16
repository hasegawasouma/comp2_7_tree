#include "Windows.h"                    // Windows API の機能定義
#include <stdbool.h>
#include "../include/libtree.h"

//
// 2分木の初期化
//
void initialize(binary_tree* t)
{
	t->root = NULL;
}

void free_recursive(node * p)
{
	if (p == NULL)
	{
		return;
	}
	free_recursive(p->left);
	free_recursive(p->right);
	free(p);
}
//
// 使用メモリの全解放
//
void finalize(binary_tree* t)
{
	free_recursive(t->root);
}

static void insert_node(node* p, node* n)
{
	if (n->key < p->key)
	{
		if (p->left == NULL)
		{
			p->left = n;
		}

		else
		{
			insert_node(p->left, n);
		}

	}
	else
	{
		if (p->right == NULL)
		{
			p->right = n;
		}

		else
		{
			insert_node(p->right, n);
		}

	}
}
//
// keyの値を見てノードを追加する
//
bool add_node(binary_tree* t, int key, const char* value)
{
	// todo: ノードを作成して、適切な位置に挿入してください

	node* p = malloc(sizeof(node));

	if (p == NULL)
	{
		false;
	}

	p->key = key;
	strcpy_s(p->value, 256, value);
	p->left = p->right = NULL;

	if (t->root == NULL)
	{
		t->root = p;
	}

	else
	{
		insert_node(t->root, p);}

	return true;
}

void static search_nodes(const node* p, void (*func)(const node* p))
{
	if (p == NULL)
	{
		return;
	}

	search_nodes(p->left, func);
	func(p);
	search_nodes(p->right, func);
}

//
// keyの小さな順にコールバック関数funcを呼び出す
//
void serach(const binary_tree* t, void (*func)(const node* p))
{
	// todo: keyの小さな順にfunc関数をよびだしてください
	search_nodes(t->root,func);// テストが通ってしまっていたので、通らなくした
}

