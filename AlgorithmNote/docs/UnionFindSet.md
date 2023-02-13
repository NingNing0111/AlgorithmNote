# 并查集

并查集是一种树形的数据结构，顾名思义，它用于处理一些不交集的$合并$及$查询$问题。它支持两种操作：

- 查找: 确定某个元素处于哪个子集或判断图中两个顶点是否在同一集合中；

> $注:$并查集只回答两个顶点之间是否有路径相连，而不回答该路径是如何连接的。

- 合并: 将两个子集合合并成一个集合。

## 设计思想

### 基于id(了解即可)

&nbsp;&nbsp;**基于id的思想是给每个元素(顶点)分配一个唯一标识，称为id。**

- 初始化的时候：所有元素的$id$都不一样，表示一个元素单独属于一个集合。
- 如果两个元素的$id$一样，标识它们同属于一个集合；
- 合并的时候，需要将其中一个集合中的所有元素的$id$赋值称为另一个集合的$id$(一个集合中的所有元素的id均一样)
&nbsp;&nbsp;**这种方法类似于给每个元素(顶点)改名字，名字一样，则表示同属于一个集合中.a**
- 优点：查询两个元素是否在一个集合中的效率很快，时间复杂度为$O(1)$.
- 缺点：把两个集合合并成一个集合较慢，需要遍历其中一个集合中的所有元素。

### 基于parent(需要掌握)

&nbsp;&nbsp;**基于parent的思想是：记录每一个顶点的父亲顶点是谁。这种设计思想也叫代表元法。**

- 我们使用$parent$数组进行设计。$parent$数组的定义是：$parent[i]$表示表示为$i$的结点的父亲结点的标识。在这个定义下，根节点的父亲结点就是自己。

## 代表元法(基于Parent)的设计思想

设计理念：

- 谁作为根结点不重要：根节点与非根节点只是位置不同，并没有附加的含义；
- 树是怎么形成的不重要：合并的时候任何一个集合的根结点指向另一个结点的根结点即可；
- 树的形态不重要：因为谁作为根结点不重要。
**任何一种树形结构对树的高度都会存在一种极端情况，即该结构是链表。**
并查集中解决这种极端情况的方案有两种：**按秩合并** 和 **路径压缩**.

1. 按秩合并的意思是：让树的秩较小的树的根结点，指向树的秩较大的树的根结点。这里的秩有两种含义：

- 按size合并，用于需要维护每个连通分量结点个数的时候；

> 按size合并的意思就是让树的结点总数较小的树的根结点指向树结点总数较大的根结点。

- 按rank合并，绝大多数时候。

> 按rank合并的意思是让树的高度较小的树的根结点指向树的高度较大的树的根结点。

2. 路径压缩的方式共有两种

- 隔代压缩：两步一条，一直循环执行 **把当前结点指向它的父结点的父节点** 的操作.

> 这种压缩方式并不彻底，需要进行多次压缩，才能达到压缩彻底的效果。

- 完全压缩：把从 **查询结点** 到 **根结点** 沿途经过的所有结点都指向根结点。完全压缩相较于隔代压缩更为彻底。

### 代码实现

1. **并查集初始化**

> $parent[i] = x$,表示元素i的父结点为$x$.在初始化时，我们将每个元素的父节点设为自身。

```C++
// parent数组
int parent[MAX];
void init(int n){
    for(int i=1;i<=n;i++){
        // 初始化时，每个元素的父节点为自身
        parent[i] = i;
    }
}
```

2. **查询操作**

> $find(x)$:查找$x$的祖先，并直接返回。
>
> - 查询操作也是一种判断某个元素是否是某个集合(这里的集合一定是以某个元素为祖先构建出来的)的操作。例如：$find(x1) == find(x2)$说明$x1,x2$同属于某一个集合，因为它们的祖先是一样的。
> - 查询操作也为后续的合并提供了操作。两个集合$A,B$进行合并是在满足合并条件下，将集合$B$的祖先指向集合$A$的祖先(简单说就是将集合$A$的祖先赋值给集合$B$)。

```C++
int find(int index){
    // 祖先元素：该元素的祖先一定为自身，因此若index == parent[index],则index就是祖先元素.这就是递归出口。
    if(index == parent[index]){
        return index;
    }
    // 如果当前元素不是祖先元素，则以当前元素的父结点作为查找参数，不断向上进行查找。
    return find(parent[index])
}
```

**注**:上述查询操作在极端情况下，是一种链式线性表的结构，时间复杂度为$O(n)$,因此需要进行路径压缩。我们采用完全压缩方法：**查询结点到根结点的沿途结点的父节点都指向根结点**。

```C++
int find(int index){
    if(index == parent[index]){
        return index;
    }else{
        // 当前结点的父节点指向根结点
        parent[index] = find(parent[index]);
        return parent[index];
    }
}
```

***注:*** **一边查询一边合并是并查集操作的一大特色.**
3. **合并操作**
> $unionn(i,j)$: 表示将元素$j$合并到元素$i$里(就是将$i$的祖先赋值给$j$的祖先).

