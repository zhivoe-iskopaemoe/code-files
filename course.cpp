#include <iostream>
#include <memory>

struct object {
    int data;
    std::shared_ptr<object> next;
    object(int data,  std::shared_ptr<object> next) {
        this->data = data;
        this->next = next;
    }
};

using shared_obj_ptr = std::shared_ptr<object>;

void push_back(shared_obj_ptr& head, shared_obj_ptr& tail, int data)
{
    shared_obj_ptr obj{std::make_shared<object>(data, nullptr)};
	if (head == NULL && tail == NULL) {
            head = obj; 
            tail = obj;
        }
	else{
        if(head == tail){
            head->next = obj;
            tail = obj;
        }
        else{
            tail->next = obj;
		    tail = obj;
        }
    }
}


void pop_front(shared_obj_ptr& head, shared_obj_ptr& tail) {
    if (head == NULL) return;
		if (head == tail) {
			head = tail = NULL;
			return;
		}

		head = head->next;
	}


void show(const shared_obj_ptr& head)
{
    std::cout << head->data << " ";
    shared_obj_ptr t = head->next;
    while(t){
        std::cout << t->data << " ";
        t = t->next;
    }
}


int main(void)
{
    // здесь продолжайте функцию main
    shared_obj_ptr head, tail;
    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);
    show(head);
    return 0;
}