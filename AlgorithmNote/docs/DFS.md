# 深度优先(遍历)搜索(dfs)
>
> **一条路走到底，不撞南墙不回头** 是对$dfs$的最直观描述。

说明：

- dfs **只要前面有可以走的路** ，就会一直向前走，直到无路可走才会回头。
- **无路可走** 有两种情况： **遇到了墙** 和 **遇到了已经走过的路了**。
- 有一些路径没有走到，是因为已经找到了出口，程序停止了。
- 搜索是把所有可能的情况都看一遍，搜索的结果就两种：**找到目标** 或 **没找到**。

> **遍历** 和**搜索**可以看成两个等价的概念，通过遍历所有的可能情况达到搜索的目的。遍历是手段，搜索是目的。因此**深度优先遍历**也叫**深度优先搜索**。

## 1.树的深度优先遍历

以二叉树为例，深度优先遍历是从**根结点**开始，依次**递归**遍历**左子树**的所有结点和**右子树**的所有结点。当然，先遍历右子树再遍历左子树同样也是深度优先遍历，只是为了符合人们**从左往右**的习惯。
![](./imags/dfs_1.png)

**二叉树深度遍历的递归终止条件**：遍历完**所有的叶子结点**,依据二叉树的定义，等价于遍历到**空结点**。

依据二叉树深度遍历的顺序，可以分为：**前序遍历**、**中序遍历**和**后序遍历**

> 后序遍历是非常重要的遍历方式，解决很多树的问题都采用了后序遍历的思想。后序遍历是一种**一层一层向上传递信息的遍历方式**。也就是：**先必需得到左右子树的结果，才能得到当前子树的结果**。

对于这三种遍历形式，具有如下几个性质：

- 二叉树的**前序遍历**序列，跟结点一定是**最先**访问到的结点；
- 二叉树的**后序遍历**序列，跟结点一定是**最后**访问到的结点；
- **根节点**把二叉树的**中序遍历**划分成两个部分，第一部分的所有结点构成了根节点的**左子树**，第二部分的所有结点构成了根节点的**右子树**。

## 2. 图的深度优先遍历
>
> 深度优先遍历有**回头**的过程，在树中由于不存在**环**，对于每一个结点来说，每一个结点只会被递归处理一次。而**图**中由于存在**环**，就需要**记录已经被递归处理的结点(通常使用布尔数组或哈希表)**，以免结点被重复遍历。
> *深度优先遍历的结果通常与图的顶点如何存储有关，所以图的深度优先遍历的结果并不唯一。*

## 3. 例题
>
> 以下提供LeetCode上的几道关于树的例题来进一步理解深度优先遍历的后序**遍历思想**。

深度优先遍历是一种递归算法，**如何设计递归算法**对整个深度优先遍历的结构是十分重要的。

递归算法涉及三个要素：

1. **确定递归函数的参数和返回值：**
确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数，并且还要明确每次递归的返回值是什么，进而确定递归函数的返回类型。一般的，**如果需要遍历整棵树，递归函数就不能有返回值。如果需要遍历某一条固定路线，递归函数就一定要有返回值。**
2. **确定终止条件：**
写完了递归算法，运行的时候，经常会遇到栈溢出的错误，这就是没写终止条件或者终止条件写得不对造成的。操作系统也是一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。

3. **确定单层递归的逻辑：**
确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。

**每一个递归算法都需要围绕这三个要素进行实现。**

### 例题一

 例一：给定一个二叉树，找出其最大深度。二叉树的深度为根结点到最远叶子结点的最长路径上的节点数。叶子节点是指没有子节点的节点

示例：
*给定二叉树 [3,9,20,null,null,15,7]*

```
    3
   / \
  9  20
    /  \
   15   7
```

*输出：3*

> 1. **确定递归函数的参数和返回值：**

求树的最大深度，参数自然而然首先想到的是需要传入树的根节点。而返回值，自然就是该树的深度，为int类型。

```C++
int getDepth(TreeNode* node)
```

> 2. **确定终止条件：**

当结点为空结点时，返回0，表示长度为0；

```C++
if(!node) return 0;
```

> 3. **确定单层递归的逻辑：**

