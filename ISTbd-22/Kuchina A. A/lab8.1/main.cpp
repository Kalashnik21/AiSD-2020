#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void new_node(unsigned long field_data);
void creation_node_in_target_place(int place, unsigned long field_data);//����� ����������� ���� �� ��������� �������
void print_list_ahead();//�����, ��������� ��� �������� �� ������ �� �����
void print_list_back();//�����, ��������� ��� �������� � ����� �� ������
int getsize() {
    return count_conteiner;};
void delete_target_element(int target);
void pop_front();//�������� ������� ��������
void clear();//������ ����������
void search_by_value(unsigned long value);//����� ������� �� ��������
unsigned long sum_values_list();//����� ���� ���������
unsigned long mid_value();//������� �������� ���� �������� ���������
unsigned long find_min_value();//����� ������������ ��������
unsigned long find_max_value();//����� ������������� ��������
unsigned long& operator[](const int index);//����� �������� �� �������
private:

class Node
    {
    public:
        Node *pNext;
        Node *pPrevious;
        unsigned long field_data;
        Node(unsigned long field_data = 123, Node *pPrevious = nullptr,Node *pNext = nullptr)
        {
            this->field_data = field_data;
            this->pPrevious = pPrevious;
            this->pNext = pNext;
        }
    };

int count_conteiner;
Node *head;//������ �������-������
Node *tail;//��������� �������-�����
};

List::List()
{
    count_conteiner = 0;
    head = nullptr;
}
List::~List()
{
}

unsigned long & List::operator[](const int index)
{
    int counter = 0;
    Node *current = this->head;
    while(current != nullptr)
    {
        if(counter == index){
            return current->field_data;
        }
        current = current->pNext;
        counter++;
    }

}

//������ ���������� ���������
void List::new_node(unsigned long field_data)
{
    if (head == nullptr)
    {
        head = new Node(field_data);
        Node *current = head;
        cout << "��� ������ ������ �������: " << "; pPrevious=" << current->pPrevious;
        cout << ";  ����� �������� �������� =  = " << current;
        cout << "; ���������� = " << field_data;
        cout << "; pNext = " << current->pNext << endl;
    }
    else
    {
        Node *current = this->head;//������� ���������, ����������� �� ������-1�� �������
        if(count_conteiner == 1 )
            {//���� ��� ������ �������
        Node *current_this;//��������� ��� ������������ �������� ������ ������
        current->pNext = new Node(field_data, current);//������� ����� �����, �������� pNext ���� ����� ����
        tail = current->pNext;//������� ������, ��� ��� ������� ���
        current_this = current->pNext;//������������ ����� ������ ��� ������
        current = current->pNext;//������� current �� �����, ��� ������ ��� ����������
        cout << "��� ������ ��������� �������: " << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ����� �������� = " << current_this;
        cout << "; ���������� = " << field_data;
        cout << "; ����� ���������� ��������:" << current->pNext << ";" << endl;
        }//���� �����, ��� ������
        else
        {
        Node *conteiner_for_uk;
        Node *current_this;//��������� �� ����������� �������
        Node *current_prev;//�������� ��������� ����������� ��������
        conteiner_for_uk = current->pNext;//��������� � ��������� ��������� �� ��������� ������� ������
        current->pNext = new Node(field_data,head,conteiner_for_uk);//�������� ������ ����
        current = current->pNext;//������������ �� ����. ����
        current_this = current;//��������������� ������ ����� ���� ��� ������ � ��������
        current = current->pNext;//������������ �� ����, ��� ����� ������� ��������� �� ����������
        current->pPrevious = current_this;//��������� ��������� �� ������� �������(2��� ��������, ����� �������� �� ��������� ���� �����) �� ���������� ��������� �� ����������� ����
        cout << "��� ������ �������: " << " ����� ����������� �������� = " << head;
        cout << "; ����� ����� �������� = " << current_this;
        cout << "; ���������� = " << field_data;
        cout << "; ����� ���������� ��������:" << conteiner_for_uk << ";" << endl;
        }
    }
    count_conteiner++;
}

