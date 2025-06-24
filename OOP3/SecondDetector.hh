#ifndef SECONDDETECTOR_H
#define SECONDDETECTOR_H

class SecondDetector {
public:
    SecondDetector();
    ~SecondDetector();

    void Initialize();
    void PrintStatus() const;

private:
    int fID;
};

#endif
