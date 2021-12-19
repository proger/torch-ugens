// PluginTorch.cpp
// Vol Ki (proger@wilab.org.ua)

#include "SC_PlugIn.hpp"
#include "Torch.hpp"

static InterfaceTable* ft;

namespace Torch {

Torch::Torch() {
    mCalcFunc = make_calc_function<Torch, &Torch::next>();
    next(1);
}

void Torch::next(int nSamples) {
    const float* input = in(0);
    const float* gain = in(1);
    float* outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain[i];
    }
}

} // namespace Torch

PluginLoad(TorchUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<Torch::Torch>(ft, "Torch", false);
}
