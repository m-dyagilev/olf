#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <functional>
#include <stdexcept>

template<typename T>
class Operation {
protected:
    virtual T calc_();
    virtual bool checkPrerequisites();
public:
    T apply() {
        if (checkPrerequisites()) {
            return calc_();
        }
        else {
            throw std::logic_error("Prerequisites are not met"); // Подробности?
        }
    }
};

#endif