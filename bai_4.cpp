/*
    Câu 4: 
        3.	Viết chương trình thực hiện các yêu cầu sau:
            1.	Khai báo lớp time với các thuộc tính: giờ, phút, giây.
            Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng time.
            2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng time.
            3.	Định nghĩa toán từ ++,-- để tăng, giảm một giây. Thực hiện tăng, 
            giảm một giây và in kết quả ra màn hình (kết quả phải được chuẩn hóa 
            dưới định dạng 24 tiếng hh:mm:ss).
            
*/

#include"bits/stdc++.h"

using namespace std;

class thoigian{
    private:
    int hour , minutes, sec;

    public:
    thoigian (){};
    thoigian (int hour , int minutes, int sec) : hour(hour) , minutes(minutes) , sec(sec) {};
    ~thoigian(){};

    friend istream &operator >> (istream &is, thoigian &tm);
    friend ostream &operator << (ostream &os, thoigian );

    thoigian operator ++ (){

        sec ++;
        while(sec >= 60){
            minutes ++;
            sec -= 60;
        }
        while(minutes >= 60){
            hour ++;
            minutes -= 60;
        }
        while(hour >= 24){
            hour -= 24;
        }
 
    return thoigian(hour,minutes,sec);
    }
        thoigian operator -- (){

        sec -2;
        while(sec = 0){
            sec = 59;
            minutes = 59;
            if(hour == 0){
                hour = 23;
            }else
                hour --;
    
        }
    return thoigian(hour,minutes,sec);
    }
};


    istream &operator >> (istream &is, thoigian &tm){
        cin >> tm.hour >> tm.minutes >> tm.sec ;
    }

    ostream &operator << (ostream &os, thoigian tm){

        while(tm.sec >= 60){
            tm.minutes ++;
            tm.sec -= 60;
        }
        while(tm.minutes >= 60){
            tm.hour ++;
            tm.minutes -= 60;
        }
        while(tm.hour >= 24){
            tm.hour -= 24;
        }

        cout << tm.hour << ":" << tm.minutes << ":" << tm.sec;
    }

int main(){
    thoigian times;

    cout << "nhap vao gio , phut , giay: ";
    cin >> times;

    cout << times << endl;

    cout <<"tang 1 sec : "<< endl;
    cout << ++ times << endl;
    cout <<"giam 1 sec : "<< endl;
    cout << -- times << endl;
}
