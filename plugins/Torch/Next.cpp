#include <torch/torch.h>
#include "Torch.hpp"

// references:
// https://scsynth.org/t/tutorial-supercollider-server-plugins-in-c/3449/10
// https://pytorch.org/cppdocs/api/function_namespacetorch_1a3e6645190c2bff2c40f5ce87ea828011.html

namespace TorchUGens {

void Torch::next(int nSamples) {
    auto unit = this;
    const float* input = in(0);
    float* outbuf = out(0);

    torch::Tensor tensor = torch::rand({ nSamples });

    for (int i = 0; i < nSamples; i++) {
        outbuf[i] = tensor[i].item<float>() * input[i];
    }
}

} // namespace TorchUGens
