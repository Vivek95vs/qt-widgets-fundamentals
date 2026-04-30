/*#include <QCoreApplication>
#include<iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<"Hello world";

    return a.exec();
}*/

/*//Function overloading with different parameter

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

int absolute(int var){
    if(var<0){
        var=-var;
    }
    return var;
}

float absolute(double var){
    if(var<0.0){
        var=-var;
    }
    return var;
}

int main(int argc, char *argv[]){

    QCoreApplication a(argc,argv);

    qDebug()<<"The Integer Value is:"<<absolute(5)<<'\n';
    qDebug()<<"The Float Value is:"<<absolute(5.5f)<<'\n';

    return a.exec();
}*/

/*#include<QCoreApplication>
#include<iostream>
#include<QDebug>

void disp(int v1, double v2){
    qDebug()<<"Integer value of v1:"<<v1<<'\n';
    qDebug()<<"Float Value of v2:"<<v2<<'\n';
}

void disp(int A){
    qDebug()<<"Integer value of A:"<<A<<'\n';
}

void disp(double B){
    qDebug()<<"Double value of B:"<<B<<'\n';
}

int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);

    int a=5;
    double b=6.6;

    disp(a);
    disp(b);
    disp(a,b);

    return app.exec();
}*/


//Default arguments

/*#include<QCoreApplication>
#include<iostream>
#include<QDebug>

void disp(char= '*', int=25);
int main(int argc, char *argv[]){
    QCoreApplication app(argc, argv);
    int count=50;
    disp();
    disp('#');
    disp('@',count);
    return app.exec();
}

void disp(char c, int count){
    for(int i=0;i<c;i++){
        qDebug()<<c;
    }
    qDebug()<<'\v';
}*/

/*#include<QCoreApplication>
#include<iostream>
#include<QDebug>
void disp(char c='*',int count=13){
    for(int i=0;i<count;i++){
        qDebug()<<c<<'\n';
    }
}

int main(int argc, char *argv[]){
    QCoreApplication app(argc,argv);
    int count=2;

    disp();
    disp('#');
    disp('@',count);
    return app.exec();
}*/

/*//Static Local Variable

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

void disp(){
    static int var=2;
    ++var;
    qDebug()<<var;
}

int main(int argc, char *argv[]){
    QCoreApplication app(argc,argv);

    disp();
    disp();

    return app.exec();

}*/

/*//Factorial of number using recursion

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

int factorial(int);
int main(int argc, char *argv[]){
    QCoreApplication app(argc,argv);
    int num,result;
    qDebug()<<"Enter The Positive Integer:";
    std::cin>>num;
    result=factorial(num);
    qDebug()<<"Factorial of "<<num<<"="<<result;
    return app.exec();
}
int factorial(int n){
    if(n>1){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}*/

/*//Object and Classes

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Room{
public:
    double length;
    double height;
    double breadth;

    double calculateArea(){
        return length*height;
    }

    double calculateVolume(){
        return length*breadth*height;
    }
};

int main(int argc,char *argv[]){
    Room room1,room2;
    QCoreApplication app(argc,argv);

    room1.length=56.7;
    room1.height=43.5;
    room1.breadth=45.9;

    room2.length=38.2;
    room2.height=67.7;
    room2.breadth=59.7;

    qDebug()<<"Area of Room1 is:"<<room1.calculateArea()<<'\n';
    qDebug()<<"Volume of Room1 is:"<<room1.calculateVolume()<<'\n';
    qDebug()<<"Area of Room2 is:"<<room2.calculateArea()<<'\n';
    qDebug()<<"Volume of Room2 is:"<<room2.calculateVolume()<<'\n';

    return app.exec();
}*/

/*//Private and Public class

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Dog{
    private:
    double DHeight;
    double DLength;
    double DWeight;

public:
    void disp(double len,double hgt, double wgt){
        DLength=len;
        DHeight=hgt;
        DWeight=wgt;
    }
    double dogArea(){
        return DLength*DHeight;
    }
    double dogVolume(){
        return DLength*DHeight*DWeight;
    }
};
int main(int argc,char *argv[]){
    Dog dog1;
    dog1.disp(24.5,23.4,45.6);
    QCoreApplication app(argc,argv);
    qDebug()<<"Area of a dog:"<<dog1.dogArea()<<'\n';
    qDebug()<<"Volume of a dog:"<<dog1.dogVolume()<<'\n';

    return app.exec();
}*/

//Constructor

/*//1.Default constructor

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Room{
private:
    double length;
public:
    Room(){
        length=5.6;
        qDebug()<<length;
    }
};
int main(int argc,char *argv[]){
    QCoreApplication app(argc, argv);
    Room room1;
    return app.exec();
}*/

