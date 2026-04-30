/*#include <iostream>
#include <QCoreApplication>
#include<string.h>
#include<QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int i,count = 0,j,flag = 0,len;
    char a[20];
    char temp;

    qDebug() << "Enter a string" << endl;
    std::cin.get(a,20);

    len=strlen(a);

    for(i = 0, j = len-1; i < len/2; ++i, --j)
    {
        if(a[j]!= a[i])
            flag = 1;
    }

    if(flag == 0)
        qDebug() << "The string is a palindrome";
    else
        qDebug() << "The string is not a palindrome";

qDebug() << endl;

    for(i = 0, j = len-1; i < len/2; ++i, --j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    qDebug() << a;

    qDebug() << endl;

    for(i = 0; i<=len-1; i++)
        {
            count++;
        }
        qDebug() << "The Length of string is: " << count;

        return app.exec();
    }*/

/*#include<iostream>
#include<QDebug>
#include<string.h>
#include<QCoreApplication>

// Function to print all sub strings
void subString(char str[], int n)
{
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point.
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
                qDebug() << str[k]<<'\t';

            qDebug() << endl;
        }
    }
}

int main(int argc,char *argv[])
{
    QCoreApplication app(argc,argv);
    char str[20];
    qDebug() << "Enter a string" << endl;
    std::cin.get(str,20);

    subString(str, strlen(str));
    return app.exec();
}*/

/*#include<iostream>
#include<QDebug>
#include<string.h>
#include<QCoreApplication>

void printPalin(char a[], int len){
    int i,j,flag=0;
    for(i = 0, j = len-1; i < len; ++i, --j)
    {
        if(a[j]!= a[i])
            flag = 1;
    }

    if(flag == 0)
        qDebug() << "The string is a palindrome";
    else
        qDebug() << "The string is not a palindrome";

} 

// Function to print all sub strings
void subString(char a[], int len)
{
     //char str1[20];
    for(int i=1; i<=len; i++)
        {
            for (int j = 0; j <= (len-i); j++)
            {
                qDebug()<<"\n";
                for (int k = j; k <= i+j-1; k++)
                    qDebug()<<a[k];
            }
            //printPalin(str, strlen(str));
            qDebug() << endl;
        }

    }


int main(int argc,char *argv[])
{
    QCoreApplication app(argc,argv);
    char a[20];
    qDebug() << "Enter a string" << endl;
    std::cin.get(a,20);

    subString(a, strlen(a));
    printPalin(a, strlen(a));

    return app.exec();
}*/

/*#include<iostream>
#include<string>
#include<QCoreApplication>
#include<QDebug>
#include<QString>

using namespace std;
int palinsubstring(const string a, int j, int k) {
  int count = 0;
  for (; j >= 0 && k < a.length(); --j, ++k) {
    if (a[j] != a[k]) {
      break;
    }
    qDebug()<< a.substr(j, k - j + 1) << endl;
    ++count;
  }
  return count;
}

int substrings(const string a) {
  int count = 0,len=a.length();
  for (int i = 0; i < len; ++i) {
    count = count + palinsubstring(a, i - 1, i + 1);
    count = count + palinsubstring(a, i, i + 1);
  }
  return count;
}

int main(int argc,char *argv[]) {

    QCoreApplication app(argc,argv);
    string str;
    qDebug()<< "Enter a string: ";
    getline(cin, str);

  qDebug()<< "Total palindrome substrings: "  << substrings(str) << endl;

  return app.exec();
}*/

/*#include<QCoreApplication>
#include<iostream>
#include<string>
#include<QDebug>

using namespace std;

string b[500];
int var = 0;

// Function to print the sorted array of string
void prtArrstr(string, int);

// implementing Insertion Sort.
void sort(string s[], int n)
{
    for (int i = 1; i<n; i++)
    {
        string temp = s[i];

        // Insert s[j] at its correct position
        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length())
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

// Function to print the sorted array of string
void prtArrstr(string str[], int n)
{

    int i = 0;
    qDebug() << "The sorted palindrom substrings are:" << endl;
    while (i < n){
        qDebug() << str[i] << " ";
        i++;
    }
}

int palinsubstring(const string a, int j, int k) {
    int count = 0;
    for (; j >= 0 && k < a.length() - 1; --j, ++k) {
        if (a[j] != a[k]) {
            break;
        }
        b[var] = a.substr(j, k - j + 1);
        //qDebug()<<b[var]<<'\t'<<endl;
        var++;
        ++count;
    }

    return count;
}

int substrings(const string a) {
    int count = 0;
    for (int i = 0; i < a.length(); ++i) {
        count = count + palinsubstring(a, i - 1, i + 1);
        count = count + palinsubstring(a, i, i + 1);
    }
    return count;
}



int main(int argc,char *argv[])
{
    QCoreApplication app(argc,argv);
    string str;
    int i, j, flag = 0;
    qDebug() << "Enter a string: ";
    getline(cin, str);

    for (i = 0, j = str.length() - 1; i < str.length(); ++i, --j)
    {
        if (str[j] != str[i])
            flag = 1;
    }

    if (flag == 0){

        qDebug() << "The Entered string is a palindrome" << endl;
        qDebug() << "Total number of palindrome substrings: " << substrings(str) << endl;
        for (i = 0; i <= var - 1; i++){

            qDebug() << b[i] << " " << endl;;

        }
        int n = str.length();
        sort(b, n);
        prtArrstr(b, n);
    }

    else{

        qDebug() << "The Entered string is not a palindrome";
    }


    return app.exec();
}*/


