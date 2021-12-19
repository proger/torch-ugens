#pragma once

#include <memory>
#include <torch/script.h>

#include "SC_PlugIn.hpp"


namespace TorchUGens {

class Torch : public SCUnit {
public:
    Torch();
    ~Torch();

private:
    int loadScript(const char *filename);
    void next(int nSamples);

    torch::jit::Module module;
    int i;
    int bufferSamples;
    at::Tensor buffer;
};

} // namespace TorchUGens
