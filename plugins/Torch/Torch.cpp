#include "SC_PlugIn.hpp"
#include "Torch.hpp"

static InterfaceTable* ft;

namespace TorchUGens {

Torch::Torch() {
    mCalcFunc = make_calc_function<Torch, &Torch::next>();

    next(1);
}

Torch::~Torch() {
}

} // namespace TorchUGens

PluginLoad(TorchUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<TorchUGens::Torch>(ft, "Torch", true);
}
