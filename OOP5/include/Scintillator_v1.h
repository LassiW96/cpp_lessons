# ifndef SCINTILLATOR_H
# define SCINTILLATOR_H

# include <string>
# include <vector>
# include <tuple>

class Scintillator_v1 {
public : 
    bool ReadDatabase(const std::string& filename); // Read the database file and store (X,Y,Z,fADC) tuples internally
    void PrintData() const; // Print all entries to the console

private : 
    std::vector<std::tuple<double, double, double, double>> data_; // Store each record in the vector as (X,Y,Z,fADC)
};

# endif
