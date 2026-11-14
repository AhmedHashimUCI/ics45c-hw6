// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the shapes and Picture. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the areas, for print_all and draw_all,
// for total_area, and for copying a Picture.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include <numbers>
#include <sstream>

/*TEST(ShapeTests, RectangleAreaIsWidthTimesHeight) {
    EXPECT_NEAR(Rectangle({0, 0}, "R", 7, 3).area(), 21.0, 0.001);
}

TEST(PictureTests, AnEmptyPictureHasNoArea) {
    const Picture p;
    EXPECT_DOUBLE_EQ(p.total_area(), 0.0);
}*/

// ADD YOUR TESTS HERE

TEST(CircleTest, AreaRadiusTwo) {
    Circle c{{0, 0}, "Circle_1", 2};

    EXPECT_DOUBLE_EQ(c.area(), 4 * std::numbers::pi);
}

TEST(CircleTest, AreaRadiusZero) {
    Circle c{{0, 0}, "Zero", 0};

    EXPECT_DOUBLE_EQ(c.area(), 0.0);
}

TEST(CircleTest, PrintFormat) {
    Circle c{{3, 4}, "MyCircle", 2};

    std::ostringstream out;
    c.print(out);

    EXPECT_EQ(
        out.str(),
        "MyCircle at (3, 4) area = 12.5664\n"
    );
}

TEST(CircleTest, CloneIsIndependent) {
    Circle original{{1, 2}, "Original", 3};

    Circle* copy = original.clone();

    ASSERT_NE(copy, nullptr);
    EXPECT_NE(copy, &original);
    EXPECT_DOUBLE_EQ(copy->area(), original.area());

    std::ostringstream first;
    std::ostringstream second;

    original.print(first);
    copy->print(second);

    EXPECT_EQ(first.str(), second.str());

    delete copy;
}


TEST(CircleTest, DrawRadiusThree) {
    Circle c{{0, 0}, "Test", 3};

    std::ostringstream out;
    c.draw(out);

    EXPECT_EQ(
        out.str(),
        "   *   \n"
        " ***** \n"
        " ***** \n"
        "   *   \n"
    );
}

