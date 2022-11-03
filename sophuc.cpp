/*Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (nhỏ hơn), == (so sánh bằng)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử).
 Tìm số phức có giá trị lớn nhất và đếm xem có bao nhiêu số phức trong danh sách có giá trị bằng 3+4i.
*/

#include "bits/stdc++.h"

using namespace std;

class sophuc{
    protected:
    float thuc;
    float ao;

    public:
    sophuc(){};
    sophuc(float thuc, float ao): thuc(thuc), ao(ao){};

    void nhap(){
        cout << "nhap vao phan thuc : "; cin >> thuc;
        cout << "nhap vao phan ao : "; cin >> ao;
    }

    void xuat(){
        cout << thuc << "+" << ao << "*i" << endl;
    }

    float modun(){
        return sqrt(ao*ao + thuc*thuc);
    }
};

class sophuc2 : public sophuc{
    private:
        float md;
    public: 
    sophuc2(){
        md = sophuc::modun();
    }
    sophuc2(float thuc, float ao) : sophuc(thuc,ao){};

    void operator = (const sophuc2 &d){
        this -> thuc = d.thuc;
        this -> ao = d.ao;
    }

    bool operator == (const sophuc2 &d){
        if(thuc == d.thuc && ao == d.ao)
            return true;
                return false;
    }
    
    bool operator < (const sophuc2 &d){
        return md < d.md;
    }

    sophuc2 operator + (const sophuc2 &d){
        
        thuc = thuc + d.thuc;
        ao = ao + d.ao;

        return sophuc2(thuc,ao);
    }

    void max(sophuc2 *sp, int n){
        sophuc2 max = sp[0];
        for(int i = 0; i < n; i++){
            if (max.modun() < sp[i].modun()){
                max = sp[i];
            }
        }
        max.xuat();
    }

    void demsp(sophuc2 *sp,int n){
        int dem = 0;
        sophuc2 tg(3,4);
        for(int i = 0; i < n; i++){
            if (sp[i] == tg){
                dem ++;
            }
        } 
        cout << dem; 
    }
    sophuc2 tong(sophuc2 *sp, int n){
        sophuc2 sum(0,0);
        for(int i = 0; i < n; i++){
            sum = sp[i] + sum;
        }
        return sum;
    }
};

int main(){
    sophuc2 *sp, kq;
    int n;
    cout << "nhap vao n : "; cin >> n;

    sp = new sophuc2[n];

    for(int i = 0; i < n; i++){
        sp[i].nhap();
    }
        for(int i = 0; i < n; i++){
        sp[i].xuat();
    }
    cout << "tong so phuc : ";
    kq = sp -> tong(sp,n);
    kq.xuat();
    cout << endl << "max la :";
    sp ->max(sp,n);
    cout << "dem : ";
    sp -> demsp(sp,n);
}