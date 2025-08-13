#include <iostream>
#include <string.h>
using namespace std;

class Date;
class Person;
class Address;
class Student;
class Teacher;

/**************************************************************************
**************************** CLASS DATE  ***************************************************/

class Date{
    int day;
    int month;
    int year;
    public :
    Date(){
        setAll(0,0,0);
        cout << "Created birthday but no data" << endl;
    }
    Date(int a){
        setDay(a);
        setMonth(0);
        setYear(0);
        cout << "Created birthday  " << day << "/xx/xx" << endl;
    }
    Date(int a, int b){
        setDay(a);
        setMonth(b);
        setYear(0);
        cout << "Created birthday  " << day << month << "/xx" << endl;
    }
    Date(int a, int b, int c){
        setDay(a);
        setMonth(b);
        setYear(c);
        cout << "Created birthday  " << day << month << year << endl;
    }
    void setAll(int a, int b, int c);
    void setDay(int a);
    void setMonth(int a);
    void setYear(int a);
    void setBirthday(Date a);
    int getDay();
    int getMonth();
    int getYear();
    void show();
};

void Date::setAll(int a, int b, int c){
    setDay(a);
    setMonth(b);
    setYear(c);
}

void Date::setDay(int a){
    day=a;
}

void Date::setMonth(int a){
    month=a;
}

void Date::setYear(int a){
    year=a;
}

