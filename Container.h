#ifndef CONTAINER_HEADER
#define CONTAINER_HEADER

#include "stdafx.h"
#include "Box.h"

namespace Boxes { //15
	class Container { //10
	private:
		std::vector <Box> arr;
		int length;
		int width;
		int height;
		double maxWeight;

	public:
		Container();
		Container(const int& length, const int& width, const int& height, const double& maxWeight); //10

		int getLength() const;
		int getWidth() const;
		int getHeight() const;
		double getWeight() const;

		int numberOfBoxes() const; //11
		double weightOfBoxes() const; //11
		int valueOfContainer() const; //11

		const Box& getBox(const size_t& i) const; //11
		int addBox(const Box& box); //11
		void removeBox(const size_t& i); //11

		Box& operator[](const size_t& i); //13
	};
	std::ostream& operator<<(std::ostream& out, const Container& container); //12 -?
	std::istream& operator>>(std::istream& in, Container& container); //12 -?
};

class OutOfMaxWeightException : public std::exception {};

class OutOfBoundsException : public std::exception {
public:
	OutOfBoundsException(const char* message) : std::exception(message) {}
	OutOfBoundsException() = default;
};

#endif