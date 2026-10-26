#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int id;
    string name;
    string major;
    Node *next;

    Node(int studentId, string studentName, string studentMajor)
    {
        id = studentId;
        name = studentName;
        major = studentMajor;
        next = nullptr;
    }
};

class studentList
{
private:
    Node *head = nullptr;

public:
    void insertAtBeginning(int id, string name, string major)
    {
        Node *newNode = new Node(id, name, major);
        newNode->next = head;
        head = newNode;
    }

    int count()
    {
        int accumulator = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            accumulator += 1;
            temp = temp->next;
        }
        return accumulator;
    }

    bool search(int id)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool deleteAtFirst()
    {
        if (head == nullptr)
            return false;

        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    void clearList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty list" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->id << " " << temp->name << " " << temp->major << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    
    void restore(){
        clearList();
        insertAtBeginning(1, "kola", "DS");
        insertAtBeginning(2, "phanea", "SE");
        insertAtBeginning(3, "kheang", "CB");
    }
};

int main()
{
    studentList list;
    cout << "Exercise 2.2" << endl;
    list.insertAtBeginning(1, "kola", "DS");
    list.insertAtBeginning(2, "phanea", "SE");
    list.insertAtBeginning(3, "kheang", "CB");

    list.display();

    cout << "-Exercise 2.3" << endl;
    cout << "Count: " << list.count() << endl << endl;

    cout << "-Exercise 2.4" << endl;
    int num_search = 2;
    cout << "Search " << num_search << ": " << list.search(num_search) << endl << endl;

    cout << "-Exercise 2.5" << endl;
    list.deleteAtFirst();
    list.display();
    list.restore();

    cout << "-Exercise 2.6" << endl;
    list.clearList();
    list.display();
    list.restore();

    return 0;
}