每层递归，都需要先求它的左子树的深度，再求它的右子树的深度，最后返回左右深度最大的值 + 1(当前结点),就为当前节点为根结点的树的深度。

```C++
int left = getDepth(node->left);
int right = getDepth(node->right);
return 1 + max(left,right);
```

完整代码

```C++
int maxDepth(TreeNode* root){
    if(!root){
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left,right) + 1
}
```

### 例题二

例二：给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量

*给定二叉树 [3,9,20,null,null,15,7]*

```
    3
   / \
  9  20
    /  \
   15   7
```

*输出：2*

求树的最小深度与求树的最大深度是有很大的区别的。大部分人在理解最大深度的求法后，都会不仔细考虑从而写出如下代码：

```C++
int minDepth(TreeNode* root){
    if(!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return min(left,right) + 1;
}
```

该算法在求解下面这棵树时会给出错误答案

```
    3
     \
     20
    /  \
   15   7
```

*程序输出：1*
**实际答案：3**

设计：
>
> 1. **确定递归函数的参数和返回值**

参数需要传入树的根节点，返回值为树的最小深度，int类型

```C++
int minDepth(TreeNode* root)
```
>
> 2. **确定终止条件**

终止条件也是当根节点为空时，返回深度0

```C++
if(!root){
    return 0;
}
```

> 3. **确定单层递归逻辑**

此处若写为刚刚展示的错误代码，则会对没有左孩子的分支算为最短深度。但实际上，**如果左子树为空，右子树不为空，则最小深度应该为 1 + 右子树的最小深度。** 同理，**若右子树为空，左子树不为空，则最小深度应该为 1 + 左子树最小深度**。**当左右子树都不为空时，返回左右子树深度最小值 + 1。**

```C++
int left = minDepth(root->left);
int right = minDepth(root->right);

// 当左树为空，右树不为空，则返回右树最小深度 + 1
if(!root->left && root->right){
    return right + 1;
}

// 当右树为空，左树不为空，则返回左树最小深度 + 1
if(!root->right && root->left){
    return left + 1;
}

// 当左右两树都不为空时，返回两边的最小深度 + 1
return min(left,right) + 1;
```

完整代码

```C++
int minDepth(TreeNode* root){
    if(!root){
        return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(!root->left && root->right){
        return right + 1;
    }
    if(!root->right && root->left){
        return left + 1;
    }

    return min(left,right) + 1; 
}
```

### 例题三

例三: 给定二叉树的根结点root和一个表示目标和的整数targetSum。判断该树中是否存在根节点到叶子结点的路径，这条路径上所有节点值之和等于目标值targetSum。如果存在，返回true，否则返回false

示例：
*输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1],targetSum = 22*

```C++
        5
       / \
      4   8
     /   / \
    11  13  4
   / \       \
  7   2       1 
```

*输出：true, 路径为：[5,4,11,2]*

> 1. **确定递归函数的参数和返回值**

需要二叉树的根结点，同时还需要一个计数器，这个计数器用于计算二叉树的一条边之和是否是目标值，计数器的类型为int类型。本题中，需要找到一条符合题意的路径，因此需要有返回值，该返回值就用来表示路径是否满足题意即可，即bool类型。

```C++
bool traversal(TreeNode* root,int count)
```

> 2. **确定终止条件**

终止条件毋庸置疑，就是搜索到了叶子结点，判断此时计数器的值是否等于目标值即可。但我们其实可以不用累加，然后进行判断是否等于目标值，我们可以使用递减操作。让计数器初始为目标值，每遍历一个结点，我们减去即可。当遍历到了叶子结点，同时计数器的值为0时，就说明找到了一条满足题意的路径。

```C++
if(!root->left && !root->right && !count) return true;
if(!root->left && !root->right) return false;
```

> 3. **确定单层递归的逻辑**

因为递归条件是判断叶子结点，所以递归过程中就不用让空节点进入递归中。如果递归函数返回了true，则说明找到了合适路径，应该立即返回。

```C++
// 如果左树不为空
if(root->left){
    if(traversal(root->left),count - root->left->val) return true;
}
// 如果右树不为空
if(root->right){
    if(traversal(root->right),count - root->right->val) return true;
}
return false;
```

完整代码