void List::creation_node_in_target_place(int place, unsigned long field_data)
{
    Node *current = this->head;
    int i = 0;
    if(place == 0)
        {
        current->pPrevious = new Node(field_data, nullptr, current);
        head = current->pPrevious;
    }
    else
    {
    while(place - i != 1)
    {
        current = current->pNext;
        i++;
    };
    Node *conteiner_for_uk;
    conteiner_for_uk = current->pNext;//��������������� ���������
    current->pNext = new Node(field_data, current, conteiner_for_uk);//�������� ���� ��� ��������� �������
    current = current->pNext;//����������� ����
    conteiner_for_uk = current;//��������������� ��� ������
    current = current->pNext;//����������� �� �������, ������� ����� ����������
    current->pPrevious=conteiner_for_uk;//����������� ��������� �� ����������
    };
    count_conteiner++;
    cout << "������� ��������" << endl;
}
//������ ������ ������ �� �������
void List::print_list_ahead()
{
    Node *current = this->head;
    for(int i = 0; i < count_conteiner; i++)
    {
        cout << "������� " << i << ":" << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ���������� = " << current->field_data;
        cout << "; ����� ���������� �������� = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::print_list_back()
{
    Node *current = this->tail;
    for(int i = count_conteiner - 1; i != -1; i--)
    {
        cout << "������� " << i <<":" << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ���������� = " << current->field_data;
        cout << "; ����� ���������� �������� = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//��������� ������
void List::delete_target_element(int target)
{
    Node *current = this->head;
    int i = 0;
    if(target == 0)
        {
        current = head;
        head = head->pNext;
        delete current;
    }
    if(target > 0 && target < (count_conteiner - 1))
    {
    while(i - target != 1)
    {
        current = current->pNext;
        i++;
    };
    Node *conteiner_for_uk;
    Node *uk_to_delete;
    conteiner_for_uk = current;//��������������� ������ ���������� ����� �������� ��������
    current = current->pPrevious;//������� �� ��������� �������
    uk_to_delete = current;//���������� ������ ���������� ��������
    current = current->pPrevious;//������� �� ������� �� ����������
    current->pNext = conteiner_for_uk;//�������������� ����� ���������� �� ����� ����� ����������
    conteiner_for_uk = current;//���������� ������ �������� ��������
    current = current->pNext;//������� �� ������� ����� ���������� �� ������������ ����
    current->pPrevious = conteiner_for_uk;//�������������� ��������� �� ���������� � ���������� ��������
    delete uk_to_delete;
    };
    if(target == (count_conteiner -1))
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    count_conteiner--;

    cout << "������� ������" << endl;
}

void List::pop_front()
{
    Node *temp = head;
    if(head->pNext != nullptr)
        {
    head = head->pNext;
    head->pPrevious = nullptr;
    delete temp;
    count_conteiner--;
    }
    else
    {
         delete head;
         count_conteiner--;
    }
}

void List::clear()
{
    while(count_conteiner)
    {
        pop_front();
    }
}

//������ ������
void List::search_by_value(unsigned long value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "I������ �������� �������� " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != count_conteiner -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "������ �������� �������� " << i <<endl;
    };
}

unsigned long List::sum_values_list()
{
    unsigned long sum = 0;
    Node *current = this->head;
    while(current->pNext != nullptr)
    {
        sum += current->field_data;
        current = current->pNext;
    }
    return sum;
}

unsigned long List::mid_value()
{
    unsigned long mid;
    mid = sum_values_list()/count_conteiner;
    return mid;
}

unsigned long List::find_min_value()
{
    Node *current = this->head;
    unsigned long min = current->field_data;
    while((current->pNext) != nullptr)
    {
        if(current->field_data < min)
        min = current->field_data;
        current = current->pNext;
    }
    return min;
}

unsigned long List::find_max_value()
{
    Node *current = this->head;
    unsigned long max = current->field_data;
    while((current->pNext) != nullptr)
    {
        current = current->pNext;
        if(current->field_data > max)
        max = current->field_data;

    }
    return max;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List lst;
    lst.new_node(1);
    lst.new_node(12345);
    lst.new_node(1234);
    lst.new_node(123);
    lst.new_node(12);
    cout << endl << "����� ���������� ��������� � ������ - " << lst.getsize() << endl;
    cout << endl << "��������� ������ �� ������ �� �����" << endl << "-------------------" << endl;;
    lst.print_list_ahead();
    lst.creation_node_in_target_place(2,55);
    cout << endl << "��������� ������ � ����� �� ������" << endl << "-------------------" << endl;;
    lst.print_list_back();
    lst.delete_target_element(3);
    cout << endl << "����� ���������� ��������� � ������ - " << lst.getsize() << endl;
    lst.search_by_value(123);
    cout << "����� ���� ��������� ������ - ";
    cout << lst.sum_values_list();
    cout << endl << "������� �������� ��������� ������ - ";
    cout << lst.mid_value();
    cout << endl << "M���������� ������� - ";
    cout<<lst.find_min_value();
    cout << endl << "M����������� ������� - ";
    cout<<lst.find_max_value();
    lst.clear();
    return 0;
}
