# Torch for SuperCollider

Forward samples through PyTorch models

### Requirements

- CMake >= 3.5
- SuperCollider source code

### Building

Clone the project:

    git clone https://github.com/proger/torch-ugen
    cd torch-ugen
    mkdir build
    cd build

Then, use CMake to configure and build it:

    cmake .. -DCMAKE_BUILD_TYPE=Release
    cmake --build . --config Release
    cmake --build . --config Release --target install

You may want to manually specify the install location in the first step to point it at your
SuperCollider extensions directory: add the option `-DCMAKE_INSTALL_PREFIX=/path/to/extensions`.

It's expected that the SuperCollider repo is cloned at `../supercollider` relative to this repo. If
it's not: add the option `-DSC_PATH=/path/to/sc/source`.

### Developing

Use the command in `regenerate` to update CMakeLists.txt when you add or remove files from the
project. You don't need to run it if you only change the contents of existing files. You may need to
edit the command if you add, remove, or rename plugins, to match the new plugin paths. Run the
script with `--help` to see all available options.

## References

- Prototype plugin by @xavriley: https://github.com/xavriley/qlibugens
- [SuperCollider plugin tutorial](https://scsynth.org/t/tutorial-supercollider-server-plugins-in-c/3449)
- [Sonic Pi Synth Design](https://github.com/sonic-pi-net/sonic-pi/blob/dev/SYNTH_DESIGN.md)
- [RAVE waveform model](https://github.com/caillonantoine/RAVE)
- [NASH hackathon by @benhayesmusic](https://twitter.com/benhayesmusic/status/1469344561352880130)
