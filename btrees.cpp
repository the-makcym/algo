//    auto tree = new TreeNode[5];
//    for (int i = 0; i < 5; ++i)
//        tree[i].val = i;
//    tree[0].left = &tree[1];
//    tree[0].right = &tree[2];
//    tree[2].left = &tree[3];
//    tree[2].right = &tree[4];

//    auto tree = new TreeNode[20];
//    for (int i = 0; i < 20; ++i)
//        tree[i].val = i;
//    tree[0].left = &tree[1];
//    tree[0].right = &tree[2];
//    tree[1].left = &tree[3];
//    tree[1].right = &tree[4];
//    tree[2].left = &tree[5];
//    tree[2].right = &tree[6];
//    tree[3].left = &tree[7];
//    tree[3].right = &tree[8];
//    tree[4].left = &tree[9];
//    tree[4].right = &tree[10];
//    tree[5].left = nullptr;
//    tree[5].right = &tree[11];
//    tree[6].left = nullptr;
//    tree[6].right = &tree[12];
//    tree[8].left = &tree[13];
//    tree[8].right = &tree[14];
//    tree[11].left = &tree[15];
//    tree[11].right = nullptr;
//    tree[12].left = &tree[16];
//    tree[12].right = &tree[17];
//    tree[16].left = &tree[18];
//    tree[16].right = &tree[19];

//    auto tree = new TreeNode[9];
//    for (int i = 0; i < 9; ++i) tree[i].val = i;
//    tree[4].left = &tree[1];
//    tree[4].right = &tree[6];
//    tree[1].left = &tree[0];
//    tree[1].right = &tree[2];
//    tree[2].right = &tree[3];
//    tree[6].left = &tree[5];
//    tree[6].right = &tree[7];
//    tree[7].right = &tree[8];

//    auto tree = new TreeNode[10];
//    for (int i = 0; i < 10; ++i) tree[i].val = i;
//    tree[0].right = &tree[8];
//    tree[1].right = &tree[2];
//    tree[3].left = &tree[1];
//    tree[3].right = &tree[6];
//    tree[4].right = &tree[5];
//    tree[6].left = &tree[4];
//    tree[7].left = &tree[3];
//    tree[8].left = &tree[7];
//    tree[8].right = &tree[9];

//    auto tree = new TreeNode[10];
//    for (int i = 0; i < 10; ++i) tree[i].val = i;
//    tree[0].right = &tree[8];
//    tree[1].right = &tree[2];
//    tree[3].left = &tree[1];
//    tree[3].right = &tree[6];
//    tree[4].right = &tree[5];
//    tree[6].left = &tree[4];
//    tree[7].left = &tree[3];
//    tree[8].left = &tree[7];
//    tree[8].right = &tree[9];