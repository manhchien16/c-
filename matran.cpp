/*Câu 8: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào 1 ma trận. In ra màn hình ma trận vừa nhập. Tính tổng các phần tử nằm trên 4 đường viền của ma trận.
*/

#include "bits/stdc++.h"

using namespace std;

class  matrix{
    private:
    int hang;
    int cot;
    int **a;
    public:

    matrix(){};
    ~matrix(){};

    void nhap(){
        cout << "nhap vao so hang : "; cin >> hang;
        cout << "nhap vao so cot : "; cin >> cot;

        a = new int *[hang];
        for(int i = 0; i < hang; i++){
            a[i] = new int[cot];
        }
        for(int i = 0; i < hang; i ++){
            for(int j = 0; j < cot; j++){
                cout << "a[" << i <<"][" <<j<<"]="; cin >>a[i][j];
            }
        }
    }

    void xuat(){
        for(int i = 0; i < hang; i++){
            for(int j = 0; j < cot; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void sum(){
        float sum = 0;
        for(int i = 0; i < hang; i++){
            for(int j = 0; j < cot; j++){
                if(i == 0 || i == hang - 1|| j == 0 || j == cot -1){
                    sum += a[i][j];
                }
            }
        }
        cout << sum;
    }


};

int main(){
    matrix mt;
    mt.nhap();
    mt.xuat();
    mt.sum();
}