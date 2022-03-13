#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <stack>
#include<set>

using namespace std;
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    }



struct book
{
    int id,copies,borrowed=0;

    string name;
    void add ()
    {
        cout <<"Enter book info: id& name & quantity: "<<endl;
        cin >>id>>name>>copies;
    }
    void print()
    {
        cout <<"id = "<<id<<" name = "<<name <<" total quantity "<<copies<< " total_borrowed "<<borrowed<<endl;
    }
};
book books [100]={};
int n=0;
int search_book(string name)
{
    for (int i =0; i<n;i++)
    {
        if (name== books[i].name)
        {
            return i;
        }
    }
}


struct user
{
    string name; int id;
    int books_id[100]={};
    int cnt=0;


    void add_id( int book_num )
    {

        books_id[cnt++]=books[book_num].id;
    }

    void add()
    {
        cout << "Enter user name & national id"<<endl;
        cin >> name>>id;
    }
    void print()
    {
        cout<< "user "<<name<<" id "<<id<<" borrowed books ids: ";

        for (int i=0;i<cnt;i++)
        {
            if (books_id[i]==-1) continue;
            cout << books_id[i]<<" ";
        }
        cout <<endl;
    }


};
user users[100];
int s=0;


int search_user(string user_name)
{
     for (int i =0; i<s;i++)
    {
        if (user_name== users[i].name)
        {
            return i;
        }
    }

}


void borrow()
{
    cout << "Enter user name & book name"<<endl;
            string user_name,book_name;
            cin>> user_name>> book_name;
            int book_num= search_book(book_name);
            int user_num=search_user(user_name);

            if (books[book_num].borrowed<books[book_num].copies)
                books[book_num].borrowed++;
            else
                cout << "There is no copies to borrow"<<endl;

           users[user_num].add_id(  book_num );

}

void return_book()
{
    cout <<"Enter user name and book name: "<<endl;
    string book_name,user_name;
    cin>>user_name>>book_name;
    int book_num=search_book(book_name);
    int user_num=search_user(user_name);
    int book_id=books[book_num].id;
    books[book_num].borrowed--;
    for (int i=0;i <users[user_num].cnt;i++)
    {
        if (users[user_num].books_id[i]==book_id )
        {
            users[user_num].books_id[i]=-1;
            break;
        }
    }
}


void who_borrowed()
{
    string name;
    cout << "Enter book name: "<<endl;
    cin >>name;
    int book_num=search_book(name);
    int book_id= books[book_num].id;
    int res=0;
    for (int i=0;i<n;i++)
    {
     for (int j=0;j<users[i].cnt;j++)
        {
                if (users[i].books_id[j]==book_id)
                {
                    res++;
                    cout<<users[i].name<<endl;
                    continue;
                }
        }
    }
    if (res==0)
    {
        cout << "Invalid book name"<<endl;
    }
}

void  pref_search()
{
    string pref;
    cout<<"Enter book name prefix: "<<endl;
    cin >>pref;
      int res=0;

    for (int i=0;i<n;i++)
    {
        bool flag=true;
        if (pref.size()>books[i].name.size())
            continue;
        for (int j=0;j<pref.size();j++)
        {
            if(books[i].name[j]!= pref[j])
            {
                flag=false;
                break;
            }
        }
        if  (flag)
        {
            cout <<books[i].name<<endl ;
            res++;
        }
    }
    if (res==0)
    {
        cout << "NO books with such prefix"<<endl;
    }

}


void print_books()
{
    for (int i=0; i<n;i++)
    {
        books[i].print();
    }
}

void print_users()
{
    for (int i=0; i<s;i++)
    {
        users[i].print();
    }

}
bool by_id(book a, book b)
{
    return a.id <b.id;
}
bool by_name(book a, book b)
{
    return a.name <b.name;
}

void menu()
{
    cout<<"Library Menu; \n 1) add_book \n 2) search_books_by_prefix \n 3) print who brrowed book by name"<<endl;
    cout << " 4) print library by id \n 5) print library by name \n 6) add user \n 7) user borrow book"<<endl;
    cout << " 8) user return book \n 9) print users \n 10) exit"<<endl;
}

void lib_sys()
{
    menu();
    while (true)
    {
        cout <<"Enter your menu choice from [1:10]"<<endl;

        int choice;
        cin >>choice;
        //  correct
        if (choice==1)
        {
            books[n++].add();
        }
       //    correct
        if (choice==2)
        {
            pref_search();
        }
       //  correct
        if (choice==3)
        {
            who_borrowed();
        }
        //correct
        if (choice==4)
        {
            sort (books, books+n,by_id);
            print_books();
        }
        //correct
        if (choice==5)
        {
            sort (books, books+n,by_name);
            print_books();
        }
        //correct
        if (choice==6)
        {
            users[s++].add();
        }
        //correct
        if (choice==7)
        {
            borrow();

        }
        //  correct
        if (choice==8)
        {
            return_book();
        }
        // correct
        if (choice==9)
        {
            print_users();
        }
        // correct
        if (choice==10)
        {
          break;
        }
    }
}

int main()
{
    init();
   lib_sys();
    return 0;
}



/*
1
100 math4 3
1
101 math2 5
1
102 math1 4
1
103 math3 2
1
201 prog1 5
1
202 prog 3
4
5
6
mostafa 30301
6
ali 50501
6
noha 70701
6
ashraf 90901
7
mostafa math1
7
mostafa math2
7
mostafa math3
7
ali math1
7
ali math2
7
noha math1
7
noha math2
4
9
2
ma
2
pro
2
machine
3
math1
3
math2
3
machine
4
9
8
mostafa math1
4
9
*/

