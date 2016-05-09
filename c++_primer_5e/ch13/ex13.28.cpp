#include <iostream>

using namespace std;

class TreeNode {
private:
    std::string value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
public:
    TreeNode() : value("rt"), count(1), left(NULL), right(NULL) {}
    TreeNode(const TreeNode& other);
    TreeNode& operator=(const TreeNode& other);
    ~TreeNode() {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }
};

TreeNode::TreeNode(const TreeNode& other) 
: value(other.value), count(other.count) {
    if (other.left != NULL) {
        left = new TreeNode(*other.left);
    } else {
        left = NULL;
    }
    if (other.right != NULL) {
        right = new TreeNode(*other.right);
    } else {
        right = NULL;
    }
}

TreeNode& TreeNode::operator=(const TreeNode& other) {
    value = other.value;
    count = other.count;
    TreeNode* nleft = new TreeNode(*other.left);
    TreeNode* nright = new TreeNode(*other.right);
    if (left != NULL)
        delete left;
    if (right != NULL)
        delete right;
    left = nleft;
    right = nright;
    return *this;
}

class BinStrTree {
private:
    TreeNode *root;
public:
    BinStrTree() { root = new TreeNode(); }
    BinStrTree(const BinStrTree& bs) : root(new TreeNode(*bs.root)) {}
    BinStrTree& operator=(const BinStrTree& bst);
    ~BinStrTree();
};

BinStrTree& BinStrTree::operator=(const BinStrTree& bst) {
    auto nroot = new TreeNode(*bst.root);
    delete root;
    root = nroot;
    return *this;
}

BinStrTree::~BinStrTree() {
    delete root;
}

int main(int argc, char **argv) {
    BinStrTree bst;
    BinStrTree bst2 = bst;
    BinStrTree bst3;
    bst3 = bst2;
}