//2.Parameterized constructor

/*#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Room{
private:
    double length;
    double height;
    double breadth;

public:
    Room(double len,double hgt,double brd){
        length=len;
        height=hgt;
        breadth=brd;
    }
    double calculateVolume(){
        return length*breadth*height;
    }
};
int main(int argc,char *argv[]){

    Room room1(32.4,45.8,54.5);
    Room room2(34.8,52.9,86.5);
    QCoreApplication app(argc,argv);
    qDebug()<<"The Volume of room1 is:"<<room1.calculateVolume()<<'\n';
    qDebug()<<"The Volume of room2 is:"<<room2.calculateVolume()<<'\n';
    return app.exec();
}*/

//3.Copy constructor

/*#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Room{
private:
    double length;
    double height;
    double breadth;

public:
    Room(double len,double hgt,double brd){
        length=len;
        height=hgt;
       breadth=brd;
    }
    Room(Room &obj){
        length=obj.length;
        height=obj.height;
        breadth=obj.breadth;
    }
    double calculateVolume(){
        return length*height*breadth;
    }
};

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    Room room1(34.5,56.4,53.6);
    qDebug()<<"Volume of room1 is:"<<room1.calculateVolume()<<'\n';
    Room room2=room1;
    qDebug()<<"Volume of room1 is:"<<room2.calculateVolume()<<'\n';
    return app.exec();
}*/

/*//Pass object to function

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Boy{
public:
    double marks;
    Boy(double m){
        marks=m;
    }
    };
    void print(Boy s1, Boy s2){
        double average=(s1.marks+s2.marks)/2;
        qDebug()<<"Average is:"<<average;
    }

int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);
    Boy boy1(67),boy2(67.1);
    print(boy1, boy2);
    return app.exec();

}*/

/*//Return object from a function

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Room{
public:
    double length;
    double height;
};

Room createroom(){
    Room room;
    room.height=45.5;
    room.length=56.7;
    qDebug()<<"The Room Length is:"<<room.length<<'\n';
    qDebug()<<"The Room Height is:"<<room.height<<'\n';
    return room;
}

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);

    Room room1;
    room1=createroom();
    return app.exec();
}*/

/*//To find Array Sum and Average

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);
    double n[]={2.3,3.5,6,7.8,8.9,2.5};
    double sum=0,count=0,Average;

    for(int i=0;i<6;i++){

        sum=sum+n[i];

         ++count;
    }
    qDebug()<<"Sum is:"<<sum<<'\n';
    Average=sum/count;
    qDebug()<<"Average is:"<<Average<<'\n';
    return app.exec();
}*/

/*//Structure and Function

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

struct person{
    char name[100];
    int age;
    float salary;
};
void disp(person);
int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);
    person p1;
    qDebug()<<"Enter Full Name:";
    std::cin.get(p1.name,100);
    qDebug()<<"Enter the Age:";
    std::cin>>p1.age;
    qDebug()<<"Enter the Salary:";
    std::cin>>p1.salary;
    disp(p1);
    return app.exec();
}
void disp(person a){
    qDebug()<<"Full Name is:"<<a.name<<'\n';
    qDebug()<<"Salary is:"<<a.salary<<'\n';
    qDebug()<<"age is:"<<a.age<<'\n';
}*/

/*//Inheritance

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Animal{
public:
    void eat(){
        qDebug()<<"I will eat"<<'\n';
    }
    void sleep(){
        qDebug()<<"I will sleep"<<'\n';
    }
};

class Dog : public Animal{
public:
    void bark(){
        qDebug()<<"I can bark"<<'\n';
    }
    void guard(){
        qDebug()<<"I can guard"<<'\n';
    }
};

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    Dog dog1;
    dog1.eat();
    dog1.sleep();
    dog1.bark();
    dog1.guard();
    return app.exec();
}*/

/*//Overridding function

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Animal{
public:
    void disp(){
        qDebug()<<"Base Class";
    }
};

class Dog : public Animal{
public:
    void disp(){
         qDebug()<<"Derived Class";
    }
};

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    Dog obj;
    obj.disp();
    return app.exec();
}*/

/*//Acessing Overloading function

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Animal{
public:
    void disp(){
        qDebug()<<"Base Class";
    }
};

class Dog : public Animal{
public:
    void disp(){
         qDebug()<<"Derived Class";
    }
};

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    Dog obj1,obj2;
    obj1.disp();
    obj2.Animal::disp();
    return app.exec();
}*/

/*//Acessing Overloading function from derived class

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Animal{
public:
    void disp(){
        qDebug()<<"Base Class";
    }
};

class Dog : public Animal{
public:
    void disp(){
         qDebug()<<"Derived Class";

         Animal::disp();
    }
};

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    Dog obj;
    obj.disp();
    return app.exec();
}*/

