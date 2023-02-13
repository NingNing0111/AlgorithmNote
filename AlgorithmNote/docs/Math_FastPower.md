# 快速幂运算

## 介绍

> 快速幂，二进制取幂（Binary Exponentiation，也称平方法），是一个在$O(log n)$的时间内计算$a^n$的小技巧，而暴力的计算需要$O(n)$的时间。而这个技巧也常常用在非计算的场景，因为它可以应用在任何具有结合律的运算中。其中显然的是它可以应用于模意义下取幂、矩阵幂等运算.

## 引入

首先，如何计算$7^{10}$？
>
> - 方法一：$7*7*7*...*7$，连乘9次，毫无疑问，这种算法的时间复杂度太慢了，尤其是对于CPU而言，每次乘的数都是个位数，无疑是太屈才了，因此，我们可以尝试对问题进行分解。
> - 方法二: 先算$7^5$,再算$({7^5})^2$,共进行了5次乘法运算
> - 方法三: 先算$7^2$,再算${7^2}*{7^2}*7$,共进行了四次乘法运算
> - 以此类推，即可得到时间复杂度为$O(log n)$的幂运算递归算法

> - $if ({n\%2} == 1)$, $a^n = a^{n-1} * a$
> - $if ({n\%2} == 0)$, $a^n = a^{n/2} * a^{n/2}$
> - $if (n==0)$,$a^n = 1$

## 实现

### 递归实现快速幂

```C++
//递归快速幂
int qpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a;
    else
    {
        int temp = qpow(a, n / 2);
        return temp * temp;
    }
}
```

> 在大多数实际问题中，题目常常会要求对一个大素数取模，因为幂运算的结果是十分巨大的，此时考察高精度算法又并不是十分重要，这时就需要我们的快速幂运算也进行取模操作。
>
> - 取模原则：步步取模，尽量开long long

### 递归实现快速幂(取余版)

```C++
//递归快速幂（对大素数取模）
#define MOD 1000000007
typedef long long ll;
ll qpow(ll a, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % MOD;
    else
    {
        ll temp = qpow(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}

```

上述描述的还只是快速幂的递归版，递归算法的效率一般都不高，且任意造成栈溢出。因此，下面给出快速幂的非递归版。

### 非递归实现的快速幂

```C++
// C++ Version
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
```

### 非递归实现的快速幂(取余版)

```C++
// C++ Version
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
```
