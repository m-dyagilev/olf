#ifndef DMOLARITIES2MEANMOLARWEIGHTOP_H
#define DMOLARITIES2MEANMOLARWEIGHTOP_H

#include <Operation.hpp>
#include <Quantities/Density.hpp>
#include <Quantities/Molarities.hpp>

class DMolarities2MeanMolarWeightOp : public Operation<double> {
    Density d_;
    Molarities molarities_;
    double calc_() override {
        double sum = 0.0;
        std::vector<double>& molarities = molarities_.get();
        size_t numSpecs = molarities.size();
        for (size_t i = 0; i < numSpecs; ++i) {
            sum += molarities[i];
        }
        return d_.get() / sum;
    }
public:
    bool checkPrerequisites() override {
        // Здесь же нужны и логические проверки. Вдруг вектора разной длины?
        return (d_ && molarities_);
    }

    void setD(Density d) {
        d_ = d;
    }

    void setMolarities(Molarities molarities) {
        molarities_ = molarities;
    }
};

#endif
