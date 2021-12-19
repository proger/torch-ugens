// PluginTorch.hpp
// Vol Ki (proger@wilab.org.ua)

#pragma once

#include "SC_PlugIn.hpp"

namespace Torch {

class Torch : public SCUnit {
public:
    Torch();

    // Destructor
    // ~Torch();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace Torch
