template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

    BinaryTreeNode(T data){
        left = NULL;
        right = NULL;
        this->data = data;
    }
    
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
