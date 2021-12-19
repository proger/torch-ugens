# Torch for SuperCollider

Forward samples through PyTorch models.

### Building

```
git clone https://github.com/proger/torch-ugen
cd torch-ugen

rm -rf build
mkdir build && cd build && cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/share/SuperCollider/Extensions -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release --target install -v
```

You need CMake >= 3.12 and SuperCollider source code.

It's expected that the SuperCollider repo is cloned at `../supercollider` relative to this repo. If
it's not: add the option `-DSC_PATH=/path/to/sc/source`.

## References

- Prototype plugin: https://github.com/xavriley/qlibugens (thanks for showing me this @xavriley!)
- [SuperCollider plugin tutorial](https://scsynth.org/t/tutorial-supercollider-server-plugins-in-c/3449)
- [Sonic Pi Synth Design](https://github.com/sonic-pi-net/sonic-pi/blob/dev/SYNTH_DESIGN.md)
- [RAVE waveform model](https://github.com/caillonantoine/RAVE)
- [NASH hackathon by @benhayesmusic](https://twitter.com/benhayesmusic/status/1469344561352880130)