void Date::setBirthday(Date a){
    setDay(a.day);
    setMonth(a.month);
    setYear(a.year);
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

void Date::show(){
    cout << "Birthday : " << day << "/" << month << "/" << year << endl;
}

/********************************************************************
 * ***********************  CLASS ADDRESS   ****************************************/

class Address{
    string sub;
    string dist;
    string prov;
    public :
    Address(){
        setAll("-","-","-");
        cout << "Created address but no data" << endl;
    }
    Address(string a){
        setSub("-");
        setDist("-");
        setProv(a);
        cout << "Created address " << sub << endl;
    }
    Address(string a, string b){
        setSub("-");
        setDist(b);
        setProv(a);
        cout << "Created address " << sub << dist << endl;
    }
    Address(string a, string b, string c){
        setSub(c);
        setDist(b);
        setProv(a);
        cout << "Created address " << sub << dist << prov << endl;
    }
    void setAll(string a, string b, string c);
    void setSub(string a);
    void setDist(string a);
    void setProv(string a);
    void setAddress(Address a);
    string getSub();
    string getDist();
    string getProv();
    void show();
};

void Address::setAll(string a, string b, string c){
    setProv(a);
    setDist(b);
    setSub(c);
}

void Address::setSub(string a){
    sub=a;
}

void Address::setDist(string a){
    dist=a;
}

void Address::setProv(string a){
    prov=a;
}

void Address::setAddress(Address a){
    setSub(a.sub);
    setDist(a.dist);
    setProv(a.prov);
}

string Address::getSub(){
    return sub;
}

string Address::getDist(){
    return dist;
}

string Address::getProv(){
    return prov;
}

void Address::show(){
    cout << "Address : " << sub << "," << dist << "," << prov << endl << endl;
}

/********************************************************************
 * ***********************  CLASS PERSON   ****************************************/

class Person{
    string fname;
    string lname;
    Date birthday;
    Address adds;
    public :
    Person(){
        setName("no data","no data");
        setBD(0,0,0);
        setAdds("-","-","-");
        cout << "Create Person " << fname << lname << endl;
    }
    Person(string a, string b){
        setName(a,b);
        setBD(0,0,0);
        setAdds("-","-","-");
        cout << "Create Person " << fname << lname << endl;
    }
    Person(string a, string b, int c, int d ,int e){
        setName(a,b);
        setBD(c,d,e);
        setAdds("-","-","-");
        cout << "Create Person " << fname << lname << endl;
    }
    Person(string a, string b, int c, int d ,int e,string f,string g, string h){
        setAll(a,b,c,d,e,f,g,h);
        cout << "Create Person " << fname << lname << endl;
    }
    Person(string a, string b, Date c, Address d){
        setFname(a);
        lname=b;
        birthday.setBirthday(c);
        adds.setAddress(d);
    }
    void setAll(string a, string b, int c, int d ,int e,string f,string g, string h);
    void setName(string a, string b);
    void setFname(string a);
    void setLname(string a);
    void setBD(int a, int b, int c);
    void setBD(Date a);
    void setAdds(string a, string b, string c);
    void setAdds(Address a);
    string getFname();
    string getLname();
    int getBDday();
    int getBDmonth();
    int getBDyear();
    Date getBD();
    Address getAdds();
    void show();
    void showBD();
    void showAdds();
};

void Person::setAll(string a, string b, int c, int d ,int e,string f,string g, string h){
    fname=a;
    lname=b;
    birthday.setDay(c);
    birthday.setMonth(d);
    birthday.setYear(e);
    adds.setSub(h);
    adds.setDist(g);
    adds.setProv(f);
}

void Person::setName(string a, string b){
    fname=a;
    lname=b;
}

void Person::setFname(string a){
    fname= a;
}

void Person::setLname(string a){
    lname =a;
}
void Person::setBD(int a, int b, int c){
    birthday.setAll(a,b,c); 
}

void Person::setBD(Date a){
    birthday.setAll(a.getDay(),a.getMonth(),a.getYear());
}

void Person::setAdds(string a, string b, string c){
    adds.setAll(a,b,c);
}

void Person::setAdds(Address a){
    adds.setAll(a.getProv(),a.getDist(),a.getSub());
}

string Person::getFname(){
    return fname;
}

string Person::getLname(){
    return lname;
}

int Person::getBDday(){
    return birthday.getDay();
}

int Person::getBDmonth(){
    return birthday.getMonth();
}

int Person::getBDyear(){
    return birthday.getYear();
}

Date Person::getBD(){
    return birthday;
}

Address Person::getAdds(){
    return adds;
}

void Person::show(){
    cout << "First name : " << fname << endl;
    cout << "Last name : " << lname << endl;
    birthday.show(); 
    adds.show();
}

void Person::showBD(){
    cout << birthday.getDay() << "/" << birthday.getMonth() << "/" << birthday.getYear();
}

void Person::showAdds(){
    cout << adds.getSub() << ", " << adds.getDist() << ", " << adds.getProv();
}


/**************************************************************************
 * ************************** CLASS STUDENT **************************************************/

class Student:public Person{
    string id;
    string fac;
    public :
    Student(){
        setAll("no data","no data",0,0,0,"-","-","-","no data","no data");
        cout << "Created a student no data" << endl;
    }
    Student(string a, string b){
        setAll(a,b,0,0,0,"-","-","-","no data","no data");
        cout << "Created a student" << getFname() << getLname() << endl;
    }
    Student(string a, string b, int c, int d, int e){
        setAll(a,b,c,d,e,"-","-","-","no data","no data");
        cout << "Created a student" << getFname() << getLname() << endl;
    }
    Student(string a, string b, int c, int d, int e, string f, string g, string h){
        setAll(a,b,c,d,e,f,g,h,"no data","no data");
        cout << "Created a student" << getFname() << getLname() << endl;
    }
    Student(string a, string b, int c, int d, int e, string f, string g, string h, string i, string j):Person(a,b,c,d,e,f,g,h){
        id=i;
        fac=j;
        cout << "Created a student" << getFname() << getLname() << endl;
    }
    ~Student(){
        cout << "Delete" << getFname() << getLname() << endl;
    }
    void setAll(string a, string b,int c, int d, int e, string f, string g, string h, string i, string j);
    void setID(string a);
    void setFac(string a);
    string getID();
    string getFac();
    void show();
};

void Student::setAll(string a, string b,int c, int d, int e, string f, string g, string h, string i, string j){
    setFname(a);
    setLname(b);
    setBD(c,d,e);
    setAdds(f,g,h);
    id=i;
    fac=j;
}

void Student::setID(string a){
    id=a;
}

void Student::setFac(string a){
    fac=a;
}

string Student::getID(){
    return id;
}

string Student::getFac(){
    return fac;
}

void Student::show(){
    cout << "Student ID : " << id << endl;
    cout << "Faculty : " << fac << endl;
    Person::show();
}

/***************************************************************
 * ********************** CLASS TEACHER *****************************************/

class Teacher:public Person{
    string idt;
    int sal;
    public :
    Teacher(){
        setAll("no data","no data",0,0,0,"-","-","-","no data",0);
        cout << "Created a teacher no data" << endl;
    }
    Teacher(string a, string b){
        setAll(a,b,0,0,0,"-","-","-","no data",0);
        cout << "Created a teacher" << getFname() << getLname() << endl;
    }
    Teacher(string a, string b, int c, int d, int e){
        setAll(a,b,c,d,e,"-","-","-","no data",0);
        cout << "Created a teacher" << getFname() << getLname() << endl;
    }
    Teacher(string a, string b, int c, int d, int e, string f, string g, string h){
        setAll(a,b,c,d,e,f,g,h,"no data",0);
        cout << "Created a teacher" << getFname() << getLname() << endl;
    }
    Teacher(string a, string b, int c, int d, int e, string f, string g, string h,string i, int j){
        setAll(a,b,c,d,e,f,g,h,i,j);
        cout << "Created a teacher" << getFname() << getLname() << endl;
    }
    ~Teacher(){
        cout << "Delete" << getFname() << getLname() << endl;
    }
    void setAll(string a, string b, int c, int d, int e, string f, string g, string h, string i, int j);
    void setIdt(string a);
    void setSal(int a);
    string getIdt();
    int getSal();
    void show();
};

void Teacher::setAll(string a, string b, int c, int d, int e, string f, string g, string h, string i, int j){
    setFname(a);
    setLname(b);
    setBD(c,d,e);
    setAdds(f,g,h);
    setIdt(i);
    setSal(j);
}

void Teacher::setIdt(string a){
    idt=a;
}

void Teacher::setSal(int a){
    sal=a;
}

string Teacher::getIdt(){
    return idt;
}

int Teacher::getSal(){
    return sal;
}

void Teacher::show(){
    cout << "Teacher ID : " << idt << endl;
    cout << "Salary : " << sal << endl;
    Person::show();
}

int main(){
    cout << "---------------------1. default constructor -----------------------" << endl;
    Person per1;
    Date date1;
    Address adds1;
    Student stu1;
    Teacher tea1;
    per1.show();
    date1.show();
    cout << "\n";
    adds1.show();
    stu1.show();
    tea1.show();
    cout << "---------------------2. one constructor & add name -----------------------" << endl;
    Student stu2("Bamboo ","Kendel");
    Teacher tea2("Wanphen ","Rakdee");
    per1.setFname("Tamrong ");
    per1.setLname("Saksee");
    Date date2(14);
    Address adds2("Chiangmai");
    adds2.setSub("Fang");
    adds2.setDist("Maetang");
    per1.show();
    stu2.show();
    tea2.show();
    date2.show();
    adds2.show();
    cout << "---------------------3. constructor to object BD & get BD-----------------------" << endl;
    Student stu3("Wendy ","Morphan",7,4,2540);
    Teacher tea3("Somsri ","Benjamas",21,8,2525);
    date1.setAll(14,11,2537);
    per1.setBD(date1);
    per1.show();
    stu3.show();
    tea3.show();
    cout << "---------------------4. constructor to object adds & get adds -----------------------" << endl;
    Address adds3("Chonburi","Panusnikom","-");
    adds3.setSub("Borthong");
    Student stu4("Printon ","Amonra",16,1,2543,"Lampang","Mueng","Somtui");
    Teacher tea4("Weerayut ","Jaiarsa",3,6,2529,"Pichit","Dongcharuen","Wangbong");
    per1.setAdds(adds2);
    per1.show();
    stu4.show();
    tea4.show();
    cout << "---------------------4. all constructor  -----------------------" << endl;
    Student stu5("Amiba ","Couren",11,12,2537,"Lampang","Mueng","Somtui","10452","Comsci");
    Teacher tea5("Anan ","Chansri",30,9,2522,"Pichit","Dongcharuen","Wangbong","70489",58000);
    stu5.show();
    tea5.show();
    cout << "---------------------5. call func from Inheritance  -----------------------" << endl;
    cout << stu3.getFname() << " birth in ";
    stu3.showBD();
    cout << endl;
    cout << tea2.getFname() << " live in " << adds2.getSub() << "," << adds2.getDist() << "," << adds2.getProv() << endl;
    cout << stu4.getFname() << " birth in " << stu4.getBDday() << "/" << stu4.getBDmonth() << "/" << stu4.getBDyear() << endl; 
    cout << stu5.getFname() << " " << stu5.getLname() << " studying in " << stu5.getFac() << endl;
    cout << tea5.getFname() << " " << tea5.getLname() << " salary : " << tea5.getSal() << endl;
} 