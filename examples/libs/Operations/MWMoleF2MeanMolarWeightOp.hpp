#ifndef MWMOLEF2MEANMOLARWEIGHTOP_H
#define MWMOLEF2MEANMOLARWEIGHTOP_H

#include <Operation.hpp>
#include <Quantities/MoleWeights.hpp>
#include <Quantities/MoleFractions.hpp>

class MWMoleF2MeanMolarWeightOp : public Operation<double> {
    MoleWeights mW_;
    MoleFractions moleF_;
    double calc_() override {
        double sum = 0.0;
        std::vector<double>& moleWeights = mW_.get();
        std::vector<double>& moleFractions = moleF_.get();
        size_t numSpecs = moleWeights.size();
        for (size_t i = 0; i < numSpecs; ++i) {
            sum += moleFractions[i] * moleWeights[i];
        }
        return sum;
    }
public:
    bool checkPrerequisites() override {
        // Здесь же нужны и логические проверки. Вдруг вектора разной длины?
        return (mW_ && moleF_);
    }

    void setMW(MoleWeights mW) {
        mW_ = mW;
    }

    void setMoleF(MoleFractions moleF) {
        moleF_ = moleF;
    }
};

#endif
