/*
Câu 4: 
3.	Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp time với các thuộc tính: giờ, phút, giây.
Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng time.
2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng time.
3.	Định nghĩa toán từ ++,-- để tăng, giảm một giây. Thực hiện tăng, giảm một giây và in kết quả ra màn hình (kết quả phải được chuẩn hóa dưới định dạng 24 tiếng hh:mm:ss).
 
*/

#include"bits/stdc++.h"

using namespace std;

class thistime{
    private:
    int sec;
    int minute;
    int hour;

    public:
    thistime(){};
    thistime(int hour, int ninute, int sec) : hour(hour) , minute(minute), sec(sec){};
    ~thistime(){};

    friend istream &operator >> (istream &is, thistime &t){
        cout << "nhap gio : "; is >> t.hour;
        cout << "nhap phut : "; is >> t.minute;
        cout << "nhap vao giay : "; is >> t.sec;

        return is;
    }

    friend ostream &operator << (ostream &os, thistime t){
        if(t.sec == 60){
                t.sec = 0;
            if(t.minute == 60){
                t.minute = 0;
            if(t.hour == 24){
                t.hour = 0;
            }
            t.hour ++;
        }
            t.minute ++;
        }

        if(t.minute == 60){
                t.minute = 0;
            if(t.hour == 24){
                t.hour = 0;
            }
            t.hour ++;
        }

        if(t.hour == 24){
                t.hour = 0;
            }
        
     
            cout << t.hour <<":"<< t.minute <<":"<<t.sec;

        return os;
    }
    


int main(){
    thistime tm;

    cin >> tm;
    cout << tm;

}