```C++
bool traversal(TreeNode* root, int count){
    if(!root) return false;
    if(!root->left && !root->right && !count) return true;
    if(!root->left && !root->right) return false;
    if(root->left){
        if(traversal(root->left,count - root->left->val)) return true;
    }
    if(root->right){
        if(traversal(root->right,count - root->right->val)) return true;
    }
    return false;
}

bool hasPathSum(TreeNode* root,int targetSum){
    if(!root) return false;
    return traversal(root,targetSum - root->val);
}
```

代码进行简化后

```C++
bool hasPathSum(TreeNode* root,int targetSum){
    if(!root){
        return false;
    }
    if(!root->left && !root->right && root->val == targetSum) return true;

    return hasPathSum(root->left,targetSum - root->val) || hasPathSum(root->right,targetSum - root->val);
}
```

### 例题四

例四：给定一课二叉树的根节点root,翻转这颗二叉树，并返回其根结点

示例：

```
     4              4        
   /   \          /   \
  2     7   ===> 7     2
 / \   / \      / \   / \
1   3 6   9    9   6 3   1
```

> 可以发现的是，想要翻转一课二叉树，只需要将其左右子树交换即可。但选择哪种遍历顺序可以更好得实现呢？前序和后序都可以完成翻转操作，唯独中序不行，中序遍历会翻转两次。

**以下使用先序遍历方式**

> 1. **确定递归函数的参数和返回值**

主要参数就是树的根节点(在确定递归参数过程中，将主要参数确定下来后，可以在后序的递归逻辑中需要哪些参数再加上即可)。返回值也可以不需要，但题目要求返回根结点，因此，可以让返回值的类型为TreeNode*。

```C++
TreeNode* invertTree(TreeNode* root)
```

> 2. **确定递归函数的终止条件**

当前结点为空时，返回root

```C++
if(!root) return root
```

> 3. **确定单层递归的逻辑**

因为是先序遍历，因此在递归前，先对当前结点的左右子树进行交换，然后翻转左子树和右子树。

```C++
swap(root->left,root->right);
invertTree(root->left);
invertTree(root->right);
return root;
```

完整代码

```C++
TreeNode* invertTree(TreeNode* root){
    if(!root) return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
```

### 例题五

 例五：给定两个整数数组inorder和postorder,其中inorder是二叉树的中序遍历，postorder是同一棵树的后序遍历。依据中序遍历和后序遍历的序列，构造出二叉树并返回根结点

示例
输入：
*inorder=[9,3,15,20,7]*
*postorder=[9,15,7,20,3]*
输出：

```C++
    3
   / \
  9  20
    /  \
   15   7
```

> 我们可以依据二叉树的前序遍历与中序遍历序列 和 中序遍历与后序遍历序列 来还原一棵二叉树。对于后者，我们要以后序遍历的序列的最后一个元素作为切割点，将中序遍历的序列进行划分。一层一层划分下去，每一次划分，后序序列的最后一个元素就是节点元素。既然是一层一层的进行划分，自然而然的就是递归了。

- 第一步：如果数组大小为零的话，说明是空结点了。
- 第二步：如果数组不为空，取后序数组的最后一个元素作为节点元素。
- 第三步：找到后序数组最后一个元素在中序数组的位置，以此作为分割点。
- 第四步：切割中序数组，切成中序左数组和中序右数组。
- 第五步：切割后序数组，切成后序左数组和后序右数组。(两个数组的切割顺序不能颠倒，一定是先中序，再后序)
- 第六步：递归处理左区间和右区间。

依据每一步操作，我们就可以大致写出算法的框架

```C++
TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
    // 第一步：如果后序遍历的数组大小为0，则是空节点
    if(postorder.size() == 0){
        return null;
    }

    // 第二步：后序数组的最后一个元素就是当前结点元素
    int rootVal = postorder[postorder.size()-1];
    TreeNode* root = new TreeNode(rootVal);

    // 如果后序数组的大小为1，则为叶子结点，不需要继续进行划分了
    if(postorder.size() == 1) return root;

    // 第三步： 找切割点
    int delIndex;
    for(delIndex = 0;delIndex < inorder.size();delIndex++){
        if(inorder[delIndex] == rootVal) break;
    }

    // 第四步：切割中序数组，得到中序左数组和中序右数组

    // 第五步：切割后序数组，得到后序左数组和后序右数组

    // 第六部：递归左右数组，得到左右子树
}
```

