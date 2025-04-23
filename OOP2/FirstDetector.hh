#ifndef FIRSTDETECTOR_H
#define FIRSTDETECTOR_H

class FirstDetector {
public:
    FirstDetector();
    ~FirstDetector();

    void Initialize();
    void PrintStatus() const;

private:
    int fID;
};

#endif