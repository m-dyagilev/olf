#ifndef QUANTITY_HPP
#define QUANTITY_HPP

template<typename T>
class Quantity {
    T value_;
    bool isSet_ = false;
public:
    operator bool() {
        return isSet_;
    }

    void set(T value) {
        value_ = value;
        isSet_ = true;
    }

    T& get() {
        return value_;
    }
};

#endif
