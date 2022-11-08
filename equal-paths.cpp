#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int equalPathsHelper(Node* root, int path){
    int leftLeaf = 0;
    int rightLeaf = 0;
    if(root->left == NULL){
        if(root->right ==NULL){
            return path;
        }
        else{
            rightLeaf = equalPathsHelper(root->right, path+1);
            return rightLeaf;
        }
    }
    else if(root->right ==NULL){
        leftLeaf = equalPathsHelper(root->left, path+1);
        return leftLeaf;
    }
    else{
        rightLeaf = equalPathsHelper(root->right, path+1);
        leftLeaf = equalPathsHelper(root->left, path +1);
    }
    if(rightLeaf == leftLeaf){
        return rightLeaf;
    }
    else{
        return -1;
    }
}

bool equalPaths(Node * root)
{
    if(root ==NULL){
        return true;
    }
    // Add your code below
    if(equalPathsHelper(root, 0)==-1){
        return false;
    }
    return true;
}

