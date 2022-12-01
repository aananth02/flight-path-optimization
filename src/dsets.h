/* Your code here! */
#ifndef _DSETS_H_
#define _DSETS_H_

#include <vector>

class DisjointSets {
    public:
        void addelements(int num);
        int find(int elem);
        void setunion(int a, int b);
        int size(int elem);
        void print();
    // private:
        // What does this vector store? Every index is representative of a node value.
        
        // At each index, the vector stores an integer, which:
            // if the index value represents an internal node in an up-tree, the value stored at that index is the index of the parent

            // if the index value represents a root of an up-tree, the value stored at that index is a negative number 
            // whose absolute value denotes the number of nodes in the up-tree that the current node is a parent of
        
        std::vector<int> set_rep;
};

#endif