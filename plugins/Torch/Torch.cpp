#include <iostream>
#include "Torch.hpp"

#include "SC_PlugIn.hpp"

static InterfaceTable* ft;

namespace TorchUGens {

Torch::Torch() {
#if 0
    auto unit = this;

    int filenameSize = (int)in0(2); // number of chars in the filename string
    char *filename = (char*)RTAlloc(this->mWorld, (filenameSize + 1) * sizeof(char));

    for (int i = 0; i < filenameSize; i++) {
        filename[i] = (char)IN0(3 + i);
    }
#else
    const char *filename = "/home/proger/RAVE/speech/speech_realtime.ts";
#endif

    loadScript(filename);
    mCalcFunc = make_calc_function<Torch, &Torch::next>();
}

Torch::~Torch() = default;

} // namespace TorchUGens

PluginLoad(TorchUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<TorchUGens::Torch>(ft, "Torch", true);
}
