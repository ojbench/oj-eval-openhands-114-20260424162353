
#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
    p = new int*[n]();
}
void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
    if (p[x - 1] == nullptr) {
        p[x - 1] = new int[3];
        p[x - 1][0] = 1; // capacity
        p[x - 1][1] = 1; // size
        p[x - 1][2] = y;
    } else {
        if (p[x - 1][1] == p[x - 1][0]) {
            int *old = p[x - 1];
            int new_cap = old[0] * 2;
            p[x - 1] = new int[new_cap + 2];
            p[x - 1][0] = new_cap;
            p[x - 1][1] = old[1];
            std::copy(old + 2, old + 2 + old[1], p[x - 1] + 2);
            delete[] old;
        }
        p[x - 1][p[x - 1][1] + 2] = y;
        p[x - 1][1]++;
    }
}
int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
    return p[x - 1][k + 1];
}
void Clear(int **&p,int n){//回收空间
    for (int i = 0; i < n; ++i) {
        delete[] p[i];
    }
    delete[] p;
}
