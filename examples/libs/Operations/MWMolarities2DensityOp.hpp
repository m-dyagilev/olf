#ifndef MWMOLARITIES2MEANMOLARWEIGHTOP_H
#define MWMOLARITIES2MEANMOLARWEIGHTOP_H

#include <Operation.hpp>
#include <Quantities/MoleWeights.hpp>
#include <Quantities/Molarities.hpp>

class MWMolarities2MeanMolarWeightOp : public Operation<double> {
    MoleWeights mW_;
    Molarities molarities_;
    double calc_() override {
        double sum = 0.0;
        std::vector<double>& moleWeights = mW_.get();
        std::vector<double>& molarities = molarities_.get();
        size_t numSpecs = moleWeights.size();
        for (size_t i = 0; i < numSpecs; ++i) {
            sum += molarities[i] * moleWeights[i];
        }
        return sum;
    }
public:
    bool checkPrerequisites() override {
        // Здесь же нужны и логические проверки. Вдруг вектора разной длины?
        return (mW_ && molarities_);
    }

    void setMW(MoleWeights mW) {
        mW_ = mW;
    }

    void setMolarities(Molarities molarities) {
        molarities_ = molarities_;
    }
};

#endif
