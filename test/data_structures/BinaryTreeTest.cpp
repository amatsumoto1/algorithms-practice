#include "gtest/gtest.h"

#include "BinaryTree.h"

namespace DataStructures {

TEST(BinaryTreeTests, Constructor) {
    BinaryTree<int> tree(2);

    EXPECT_EQ(tree.GetValue(), 2);
    EXPECT_FALSE(tree.HasLeftChild());
    EXPECT_EQ(tree.GetLeftChild(), nullptr);
    EXPECT_FALSE(tree.HasRightChild());
    EXPECT_EQ(tree.GetRightChild(), nullptr);
    EXPECT_TRUE(tree.IsLeaf());
}

TEST(BinaryTreeTests, SetValue) {
    BinaryTree<int> tree(2);
    tree.SetValue(5);
    EXPECT_EQ(tree.GetValue(), 5);
}

TEST(BinaryTreeTests, SetLeftChild) {
    BinaryTree<int>* tree = new BinaryTree<int>(4);
    BinaryTree<int>* leftChild = new BinaryTree<int>(5);
    tree->SetLeftChild(leftChild);

    EXPECT_FALSE(tree->IsLeaf());
    EXPECT_TRUE(tree->HasLeftChild());
    EXPECT_EQ(tree->GetLeftChild(), leftChild);
    EXPECT_FALSE(tree->HasRightChild());

    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, CreateLeftChid) {
    BinaryTree<int>* tree = new BinaryTree<int>(4);
    BinaryTree<int>* leftChild = tree->CreateLeftChild(5);

    ASSERT_TRUE(tree->HasLeftChild());
    EXPECT_EQ(tree->GetLeftChild(), leftChild);
    EXPECT_EQ(leftChild->GetValue(), 5);
    EXPECT_FALSE(tree->HasRightChild());

    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, SetRightChild) {
    BinaryTree<int>* tree = new BinaryTree<int>(4);
    BinaryTree<int>* rightChild = new BinaryTree<int>(5);
    tree->SetRightChild(rightChild);

    EXPECT_FALSE(tree->IsLeaf());
    EXPECT_TRUE(tree->HasRightChild());
    EXPECT_EQ(tree->GetRightChild(), rightChild);
    EXPECT_FALSE(tree->HasLeftChild());

    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, CreateRightChid) {
    BinaryTree<int>* tree = new BinaryTree<int>(4);
    BinaryTree<int>* rightChild = tree->CreateRightChild(5);

    ASSERT_TRUE(tree->HasRightChild());
    EXPECT_EQ(tree->GetRightChild(), rightChild);
    EXPECT_EQ(rightChild->GetValue(), 5);
    EXPECT_FALSE(tree->HasLeftChild());

    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, InitFromArray) {
    std::vector<int> arr = {1, 2, 4, 5};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    EXPECT_EQ(tree->GetValue(), 1);
    ASSERT_TRUE(tree->HasLeftChild());
    EXPECT_EQ(tree->GetLeftChild()->GetValue(), 2);
    ASSERT_TRUE(tree->HasRightChild());
    EXPECT_EQ(tree->GetRightChild()->GetValue(), 4);
    EXPECT_TRUE(tree->GetRightChild()->IsLeaf());
    EXPECT_FALSE(tree->GetLeftChild()->HasRightChild());
    ASSERT_TRUE(tree->GetLeftChild()->HasLeftChild());
    EXPECT_EQ(tree->GetLeftChild()->GetLeftChild()->GetValue(), 5);
    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, GetMaxDepth) {
    BinaryTree<int>* tree = new BinaryTree<int>(0);
    EXPECT_EQ(tree->GetMaxDepth(), 1);
    BinaryTree<int>* rightTree = tree->CreateRightChild(4);
    rightTree->CreateLeftChild(6);
    tree->CreateLeftChild(6);
    EXPECT_EQ(tree->GetMaxDepth(), 3);
    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, GetNumNodes) {
    BinaryTree<int> leaf(0);
    EXPECT_EQ(leaf.GetNumNodes(), 1);

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    EXPECT_EQ(tree->GetNumNodes(), 10);
    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, GetNodeWithValue_BFS) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    BinaryTree<int>* bfsNode = tree->GetNodeWithValue_BFS(8);
    EXPECT_EQ(bfsNode->GetValue(), 8);
    EXPECT_EQ(tree->GetNodeWithValue_BFS(-2), nullptr);
    BinaryTree<int>::DestroyTree(tree);
}

TEST(BinaryTreeTests, GetNodeWithValue_DFS) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    BinaryTree<int>* bfsNode = tree->GetNodeWithValue_DFS(8);
    EXPECT_EQ(bfsNode->GetValue(), 8);
    EXPECT_EQ(tree->GetNodeWithValue_DFS(-2), nullptr);
    BinaryTree<int>::DestroyTree(tree);
}

/**
 *       1
 *     2   3
 *   4   5  6 7
 *  8 9 10
 */

TEST(BinaryTreeTests, GetPreorderValues) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {1, 2, 4, 8, 9, 5, 10, 3, 6, 7};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    std::vector<int> tranversal = tree->GetPreorderValues();
    EXPECT_EQ(expected, tranversal);
}

TEST(BinaryTreeTests, GetPostorderValues) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {8, 9, 4, 10, 5, 2, 6, 7, 3, 1};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    std::vector<int> tranversal = tree->GetPostorderValues();
    EXPECT_EQ(expected, tranversal);
}

TEST(BinaryTreeTests, GetInorderValues) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {8, 4, 9, 2, 10, 5, 1, 6, 3, 7};
    BinaryTree<int>* tree = BinaryTree<int>::InitFromArray(arr);
    std::vector<int> tranversal = tree->GetInorderValues();
    EXPECT_EQ(expected, tranversal);
}

}