#include"windows.h"
#include <iostream>
#include<list>
#include<forward_list>
#include<array>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

struct book {
    void input() {
        cout << "введите название книги" << endl;
        cin >> name;
        cout << "введите автора книги" << endl;
        cin >> author;
        cout << "введите жанр книги" << endl;
        cin >> genre;
        cout << "введите дату издания книги" << endl;
        cin >> dati;
    }
    void show() {
        cout << "название: " << name << " автор: " << author << " жанр: " << genre << " дата выхода: " << dati << endl;
    }
    string name;
    string author;
    string genre;
    int dati;
};
void sorted(array<book, 1> array1, list<book> list1, forward_list<book> forward_list1, deque<book> deque1) {
    priority_queue<int> sorting;
    stack<book> stack;
    queue<book> que;
    for (book b : array1)
    {
        sorting.push(b.dati);
        stack.push(b);
        que.push(b);
    }
    for (book b : list1)
    {
        sorting.push(b.dati);
        stack.push(b);
        que.push(b);
    }
    for (book b : forward_list1)
    {
        sorting.push(b.dati);
        stack.push(b);
        que.push(b);
    }
    for (book b : deque1)
    {
        sorting.push(b.dati);
        stack.push(b);
        que.push(b);
    }
    cout << "сортировка priotity" << endl;
    while (!sorting.empty())
    {
        for (book b : array1) {
            if (sorting.top() == b.dati) {
                b.show();
            }
        }
        for (book b : list1) {
            if (sorting.top() == b.dati) {
                b.show();
            }
        }
        for (book b : forward_list1) {
            if (sorting.top() == b.dati) {
                b.show();
            }
        }
        for (book b : deque1) {
            if (sorting.top() == b.dati) {
                b.show();
            }
        }
        sorting.pop();

    }
    cout << "Сортировка stack" << endl;
    while (!stack.empty()) {
        stack.top().show();
        stack.pop();
    }
    cout << "Сортировка queview" << endl;
    while (!que.empty())
    {
        que.front().show();
        que.pop();
    }


}
int main()
{
    SetConsoleCP(1251);
    setlocale(0, "");
    book one = book();
    one.input();

    book two = book();
    two.input();

    book three = book();
    three.input();


    book four = book();
    four.input();
    array<book, 1> array1{ one };
    list<book> list1;

    list1.push_back(two);
    forward_list<book> forward_list1;

    forward_list1.push_front(four);

    deque<book> deque1;
    deque1.push_back(three);
    sorted(array1, list1, forward_list1, deque1);
}