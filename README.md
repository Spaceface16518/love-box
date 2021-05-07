# Love Box

A little box that displays quotes on an e-ink screen.

Made with Raspberry Pi Pico and Waveshare Pico e-Paper screen.

## Usage

### Sources

Clone the repository.

```shell
git clone "https://github.com/Spaceface16518/love-box.git"
```

### Dependencies

- [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)  
  `pico_sdk_import.cmake` is able to import the pico sdk for you if you don't already have `PICO_SDK_PATH` defined.
- [Waveshare Pico e-Paper library](https://www.waveshare.com/w/upload/2/27/Pico_ePaper_Code.zip) (Warning: high chance
  of bit-rot. Try looking around [the relevant wiki](https://www.waveshare.com/wiki/Pico-ePaper-2.9) for "demo codes")  
  Copy the `lib` directory from the archive into the project root.

*NOTE: I would vendor the e-Paper libraries directly in the repository but I can't find a license for them.*

### Build

Love Box is built using [CMake](https://cmake.org/). You will also need the arm-none-eabi gcc toolchain.

```shell
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi
```

```shell
cmake --build . --target love_box
```

This will build UF2 files that you can drop into the Pico.
