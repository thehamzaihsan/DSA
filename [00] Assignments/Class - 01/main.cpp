#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int enroll;
    Student(string name_t, int enroll_t)
    {
        name = name_t;
        enroll = enroll_t;
    }
    Student() {}
};

class Node
{
public:
    Student data;
    int marks;
    Node *next;

    Node(Student data_t, int marks_t)
    {
        data = data_t;
        marks = marks_t;
    }
    Node();
};

class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert_student(Student st, int marks)
    {
        Node *new_node = new Node(st, marks);
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp_node = head;
            while (true)
            {
                if (temp_node->next == NULL)
                {
                    temp_node->next = new_node;
                }
                temp_node = temp_node->next;
            }
        }
        new_node->next = NULL;
    }

    void delete_student(string name)
    {
        Node *temp_node = head;
        Node *prev_node = head;
        while (true)
        {
            if (temp_node->data.name == name)
            {
                prev_node->next = temp_node->next;
                delete temp_node;
                break;
            }
            prev_node = temp_node;
            temp_node = temp_node->next;
        }
    }
    void find_student(string name)
    {
        Node *temp_node = head;
        while (true)
        {
            if (temp_node->data.name == name)
            {

                cout << temp_node->data.name << endl;
                cout << temp_node->data.enroll << endl;
                cout << temp_node->marks << endl;
                break;
            }
            temp_node = temp_node->next;
        }
    }
    void display_list()
    {
        Node *temp_node = head;
        while (true)
        {
            if (temp_node == NULL)
            {
                break;
            }
            cout << temp_node->data.name << endl;
            cout << temp_node->data.enroll << endl;
            cout << temp_node->marks << endl;
            temp_node = temp_node->next;
        }
    }
};

int main()
{

    cout << "help";
    List myList;
    // // generate main for this class
    Student st1("Ali", 1);
    Student st2("Ahmed", 2);
    // // Student st3("Asad", 3);
    // // Student st4("Ahsan", 4);
    // // Student st5("Adeel", 5);
    myList.insert_student(st1, 90);
    myList.insert_student(st2, 80);
    // // myList.insert_student(st3, 70);
    // // myList.insert_student(st4, 60);
    // // myList.insert_student(st5, 50);
    myList.display_list();
    // // myList.delete_student("Asad");
    // // myList.display_list();
    // // myList.find_student("Ali");
    return 0;
}