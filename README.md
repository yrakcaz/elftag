[![CI](https://github.com/yrakcaz/elftag/actions/workflows/ci.yml/badge.svg)](https://github.com/yrakcaz/elftag/actions/workflows/ci.yml)
[![MIT License](https://img.shields.io/github/license/yrakcaz/elftag?color=blue)](./LICENSE)

# elftag

A command-line ELF64 binary analysis tool written in C++11. Displays ELF headers, lists sections, and disassembles x86-64 code using the udis86 library (AT&T syntax).

## Requirements

- udis86 (`libudis86-dev`)
- g++ or clang++ with C++11 support

On Debian/Ubuntu:

```
apt install libudis86-dev
```

## Build

```
./configure && make
```

Options:

- `--with-debug` — enable debug symbols (`-g3`)
- `--with-clang` — compile with clang++ instead of g++
- `--prefix=DIR` — set install directory (default: `/usr/local`)

## Install

```
make install
```

To uninstall:

```
make uninstall
```

## Usage

```
elftag [options] <file>
```

| Option | Description |
|---|---|
| `-d`, `--display-header` | Display the ELF64 header |
| `-s`, `--display-sections` | List ELF64 sections |
| `-a`, `--disass` | Disassemble the `.text` section (AT&T syntax) |
| `-h`, `--help` | Show help |

## Examples

Display the ELF header:

```
elftag -d /bin/ls
```

List sections:

```
elftag -s /bin/ls
```

Disassemble:

```
elftag -a /bin/ls
```

Combine options:

```
elftag -d -s -a /bin/ls
```

