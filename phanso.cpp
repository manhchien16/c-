/*1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là phân số (tối đa 10 phần tử). Sắp xếp lại danh sách đã nhập theo trật tự giảm dần.
*/
#include "bits/stdc++.h"

using namespace std;

class PS1 {
    protected:
    int tu;
    int mau;
    public:
        PS1(){
        tu = 0;
        mau = 1;
    }
    PS1(int tu, int mau) : tu(tu) , mau(mau) {};
    
    void nhap(PS1 &p){
        cout << "nhap vao tu so : "; cin >> p.tu;

    do{
        cout << "nhap vao mau so : "; cin >> p.mau;
    }while(p.mau == 0);
    }

    int UCLN(int a, int b){
        if(b == 0)
        return a;
            return UCLN(b, a % b);
    }

    void toigian(){
        int uc = UCLN(tu , mau);

        tu = tu / uc;
        mau = mau /uc;
    }

    void xuat(PS1 &p){

        cout << p.tu << "/" << p.mau;

    }
};

class PS2 : public PS1 {
    public:
    PS2(){};
    PS2(int tu, int mau) : PS1(tu,mau) {};


    void operator = (PS2 ps){
        this -> tu = ps.tu;
        this -> mau = ps.mau;
    }

    bool operator < (PS2 ps){
        if ((tu * 1.0) / mau < (ps.tu * 1.0) / ps.mau) 
        return true;
            return false;
    }

    PS2 operator + (PS2 ps){
        PS2 sum;

        sum.tu = tu*ps.mau + ps.tu+mau;
        sum.mau = mau *ps.mau;


        return sum;
    }

    void sumps(PS2 *ps, int n){
        PS2 sum(1,1);
        PS2 tg(1,2);
        for(int i = 0; i < n; i++){
            if(ps[i] < tg){
                if(sum.mau == 1 && sum.tu == 1){
                    sum = ps[i];
                }else{
                    sum = sum + ps[i];
                }
            }
        }
        sum.xuat(sum);
    }
};

int main(){
    PS2 *ps, sum;
    int n;

    cout << "nhap vao so phan so : "; cin >> n;

    ps = new PS2[n];

    for(int i = 0; i < n; i++){
        ps[i].nhap(ps[i]);
    }

    for(int i = 0; i < n; i++){
        ps[i].xuat(ps[i]);
        cout <<"\t";
    }
    
    ps -> sumps(ps,n);

}