/*//Acessing Overloading function using pointer

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Animal{
public:
    void disp(){
        qDebug()<<"Base Class";
    }
};

class Dog : public Animal{
public:
    void disp(){
         qDebug()<<"Derived Class";
    }
};

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    Dog obj;

    Animal *ptr=&obj;
    ptr->disp();
    return app.exec();
}*/

/*//Multilevel Inheritance

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class A{
public:
    void eat(){
        qDebug()<<"Base class"<<'\n';
    }
};
class B : public A{
public:
    void sleep(){
        qDebug()<<"derived  class 1"<<'\n';
    }
};
class C :public B{
public:
    void bark(){
        qDebug()<<"derived class 2"<<'\n';
    }
};
int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);

    C obj;
    obj.eat();
    obj.sleep();
    obj.bark();

    return app.exec();
}*/

/*//Multiple inheritance

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class mammal{
public:
    void mam(){
        qDebug()<<"Animal can give Birth"<<'\n';
    }
};

class WingedAnimal{
public:
    void wing(){
        qDebug()<<"Animal can Fly"<<'\n';
    }
};

class Bat : public mammal,public WingedAnimal{
public:
};
int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);

    Bat obj;
    obj.mam();
    obj.wing();

    return app.exec();
}*/

/*//Virtual Function

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

class Animal{
public:
  virtual void disp(){
        qDebug()<<"Base class";
    }
};
class Dog : public Animal{
public:
    void disp(){
        qDebug()<<"Derived class";
    }
};
int main(int argc, char *argv[]){

    QCoreApplication app(argc,argv);
    Dog obj;
    Animal *ptr=&obj;
    ptr->disp();
    return app.exec();
}*/

/*//Function Overloading

#include<QCoreApplication>
#include<iostream>
#include<QDebug>

int sum(int n1,int n2){
    return n1+n2;
}

double sum(double n1,double n2){
    return n1+n2;
}
int sum(int n1,int n2,int n3){
    return n1+n2+n3;
}

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);
    qDebug()<<"The Sum is:"<<sum(3,6)<<'\n';
    qDebug()<<"The Sum is:"<<sum(3.4,6.5)<<'\n';
    qDebug()<<"The Sum is:"<<sum(3,6,7)<<'\n';

    return app.exec();
}*/

/*//if else statement

#include <QCoreApplication>
#include <iostream>
#include<QDebug>

int main(int argc, char *argv[])
{
    char selection;
    QCoreApplication a(argc, argv);

    qDebug()<<"Please think of a traffic light with red, yellow and green lights."<<'\n';
    qDebug()<<"Choose one of the colors by pressing the R, Y or G key..."<<'\n';

    selection = getchar();
    selection = tolower(selection);

    if (selection=='r')
    {
        // the R key was pressed
        qDebug()<<"RED LIGHT:";
        qDebug()<<"The if the traffic light is red, then stop.";
    }
    else
    {
        // other key was pressed
        if (selection=='y')
        {
            // the Y key was pressed
            qDebug()<<"YELLOW LIGHT:";
            qDebug()<<"The if the traffic light shows yellow, slow down and stop.";
        }
        else
        {
            // other key was pressed
            if (selection=='g')
            {
                // the G key was pressed
                qDebug()<<"GREEN LIGHT:";
                qDebug()<<"The if the traffic light is green, then go.";
            }
            else
            {
                // other key was pressed
                qDebug()<<"Please only press R, Y or G.";
            };
        };
    };

    return a.exec();
}*/

//Switch case statement

#include <QCoreApplication>
#include <iostream>
#include<QDebug>

int main(int argc, char *argv[])
{
    char selection;
    QCoreApplication a(argc, argv);

    qDebug()<<"Please think of a traffic light with red, yellow and green lights."<<'\n';
    qDebug()<<"Choose one of the colors by pressing the R, Y or G key..."<<'\n';

    selection = getchar();
    selection = tolower(selection);

    switch (selection)
    {
        case 'r':
          // the R key was pressed
        qDebug()<<"RED LIGHT:";
        qDebug()<<"The if the traffic light is red, then stop.";
        break;

        case 'y':

           // the Y key was pressed
        qDebug()<<"YELLOW LIGHT:";
        qDebug()<<"The if the traffic light shows yellow, slow down and stop.";
        break;


         case 'g':

            // the G key was pressed
         qDebug()<<"GREEN LIGHT:";
         qDebug()<<"The if the traffic light is green, then go.";
        break;

    default:

         qDebug()<<"Please only press R, Y or G.";
        break;

            }
    return a.exec();
}
