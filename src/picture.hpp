#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "shape.hpp"

class Picture {
private:
    struct ListNode {
        Shape* shape;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;

public:
    Picture();

    Picture(const Picture& other);
    Picture(Picture&& other) noexcept;

    Picture& operator=(const Picture& other);
    Picture& operator=(Picture&& other) noexcept;

    ~Picture();

	void swap(Picture& other);

    void add(const Shape& shape);

    void print_all(std::ostream& out) const;
    void draw_all(std::ostream& out) const;

    double total_area() const;
};

#endif

