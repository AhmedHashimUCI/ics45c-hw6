#include "picture.hpp"
#include <iostream>
#include <utility>


Picture::Picture():
		head(nullptr), tail(nullptr){}



Picture::Picture(const Picture& other)
		:head(nullptr), tail(nullptr){
			
			for(ListNode* p = other.head; p != nullptr; p = p->next){
			
				add(*p->shape);

			}
	
		}


void Picture::swap(Picture& other){
	std::swap(head, other.head);
	std::swap(tail, other.tail);


}

Picture& Picture::operator=(const Picture& other){
	if(this != &other){
		Picture newpic(other);
		swap(newpic);
	}

	return *this;

}


Picture::Picture(Picture&& other) noexcept
		:head(other.head), tail(other.tail){
			other.head = nullptr;
			other.tail = nullptr;

		}


Picture& Picture::operator=(Picture&& other) noexcept {
	if(this != &other){
	Picture newpic(std::move(other));
	swap(newpic);

	}

	return *this;

}


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

