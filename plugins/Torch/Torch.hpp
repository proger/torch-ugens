#pragma once

#include "SC_PlugIn.hpp"

namespace TorchUGens {

class Torch : public SCUnit {
public:
    Torch();
    ~Torch();

private:
    void next(int nSamples);
};

} // namespace TorchUGens
