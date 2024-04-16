#include "stdafx.h"
#include "Box.h"
#include "Container.h"
using namespace Boxes;

int main()
{
    int size, maxarr1, maxarr2, maxV1, maxV2;
    Box a, b;

    size = 3;

    std::vector<Boxes::Box> arr(size);

    arr[0] = Box(1,2,3,4,5);
    arr[1] = Box(6,7,8,9,10);
    arr[2] = Box(11,12,13,14,15);
    std::cout << "Array of Boxes:" << std::endl << arr[0] << std::endl << arr[1] << std::endl << arr[2] << std::endl;

    int k = allValue(arr);
    std::cout << "Sum value of array: " << k  << std::endl;
    if (k == 30) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }


    maxarr1 = 36;
    maxarr2 = 35;
    maxV1 = 336;
    maxV2 = 335;

    bool flag = isBoxSizeRight(arr, maxarr1);
    std::cout << "The maximum sum of length, width and height of boxes: " + maxarr1;
    std::cout << "Is the original lower then this sum: " << isBoxSizeRight(arr, maxarr1) << std::endl;
    if (flag) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }
    
    flag = isBoxSizeRight(arr, maxarr2);
    std::cout << "The another maximum sum of length, width and height of boxes: " + maxarr2;
    std::cout << "Is the original lower then this sum: " << isBoxSizeRight(arr,maxarr2) << std::endl;
    if (!flag) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }

    double check = maxWeightUnderV(arr, maxV1);
    std::cout << "The maxV parametr: " + maxV1;
    std::cout << "Maximum weight: " << check << std::endl;
    if (check == 9) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }

    check = maxWeightUnderV(arr, maxV2);
    std::cout << "The maxV parametr: " + maxV2;
    std::cout << "Maximum weight: " << check << std::endl;
    if (check == 4) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }

    flag = canWePutBoxes(arr);
    std::cout << "Can we put all boxes in each one? " << flag << std::endl;
    if (flag) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }

    arr.push_back(Box(3,2,1,2,3));
    flag = canWePutBoxes(arr);
    std::cout << "Can we put all boxes in each one? " << flag << std::endl;
    if (!flag) {
        std::cout << "[OK]" << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
    }

    a = Box(1, 1, 2, 3, 4);
    b = Box(1, 1, 2, 3, 4);
    std::cout << "Enter two boxes: \n1: " << a << std::endl;
    std::cout << "2: " << b << std::endl;
    if (a == b) {
        std::cout << "[OK] They are same" << std::endl;
    }
    else {
        std::cout << "[FAIL] They are different" << std::endl;
    }

    b = Box(1, 1, 3, 3, 4);
    std::cout << "Enter two boxes: \n1: " << a << std::endl;
    std::cout << "2: " << b << std::endl;
    if (a == b) {
        std::cout << "[FAIL] They are same" << std::endl;
    }
    else {
        std::cout << "[OK] They are different" << std::endl;
    }
    
    Container oneContainer = Container(67,91,35,46);
    oneContainer.addBox(arr[0]);
    oneContainer.addBox(arr[1]);
    oneContainer.addBox(arr[2]);
    std::cout << "Created the container and added the array of boxes" << std::endl << oneContainer << std::endl;

    std::cout << "Number of boxes is:" << oneContainer.numberOfBoxes() << std::endl;
    std::cout << "Sum weight of boxes is:" << oneContainer.weightOfBoxes() << std::endl;
    std::cout << "Sum value of boxes is:" << oneContainer.valueOfContainer() << std::endl;
    std::cout << "The box with index 0: " << oneContainer.getBox(0) << std::endl;
    std::cout << "Add new box that we can add with weight: " << oneContainer.addBox(Box(1,2,3,19,25)) << std::endl;
    std::cout << "Add new box that we can't add with weight: "; 
    
    try {
        oneContainer.addBox(Box(1, 2, 3, 1, 25));
    }
    catch(OutOfMaxWeightException& e){
        std::cout << "[OK] Exception was thrown" << std::endl;
    }

    oneContainer.removeBox(2);
    std::cout << oneContainer[2] << std::endl;
    oneContainer[2] = arr[2];
    std::cout << oneContainer[2] << std::endl;

    Container twoContainer;

    std::cin >> twoContainer;
    std::cout << twoContainer;
    return 0;
}
