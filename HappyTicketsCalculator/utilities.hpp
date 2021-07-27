#ifndef UTILITIES_HPP
#define UTILITIES_HPP

template<class T>
T factorial(T val) {
    if (val < 2) { return val; }
    return val * factorial(val - 1);
}

#endif  // UTILITIES_HPP
