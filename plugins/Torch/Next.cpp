#include <memory>
#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include "Torch.hpp"

// references:
// https://scsynth.org/t/tutorial-supercollider-server-plugins-in-c/3449/10
// https://pytorch.org/cppdocs/api/function_namespacetorch_1a3e6645190c2bff2c40f5ce87ea828011.html

namespace TorchUGens {

using Module = torch::jit::Module;

int Torch::loadScript(const char *filename) {
    this->module = torch::jit::load(filename);
    this->i = 0;
    this->bufferSamples = 0;
    return 0;
}

void Torch::next(int nSamples) {
    const float temperature = in0(1);
    const float* input = in(0);
    float* outbuf = out(0);

    if (this->buffer.size(-1) == 0 || (this->i*nSamples % this->bufferSamples) == 0) {
        // TODO: do this in a separate thread because I can hear the jitters
        Module &module = this->module;

        std::vector<torch::jit::IValue> inputs;
        inputs.push_back(torch::ones({1, 1, 64})*temperature);

        auto x = module.get_method("decode")({module.get_method("prior")(inputs).toTensor()});
        at::Tensor output = at::squeeze(x.toTensor());
        this->bufferSamples = output.size(-1);
        this->buffer = output;
        std::cout << "have " << this->bufferSamples << " newly buffered samples to play\n";
    }

    for (int i = 0; i < nSamples; i++) {
        outbuf[i] = this->buffer[(this->i*nSamples + i)%this->bufferSamples].item<float>() * input[i];
    }
    this->i++;
}

} // namespace TorchUGens
