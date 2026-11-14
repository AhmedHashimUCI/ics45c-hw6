#include "picture.hpp"
#include <iostream>
#include <utility>


Picture::Picture():
		head(nullptr), tail(nullptr){}


void Picture::add(const Shape& shape){
	Shape* clone = shape.clone();
	ListNode* node = new ListNode{clone, nullptr};


	if (head == nullptr){
		head = node;
		tail = node;
	}else {
		tail-> next = node;
		tail = node;
	
	}

}

void Picture::print_all(std::ostream& out) const{
	for (ListNode* p = head; p != nullptr; p = p->next){

		p->shape->print(out);
		p->shape->draw(out);


	}

}

Picture:: ~Picture(){
	for(ListNode* p = head; p != nullptr;){
	ListNode* next = p->next;

	delete p->shape;
	delete p;

	p = next;

	}
}

double Picture::total_area() const {
    double total = 0.0;

    for (ListNode* current = head;
         current != nullptr;
         current = current->next) {

        total += current->shape->area();
    }

    return total;
}

void Picture::draw_all(std::ostream& out) const {
    for (ListNode* current = head;
         current != nullptr;
         current = current->next) {

        current->shape->draw(out);
    }
}

