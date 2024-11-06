#ifndef MOLEFMMWD2MOLARITIESOP_H
#define MOLEFMMWD2MOLARITIESOP_H

#include <Operation.hpp>
#include <Quantities/MoleFractions.hpp>
#include <Quantities/MeanMolarWeight.hpp>
#include <Quantities/Density.hpp>
#include <Quantities/Molarities.hpp>

class MoleFMMWD2MolaritiesOp : public Operation<std::vector<double>> {
    MoleFractions moleF_;
    MeanMolarWeight mMW_;
    Density d_;
    std::vector<double> calc_() override {
        std::vector<double> result;
        std::vector<double>& moleFractions = moleF_.get();
        double meanMolarWeight = mMW_.get();
        double density = d_.get();
        double coeff = density / meanMolarWeight;
        for (double x : moleFractions) {
            result.push_back(x * coeff);
        }
        return result;
    }
public:
    bool checkPrerequisites() override {
        return (moleF_ && mMW_ && d_);
    }

    void setMoleFractions(MoleFractions moleF) {
        moleF_ = moleF;
    }

    void setD(Density d) {
        d_ = d;
    }

    void setMMW(MeanMolarWeight mMW) {
        mMW_ = mMW;
    }
};

#endif
