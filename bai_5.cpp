/*
Câu 5: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
Khai báo lớp sinh viên kế thừa từ lớp người và thêm các thuộc tính: mã sinh viên, điểm trung bình.
2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng người, sinh viên.
3.	Nhập vào n sinh viên. Sắp xếp lại và in ra màn hình danh sách sinh viên theo thứ tự giảm dần của điểm trung bình.

*/

#include"bits/stdc++.h"

using namespace std;

class people{
    protected:
    string hoten;
    int namsinh;

    public:


};
class people2 : public people{
    private:
    string msv;
    float dtb;

    public:


        friend istream &operator >>(istream &is, people2 &p){
            cin.ignore();
            cout << "nhap vao ma sinh vien : "; getline (is, p.msv);
            cout << "nhap ho ten : "; getline(is,p.hoten);
            cout << "nhap vao nam sinh : "; is >> p.namsinh;
            cout << "nhap vao tb : "; is >> p.dtb;

            return is;   
    }
        friend ostream &operator <<(ostream &os, people2 p){
            cout << setw(15) << left << p.msv;
            cout << setw(25) << left << p.hoten;
            cout << setw(15) << left << p.namsinh;
            cout << setw(15) << left << p.dtb;
            cout << endl;    

        return os;       
    }

    void giamdan(people2 *arr, int n){
        people2 tg;
         for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n ; j++){
                if(arr[i].dtb < arr[j].dtb){
                    tg = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tg;
                }
            }
         }
    }

        
};

        void khung(){
            cout << setw(15) << left << "msv";
            cout << setw(25) << left << "hoten";
            cout << setw(15) << left << "nam sinh";
            cout << setw(15) << left << "diem trung binh";
            cout << endl;
        }


int main(){
    people2 *arr;
    int n;
    cout <<" nhap vao so sinh vien : "; cin >> n;

    arr = new people2[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    khung();

    for(int i = 0; i < n; i++){
        cout << arr[i];
    }

    arr->giamdan(arr,n);
    khung();
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }   
 

}