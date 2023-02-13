
# 广度优先(遍历)搜索(BFS)

**齐头并进，一层一层向外扩展**是对$dfs$的最直观描述。

说明：

- BFS可以用于**树**和**图**的问题遍历。
- BFS作用于**无权图**,得到的是**最短路径**。若题目让求**最小、最短、最少**,可以优先考虑该问题是否可以构建成一个**图形结构**或**树形结构**。利用BFS可以求得**最小、最短、最少**的数值。
- BFS作用于图论问题时，结点在加入队列以后标记为已访问状态，否则会出现结点重复入队的情况。

## 树的广度优先遍历

树的BFS写法相对固定：

- 使用队列;
- 当队列非空时，动态地取出队首元素;
- 取出队首元素后，将该元素的相邻非空结点放入队列中;

- - -
&emsp;&emsp;**给定一棵二叉树的根结点，返回其结点值的层序遍历结果。(即逐层遍历，从左到右访问所有结点)**

**示例**

```C++
  3
 / \
9  20
  /  \
 15   7
```

```C++
输出：[[3],[9,20],[15,7]]
```

```C++
vector<vector<int>> levelOrder(TreeNode* root){
    if(!root){
        return {};
    }
    // 队列
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    // 先将根节点放入队列中
    q.push(root);
    // 当队列不为空时，动态地取出队首元素
    while(!q.empty()){
        // 先获取当前队列的长度
        // 长度值就是当前层的结点个数，因为题目要分别求每层的遍历顺序，这步就不可缺少了
        int qLen = q.size();
        // 存放每层的遍历序列
        vector<int> t;
        while(qLen--){
            // 取出队首元素并出队
            TreeNode* node = q.front();
            q.pop();
            // 将该元素放入t中
            t.push_back(node->val);
            // 将该结点的相邻非空结点放入队列中
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        // 当前层遍历完后，放入结果集中
        ans.push_back(t);
    }
    return ans;
}
```

## BFS在图论中最短路径问题的应用

&emsp;&emsp;在**无权图**中，由于BFS本身的特点，假设源点为**source**,只有在遍历到所有距离源点的距离为**d**的所有结点以后，才能遍历到所有距离源点的距离为**d+1**的所有结点。也可以用**两点之间，线段最短**来理解如下结论：**从源点source到目标结点target走直线走过的路径一定是最短的。**
- - -
&emsp;&emsp;在图中,由于**图存在环**,和DFS一样，BFS也需要在遍历的过程中，不断对结点进行记录(标记)。当结点加入到队列中时，**一定要将该结点标记为已访问**,否则该结点会重复入队。
- - -
&emsp;&emsp;BFS能够用于求解**无权图**的最短路径，针对有权图的最短路径求解，需要使用专门的算法解决。

- 带权有向图、且所有权重都为非负的单源最短路径问题：Dijkstra算法
- 带权有向图的单源最短路径问题：Bellman-Ford算法
- 一个图的所有结点的最短路径问题：Floy-Warshall算法

- - -
&emsp;&emsp;**BFS求解无向图的连通分量个数。给定编号从0到n-1的$n$个结点和一个无向边列表$edges$(每条边都是一对结点)，据此编写一个函数计算该无向图中连通分量的个数。**
(1) **分析**：

- 对于无向图来说，边[0,1]与边[1,0]是等价的，因此这两条等价边是不可能出现在$edges$中。
- 对于给定的边数组，我们首先需要将其转换为图进行存储。使用嵌套数组$grid$来表示邻接表。结点$i$的相邻结点为$grid[i]$。
- 遍历所有结点，从每个未遍历的结点起，执行BFS。每执行一次BFS，连通分量的个数就+1.**在遍历过程中，必须使用$vis$数组来记录遍历过的结点**

```C++
vector<vector<int>>grid;
vector<bool>vis;
int countComponents(int n, vector<vector<int>>& edges) {
    vis = vector<bool>(n,false);
    grid = vector<vector<int>>(n);
    int len = edges.size();
    
    // 将边集合转换为图的邻接表存储 [0,1]与[1,0]是等价的，都需要存入
    for(auto edge:edges){
        grid[edge[0]].push_back(edge[1]);
        grid[edge[1]].push_back(edge[0]);
    }
    
    int ans = 0;
    
    // 遍历每个结点
    for(int i=0;i<n;i++){
        if(!vis[i]){
            BFS(i);
            ans++;
        }
    }
    return ans;
}
void BFS(int u){
    queue<int>q;
    q.push(u);
    vis[u] = true;
    while(!q.empty()){
        // 取出队首元素
        int sx = q.front();
        q.pop();
        // 将该结点的相邻结点放入到队列中
        for(auto tx:grid[sx]){
            if(!vis[tx]){
                q.push(tx);
                vis[tx] = true;
            }
        }
    }
}
```

