#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>

namespace DataStructures {

template <typename T>
class BinaryTree {
public:
    BinaryTree(T value);
    ~BinaryTree();

    static BinaryTree* InitFromArray(const std::vector<T>& arr);
    static void DestroyTree(BinaryTree* tree);

    bool IsLeaf() const;
    T GetValue() const;
    void SetValue(T value);

    const BinaryTree* GetRightChild() const;
    BinaryTree* GetRightChild();
    bool HasRightChild() const;
    void SetRightChild(BinaryTree* tree);
    BinaryTree*  CreateRightChild(T value);
    void RemoveRightChild();

    const BinaryTree* GetLeftChild() const;
    BinaryTree* GetLeftChild();
    bool HasLeftChild() const;
    void SetLeftChild(BinaryTree* tree);
    BinaryTree*  CreateLeftChild(T value);
    void RemoveLeftChild();

    int GetMaxDepth() const;
    int GetNumNodes() const;

    BinaryTree* GetNodeWithValue_BFS(T value);
    BinaryTree* GetNodeWithValue_DFS(T value);

    std::vector<T> GetPreorderValues() const;
    std::vector<T> GetPostorderValues() const;
    std::vector<T> GetInorderValues() const;
private:
    T value_;
    BinaryTree* left_;
    BinaryTree* right_;

    static BinaryTree* CreateLevel(const std::vector<T>& array, int startIndex);
};

}

#include "inl/BinaryTree.inl"

#endif