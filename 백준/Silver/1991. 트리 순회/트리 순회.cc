#include <iostream>
using namespace std;

struct Node {
	char key;
	struct Node* right;
	struct Node* left;
};

void Insert(Node* root, char c1, char c2, char c3);
void Inorder(Node* root);
void Preorder(Node* root);
void Postorder(Node* root);
void Freetree(Node* root);

int main(void)
{
	struct Node* root = NULL;
	int num;
	char data[3];

	cin >> num;
	for (int count = 0; count < num; count++) {
		for (int i = 0; i < 3; i++) {
			cin >> data[i];
			fflush(stdin);
		}
		if (root == NULL) {
			struct Node* temp = (Node*)malloc(sizeof(Node));
			temp->key = data[0];
			if (data[1] != '.') {
				struct Node* leftSubtree = (Node*)malloc(sizeof(Node));
				leftSubtree->key = data[1];
				leftSubtree->left = NULL;
				leftSubtree->right = NULL;
				temp->left = leftSubtree;
			}
			if (data[2] != '.') {
				struct Node* rightSubtree = (Node*)malloc(sizeof(Node));
				rightSubtree->key = data[2];
				rightSubtree->left = NULL;
				rightSubtree->right = NULL;
				temp->right = rightSubtree;
			}
			root = temp;
		}
		else {
			Insert(root, data[0], data[1], data[2]);
		}
	}

	Preorder(root);
	printf("\n");
	Inorder(root);
	printf("\n");
	Postorder(root);
	printf("\n");

	Freetree(root);

	return 0;
}

void Insert(Node* root, char c1, char c2, char c3)
{
	if (root == NULL) return;

	if (root->key == c1) {
		if (c2 != '.') {
			struct Node* temp = (Node*)malloc(sizeof(Node));
			temp->key = c2;
			temp->left = NULL;
			temp->right = NULL;
			root->left = temp;
		}
		if (c3 != '.') {
			struct Node* temp = (Node*)malloc(sizeof(Node));
			temp->key = c3;
			temp->left = NULL;
			temp->right = NULL;
			root->right = temp;
		}
	}
	else {
		Insert(root->left, c1, c2, c3);
		Insert(root->right, c1, c2, c3);
	}
}

void Inorder(Node* root)
{
	if (root == NULL) return;

	Inorder(root->left);
	printf("%c", root->key);
	Inorder(root->right);
}

void Preorder(Node* root)
{
	if (root == NULL) return;

	printf("%c", root->key);
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(Node* root)
{
	if (root == NULL) return;

	Postorder(root->left);
	Postorder(root->right);
	printf("%c", root->key);
}

void Freetree(Node* root)
{
	if (root == NULL) return;

	Freetree(root->left);
	Freetree(root->right);
	free(root);
}