在整个算法的框架中，最主要的地方还是数组切割部分。
对于中序数组的切割，还是非常容易的，直接将[0,delIndex)作为左中序数组，[delIndex+1,end)作为右中序数组即可。代码如下：

```C++
// 左中序数组:[0,delIndex)
vecror<int> leftInorder(inorder.begin(),inorder.begin() + delIndex);
// 右中序数组:[delIndex+1,end)
vector<int> rightInorder(inorder.begin()+delIndex+1,inorder.end());
```

而对于后序数组，我们无法明确一个切割点对后序数组进行左右划分。但是，**中序数组大小一定与后序数组大小相同**。因此我们可以依据切割后的左右中序数组大小对后序数组进行切割(**这就是为什么要先切割中序数组，再切割后序数组的原因**)。代码如下：

```C++
// postorder 舍弃末尾元素
postorder.resize(postorder.size() - 1);

// 左闭右开：[0,leftInorder.size())
vector<int> leftPostorder(postorder.begin(),postorder.begin() + leftInorder.size());

// [leftInorder.size(),end)
vector<int> rightPostorder(postorder.begin() + leftInorder.size() + 1,postorder.end());
```

最后在分别对切割后的左右数组进行递归调用，得到左右子树.

```C++
root->left = traversal(leftInorder,leftPostorder);
root->right = traversal(rightInorder,rightPostorder);
```

完整代码如下：

```C++
TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
    // 第一步：如果后序遍历的数组大小为0，则是空节点
    if(postorder.size() == 0){
        return NULL;
    }

    // 第二步：后序数组的最后一个元素就是当前结点元素
    int rootVal = postorder[postorder.size()-1];
    TreeNode* root = new TreeNode(rootVal);

    // 如果后序数组的大小为1，则为叶子结点，不需要继续进行划分了
    if(postorder.size() == 1) return root;

    // 第三步： 找切割点
    int delIndex;
    for(delIndex = 0;delIndex < inorder.size();delIndex++){
        if(inorder[delIndex] == rootVal) break;
    }

    // 第四步：切割中序数组，得到中序左数组和中序右数组
    
    // 左中序数:[0,delIndex)
    vector<int> leftInorder(inorder.begin(),inorder.begin() + delIndex);
    // 右中序数组:[delIndex+1,end)
    vector<int> rightInorder(inorder.begin()+delIndex+1,inorder.end());
    
    // 第五步：切割后序数组，得到后序左数组和后序右数组

    // postorder 舍弃末尾元素
    postorder.resize(postorder.size() - 1);

    // 左闭右开：[0,leftInorder.size())
    vector<int> leftPostorder(postorder.begin(),postorder.begin() + leftInorder.size());

    // [leftInorder.size(),end)
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(),postorder.end());

    // 第六部：递归左右数组，得到左右子树
    root->left = traversal(leftInorder,leftPostorder);
    root->right = traversal(rightInorder,rightPostorder);
    return root;
}
```

## 深度优先搜索的应用

### 1. 计算无向图中连通分量的个数

给定一个包含n个节点的图。给定整数n和一个数组edges。其中edges[i] = [$a_i$,$b_i$]表示图中$a_i$和$b_i$之间有一条边。返回图中连通分量的个数。本题可以用**并查集**来做。
> 无向图G的极大连通子图称为G的连通分量。任何连通图的连通分量只有一个，即是其自身，非连通的无向图有多个连通分量。

例如：下图的连通分量为2

```
    1    6
   / \   |
  2 - 3  4 - 5
```

若使用并查集计算无向图中连通分量的个数，则只需要将相连接的顶点合并到一个集合中去，再求整个连通分量的个数即可。直接上代码！

