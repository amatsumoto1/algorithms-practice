#include <algorithm>
#include <queue>

namespace DataStructures {

template <typename T>
BinaryTree<T>::BinaryTree(T value)
    : value_(value),
      left_(nullptr),
      right_(nullptr)
{}

template <typename T>
BinaryTree<T>::~BinaryTree() {}

template <typename T>
BinaryTree<T>* BinaryTree<T>::CreateLevel(const std::vector<T>& array, int startIndex) {
    if (startIndex >= array.size()) {
        return nullptr;
    }
    
    BinaryTree* root = new BinaryTree<T>(array[startIndex]);
    root->SetLeftChild(CreateLevel(array, 2 * startIndex + 1));
    root->SetRightChild(CreateLevel(array, 2 * startIndex + 2));

    return root;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::InitFromArray(const std::vector<T>& arr) {
    return CreateLevel(arr, 0);
}

template <typename T>
void BinaryTree<T>::DestroyTree(BinaryTree<T>* tree) {
    if (tree->left_ != nullptr) {
        DestroyTree(tree->left_);
    }

    if (tree->right_ != nullptr) {
        DestroyTree(tree->right_);
    }

    delete tree;
}

template <typename T>
bool BinaryTree<T>::IsLeaf() const {
    return left_ == nullptr && right_ == nullptr;
}

template <typename T>
T BinaryTree<T>::GetValue() const {
    return value_;
}

template <typename T>
void BinaryTree<T>::SetValue(T value) {
    value_ = value;
}

template <typename T>
const BinaryTree<T>* BinaryTree<T>::GetRightChild() const {
    return right_;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::GetRightChild() {
    return right_;
}

template <typename T>
bool BinaryTree<T>::HasRightChild() const {
    return right_ != nullptr;
}

template <typename T>
void  BinaryTree<T>::SetRightChild(BinaryTree<T>* tree) {
    right_ = tree;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::CreateRightChild(T value) {
    right_ = new BinaryTree(value);
    return right_;
}

template <typename T>
void BinaryTree<T>::RemoveRightChild() {
    right_ = nullptr;
}

template <typename T>
const BinaryTree<T>* BinaryTree<T>::GetLeftChild() const {
    return left_;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::GetLeftChild() {
    return left_;
}

template <typename T>
bool BinaryTree<T>::HasLeftChild() const {
    return left_ != nullptr;
}

template <typename T>
void  BinaryTree<T>::SetLeftChild(BinaryTree<T>* tree) {
    left_ = tree;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::CreateLeftChild(T value) {
    left_ = new BinaryTree(value);
    return left_;
}

template <typename T>
void BinaryTree<T>::RemoveLeftChild() {
    left_ = nullptr;
}

template <typename T>
int BinaryTree<T>::GetMaxDepth() const {
    if (IsLeaf()) {
        return 1;
    }
    else if (left_ == nullptr) {
        return 1 + right_->GetMaxDepth();
    }
    else if (right_ == nullptr) {
        return 1 + left_->GetMaxDepth();
    }

    return 1 + std::max(left_->GetMaxDepth(), right_->GetMaxDepth());
}

template <typename T>
int BinaryTree<T>::GetNumNodes() const {
    int numNodes = 1;
    if (left_ != nullptr) {
        numNodes += left_->GetNumNodes();
    }
    if (right_ != nullptr) {
        numNodes += right_->GetNumNodes();
    }

    return numNodes;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::GetNodeWithValue_BFS(T value) {
    std::queue<BinaryTree<T>*> queue;
    queue.push(this);
    
    while (!queue.empty()) {
        BinaryTree<T>* node = queue.front();
        queue.pop();

        if (node->value_ == value) {
            return node;
        }

        if (node->left_ != nullptr) {
            queue.push(node->left_);
        }

        if (node->right_ != nullptr) {
            queue.push(node->right_);
        }
    }

    return nullptr;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::GetNodeWithValue_DFS(T value) {
    std::vector<BinaryTree<T>*> stack = { this }; // Can also be done recursively.

    while(!stack.empty()) {
        BinaryTree<T>* node = stack.back();
        stack.pop_back();

        if (node->value_ == value) {
            return node;
        }

        if (node->left_ != nullptr) {
            stack.push_back(node->left_);
        }

        if (node->right_ != nullptr) {
            stack.push_back(node->right_);
        }
    }

    return nullptr;
}

template<typename T>
std::vector<T> BinaryTree<T>::GetPreorderValues() const {
    std::vector<T> values = { value_ };
    if (left_ != nullptr) {
        std::vector<T> leftValues = left_->GetPreorderValues();
        values.insert(values.end(), leftValues.begin(), leftValues.end());
    }

    if (right_ != nullptr) {
        std::vector<T> rightValues = right_->GetPreorderValues();
        values.insert(values.end(), rightValues.begin(), rightValues.end());
    }

    return values;
}

template <typename T>
std::vector<T> BinaryTree<T>::GetPostorderValues() const {
    std::vector<T> values;

    if (left_ != nullptr) {
        std::vector<T> leftValues = left_->GetPostorderValues();
        values.insert(values.end(), leftValues.begin(), leftValues.end());
    }

    if (right_ != nullptr) {
        std::vector<T> rightValues = right_->GetPostorderValues();
        values.insert(values.end(), rightValues.begin(), rightValues.end());
    }

    values.push_back(value_);

    return values;
}

template <typename T>
std::vector<T> BinaryTree<T>::GetInorderValues() const {
    std::vector<T> values;

    if (left_ != nullptr) {
        std::vector<T> leftValues = left_->GetInorderValues();
        values.insert(values.end(), leftValues.begin(), leftValues.end());
    }

    values.push_back(value_);

    if (right_ != nullptr) {
        std::vector<T> rightValues = right_->GetInorderValues();
        values.insert(values.end(), rightValues.begin(), rightValues.end());
    }

    return values;
}

}