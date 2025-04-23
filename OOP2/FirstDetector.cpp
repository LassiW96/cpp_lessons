#include <iostream>
#include "FirstDetector.hh"

FirstDetector::FirstDetector() : fID(0) {}

FirstDetector::~FirstDetector() {}

void FirstDetector::Initialize() {
    fID = 96;
}

void FirstDetector::PrintStatus() const {
    std::cout << "Detector ID: " << fID << std::endl;
}