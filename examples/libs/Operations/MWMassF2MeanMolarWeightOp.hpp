#ifndef MWMASSF2MEANMOLARWEIGHTOP_H
#define MWMASSF2MEANMOLARWEIGHTOP_H

#include <Operation.hpp>
#include <Quantities/MoleWeights.hpp>
#include <Quantities/MassFractions.hpp>

class MWMassF2MeanMolarWeightOp : public Operation<double> {
    MoleWeights mW_;
    MassFractions massF_;
    double calc_() override {
        double sum = 0.0;
        std::vector<double>& moleWeights = mW_.get();
        std::vector<double>& massFractions = massF_.get();
        size_t numSpecs = moleWeights.size();
        for (size_t i = 0; i < numSpecs; ++i) {
            sum += massFractions[i] / moleWeights[i];
        }
        return 1 / sum;
    }
public:
    bool checkPrerequisites() override {
        // Здесь же нужны и логические проверки. Вдруг вектора разной длины?
        return (mW_ && massF_);
    }

    void setMW(MoleWeights mW) {
        mW_ = mW;
    }

    void setMassF(MassFractions massF) {
        massF_ = massF;
    }
};

#endif