```C++
class Solution {
public:
    int par[2003];
    // 初始化
    void init(int n){
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    // 查找
    int find(int index){
        if(index == par[index]){
            return index;
        }
        par[index] = find(par[index]);
        return par[index];
    }
    // 合并
    void unionn(int index1,int index2){
        if(par[index1] == par[index2]){
            return;
        }
        int index1_par = find(index1);
        int index2_par = find(index2);
        par[index2_par] = index1_par;
    }
    // 连通分量
    int cnt(int n){
        int ans = 0;
        for(int i=0;i<n;i++){
            if(par[i] == i){
                ans++;
            }
        }
        return ans;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        init(n);
        for(auto edge:edges){
            unionn(edge[0], edge[1]);
        }
        return cnt(n);
    }
};
```

考虑使用深度优先搜索(遍历)来求解图的连通分量。

- 首先我们需要遍历每一个顶点，对每一个顶点执行一次dfs，为防止重复遍历，我们需要将遍历过的结点记录下来。
- 每一次dfs，都代表着一个连通分量(每个顶点彼此连通，因此一次深度优先搜索，必定能遍历完一个连通图的所有顶点)。

> 1. **确定dfs的参数和返回值类型**

因为需要遍历整个图的所有路径，因此可以不需要返回值。参数自然是需要当前顶点，因为每次dfs，都是从一个顶点开始进行的。

```C++
void dfs(int u)
```

> 2. **确定dfs的边界条件**

对于一个连通图，搜索到何种地步意味着不需要继续搜索了？自然是搜索到了已经搜索过的结点，此时就不需要继续执行。而如何表示某个结点已经搜索过了？此处就是$vis$数组的作用。$vis[u] == 1$ 表示结点u已经搜索过了。

```C++
if(vis[u]) return;
```

> 3. **单层递归的逻辑**

每层递归，重复执行的部分就是从当前结点开始，向与其相邻的结点执行深度优先搜索。当然，在对相邻结点进行dfs前，需要将当前结点的状态设置为已搜索过，然后再对其它结点进行dfs。

```C++
vis[u] = 1;
for(auto e:grad[u]){
    dfs(e);
}
```

完整代码:

```C++
class Solution {
public:
    // 图结构
    vector<vector<int>> grad;
    // 状态
    vector<int> vis;

    // 深搜
    void dfs(int u){
        if(vis[u])return;
        vis[u] = 1;
        for(auto e:grad[u]){
            dfs(e);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        grad.resize(n);
        vis.resize(n);

        int len = edges.size();
        for(int i=0;i<len;i++){
            // 因为是无向图，因此A->B,B->A都需要进行赋值
            grad[edges[i][0]].push_back(edges[i][1]);
            grad[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};
```

### 2. 图中是否存在环的判断

图中是否有环的判断方法有多种，依据有向图和无向图，可以划分为：

1. 无图图
**数学方法:** 若图的顶点数为$n$，边数为$m$，如果$n >= m+1$,则无环，否则有环。
**并查集:** 对于边$u-v$,若$u,v$的$parent$相同，则存在环，否则将两个顶点合并。
**dfs:** 在dfs过程中，我们每经过一个节点，就将该节点的访问状态标记为$true$。当在dfs过程中，**发现当前结点指向一个已经访问过的结点**，则存在环。
**拓扑排序:** 先求出图中所有结点的度，将所有度小于等于1的结点入队(独立结点的度为0)。当队列不为空时，弹出队首元素，把与队首元素相邻结点的度减1.如果相邻结点的度变为了1，则将相邻结点入队。当队列为空时，跳出循环，判断已经访问过的结点数是否等于n。若等于n说明全部结点都被访问过了，无环；反之，有环。

2. 有向图
    **并查集:** 对于边$u->v$,若$u$的父节点是$v$,则存在环，否则将两个结点合并($u$的父节点赋值为$v$)。

    ```
    1 <- 4       1 -> 4
    ↓    ↑       ↓    ↑
    2 -> 3       2 -> 3
    (有环)        (无环)
    ```

    **dfs:** 因为有向图的深度优先遍历是多源的(即可以从多个结点开始遍历)，因此，单个结点在遍历过程中具有3个状态：**未遍历、遍历中、已遍历**。如下图，假如从结点1开始遍历，得到路径:$1 -> 2 -> 3$。遍历前，所有结点都处于**未遍历**的状态(结点1,2,3)，遍历中，每遍历一个结点后，该结点就处于**遍历中**的状态(结点1,2)；该条路径遍历完后，该路径上的所有结点就都处于**已遍历**的状态(结点1,2,3)。因此，不难看出，若有向图中存在环，则在dfs过程中，必定有：**当前结点指向的下一个结点处于遍历中的状态**。若下一个结点处于已遍历的状态，对环的判断并不影响(例如从结点1执行完一次dfs后，还需要从结点4执行dfs，此时结点1,2,3都处于已遍历的状态，因此不会影响环的判断)。这种dfs也称为染色法，每种颜色代表一种状态。

    ```
    1 -> 2 <- 4
         ↓
         3
    ```

    **拓扑排序:** 每次取出入度为0的节点，并删除对应的边，如果最后还有节点，则存在环。

