# ifndef DETECTOR_H
# define DETECTOR_H

# include <string>
# include <vector>
# include <tuple>

class Detector {
public :
    Detector(); // Constructor
    virtual ~Detector(); // Destructor

    virtual bool ReadDatabase(const std::string& filename); // Load data from a file
    virtual void ApplyPedestalCorrections(double pedestal); // Apply pedestal corrections to fADC values
    virtual void PrintSummary() const;

protected : 
    std::vector<std::tuple<double, double, double, double>> data_; // Vector to store detector records
    double pedestal_; // Track pedestal value
};

# endif
