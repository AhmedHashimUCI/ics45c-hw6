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


TEST(PictureTest, EmptyPicturePrintsNothing) {
    Picture p;

    std::ostringstream out;
    p.print_all(out);

    EXPECT_EQ(out.str(), "");
}

TEST(PictureTest, SingleCirclePrintsAndDraws) {
    Picture p;
    Circle c{{0, 0}, "Circle_1", 1};

    p.add(c);

    std::ostringstream out;
    p.print_all(out);

   EXPECT_EQ(
    out.str(),
    "Circle_1 at (0, 0) area = 3.14159\n"
    " * \n"
    " * \n"
);
}

TEST(PictureTest, PreservesInsertionOrder) {
    Picture p;

    Circle first{{0, 0}, "First", 0};
    Circle second{{1, 2}, "Second", 0};

    p.add(first);
    p.add(second);

    std::ostringstream out;
    p.print_all(out);

    EXPECT_EQ(
        out.str(),
        "First at (0, 0) area = 0\n"
        "*\n"
        "Second at (1, 2) area = 0\n"
        "*\n"
    );
}


TEST(PictureTest, EmptyPictureArea) {
    Picture p;

    EXPECT_DOUBLE_EQ(p.total_area(), 0.0);
}

TEST(PictureTest, EmptyPictureDraw) {
    Picture p;

    std::ostringstream out;
    p.draw_all(out);

    EXPECT_EQ(out.str(), "");
}

TEST(PictureTest, SingleCircleArea) {
    Picture p;
    Circle c{{0, 0}, "C1", 2};

    p.add(c);

    EXPECT_NEAR(p.total_area(), 12.5663706, 0.00001);
}

TEST(PictureTest, MultipleCircleAreas) {
    Picture p;

    Circle first{{0, 0}, "First", 2};
    Circle second{{1, 1}, "Second", 3};

    p.add(first);
    p.add(second);

    double expected = 13.0 * std::numbers::pi;

    EXPECT_NEAR(p.total_area(), expected, 0.00001);
}

TEST(PictureTest, DrawAllPreservesOrder) {
    Picture p;

    Circle first{{0, 0}, "First", 0};
    Circle second{{0, 0}, "Second", 1};

    p.add(first);
    p.add(second);

    std::ostringstream out;
    p.draw_all(out);

    EXPECT_EQ(
        out.str(),
        "*\n"
        " * \n"
        " * \n"
    );
}


TEST(RectangleTest, CalculatesArea) {
    Rectangle r{{0, 0}, "R1", 4, 6};

    EXPECT_DOUBLE_EQ(r.area(), 24.0);
}

TEST(RectangleTest, ZeroWidth) {
    Rectangle r{{0, 0}, "R1", 0, 5};

    EXPECT_DOUBLE_EQ(r.area(), 0.0);
}

TEST(RectangleTest, ZeroHeight) {
    Rectangle r{{0, 0}, "R1", 5, 0};

    EXPECT_DOUBLE_EQ(r.area(), 0.0);
}

TEST(RectangleTest, DrawCorrectDimensions) {
    Rectangle r{{0, 0}, "R1", 4, 5};

    std::ostringstream out;
    r.draw(out);

    EXPECT_EQ(
        out.str(),
        "****\n"
        "****\n"
        "****\n"
    );
}

TEST(RectangleTest, DrawNonSymmetricDimensions) {
    Rectangle r{{0, 0}, "R1", 5, 2};

    std::ostringstream out;
    r.draw(out);

    EXPECT_EQ(out.str(), "*****\n");
}

TEST(RectangleTest, CloneProducesIndependentCopy) {
    Rectangle original{{1, 2}, "Original", 4, 6};

    Rectangle* copy = original.clone();

    ASSERT_NE(copy, nullptr);
    EXPECT_NE(copy, &original);

    EXPECT_DOUBLE_EQ(copy->area(), original.area());

    std::ostringstream a;
    std::ostringstream b;

    original.print(a);
    copy->print(b);

    EXPECT_EQ(a.str(), b.str());

    delete copy;
}

TEST(RectangleTest, PrintFormat) {
    Rectangle r{{3, 7}, "Rectangle_1", 4, 6};

    std::ostringstream out;
    r.print(out);

    EXPECT_EQ(
        out.str(),
        "Rectangle_1 at (3, 7) area = 24\n"
    );
}


TEST(PictureTest, CircleAndRectangle) {
    Picture p;

    Circle c{{0, 0}, "Circle_1", 2};
    Rectangle r{{0, 0}, "Rectangle_1", 4, 5};

    p.add(c);
    p.add(r);

    double expected = 4 * std::numbers::pi + 20;

    EXPECT_NEAR(p.total_area(), expected, 0.00001);

    std::ostringstream out;
    p.print_all(out);

    std::string result = out.str();

    EXPECT_NE(result.find("Circle_1"), std::string::npos);
    EXPECT_NE(result.find("Rectangle_1"), std::string::npos);

    EXPECT_LT(
        result.find("Circle_1"),
        result.find("Rectangle_1")
    );
}


TEST(TriangleTest, CalculatesArea) {
    Triangle t{{0, 0}, "T1", 5, 4};

    EXPECT_DOUBLE_EQ(t.area(), 10.0);
}

TEST(TriangleTest, FractionalArea) {
    Triangle t{{0, 0}, "T1", 3, 3};

    EXPECT_DOUBLE_EQ(t.area(), 4.5);
}

TEST(TriangleTest, ZeroBase) {
    Triangle t{{0, 0}, "Zero", 0, 5};

    EXPECT_DOUBLE_EQ(t.area(), 0.0);
}

TEST(TriangleTest, ZeroHeight) {
    Triangle t{{0, 0}, "Zero", 5, 0};

    EXPECT_DOUBLE_EQ(t.area(), 0.0);
}

TEST(TriangleTest, DrawTriangle) {
    Triangle t{{0, 0}, "T1", 5, 5};

    std::ostringstream out;
    t.draw(out);

    EXPECT_EQ(
        out.str(),
        "  *\n"
        " ***\n"
        "*****\n"
    );
}

TEST(TriangleTest, DrawUnequalDimensions) {
    Triangle t{{0, 0}, "T1", 3, 5};

    std::ostringstream out;
    t.draw(out);

    EXPECT_EQ(
        out.str(),
        "  *\n"
        " ***\n"
        "*****\n"
    );
}

TEST(TriangleTest, CloneProducesIndependentCopy) {
    Triangle original{{2, 3}, "Original", 4, 6};

    Triangle* copy = original.clone();

    ASSERT_NE(copy, nullptr);
    EXPECT_NE(copy, &original);

    EXPECT_DOUBLE_EQ(copy->area(), original.area());

    std::ostringstream a;
    std::ostringstream b;

    original.print(a);
    copy->print(b);

    EXPECT_EQ(a.str(), b.str());

    delete copy;
}

TEST(TriangleTest, PrintFormat) {
    Triangle t{{1, 2}, "Triangle_1", 3, 3};

    std::ostringstream out;
    t.print(out);

    EXPECT_EQ(
        out.str(),
        "Triangle_1 at (1, 2) area = 4.5\n"
    );
}