以下介绍有向图中是否存在环的DFS算法

> 1. **确定递归函数的参数和放回值**

因为需要遍历图中的所有路径，因此可以不需要返回值，用一个全局变量flag表示图中是否有环即可。参数传入当前结点。

```C++
void dfs(int u)
```

> 2. **确定递归终止条件**

递归终止条件是:已经发现图中有环或当前结点指向的下一个结点正处于遍历中的状态，此时返回。(当然，也可以变为：当前结点处于遍历中的状态，将flag赋为true，再返回也是可以的)。因为遍历下一个结点是单层递归逻辑要处理的部分，因此这一块可以和单层递归逻辑进行合并。

```C++
// 如果已经发现了环，直接返回
if(flag){
    return;
}
```
>
> 3. **单层递归逻辑的设计**

当前递归需要做的是：将当前结点设置为变量中的状态，然后向当前结点的相邻结点指向dfs，最后将当前结点设置为已遍历的状态。

```C++
// 设置为遍历中
vis[u] = 1;
// 满足条件的情况下，向当前结点的相邻结点执行dfs
for(auto e: grad[u]){
    // 下一个结点是未访问的状态
    if(!vis[e]){
        dfs(e);
    // 下一个结点如果处于遍历中的状态，则说明有环，直接将flag赋为true并返回；
    }else if(vis[e] == 1){
        flag = true;
        return;
    }
    // 若下一个结点处于已遍历的状态，我们就不需要再执行了
}
// 在将当前结点的相邻结点都执行完dfs后，将当前结点设置为已遍历的状态
vis[u] = 2;
```

完整代码

```C++
// grad是图的邻接表的存储形式,结点i的邻接结点为grad[i]
vector<vector<int>> grad;
bool flag = false;
void dfs(int u){
    if(flag){
        return;
    }

    vis[u] = 1;

    for(auto e:grad[u]){
        if(!vis[e]){
            dfs(e);
        }else if(vis[e] == 1){
            flag = true;
            return;
        }
    }
    vis[u] = 2;
}
```

### 3. 二分图检测
>
> 如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个一个来自集合A，另一个来自集合B，我们就将该图称为二分图.

```
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3},因此该图是二分图。
```

```
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。
```

此处提供两种检测方法：并查集和DFS

1. 并查集
依据二分图的定义可知，图中每个结点的所有邻接点都属于同一集合，且不与当前结点同属于一个集合。因此，我们可以使用并查集遍历图中的每一个结点，将当前结点的所有邻接点进行合并，并判断这些邻接点中是否存在一个邻接点与当前结点同属于一个集合。若存在，则该图不是二分图。直接上代码！

```C++
class Solution {
public:
    int par[106];
    // 初始化
    void init(int n){
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    // 查找
    int find(int index){
        if(index == par[index]){
            return index;
        }
        par[index] = find(par[index]);
        return par[index];
    }
    // 合并
    void unionn(int index1,int index2){
        if(par[index1] == par[index2]){
            return;
        }
        int index1_par = find(index1);
        int index2_par = find(index2);

        par[index2_par] = index1_par;
    }
    // 判断两顶点是否连接
    bool isConnect(int index1,int index2){
        return find(index1) == find(index2);
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        init(n);
        // 遍历每个结点
        for(int i=0;i<n;i++){
            // 遍历第i个结点的所有邻接点，adjs是结点i的邻接点
            for(auto adjs:graph[i]){
                // 若邻接点与当前结点同属于一个集合，则不是二分图
                if(isConnect(i, adjs)){
                    return false;
                }
                // 否则，将邻接点进行合并
                unionn(graph[i][0], adjs);
            }
        }
        // 遍历完后，每个结点的所有邻接点都可以独立称为一个集合，则该图就是二分图
        return true;
    }
};
```

