 #include <iostream>
 #include <memory>
 #include <vector>
 #pragma once

using namespace std;
 namespace ariel{
     template<typename T> class BinaryTree{
        private:
        //Node struct to hold data , left child and right child
        struct Node{
            T data;
            Node* left;
            Node* right;

            Node(T a):data(a){}
            
        };
        public:
        //Varibales
        int size;
        vector<Node*> nodes;
        private:
        Node* root;

        public:
        //Constructor
        BinaryTree():root(nullptr),size(0){}
        //Copy constructor
        BinaryTree(BinaryTree &a){}

        //Destructor
        ~BinaryTree(){
            for(Node* n : nodes){
                delete n;
            }
        }
        
        //Methods
        BinaryTree<T>& add_root(T a){
            root = new Node(a);
            nodes.push_back(root);
            ++size;
            return *this;
        }
        BinaryTree<T>& add_left(T a, T b){
            for(Node* n : nodes){
                if(n->data == a){
                    cout<<n->data<<" found data, printing from line 49 , add_left"<<endl;
                    if(n->left == NULL){// there is no left son
                        ++size;
                        Node* left = new Node(b);
                        nodes.push_back(left);
                        n->left = left;
                        }else{// there is a left son
                            n->left->data = b;
                        }
                    }
            }
            cout<<"number of nodes: "<<nodes.size()<<endl;
            return *this;
        }
        BinaryTree<T>& add_right(T a, T b){
            for(Node* n : nodes){
                if(n->data == a){
                    cout<<n->data<<" found data, printing from line 66 , add_right"<<endl;
                    if(n->right == NULL){// there is no left son
                        ++size;
                        Node* right = new Node(b);
                        nodes.push_back(right);
                        n->right = right;
                        }else{// there is a left son
                            n->right->data = b;
                        }
                    }
            }
            cout<<"number of nodes: "<<nodes.size()<<endl;
            return *this;
        }
        T* begin(){return 0;}
        T* end(){return 0;}

        //Operators
        friend std::ostream& operator<< (std::ostream& os, const BinaryTree& bt){return os;};


        //---------------------Beginning of iterators ---------------------
        //iterator that runs on the tree in preorder
        class preorder_iterator{
            private:
            Node* current_node;
            public:
            //Constructor
            preorder_iterator(Node* p = nullptr):current_node(p){};

            //Operators
            //Returns the value iterator points to, the iterator itself is const.
            T& operator*() const {
                return current_node->data;
                }

            T* operator->() const {return &(current_node->data);};

            const preorder_iterator operator++(int) {
			preorder_iterator tmp= *this;
			return tmp;
            }

            const preorder_iterator operator++() {
			preorder_iterator tmp= *this;
			return tmp;
            }

            bool operator==(const preorder_iterator& b) const {return false;}

            bool operator!=(const preorder_iterator& b) const {return false;}

        };//End of preorder_iterator

        //iterator that runs on the tree in inorder
        class inorder_iterator{
            private:
            Node* current_node;
            public:
            //Constructor
            inorder_iterator(Node* p = nullptr):current_node(p){};

            //Operators
            //Returns the value iterator points to, the iterator itself is const.
            T& operator*() const {return current_node->data;}

            T* operator->() const {return &(current_node->data);};

            const inorder_iterator operator++(int) {
			inorder_iterator tmp= *this;
			return tmp;
            }

            const inorder_iterator operator++() {
			inorder_iterator tmp= *this;
			return tmp;
            }

            bool operator==(const inorder_iterator& b) const {return false;}

            bool operator!=(const inorder_iterator& b) const {return false;}

        };//End of inorder_iterator

        //iterator that runs on the tree in postorder 
        class postorder_iterator{
            private:
            Node* current_node;
            public:
            //Constructor
            postorder_iterator(Node* p = nullptr):current_node(p){};

            //Operators
            //Returns the value iterator points to, the iterator itself is const.
            T& operator*() const {return current_node->data;};

            T* operator->() const {return &(current_node->data);};

            const postorder_iterator operator++(int) {
			postorder_iterator tmp= *this;
			return tmp;
            }

            const postorder_iterator operator++() {
			postorder_iterator tmp= *this;
			return tmp;
            }

            bool operator==(const postorder_iterator& b) const {return false;}

            bool operator!=(const postorder_iterator& b) const {return false;}

        };//End of postorder_iterator


        //---------------------End of iterators ---------------------------


        //Iterator methods
        preorder_iterator begin_preorder(){
            preorder_iterator temp(root);
            return temp;
        };
        preorder_iterator end_preorder(){
            preorder_iterator temp(nullptr);
            return temp;
        };

        inorder_iterator begin_inorder(){
            inorder_iterator temp(root);
            return temp;
        };
        inorder_iterator end_inorder(){
            inorder_iterator temp(nullptr);
            return temp;
        };

        postorder_iterator begin_postorder(){
            postorder_iterator temp(root);
            return temp;
        };
        postorder_iterator end_postorder(){
            postorder_iterator temp(nullptr);
            return temp;
        };
     };
 }

