#include <chem.hpp>

#include <iostream>
#include <vector>

int main() {
    // H, He, N
    std::vector<double> mwVec = {1.008, 4.002602, 14.007};
    MoleWeights mw;
    mw.set(mwVec);
    std::vector<double> massFVec = {0.04, 0.06, 0.9};
    MassFractions massF;
    massF.set(massFVec);
    std::vector<double> moleFVec = {0.04, 0.06, 0.9};
    MoleFractions moleF;
    moleF.set(moleFVec);
    MWMoleF2MeanMolarWeightOp op1;
    op1.setMW(mw);
    op1.setMoleF(moleF);
    try {
        std::cout << "Mean molar weight 1 : " << op1.apply() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    MWMassF2MeanMolarWeightOp op2;
    op2.setMW(mw);
    op2.setMassF(massF);
    try {
        std::cout << "Mean molar weight 2 : " << op2.apply() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
