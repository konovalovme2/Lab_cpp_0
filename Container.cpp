#include "stdafx.h"
#include "Container.h"

namespace Boxes {
	Container::Container(): length(0), width(0), height(0), maxWeight(0) {}

	Container::Container(const int& length, const int& width, const int& height, const double& maxWeight) {
		if (length < 0) {
			throw UnderZeroException("Length less than zero");
		}
		if (width < 0) {
			throw UnderZeroException("Width less than zero");
		}
		if (height < 0) {
			throw UnderZeroException("Height less than zero");
		}
		if (maxWeight < 0) {
			throw UnderZeroException("Weight less than zero");
		}

		this->length = length;
		this->width = width;
		this->height = height;
		this->maxWeight = maxWeight;
	}

	int Container::getLength() const { return this->length; }
	int Container::getWidth() const { return this->width; }
	int Container::getHeight() const { return this->height; }
	double Container::getWeight() const { return this->maxWeight; }

	int Container::numberOfBoxes() const {
		return arr.size();
	}
	double Container::weightOfBoxes() const {
		double sumWeight = 0;
		for (const Box& box : arr)
		{
			sumWeight = sumWeight + box.getWeight();
		}
		return sumWeight;
	}
	int Container::valueOfContainer() const {
		return allValue(arr);
	}

	const Box& Container::getBox(const size_t& i) const {
		return arr[i];
	}
	int Container::addBox(const Box& box) {
		if (weightOfBoxes() + box.getWeight() <= this->maxWeight) {
			arr.push_back(box);
			return numberOfBoxes() - 1;
		}
		else {
			throw OutOfMaxWeightException();
		}
	}
	void Container::removeBox(const size_t& i) {
		if (numberOfBoxes() == 0) {
			throw OutOfBoundsException("The container was empty, you can't delete any element here");
		}
		arr.erase(arr.begin() + i);
	}

//#ifdef WINDOWS || LINUX
//#define ENDL '\n'
//#elif MAC_OS
//#define ENDL '\r' 
//#endif

	std::ostream& operator<<(std::ostream& out, const Container& container) {
		out << "Length of container = " << container.getLength()
			<< "| Width of container = " << container.getWidth()
			<< "| Height of container = " << container.getHeight()
			<< "| Maximum acceptable weight of container = " << container.getWeight() << std::endl;
		for (size_t i = 0; i < container.numberOfBoxes(); i++) {
			out << i << ": " << container.getBox(i) << std::endl;
		}

		return out;
	}
	std::istream& operator>>(std::istream& in, Container& container) {
		Box box;
		int length;
		int width;
		int height;
		double maxWeight;
		size_t numberOfBoxes;

		in >> numberOfBoxes >> length >> width >> height >> maxWeight;
		container = Container(length, width, height, maxWeight);

		for (size_t i = 0; i < numberOfBoxes; i++)
		{
			in >> box;
			try {
				container.addBox(box);
			}
			catch(OutOfMaxWeightException& e){
				std::cout << "Please rewrite data. You entered the too big weight for last box!" << std::endl;
				break;
			}
		}
		return in;
	}

	Box& Container::operator[](const size_t& i) {
		return this->arr[i];
	}
}

