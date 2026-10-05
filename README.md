# benfetch

A small system information tool for Linux, written in C++. It prints a quick summary of your system in the terminal.

![screenshot](<img width="2015" height="1235" alt="benfetch" src="https://github.com/user-attachments/assets/0c94381e-fc8b-4fc9-9a41-e93a15f0009c" />)

## What it shows

- Username
- OS
- Kernel version
- RAM usage
- GPU
- Username

## Requirements

- Linux
- `g++` (C++11 or newer)
- `make`
- libpci development headers

Install the dependencies:

**Fedora**
```
sudo dnf install gcc-c++ make pciutils-devel
```

**Debian / Ubuntu**
```
sudo apt install g++ make libpci-dev
```

**Arch**
```
sudo pacman -S gcc make pciutils
```

## Build

```
git clone https://github.com/Ben-Grogan/benfetch.git
cd benfetch
make
```

## Run

```
./benfetch
```

## Install (optional)

```
sudo cp benfetch /usr/local/bin/
```



## Known limitations

- On laptops with hybrid graphics, the GPU shown is the first one found, not necessarily the one currently rendering.