> graph是图的邻接表的存储形式，结点i的所有邻接点为$graph[i]$

2. DFS
依据二分图的定义，图中任意两个结点$u,v$，若$u,v$两结点直接有边相连，则结点$u,v$必属于不同的两个集合。因此，我们可以采用染色法，初始结点染成红色，相邻结点染成绿色，相邻结点的相邻结点染成红色，以此类推，直到所有结点都染了色。如果在染色过程中，当前需要染色的结点已经被染了色并且该颜色与我们需要染成的颜色相冲突，则说明该图不是二分图。
流程如下：

- 任选一结点将其染为红色，并从该节点开始对整个无向图进行遍历。
- 在遍历过程中，如果我们当前结点为$u$，下一个结点为$v$,那么会有两种情况需要处理：
  - 如果$v$未被染色，则将$v$染为去$u$不同的颜色，并对$v$的邻接点进行遍历；
  - 如果$v$已染了色，如果$v$的颜色与$u$的颜色相同，则说明该图不是二分图，直接退出递归函数。
- 若一直执行到了遍历结束，则说明给定的图是二分图。

> 1. **确定递归函数的参数和返回值**

因为需要遍历图中的所有路径，可以不需要任何的返回值，用一个全局变量flag来存储结果即可。参数需要传入dfs的起始结点$u$和需要染的颜色.

```C++
void dfs(int u,int color)
```

> 2. **递归的边界条件**

递归终止的情况有两种：已经判断出该图是否是二分图 和 当前结点的邻接结点已被染成了与当前结点一致的颜色。后者可以放在单层递归逻辑部分。

```C++
if(!flag){
    return;
}
```

> 3. **单层递归逻辑设计**

进入递归后，当前结点染为color，然后对当前结点的邻接结点染成其它的颜色。
我们设定：-1为未染色，0为颜色1(红色)，1为颜色2(绿色)

```C++
colors[u] = color;
for(auto e:grad[u]){
    if(colors[e] == -1){
        dfs(e,!color);
    }else if(colors[e] == color){
        flag = false;
        return;
    }
}
```

完整代码

```C++
class Solution {
public:
    bool flag = true;
    vector<int> colors;
    vector<vector<int>> grap;

    void dfs(int u,int color){
        if(!flag) return;

        colors[u] = color;

        for(auto e:grap[u]){
            if(colors[e] == -1){
                dfs(e, !color);
            }else if(colors[e] == color){
                flag = false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.resize(n, -1);
        grap.assign(graph.begin(), graph.end());

        for(int i=0; i<n && flag;i++){
            if(colors[i] == -1){
                dfs(i, 0);
            }
        }
        return flag;
    }
};
```

### 4. 拓扑排序

拓扑排序的结果序列就是在环的检测算法中产生的。拓扑排序的结果是图的后序遍历序列翻转后结果。首先，如果一个有向图中存在环，则不能执行拓扑排序。因此，我们可以先判断图中是否有环，然后执行后序遍历得到遍历结果，而该结构的翻转后的序列就是拓扑排序后的结果序列。为了简化代码，我们可以一边判断是否有环，一边存储后序遍历的结果。(因为一旦出现了环，我们只需要返回一个空序列即可)。

> 1. **确定递归函数的参数和返回值**

因为拓扑排序是在检测算法中产生，因此可以直接调用环检测算法，而拓扑排序的结果序列，用一个全局变量接收即可。

```C++
void (int u)
```

> 2. **递归边界条件**

```C++
// 如果有环,终止递归函数
if(flag){
    return;
}
```

> 3. **单层递归逻辑**

只需在检测后，将当前结点放入结果集中即可(后序遍历)。

```C++
vis[u] = 1;

for(auto e: grad[u]){
    if(!vis[e]){
        dfs(e);
    }else if(vis[e] == 1){
        flag = true;
        return;
    }
}
vis[u] = 2;
ans.push_back(u);
```

在调用过程中，我们执行完该dfs后，判断是否存在环，若存在环，则返回一个空序列，否则，返回ans序列。
