#include "stdafx.h"
#include "Box.h"
#include <algorithm>

namespace Boxes {
    Box::Box() : length(0), width(0), height(0), weight(0), value(0) {}

    Box::Box(const int& length, const int& width, const int& height, const double& weight, const int& value) {
        setLength(length);
        setWidth(width);
        setHeight(height);
        setWeight(weight);
        setValue(value);
    }

    int Box::getLength() const { return this->length; }
    int Box::getWidth() const { return this->width; }
    int Box::getHeight() const { return this->height; }
    double Box::getWeight() const { return this->weight; }
    int Box::getValue() const { return this->value; }

    void Box::setLength(const int& length)
    {
        if (length < 0) {
            throw new UnderZeroException();
        }
        this->length = length;
    }
    void Box::setWidth(const int& width)
    {
        if (width < 0) {
            throw new UnderZeroException();
        }
        this->width = width;
    }
    void Box::setHeight(const int& height)
    {
        if (height < 0) {
            throw new UnderZeroException();
        }
        this->height = height;
    }
    void Box::setWeight(const double& weight)
    {
        if (weight < 0) {
            throw new UnderZeroException();
        }
        this->weight = weight;
    }
    void Box::setValue(const int& value)
    {
        if (value < 0) {
            throw new UnderZeroException();
        }
        this->value = value;
    }

    bool Box::operator==(const Box& anotherOne) const {
        if (this == &anotherOne) {
            return true;
        }
        return (length == anotherOne.length) && (width == anotherOne.width) && (height == anotherOne.height) && (weight - anotherOne.weight <= 0.001) && (value == anotherOne.value);
    }
    std::ostream& Boxes::operator<<(std::ostream& out, const Box& box)
    {
        out << "length = " << box.getLength() << " | width = " << box.getWidth() << " | height = " << box.getHeight() << " | weight = " << box.getWeight() << " | value = " << box.getValue();
        return out;
    };
    std::istream& Boxes::operator>>(std::istream& in, Box& box) {
        int length, width, height, value;
        double weight;
        in >> length >> width >> height >> weight >> value;

        box = Box(length, width, height, weight, value);

        return in;
    };
}

using namespace Boxes;

int allValue(const std::vector <Boxes::Box>& arr) {
    int sumval = 0;
    for (const Box& box : arr)
    {
        sumval += box.getValue();
    }
    return sumval;
}

bool isBoxSizeRight(const std::vector <Boxes::Box>& arr, const int& maxsize) {
    for (const Box& box : arr)
    {
        if (box.getHeight() + box.getWidth() + box.getLength() > maxsize) {
            return false;
        }
    }
    return true;
}

double maxWeightUnderV(const std::vector <Boxes::Box>& arr, const int& maxV) {
    double max = 0;
    for (const Box& box : arr)
    {
        int V = box.getHeight() * box.getLength() * box.getWidth();
        if (max < box.getWeight() && V <= maxV) {
            max = box.getWeight();
        }
    }

    return max;
}

bool canWePutBoxes(const std::vector <Boxes::Box>& arr) {
    for (size_t i = 1; i < arr.size() ; ++i)
    {
        if ((arr[i].getLength() < arr[i-1].getLength() && arr[i].getWidth() < arr[i - 1].getWidth() && arr[i].getHeight() < arr[i - 1].getHeight()) 
            || (arr[i].getLength() > arr[i - 1].getLength() && arr[i].getWidth() > arr[i - 1].getWidth() && arr[i].getHeight() > arr[i - 1].getHeight())) {
            continue;
        }
        return false;
    }
    return true;
}