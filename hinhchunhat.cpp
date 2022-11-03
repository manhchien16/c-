/*Câu 16: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp hình vuông với thuộc tính: độ dài cạnh.
Khai báo lớp hình chữ nhật kế thừa từ lớp hình vuông và thêm
 thuộc tính: độ dài cạnh thứ 2.
2.	Xây dựng các phương thức: nhập, xuất, tính chu vi, diện
 tích hình vuông, hình chữ nhật.
3.	Nhập vào n hình vuông. In ra màn hình hình vuông có diện
 tích lớn nhất và vị trí của hình vuông đó trong danh sách vừa
nhập.
*/
#include"bits/stdc++.h"

using namespace std;

class hv{
    protected:
    float canh1;

    public:
    hv(){};
    hv(float canh1) : canh1(canh1){};

    void nhap(){
        cout << "nhap vao canh 1: "; cin >> canh1;
    }
    void xuat(){
        cout << "canh1 la : " << canh1 <<"\t";
    }
    float chuvi(){
        float sum;
        return sum = canh1 *4;
    }
    float dientich(){
        float tich;
        return tich = canh1*canh1;
    }
    

};

class hcn : public hv{
    private:
    float canh2;
    public:
    hcn(){};
    hcn(float canh1, float canh2) : hv(canh1){
        this-> canh2 = canh2;
    }

    void nhap(){
        hv::nhap();
        cout << "nhap vao canh 2: "; cin >> canh2;
    }
    void xuat(){
        hv::xuat();
        cout << "canh 2 la :" << canh2 << endl;
    }

    float chuvicn(){
        return (canh1 + canh2) * 2;
    }
    float dientichcn(){
        return (canh1 * canh2);
    }
    void max(hcn *arr, int n){
        int index = 0;
        float max = 0;
        for(int i= 0; i < n; i++){
            if(max < arr[i].dientich()){
                max = arr[i].dientich();
                index = i;

            }
        }
        cout << " dien tich hinh vuong lon nhat la :" << max << endl;
        cout << "vi tri hinh vuong la : "<< index;

    }

    void dis(){
        cout <<endl <<"cv hinh cn la :"<< chuvicn();
        cout << endl << "dt hinh cn la :"<< dientichcn();
    }

    

};

int main(){
    int n;
    hcn *arr;
    cout << "nhap vao so hinh vuong :"; cin >> n;
    arr = new hcn[n];
    for(int i = 0; i < n; i++){
        arr[i].nhap();
    }
    for(int i = 0; i <n; i++){
        arr[i].xuat();
    }

    arr ->max(arr,n);
    for(int i = 0; i <n; i++){
    
        arr[i].dis();
    }   

}