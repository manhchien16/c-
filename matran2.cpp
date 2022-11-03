/*Câu 13: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào hai ma trận đồng cấp. Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). In ra màn hình hai ma trận ban đầu và ma trận kết quả.
*/

#include "bits/stdc++.h"

using namespace std;

class matrix{
    private:
    int hang, cot;
    int a[100][100];
    public:

    void data(){
        cout << "nhap vao hang :"; cin >> hang;
        cout << "nhap vao cot :"; cin >> cot;
    }

    friend istream &operator >> (istream &is, matrix &m){

        m.data();
        for(int i = 0; i < m.hang; i++){
            for(int j = 0; j < m.cot; j++){
                cout <<"a[" << i <<"][" << j << "]= "; is >> m.a[i][j];
            }
        }
        return is;
    }
    friend ostream &operator << (ostream &os, matrix m){

        for(int i = 0; i < m.hang; i++){
            for(int j = 0; j < m.cot; j++){
                cout << m.a[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        return os;
    }
    friend matrix operator + (matrix &mt1, matrix &mt2){

        matrix sum;
        sum.data();
        for(int i = 0; i < mt1.hang; i++){
            for(int j = 0; j < mt1.hang; j++){
                sum.a[i][j] = mt1.a[i][j] + mt2.a[i][j];
            }
        }

        return sum;
        
    }

};

int main(){
    matrix mt1, mt2, sum;
    cin >> mt1;
    cin >> mt2;

    cout << mt1;
    cout << mt2;

    sum = mt1 + mt2;
    cout << sum;
}