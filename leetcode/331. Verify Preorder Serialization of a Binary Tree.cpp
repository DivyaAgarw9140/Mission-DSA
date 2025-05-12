class Solution {
public:
    bool isValidSerialization(string preorder) {
    stringstream ss(preorder);
    string node;
    int diff = 1; // Start with 1 to account for the root

    while (getline(ss, node, ',')) {
        if (--diff < 0) return false; // More nodes than available slots
        if (node != "#") diff += 2; // Non-null node adds 2 slots (left and right children)
    }
    
    return diff == 0; // At the end, there should be no extra slots

    }
};
