/*1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là phân số (tối đa 10 phần tử).
Sắp xếp lại danh sách đã nhập theo trật tự giảm dần.
*/
#include "bits/stdc++.h"

using namespace std;

class PS1{
    protected:
    int tu;
    int mau;
    public:
    PS1(){};
    PS1(int tu, int mau) : tu(tu) , mau(mau) {};

    void nhap(){
        cout << "nhap vao tu so : "; cin >> tu;
        do{
            cout << "nhap vao mau so : "; cin >> mau;
        }while(mau == 0);
    }
    void xuat(){
        cout << tu << "/" << mau << "\t";
    }

    int UCLN(int a, int b){
        if(b == 0)
        return a;
            return UCLN(b , a % b);
    }
    void toigian(){
        int uc = UCLN(tu,mau);
        tu = tu /uc;
        mau = mau/ uc;
    }
};


class PS2 : public PS1{
    public:
    PS2(){};
    PS2(int tu, int mau) : PS1(tu,mau) {};
    
    bool operator < (PS2 &p){
        if((tu*1.0)/mau < (p.tu*1.0)/p.mau)
        return true;
            return false;
    }

    void operator = (PS2 p){
        this -> tu = p.tu;
        this -> mau = p.mau;
    }

    PS2 operator + (PS2 p){
        
        tu = tu * p.mau + p.tu * mau;
        mau = mau * p.mau;

        return PS2(tu,mau);
    }

    void sapxep(PS2 *ps, int n){
        PS2 tg;
        for(int i = 0; i < n ; i++){
            for(int j = i + 1; j < n; j++){
                if (ps[j] < ps[i]){
                    tg = ps[j];
                    ps[j] = ps[i]; 
                    ps[i] = tg;
                }
            }
            ps[i].xuat();
        }
        
    }
    void sum1(PS2 *ps, int n){
        PS2 tg(1,2);
        PS2 sum(0,1);
        for(int i = 0; i < n; i++){
            if(ps[i] < tg){
                sum = ps[i] + sum ;
                
            }
            
        }
        sum.toigian();
        sum.xuat();
    }


};

int main(){
    PS2 *ps;
    int n;
    cout << "nhap vao n : "; cin >> n;
    ps = new PS2[n];

    for(int i = 0; i < n; i++){
        ps[i].nhap();
    }
    for(int i = 0; i < n; i++){
        ps[i].xuat();
    }

    cout << endl;
    ps->sapxep(ps,n);
    ps->sum1(ps,n);
;
}