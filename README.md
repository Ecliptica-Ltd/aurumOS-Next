<h1 align="center">
  aurumOS Next
  <svg xmlns="http://www.w3.org/2000/svg" height="18px" viewBox="0 -960 960 960" width="26px" fill="#7CA7D8"><path d="M600-160q-134 0-227-93t-93-227q0-134 93-227t227-93q134 0 227 93t93 227q0 134-93 227t-227 93Zm-306-12q-113-14-183.5-103.5T40-480q0-115 70.5-204.5T294-788v58q-88 16-141 87.5T100-480q0 91 53 162.5T294-230v58Zm306-308Zm0 260q107 0 183.5-76.5T860-480q0-107-76.5-183.5T600-740q-107 0-183.5 76.5T340-480q0 107 76.5 183.5T600-220Z"/></svg>
</h1>

<div align="center">

![GitHub License](https://img.shields.io/github/license/Ecliptica-Ltd/aurumOS-Next?style=for-the-badge&logo=github&logoColor=%237CA7D8&label=License&labelColor=black&color=black)
![GitHub Issues](https://img.shields.io/github/issues/Ecliptica-Ltd/aurumOS-Next?style=for-the-badge&logo=github&logoColor=%237CA7D8&label=Issues&labelColor=black&color=black)
<!-- ![SourceForge Downloads](https://img.shields.io/sourceforge/dw/aurum-os-next?style=for-the-badge&logo=sourceforge&logoColor=%237CA7D8&label=Downloads&labelColor=black&color=black) -->

</div>

## Description

**[aurumOS Next](https://aurumos.site/next)** is a highly secure, efficient, and portable Unix-like operating system based on NetBSD. 
Designed to meet modern computing needs, it is adaptable for various platforms, from servers and desktops 
to embedded systems. This repository contains the tools and configurations needed to build aurumOS Next, 
making it ideal for developers seeking a highly customizable NetBSD-based OS.

## Building

You can cross-build aurumOS Next from most UNIX-like operating systems. 
To build for `amd64` (x86_64), run the following command in the repository's root directory:

```sh
./build.sh -U -u -j4 -m amd64 -O ~/obj release
```

Additional build information is available in the [BUILDING](BUILDING) file.

## Binaries

- [Daily builds](https://github.com/Ecliptica-Ltd/aurumOS-Next/actions)
- [Releases](https://github.com/Ecliptica-Ltd/aurumOS-Next/releases)

## Troubleshooting

Report bugs and patches via the issue tracker.
Join the community discussion on aurumOS forums.

## Latest Sources
To fetch the sources for aurumOS Next:
```bash
git clone https://github.com/Ecliptica-Ltd/aurumOS-Next.git
```
