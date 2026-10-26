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

    void clearList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        if (temp->next == nullptr)
        {
            delete temp;
            head = nullptr;
            return;
        }

        while (temp != nullptr)
        {
            if (temp->next->next == nullptr)
            {
                delete temp->next;
                temp->next = nullptr;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteSpecific(int id)
    {
        if (head == nullptr)
            return;

        if (head->id == id)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->id != id)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
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
    list.insertAtBeginning(1, "kola", "DS");
    list.insertAtBeginning(2, "phanea", "SE");
    list.insertAtBeginning(3, "kheang", "CB");

    cout << "--Bonus A" << endl;
    list.deleteAtEnd();
    list.display();
    list.restore();
    
    cout << "-Bonus B" << endl;
    int num_specific = 2;
    cout << endl << "delete speific student: " << endl;
    list.deleteSpecific(num_specific);
    list.display();
    
    return 0;
}
