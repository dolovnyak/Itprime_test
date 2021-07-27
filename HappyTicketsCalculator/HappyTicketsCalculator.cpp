#include "HappyTicketsCalculator.hpp"
#include "utilities.hpp"

#define MINUS_ONE_POW(n) ((n % 2 == 0) ? (1) : (-1))

/**
 * @brief n! / ((n - k)! * k!)
 */
i128 HappyTicketsCalculator::CfromNtoK(i128 n, i128 k) {
    if (n < k) { throw std::runtime_error("CfromNtoK - n never could be less than k"); }
    if (k == 0) return 1;
    i128 prev = 1;
    i128 reduced_factorial_n = 1;
    for (i128 reduced_factorial_number = n - k + 1; reduced_factorial_number <= n; ++reduced_factorial_number) {
        reduced_factorial_n *= reduced_factorial_number;
        if (reduced_factorial_n / reduced_factorial_number != prev) {
            throw std::runtime_error("overflow exception");
        }
        prev = reduced_factorial_n;
    }
    return reduced_factorial_n / factorial(k);
}

/**
 * @brief:  solution through general formula using inclusions/exclusions
 */
i128 HappyTicketsCalculator::CalculateHappyTicketsNumber(u32 number_size, u32 notation) {
    if (notation < 2 || number_size < 2) {
        throw std::runtime_error("number_size or notation could be only >= 2");
    }
    i128 n = static_cast<i128>(number_size / 2);
    i128 m = static_cast<i128>(notation);

    i128 maxK = ((m - 1) * n) / m;
    i128 res = 0;

    for (i128 k = 0; k <= maxK; ++k) {
        res += MINUS_ONE_POW(k) * CfromNtoK(n * 2, k) * CfromNtoK((m - 1) * n + 2 * n - 1 - m * k, 2 * n - 1); // Possible overflow, but for 13 in 13 - ok
    }
    if (number_size % 2 != 0) {
        res *= notation;
    }
    return res;
}

/**
 * @brief:  correct output __int128
 */
std::ostream& operator<<(std::ostream& os, i128 val)
{
    if (val < 0) {
        os << '-';
        val *= -1;
    }
    i128 tmp = 0;
    while (val != 0) {
        tmp *= 10;
        tmp += val % 10;
        val /= 10;
    }
    while (tmp != 0) {
        os << static_cast<u32>(tmp % 10);
        tmp /= 10;
    }
    return os;
}
