/* Your code here! */

#include <algorithm>
#include "dsets.h"
#include <iostream>
#include <string>

void DisjointSets::addelements(int num) {
    for (int index = 0; index < num; index++) {
        set_rep.push_back(-1);
    }
}

int DisjointSets::find(int elem) {
    // What does "elem" denote? It is the node whose parent we want to find in our disjoint set of up-trees.
    // What represents nodes in our Disjoint Sets class? The indices in our set_rep vector.

    if (set_rep.at(elem) < 0) {
        return elem;
    }
    int up_node_as_index = find(set_rep.at(elem));
    set_rep.at(elem) = up_node_as_index;
    return up_node_as_index;
}

void DisjointSets::setunion(int a, int b) {

//     a = find(a);
//     b = find(b);

//     int newSize = set_rep[a] + set_rep[b];

//     if (set_rep[a] < set_rep[b]) {
//         set_rep[b] = a;
//         set_rep[a] = newSize;
//     } else {
//         set_rep[a] = b;
//         set_rep[b] = newSize;
//   }
    // We have two up-trees, we're finding their roots
    int a_root = find(a);
    // std::cout << "a root: " << a_root << std::endl;
    int b_root = find(b);

    // We're finding the size of the up-trees they're part of
    int a_size = size(a);
    int b_size = size(b);
    if (a_root == b_root) {
         return;
    }
    if (a_size <= b_size) {
        // auto x = size(a_root);
        // set_rep[a_root] = b_root;
        // set_rep[b_root] -= x;
        for (size_t index = 0; index < set_rep.size(); index++) {
            if (static_cast<int>(index) == a_root || set_rep.at(index) == a_root) {
                set_rep.at(index) = b_root;
                set_rep.at(b_root) -= 1;
            }
        }
    } else {
        // auto x = size(b_root);
        // set_rep[b_root] = a_root;
        // set_rep[a_root] -= x;
        for (size_t index = 0; index < set_rep.size(); index++) {
            if (static_cast<int>(index) == b_root || set_rep.at(index) == b_root) {
                set_rep.at(index) = a_root;
                set_rep.at(a_root) -= 1;

            }
        }
    }
}

int DisjointSets::size(int elem) {
    if (set_rep.at(elem) < 0) return set_rep[elem] * -1;
    //int root_of_elem_up_tree = find(elem);
    return size(find(elem));
}

void DisjointSets::print() {
    for (size_t ind = 0; ind < set_rep.size(); ind++) {
		std::cout << set_rep.at(ind) << ", ";
	}
    std::cout << "\n---------" << std::endl;
}