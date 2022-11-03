#include<iostream>
#include<math.h>
using namespace std;
class point {
    private:
      int x;
      int y;
    public:
     void nhap() {
        cout << "Nhap toa do cua x: "; cin >> x;
        cout << "Nhap toa do cua y: "; cin >> y;
     }
     void xuat() {
        cout << "(" << x << "," << y << ")";
     }
     friend double distance(point A, point B);
};
double distance(point A, point B) {
    return sqrt(pow(A.x - B.x,2) + pow(A.y - B.y,2));
}
class triangle {
    private:
      double ab, ac, bc;
      point A, B, C;
    public:
     void nhap() {
        cout << "Nhap toa do cua dinh A\n";
        A.nhap();
        cout << "Nhap toa do cua dinh B\n";
        B.nhap();
        cout << "Nhap toa do cua dinh C\n";
        C.nhap();
        ab = distance(A,B);
        ac = distance(A,C);
        bc = distance(B,C);
     }
     void xuat() {
        cout << "Toa do dinh A la: ";
        cout << "A"; A.xuat();
        cout << "Toa do dinh B la: ";
        cout << "B"; B.xuat();
        cout << "Toa do dinh C la: ";
        cout << "C"; C.xuat();
     }
     double getAB() {
        return ab;
     }
     double getAC() {
        return ac;
     }
     double getBC() {
        return bc;
     }
};
void test(triangle temp) {
    double ab = temp.getAB();
    double ac = temp.getAC();
    double bc = temp.getBC();
    if((ab + ac > bc) && (ab + bc > ac) && (ac + bc > ab)) {
        if((ab == ac) || (ab == bc) || (ac == bc)) {
            if((ab == ac) && (ab == bc) && (ac == bc)) {
            cout << "Tam giac deu";
            return;
            }
            else if((ab == sqrt(pow(ac,2) + pow(bc,2))) || (ac == sqrt(pow(ab,2) + pow(bc,2))) || (bc == sqrt(pow(ac,2) + pow(ab,2)))) {
            cout << "Tam giac vuong can";
            return;
            } else {
            cout << "Tam giac can";
            }
        }
        else if ((ab == sqrt(pow(ac,2) + pow(bc,2))) || (ac == sqrt(pow(ab,2) + pow(bc,2))) || (bc == sqrt(pow(ac,2) + pow(ab,2))))  {
               cout << "Tam giac vuong";
               return;
        } else {
            cout << "Tam giac thuong";
            return;
        }
    } else {
        cout << "Khong tao thanh 1 tam giac";
        
    }
}

int main() {
  triangle tg;
  tg.nhap();
  tg.xuat();
  test(tg);
}