//#include <QApplication>
//#include <QCoreApplication>
//#include <QtGui>
//#include <QtCore>
//#include <QGridLayout>
//#include <QLabel>
//#include <QTextEdit>
//#include <QPushButton>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    //MainWindow w;

//    QWidget *w=new QWidget();
//    w->setWindowTitle("Info");

//    QGridLayout *layout=new QGridLayout();

//    QLabel *label1= new QLabel("Name");
//    QTextEdit *txtName= new QTextEdit("Vivek");


//    layout->addWidget(label1,0,0);
//    layout->addWidget(txtName,0,1);

//    w->setLayout(layout);

//    w->show();

//    return a.exec();
//}



//#include<iostream>
//#include<QCoreApplication>
//#include<QDebug>
//#include<

//int main(int argc,char *argv[]){

//    QCoreApplication app(argc,argv);
//     st;
//    st.open("D:/Workflow/vivek1.txt",ios::out);
//    if(!st){
//        qDebug()<<"File creation failed";
//    }
//    else{
//        qDebug()<<"File created sucessfully";
//        st<<"Hello";
//        st.close();

//    }

//    return app.exec();
//}

//largest of three number
//#include<iostream>
//#include<QDebug>
//#include<QCoreApplication>

//int main(int argc,char *argv[]){

//    QCoreApplication app(argc,argv);

//    float n1,n2,n3;

//    qDebug()<<"Enter the numbers";

//    std::cin>>n1>>n2>>n3;

//    if(n1>=n2 && n1>=n3){

//        qDebug()<<"The largest number is:"<<n1;
//    }
//    if(n2>=n1 && n2>=n3){

//        qDebug()<<"The largest number is:"<<n2;
//    }
//    if(n3>=n1 && n3>=n2){

//        qDebug()<<"The largest number is:"<<n3;
//    }

//    return app.exec();
//}

//Divisor of a number
//#include<iostream>
//#include<QDebug>
//#include<QCoreApplication>

//int main(int argc,char *argv[]){

//    QCoreApplication app(argc,argv);

//    int n1,i;

//    qDebug()<<"Enter the number";

//    std::cin>>n1;

//    for(i=1;i<=n1;i++){

//        if(n1%i==0){

//            qDebug()<<"The divisor numbers are:"<<i;
//        }
//    }

//    return app.exec();
//}

//Selection Sort

#include<iostream>
#include<QDebug>
#include<QCoreApplication>

void swap(int *x,int *y){

    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void SelectionSort(int arr[],int n){

    int i,j,min_ind;
    for(i=0; i<n-1; i++){

        min_ind=i;
        for(j=i+1;j<n;j++){

            if(arr[j]<arr[min_ind]){

                min_ind=j;

                swap(&arr[min_ind],&arr[i]);
            }
        }

    }
}

void printArray(int arr[],int n){

    int i;
    for(i=0;i<n;i++){

        qDebug()<<arr[i]<<endl;
        qDebug()<<'\n';
    }
}

int main(int argc,char *argv[]){

    QCoreApplication app(argc,argv);

     int arr[]={57,89,43,56,34};

     int n=sizeof(arr)/sizeof(arr[0]);

     SelectionSort(arr,n);

     qDebug()<<"Sorted array";

     printArray(arr,n);

    return app.exec();
}
