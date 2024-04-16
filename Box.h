#ifndef HEADER
#define HEADER

#include "stdafx.h";

/*struct Box {
    int length;
    int width;
    int height;
    double weight;
    int value;

    Box();
    Box(int length, int width, int height, double weight, int value);
    
    bool operator==(const Box& anotherOne);//6
    friend std::ostream& operator<<(std::ostream& out, const Box& anotherOne);//7
    Box& operator>>(std::istream& in);//7
};*/

namespace Boxes { //15
    class Box{ //9
    private:
        int length;
        int width;
        int height;
        double weight;
        int value;

    public:
        Box();
        Box(const int& length, const int& width, const int& height, const double& weight, const int& value);

        int getLength() const;
        int getWidth() const;
        int getHeight() const;
        double getWeight() const;
        int getValue() const;

        void setLength(const int& length);
        void setWidth(const int& width);
        void setHeight(const int& height);
        void setWeight(const double& weight);
        void setValue(const int& value);

        bool operator==(const Box& anotherOne) const;//6
    };

    std::ostream& operator<<(std::ostream& out, const Box& box);//7 - ?
    std::istream& operator>>(std::istream& in, Box& box);//7 - ?
}

int allValue(const std::vector <Boxes::Box>& arr);//2

bool isBoxSizeRight(const std::vector <Boxes::Box>& arr, const int& maxsize);//3

double maxWeightUnderV(const std::vector <Boxes::Box>& arr, const int& maxV);//4

bool canWePutBoxes(const std::vector <Boxes::Box>& arr);//5

class UnderZeroException : public std::exception {
public:
    UnderZeroException(const char* message) : std::exception(message) {}
    UnderZeroException() = default;
};

#endif