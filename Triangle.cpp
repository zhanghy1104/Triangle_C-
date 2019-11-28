#include <iostream>
#include <math.h>
using namespace std;

class Point{
    private:
        double x;
        double y;

    public:
        Point(){

        }
        ~Point(){

        }
        Point(double a,double b){
            x=a;
            y=b;
        }
        void setX(double a){
            x=a;
        }
        void setY(double b){
            y=b;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
};
class Triange{
    private:
        Point p1;
        Point p2;
        Point p3;
    public:
        Triange(){

        }
        ~Triange(){

        }
        Triange(Point d1,Point d2,Point d3){
            this->p1=d1;
            this->p2=d2;
            this->p3=d3;
        }
        void setP1(Point p){
            this->p1=p;
        }
        void setP2(Point p){
            this->p2=p;
        }
        void setP3(Point p){
            this->p2=p;
        }
        Point getP1(){
            return this->p1;
        }
        Point getP2(){
            return this->p2;
        }
        Point getP3(){
            return this->p3;
        }

        double getCir(){
            double len12=pow((p1.getX()-p2.getX()),2)+pow((p1.getY()-p2.getY()),2);
            double len1=pow(len12,0.5);
            double len22=pow((p1.getX()-p3.getX()),2)+pow((p1.getY()-p3.getY()),2);
            double len2=pow(len22,0.5);
            double len32=pow((p2.getX()-p3.getX()),2)+pow((p2.getY()-p3.getY()),2);
            double len3=pow(len32,0.5);

            if(((len1+len2)>len3)&&((len2+len3)>len1)&&((len1+len3)>len2)){
                return len1+len2+len3;
            }else{
                cout << "这三个点不能构成三角形，请重新输入。" <<endl;
                return 0;
            }
            
        }

        double getS(){
            double len12=pow((p1.getX()-p2.getX()),2)+pow((p1.getY()-p2.getY()),2);
            double len1=pow(len12,0.5);
            double len22=pow((p1.getX()-p3.getX()),2)+pow((p1.getY()-p3.getY()),2);
            double len2=pow(len22,0.5);
            double len32=pow((p2.getX()-p3.getX()),2)+pow((p2.getY()-p3.getY()),2);
            double len3=pow(len32,0.5);

            if(((len1+len2)>len3)&&((len2+len3)>len1)&&((len1+len3)>len2)){
                double p=(len1+len2+len3)/2;
                double ss=pow(p*(p-len1)*(p-len2)*(p-len3),0.5);
                return ss;
            }else{
                cout << "这三个点不能构成三角形，请重新输入。" <<endl;
                return 0;
            }

           
        }

};

int main(){
    double cir;
    double ss;
    Point *p1=new Point(1,1);
    Point *p2=new Point(4,0);
    Point *p3=new Point(5,0);

    Triange *t=new Triange(*p1,*p2,*p3);

    cir=(*t).getCir();
    ss=(*t).getS();

    cout << "t的周长为：" << cir << ",t的面积为" << ss << endl;

    Point p;
    p.setX(3);
    p.setY(3);
    (*t).setP1(p);
    cir=(*t).getCir();
    ss=(*t).getS();

    cout << "t的周长为：" << cir << ",t的面积为" << ss << endl;

    return 0;
}