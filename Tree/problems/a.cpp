#include "../buildTree.hpp"
#include "diameter.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    Tree tree;
    Node* root = tree.buildTree(NULL);

    Diameter d;
    cout << "Diameter of the tree (Brute Force): " << d.diameterBruteForce(root) << endl;

    return 0;
}