#include <iostream>
#include "SecondDetector.hh"

SecondDetector::SecondDetector() : fID(0) {}

SecondDetector::~SecondDetector() {}

void SecondDetector::Initialize() {
    fID = 96;
}

void SecondDetector::PrintStatus() const {
    std::cout << "Detector ID: " << fID << std::endl;
}
