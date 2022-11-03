/*Câu 2: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp đa thức với các thuộc tính: bậc đa thức, các hệ số tương ứng.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng đa thức.
3.	Định nghĩa toán tử +, - hai đa thức. Thực hiện cộng, trừ hai đa thức và in kết quả ra màn hình.
*/

#include "bits/stdc++.h"

using namespace std;


class dathuc{
    private:
     int n;
     int *a;

    public:
    dathuc() : n(0) , a(NULL){};
    dathuc(int l) {
        n = l;
        a = new int[n];
    }


    friend istream &operator >> (istream &is, dathuc &d){
        cout << "nhap vao bac cua da thuc : "; 
        is >> d.n;

        d.a = new int [d.n + 1];
        
        for(int i = 0; i <= d.n; i ++){
            cout << "nhap vao ptu " << i << ": "; is >> d.a[i];
            cout << endl;
        }
        return is;
    }

    friend ostream &operator << (ostream &os, dathuc &d){
        for(int i = 0; i <= d.n; i++){

            os << d.a[i] << "x^" << i;

            if(i != d.n){

                os << " + ";

            }
        }

        return os;
    }


    dathuc operator + (dathuc &d){
        int max = (n > d.n) ? n : d.n;
        int min = (n < d.n) ? n : d.n;

        dathuc sum = dathuc(max);

        for(int i = 0; i <= min; i++){
            sum.a[i] = a[i] + d.a[i];
        }
        for(int i = min + 1; i <= max; i++){
            sum.a[i] = (n == max) ? a[i] : d.a[i];
        }
        return sum;
    }

    dathuc operator - (dathuc &d){
        int max = (n > d.n) ? n : d.n;
        int min = (n < d.n) ? n : d.n;

        dathuc sub = dathuc(max);

        for(int i = 0; i <= min; i++){
            sub.a[i] = a[i] - d.a[i];
        }

        for(int i = min + 1; i <= max; i++){
            sub.a[i] = (n == max) ? a[i] : d.a[i];
        }
        return sub;
    }

};



int main(){
    dathuc dt1, dt2, sum, sub;
    
    cin >> dt1;
    cin >> dt2;

    cout << dt1 << endl;
    cout << dt2 << endl;


    cout << "tong la " << endl;
    sum = dt1 + dt2;
    cout << sum << endl;
    

    cout << "hieu la " << endl;
    sub = dt1 - dt2;
    cout << sub << endl;

    

    
}
