  void topView(Node * root) {
    int matrix[1000][1000] = {0};
    int r = 0;
    int c = 500;
    matrix[r][c] = root->data;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {r, c}});

    while (!q.empty()){
        Node* t = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (t->left!=NULL){
            int newX = x + 1; 
            int newY = y - 1;
            if (newX < 1000 && newY > 0){
                q.push({t->left, {newX, newY}});
                matrix[newX][newY] = t->left->data;
            }
        }
        if (t->right!=NULL){
            int newX = x + 1; 
            int newY = y + 1;
            if (newX < 1000 && newY < 1000){
                q.push({t->right, {newX, newY}});
                matrix[newX][newY] = t->right->data;
            }
        }
    }
    vector<int> list;
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            if (matrix[j][i]!= 0){
                list.push_back(matrix[j][i]);
                break;
            }
        }
    }
    for (auto const& x : list) cout << x << " ";
