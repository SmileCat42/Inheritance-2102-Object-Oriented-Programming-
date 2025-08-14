#include <iostream>
using namespace std;
class Pork;
class Rice;
class Dish;
class Order;

class Food{
    double price;
    int type;
    public :
    Food(){
        setFoodType(1);
        setPrice(20);  
    }
    Food(double a, int b){
        setPrice(a);
        setFoodType(b);
    }
    ~Food(){
        show();
    }
    int setPrice(double  a){
        if(a<0){
            cout << "pls take price over than  0" << endl;
            return 0;
        }
        price=a;
        return 1;
    }
    int setFoodType(int a){
        if(a<1 || a>2){
            cout << "pls set value from 1-2 " << endl;
            return 0;
        }
        type=a;
        return 1;
    }
    double getPrice(){
        return price;
    }
    int getType(){
        return type;
    }
    void show(){
        cout << "Price : " << price << endl;
        if(getType()==1){
            cout << "Type food : Normal" << endl;
        }else{
            cout << "Type food : Special" << endl;
        }
    }
};

class Pork:public Food{
    int type;
    public:
    Pork(){
        setType(1);
        setFoodType(1);
        setPrice(45);
    }
    Pork(double a, int b, int c):Food(a,b){
        setType(c);
    }
    ~Pork(){
        show();
    }
    int setType(int a){
        if(a<1 || a>4){
            cout << "pls set value from 1-4 " << endl;
            return 0;
        }
        type=a;
        return 1;
    }
    int getType(){
        return type;
    }
    void show(){
        if(getType()==1){
            cout << "Pork type : frying" << endl;
        }else if(getType()==2){
            cout << "Pork type : BBQ" << endl;
        }else if(getType()==3){
            cout << "Pork type : Boild" << endl;
        }else{
            cout << "Pork type : Daddiaw" << endl;
        }
        Food::show();
    }
};

class Rice:public Food{
    int type;
    public:
    Rice(){
        setType(3);
        setFoodType(1);
        setPrice(20);
    }
    Rice(double a, int b, int c):Food(a,b){
        setType(c);
    }
    ~Rice(){
        show();
    }
    int setType(int a){
        if(a<1 || a>3){
            cout << "pls set value from 1-3 " << endl;
            return 0;
        }
        type=a;
        return 1;
    }
    int getType(){
        return type;
    }
    void show(){
        if(getType()==1){
            cout << "Rice type : Kaosuai" << endl;
        }else if(getType()==2){
            cout << "Rice type : Kaokong" << endl;
        }else{
            cout << "Rice type : Kaoniaw" << endl;
        }
        Food::show();
    }
};

class Dish{
    Pork *pork;
    int num;
    Rice rice;
    static int count;
    public: 
    Dish(){
        setNum(1);
        rice.setPrice(20);
        rice.setType(1);
        rice.setFoodType(1);
        count++;
    }
    ~Dish(){
        show();
        delete[] pork;
        count--;
    }
    void setPork(int a, Pork p){
        pork[a]=p;
    }
    int setNum(int a){
        if(a<1){
            cout << "pls take num >0" << endl;
            return 0;
        }
        num = a;
        pork = new Pork[num];
        return 1;
    }
    void setRice(int a, int b){
        rice.setType(b);
        rice.setPrice(a);
    }
    Pork& getPork(int a){
        return pork[a];
    }
    int getNum(){
        return num;
    }
    Rice& getRice(){
        return rice;
    }
    static int checkCount(){
        if(count<=0){
            cout << "Dont have dish now" << endl;
            return 0;
        }
        cout << "Dishes : " << count << endl;
        return 1;
    }
    bool isPorkType(int type){
        for(int i=0;i<num;i++){
            if(pork[i].getType()==type){
                return true;
            }
        }
        return false;
    }
    void show(){
        for(int i=0;i<num;i++){
            pork[i].show();
        }
        cout << "Num = " << num << endl;
        rice.show();
    }
};
int Dish::count;

class Order{
    Dish **dish;
    int num;
    int discount;
    public:
    Order(){
        setNum(0);
        setDiscount(0);
    }
    ~Order(){
        show();
        for(int i=0;i<num;i++){
            delete dish[i];
        }
        delete[] dish;
    }
    void setDish(int a, Dish &b){
        *dish[a]=b;
    }
    int setNum(int a){
        if(a<0){
            cout << "pls take num >=0" << endl;
            return 0;
        }
        num=a;
        dish=new Dish*[num];
        for(int i=0;i<num;i++){
            dish[i]=new Dish();
        }
        return 1;
    }
    void setDiscount(int a){
        discount=a;
    }
    Dish& getDish(int a){
        return *dish[a];
    }
    int getNum(){
        return num;
    }
    int getDiscount(){
        return discount;
    }
    double getPrice(){
        double sum;
        sum=0;
        for(int i=0;i<num;i++){
            Dish &temp=getDish(i);
            for(int j=0;j<getDish(i).getNum();j++){
                sum+=temp.getPork(j).getPrice();
            }
            sum+=temp.getRice().getPrice();
        }
        sum-=discount;
        return sum;
    }
    void checkMuYang(){
        for(int i=0;i<num;i++){
            if(dish[i]->isPorkType(2)==1){
                cout << "Hello Mu Yang" << endl;
            }
        }
    }
    void show(){
        for(int i=0;i<num;i++){
            getDish(i).show();
        }
        cout << "Num = " << num << endl;
        cout << "Discount = " << discount << endl;
    }
};

int main(){
    Dish dish1;
    Pork pork1(45,1,2);
    Pork pork2(30,1,4);
    dish1.setRice(15,3);
    dish1.setNum(2);
    dish1.setPork(0,pork1);
    dish1.setPork(1,pork2);
    Dish dish2;
    Pork pork3(60,2,3);
    dish2.setRice(25,2);
    dish2.setNum(1);
    dish2.setPork(0,pork3);
    Order order1;
    order1.setNum(2);
    order1.setDish(0,dish1);
    order1.setDish(1,dish2);
    order1.setDiscount(50);
    order1.show();
    cout << "this order1 have " << order1.getNum() << " dishes" << endl;
    cout << "order1 discount : " << order1.getDiscount() << " baht" << endl;
    cout << "--------Order dish1-------------" << endl;
    order1.getDish(0).getPork(0).show();
    order1.getDish(0).getPork(1).show();
    order1.getDish(0).getRice().show();
    cout << order1.getDish(0).getNum() << endl;
    cout << "--------Order dish2-------------" << endl;
    order1.getDish(1).getPork(0).show();
    order1.getDish(1).getRice().show();
    cout << order1.getDish(1).getNum() << endl;
    cout << "-----------checkMuYang order1-----------" << endl;
    order1.checkMuYang();
}