```C++
void unionn(int index1,int index2){
    // 找到index1的祖先
    int index1_par = find(index1);
    // 找到index2的祖先
    int index2_par = find(index2);
    // 将index1的祖先赋值给index2
    parent[index2_par] = index1_par;
}
```

## 例题

### 例题一

现有N个人，分别编号为1,2,...,N。这N个人之间有M种关系(用a b表示编号为a的人与编号为b的人存在亲戚关系)。现给定上述信息后发起Q次关于编号X与Y之间是否存在亲戚关系的提问，存在输出YES，否则输出NO

```C++
#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e4+2;
int parent[MAX];

// 初始化
void init(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
}
// 查找
int fd(int index){
    if(index == parent[index]){
        return index;
    }
    parent[index] = fd(parent[index]);
    return parent[index];
}

// 合并
void unionn(int index1,int index2){
    // 获取index1的祖先
    int index1_par = fd(index1);
    // 获取index2的祖先
    int index2_par = fd(index2);
    // 将index2的祖先改为index1的祖先
    parent[index2_par] = index1_par;
}
int main()
{
    int n,m;
    cin >> n >> m;
    init(n);
    int index1,index2;
    while(m--){
        // 两者存在亲戚关系，则进行合并
        cin >> index1 >> index2;
        unionn(index1,index2);
    }
    cin >> n;
    while(n--){
        cin >> index1 >> index2;
        // 获取index1的祖先
        int par1 = fd(index1);
        // 获取index2的祖先
        int par2 = fd(index2);
        // 若两者祖先不同，则不存在亲戚关系，否则存在
        if(par1 == par2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

```

### 例题二

给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程$equations[i]$的长度为$4$,并采用两种不同的形式之一：$"a==b"$或$"a!=b"$。在这里,$a$和$b$是小写字母，表示单字母的变量名。只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回$true%，否则返回$false$

示例1：

```
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
```

示例2:

```
输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
```

>**分析**：我们可以将等式相等的字母放在一个集合里，然后再判断不等方程是否满足。

```C++
#include<bits/stdc++.h>

using namespace std;

// 并查集
int par[27];

// 并查集初始化
void init()
{
    for(int i=0;i<26;i++)
        par[i] = i;
}

// 并查集查找
int fd(int index){
    if(par[index] == index){
        return index;
    }
    par[index] = fd(par[index]);
    return par[index];
}

// 并查集合并
void unionn(int index1,int index2){
    if(par[index1] == par[index2]) return;

    // 找到index1的root
    int index1_par = fd(index1);
    // 找到index2的root
    int index2_par = fd(index2);
    // 将index2的祖先 赋值为index1的祖先
    par[index2_par] = index1_par;

}

string strs[105];

int main()
{
    int n;
    cin >> n;
    init();
    for(int i=0;i<n;i++)
        cin >> strs[i];

    // 先将相等的变量合并
    for(int i=0;i<n;i++){
        if(strs[i][1] == '='){
            unionn((int)(strs[i][0] - 'a'),(int)(strs[i][3]-'a'));
        }
    }

    // 判断不等方程是否成立
    for(int i=0;i<n;i++){
        if(strs[i][1] == '!'){
            int index1_par = fd(strs[i][0] - 'a');
            int index2_par = fd(strs[i][3] - 'a');
            // 如果等式不等，但两变量同属于一个集合里，则等式不成立
            if(index1_par == index2_par){
                cout << "false" << endl;
                return 0;
            }
        }
    }
    cout << "true" << endl;
    return 0;
}

```

### 例题三

有n个城市，其中一些彼此相连，另一些没有相连。如果城市$a$与城市$b$直接相连，且城市$b$与城市$c$直接相连，那么城市$a$与城市$c$间接相连。省份是一组直接或间接相连的城市，组内不含其它没有相连的城市。给定一个$n*n$的矩阵$isConnected$，其中$isConnected[i][j] = 1$表示第i个城市与第j个城市直接相连，而$isConnected[i][j] == 0$ 表示二者不直接相连.输出省份的数量

> **分析**：将相连的城市合并，然后再并查集中判断连通分量的个数即可。

示例1

```
3
1 1 0
1 1 0
0 0 1

输出: 2
```

```C++
#include<bits/stdc++.h>

using namespace std;

// 并查集
int par[105];

// 并查集初始化
void init(int n)
{
    for(int i=0;i<n;i++)
        par[i] = i;
}

// 并查集查找
int fd(int index){
    if(par[index] == index){
        return index;
    }
    par[index] = fd(par[index]);
    return par[index];
}

// 并查集合并
void unionn(int index1,int index2){
    if(par[index1] == par[index2]) return;

    // 找到index1的root
    int index1_par = fd(index1);
    // 找到index2的root
    int index2_par = fd(index2);
    // 将index2的祖先 赋值为index1的祖先
    par[index2_par] = index1_par;

}

// 计算连通分量的个数

int cnt(int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(par[i] == i){
            ans++;
        }
    }
    return ans;
}

int mp[105][105];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mp[i][j];
    init(n);
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(mp[i][j]){
                unionn(i,j);
            }
        }
    }
    cout << cnt(n) << endl;
    return 0;
}

```
