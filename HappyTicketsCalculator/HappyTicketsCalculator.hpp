#ifndef HAPPY_TICKETS_CALCULATOR_HPP_
#define HAPPY_TICKETS_CALCULATOR_HPP_

#include <iostream>
#include <stdexcept>
#include "types.hpp"

class HappyTicketsCalculator {
 public:
    static i128 CalculateHappyTicketsNumber(u32 number_size, u32 notation);

 private:
    static i128 CfromNtoK(i128 n, i128 k);

};

std::ostream& operator<<(std::ostream& os, i128 val);

#endif  // HAPPY_TICKETS_CALCULATOR_HPP_
