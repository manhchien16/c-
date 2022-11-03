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
    int *arr;

    public:
    dathuc(){
        n = 0;
        arr = NULL;
    }
    dathuc(int l){
        n = l;
        arr = new int[n];
    }
    ~dathuc(){};

    void nhap(){
        cout << "nhap vao bac cua da thuc : "; cin >> n;
        arr = new int[n + 1];
        for(int i = 0; i <= n; i++){
            cin >> arr[i];
        }
    }
    void xuat(){
        for(int i = 0; i <= n; i++){
            cout << arr[i] << "x^" <<i;
            if(i != n){
                cout << "+";
            }
        }
        cout << endl;
    }

    dathuc operator + (dathuc &d){
        int max = (n > d.n) ? n : d.n;
        int min = (n < d.n) ? n : d.n;

        dathuc sum = dathuc(max);
        for(int i = 0; i <= min; i++){
            sum.arr[i] = arr[i] + d.arr[i];
        }
        for(int i = min + 1; i <= max; i++){
            sum.arr[i] = (n == max) ? arr[i] : d.arr[i];
        }

        return sum;
    }

};

int main(){
    dathuc dt1, dt2, sum;
    dt1.nhap();
    dt2.nhap();

    dt1.xuat();
    dt2.xuat();

    sum = dt1 + dt2;
    sum.xuat();
}