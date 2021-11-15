#include <iostream>
#include <iomanip>

// Komplettering: Sätt const på parametrar om de inte behöver ändras.
float count_VAT(float const price, float const percentage)
  {
    return (price * percentage / 100);
  }

float count_total(float const price, float const VAT)
  {
    return (price + VAT);
  }

int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "INMATNINGSDEL\n=============\n";
    float first{-1};
    float last{-1};
    double step{-1};
    float VATpercentage{-1};

    // Kommentar: Ni hade fått enklare kod om ni använde en do-while.
    while (first < 0) {
        std::cout << "Mata in f\x94rsta pris: ";
        std::cin >> first;
        if (first < 0) {
            std::cout << "FEL: F\x94rsta pris m\x86ste vara minst 0 (noll) kronor\n";
        }
    }
    while (last <= first) {
        std::cout << "Mata in sista pris: ";
        std::cin >> last;
        if (last <= first) {
          std::cout << "FEL: Sista pris m\x86ste \x94verstiga f\x94rsta pris\n" ;
        }
    }
    while (step < 0.01) {
        std::cout << "Mata in stegl\x84ngd: ";
        std::cin >> step;
        if (step < 0.01) {
            std::cout << "FEL: Stegl\x84ngd m\x86ste vara minst 0.01\n";
        }
    }
    while (VATpercentage < 0 or VATpercentage > 100) {
        std::cout << "Mata in momsprocent: ";
        std::cin >> VATpercentage;
        if  (VATpercentage < 0 or VATpercentage > 100) {
            std::cout << "FEL: Momsprocent m\x86ste vara mellan 0 och 100\n";
        }
    }

    // Komplettering: Vid radbrytning, lägg operatorn på nästa rad och indentera så
    // att operatorerna hamnar ovanför varandra. T.ex.
    // std::cout << "Här skriver jag ut en väldigt lång rad som inte riktigt ryms "
    //           << "på en rad, så jag måste radbryta och indentera i koden.";
    std::cout << "MOMSTABELLEN\n============\n"
              << std::setw(10) << "Pris" << std::setw(15)
              << "Moms" << std::setw(20) << "Pris med moms\n"
              << std::setfill('-') << std::setw(45) << "\n";

    while (first <= last) {

        float VAT = count_VAT(first, VATpercentage);
        std::cout << std::setfill(' ') << std::setw(10)
                  << first << std::setw(15) << VAT
                  << std::setw(19)
        // Komplettering: Även beräkning av pris inkl. moms ska vara ett underprogram.
        // Se lab-PM.
                  << count_total(first, VAT) << std::endl;
        first += step;
    }
}
