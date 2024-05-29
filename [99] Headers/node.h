 
template<typename T>
struct ListNode{
    T val;
    ListNode<T> *next;
};

template<typename T>
struct DoublyListNode{
    T val;
    DoublyListNode<T> *next;
    DoublyListNode<T> *prev;
};

template<typename T>
struct BinaryTreeNode{
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
};