#include <iostream>
#include <cmath>

static const int number = 5;

enum Colors
{
    BLACK = 1,
    YELLOW,
    RED,
    BLUE,
    GREEN,
    NONE
};

struct Coordinate
{
    double coordX = 0;
    double coordY = 0;
};

class Figure
{

    double figureArea;
    Colors color;
    Coordinate figureCoord;

public:
    Figure()
          : figureArea(0.0), color(NONE)
    {
        std::cout << "Enter the coordinates X Y of the center of the figure:";
        std::cin >> figureCoord.coordX >> figureCoord.coordY;
        int colorNumber = 0;
        std::cout << "Enter the color number from the list:" << std::endl;
        std::cout << BLACK << ". Black;\n" << YELLOW << ". Yellow;\n" << RED << ". Red;" << std::endl;
        std::cout << BLUE << ". Blue;\n" << GREEN << ". Green." << std::endl;
        std::cin >> colorNumber;
        if (colorNumber < 1 || colorNumber > 5) color = NONE;
        else color = static_cast<Colors>(colorNumber);
    }
    double outSideRectangle_1 = 0.0;
    double outSideRectangle_2 = 0.0;
    void setArea (double area) {figureArea = area;}
    void printColor (Colors inColor)
    {
        if (inColor == BLACK) std::cout << "Black.";
        if (inColor == YELLOW) std::cout << "Yellow.";
        if (inColor == RED) std::cout << "Red.";
        if (inColor == BLUE) std::cout << "Blue.";
        if (inColor == GREEN) std::cout << "Green.";
        if (inColor == NONE) std::cout << "Colorless.";
    }
    void figure_data()
    {
        std::cout << "Figure area: " << figureArea << ". Color: ";
        printColor(color);
        std::cout << "\nSides of the outer rectangle: " << outSideRectangle_1 << ", " << outSideRectangle_2;
        std::cout << "\nCoordinates of the center of the figure: (" << figureCoord.coordX << ", " << figureCoord.coordY << ")" << std::endl;
    }
};

class Circle : public Figure
{
    double radius;
    const double pi;

public:
    Circle()
          : radius(0.0), pi(3.1415)
    {
        do
        {
            std::cout << "Enter circle radius:";
            std::cin >> radius;
            if (radius <= 0) std::cout << "Incorrect! Try again." << std::endl;
        } while (radius <= 0);
        outSideRectangle_1 = (radius * 2) + 0.5;
        outSideRectangle_2 = outSideRectangle_1;
    }
    void area_circle ()
    {
        double area = pi * pow(radius,2);
        setArea(area);
    }
};

class Triangle : public Figure
{
    double ribLength;
public:
    Triangle()
            : ribLength(0.0)
    {
        do
        {
            std::cout << "Enter rib length of the triangle:";
            std::cin >> ribLength;
            if (ribLength <= 0) std::cout << "Incorrect! Try again." << std::endl;
        } while (ribLength <= 0);
        outSideRectangle_1 = (ribLength * sqrt(3) / 2) + 0.5;
        outSideRectangle_2 = ribLength + 0.5;
    }

    void area_triangle ()
    {
        double area = (pow(ribLength,2) * sqrt(3)) / 4;
        setArea(area);
    }
};

class Rectangle : public Figure
{
    double width;
    double height;

public:
    Rectangle()
             : width(0.0), height(0.0)
    {
        do
        {
            std::cout << "Enter the width of the rectangle:";
            std::cin >> width;
            std::cout << "Enter the height of the rectangle:";
            std::cin >> height;
            if (width <= 0 || height <= 0) std::cout << "Incorrect! Try again." << std::endl;
        } while (width <= 0 || height <= 0);

        outSideRectangle_1 = (width) + 0.5;
        outSideRectangle_2 = (height) + 0.5;
    }

    void area_rectangle ()
    {
        double area = width * height;
        setArea(area);
    }

};

class Square : public Figure
{
    double ribLength;

public:
    Square()
          : ribLength(0.0)
    {
        do
        {
            std::cout << "Enter rib length of the square:";
            std::cin >> ribLength;
            if (ribLength <= 0) std::cout << "Incorrect! Try again." << std::endl;
        } while (ribLength <= 0);
        outSideRectangle_1 = ribLength + 0.5;
        outSideRectangle_2 = outSideRectangle_1;
    }

    void area_square ()
    {
        double area = ribLength * 2;
        setArea(area);
    }
};

bool is_correct_answer (std::string answer, std::string* actions)
{

    for (int i=0;i < number;++i) {
        if (answer == actions[i]) return true;
    }
    return false;
}


int main() {

    std::string actions[] = {"circle","square","triangle","rectangle","exit"};
    std::string answer;

    do {
        std::cout << "\nSelect a figure to calculate its area:" << std::endl;
        for (int i=0;i < number;++i) {
            std::cout << "-" << actions[i] << std::endl;
        }
        std::cout << ">";

        do {
            std::cin >> answer;
            if (!(is_correct_answer(answer,actions))) std::cout << "Incorrect!Repeat.\n>";
        } while (!(is_correct_answer(answer,actions)));

        if (answer == actions[0])
        {
            Circle* circle = new Circle();
            circle->area_circle();
            circle->figure_data();
            delete circle;
            circle = nullptr;
        }
        else if (answer == actions[1])
        {
            Square* square = new Square();
            square->area_square();
            square->figure_data();
            delete square;
            square = nullptr;
        }
        else if (answer == actions[2])
        {
            Triangle* triangle = new Triangle();
            triangle->area_triangle();
            triangle->figure_data();
            delete triangle;
            triangle = nullptr;
        }
        else if (answer == actions[3])
        {
            Rectangle* rectangle = new Rectangle();
            rectangle->area_rectangle();
            rectangle->figure_data();
            delete rectangle;
            rectangle = nullptr;
        }
    } while (answer != "exit");

    return 0;
}