## 拓扑排序

&emsp;&emsp;拓扑排序(Topological Sorting)是一种应用在**有向无环图**上，给出结点输出先后顺序的算法。**拓扑排序不是给出大小关系的排序，而是给出先后顺序的一种算法**。这些结点的输出顺序需要保证：

- 每一个结点输出且仅输出一次；
- 在有向无环图中，如果存在一条从$u$到$v$的路径，那么在拓扑排序的结果中，$u$必须保证在$v$的前面。

&emsp;&emsp;拓扑排序的一种典型应用就是**课程安排**和**任务安排**。

- - -

&emsp;&emsp;使用**拓扑排序的前提**是：**图是有向图且图中无环**。若图中有环，则存在**循环依赖**，此时无法确定先后顺序。

&emsp;&emsp;拓扑排序的实现方法有两种：**DFS**和**BFS**。其中**BFS是最经典的实现方式，必须掌握**。BFS在思想层面上更为简单，编码也相对容易，同时还有一个好处就是：我们只需要在图中应用一次BFS，在结束之后，就能够得到这个有向图中是否存在环，若不存在环，则输出拓扑排序的结果。也就是说BFS可以帮助我们检测图中是否存在环。而DFS须要在遍历的过程中检测有向图中是否存在环。

- - -
&emsp;&emsp;**例题**：给你一个整数 $n$ ，表示编号从 $1$ 到 $n$ 的 $n$ 门课程。另给你一个数组 $relations$ ，其中 $relations[i] = [prevCoursei, nextCoursei]$ ，表示课程 $prevCoursei$ 和课程 $nextCoursei$ 之间存在先修关系：课程 $prevCoursei$ 必须在 nextCoursei 之前修读完成。在一个学期内，你可以学习 **任意数量** 的课程，但前提是你已经在上一学期修读完待学习课程的所有先修课程。
&emsp;&emsp;请你返回学完全部课程所需的 **最少** 学期数。如果没有办法做到学完全部这些课程的话，就返回 **-1**。

&emsp;&emsp;BFS实现拓扑排序的思路：

- 如果图中存在一个入度为0的顶点，那么该顶点一定是其它顶点的前驱结点。也就是说，在拓扑排序中，**该顶点应该排在最前面**。将入度为0的结点入队。
- 将入度为0的结点删除后，与被删结点相邻的结点的入度减1。若相邻结点的入度为0,则将该相邻结点入队。

```C++
class Solution {
public:
    // 图的邻接表存储
    vector<vector<int>> grid;
    // 存储结点的入度
    vector<int> inDeep;
    // BFS用的队列
    queue<int> q;

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // 因为编号从1开始，因此空间须要n+1
        grid.resize(n+1);
        inDeep.resize(n+1);

        for(auto relation:relations){
            // u->v:v的入度加一
            inDeep[relation[1]]++;
            // 邻接表存储
            grid[relation[0]].push_back(relation[1]);
        }

        // 将入度为零的结点入队
        for(int i=1;i<=n;i++){
            if(inDeep[i] == 0){
                q.push(i);
            }
        }
        
        // 开始BFS
        int ans = 0;
        while(!q.empty()){
            ans++;
            // BFS的每层就代表一个学期，因此需要按层来遍历
            int size = q.size();
            for(int i=0;i<size;i++){
                int u = q.front();
                q.pop();
                // 遍历下一个结点，意味着去掉了当前结点与下一个结点的边，此时下一个结点的入度就要减1
                for(auto v:grid[u]){
                    inDeep[v]--;
                    // 如果入度为0，则将该节点入队即可
                    if(inDeep[v] == 0){
                        q.push(v);
                    }
                }
            }
        }

        // 在完成BFS后，若还存在入度非零的结点，则说明该图存在环
        for(int i=1;i<=n;i++){
            if(inDeep[i] > 0){
                return -1;
            }
        }
        return ans;
    }
};
```
