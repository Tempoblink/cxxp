/*
 * 给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
 *
 * (a) class TreeNode {
 *      private:
 *          std::string value;
 *          int count;
 *          TreeNode *left;
 *          TreeNode *right;
 *     }
 *
 * (b) class BinStrTree {
 *      private:
 *          TreeNode *root;
 *     }
 */

#include <iostream>
#include <string>

class TreeNode {
public:
    TreeNode(const std::string &s) : value(s), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &);
    TreeNode &operator=(const TreeNode &);
    ~TreeNode();

private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree(const std::string &s) : root(new TreeNode(s)) {}
    BinStrTree(const BinStrTree &) = delete;
    BinStrTree &operator=(const BinStrTree &) = delete;
    ~BinStrTree() {
        if (root) delete root;
    }

private:
    TreeNode *root;
};

TreeNode::TreeNode(const TreeNode &node) : value(node.value), count(node.count), left(node.left), right(node.right) {
    ++count;
}

TreeNode &TreeNode::operator=(const TreeNode &node) {
    ++*node.count;
    if (--*count == 0) {
        delete count;
        if (left) delete left;
        if (right) delete right;
    }
    value = node.value;
    count = node.count;
    left = node.left;
    right = node.right;
    return *this;
}

TreeNode::~TreeNode() {
    if (--*count == 0) {
        delete count;
        if (right) delete right;
        if (left) delete left;
    }
}


int main(int argc, char const *argv[]) {
    BinStrTree root("root");

    return 0;
}
