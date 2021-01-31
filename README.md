# ardupaddle
A CW/morse code paddle built with an atmega32u4 processor.

## Building

All following commands are to be run in the repo root.

### Toolchain setup

```sh
rustup toolchain install nightly-2021-01-07
rustup component add rust-src --toolchain nightly-2021-01-07
rustup override set nightly-2021-01-07
```