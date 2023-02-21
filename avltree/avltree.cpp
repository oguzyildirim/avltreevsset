//MyDS.h

#ifndef MyDS_H
#define MyDS_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <chrono> 
using namespace std::chrono; 


class MyDS {
private:
    struct treeNode
    {
        treeNode* left;
        treeNode* right;
        int height;
        std::string data;
        treeNode() {left = NULL; right = NULL;};
        treeNode(const std::string &v, treeNode* l, treeNode* r, int h){data = v; left = l;  right = r; height = h;};
    };

    treeNode* root;
    void push(const std::string & n, treeNode * & v);
    bool search( const std::string& s, treeNode * & tree) ;
public:
    MyDS();
    ~MyDS();
    void push(const std::string & n);
    void printPreOrder() const;
    void preOrder(treeNode* pre) const;
    void clear(treeNode* & tree);
    void singleRightRotate(treeNode * & n);
    void doubleRightRotate(treeNode * & n);
    void singleLeftRotate(treeNode * & n);
    void doubleLeftRotate(treeNode * & n);
    bool search(const std::string & s);
    int avlHeight (treeNode * h);
    int max(int v1, int v2);
};
MyDS::MyDS()
{
    root = NULL;

}

MyDS::~MyDS()
{
    clear(root);
}

void MyDS::push(const std::string & n)
{
    push(n,root);
}

void MyDS::singleRightRotate(treeNode * & n)
{
    treeNode * temp;
    temp = n->right;
    n->right = temp->left;
    temp->left = n;
     n->height = max(avlHeight(n->left),avlHeight(n->right)) + 1;
    n = temp;
   
    temp->height = max(n->height,avlHeight(temp->right)) + 1;


}

void MyDS::singleLeftRotate(treeNode * & n)
{
    treeNode * temp;
    temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n->height = max(avlHeight(n->left),avlHeight(n->right)) + 1;
    n = temp;
  
    temp->height = max(avlHeight(temp->left),n->height) + 1;
}

void MyDS::doubleRightRotate(treeNode * & n)
{
    singleLeftRotate(n->right);
    singleRightRotate(n);
}

void MyDS::doubleLeftRotate(treeNode * & n)
{
    singleRightRotate(n->left);
    singleLeftRotate(n);
}

int MyDS::max(int v1, int v2)
{
    return ((v1 > v2) ? v1 : v2);
}

int MyDS::avlHeight(treeNode * h)
{
    int n;
    if( h == NULL)
    {
        return -1;
    }
    else
    {
        n = h->height;
        return n;
    }

}


bool MyDS::search(const std::string& s, treeNode *& tree)
{
    if(tree == NULL)
    {
        return false;
    }
    if(s < tree->data)
    {
        return search(s, tree->left);
    }
    if(tree->data < s)
    {
        return search(s, tree->right);
    }
    return true; // We found the value.
}

bool MyDS::search(const std::string &x)
{
    if (search(x, root)){
        return true;
    }
    else
        return false;
}

void MyDS::clear(treeNode* & tree)
{
    if(tree != NULL)
    {
        clear(tree->left);
        clear(tree->right);
        delete tree;

    }

    tree = NULL;
}

void MyDS::push(const std::string & n, treeNode* & v)
{
    if (v == NULL)
    {
        v = new treeNode(n , NULL, NULL, 0);
    }
    else
    {
        if ( n < v->data)
        {
            push(n, v->left);   // goes to left node

            if ((avlHeight(v->left) - avlHeight(v->right))==2)
            {
                if (n < v->left->data)
                {
                    singleLeftRotate(v);
                }
                else
                {
                    doubleLeftRotate(v);
                }
            }
        }
        else if ( v->data < n)
        {
            push(n, v->right);  // goes to right node
            if ((avlHeight(v->right) - avlHeight(v->left))==2)
            {
                if (n > v->right->data)
                {
                    singleRightRotate(v);
                }
                else
                {
                    doubleRightRotate(v);
                }
            }
        }
        else
        {
            ; // duplicate; do nothing.
        }
    }
    int a,b,c;
    a = avlHeight(v->left);
    b = avlHeight(v->right);
    c = max(a,b);
    v->height = c + 1;

}

void MyDS::printPreOrder() const
{
    preOrder(root);
}


void MyDS::preOrder(treeNode* pre) const
{
    if(pre != NULL)
    {
        std::cout << " " << pre->data << " ";
        preOrder(pre->left);
        preOrder(pre->right);
    }
}
#endif


int main()
{

    MyDS tree;


    string line;
    ifstream myfile ("names.txt");
    
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            tree.push(line.c_str());
        }
        myfile.close();
    }
    if (tree.search("Ali") == 1) 
        {
            std::cout << "found";
        }
    //tree.printPreOrder();
      using namespace std::chrono;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    
        tree.search("Ali");

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
    



            
    
    
}