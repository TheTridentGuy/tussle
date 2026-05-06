# tussle

My personal fork of [fuzzel](https://codeberg.org/dnkl/fuzzel)

## Requirements

### Runtime

* pixman
* wayland (_client_ and _cursor_ libraries)
* xkbcommon
* cairo (optional, required by librsvg)
* libpng (optional)
* librsvg (optional, for enhanced SVG icon support)
* [fcft](https://codeberg.org/dnkl/fcft) [^1]

Fuzzel uses the builtin nanosvg backend to render SVG icons by
default. Since nanosvg is somewhat limited, we also offer a librsvg
backend for SVG icons. Note that librsvg also requires cairo.

[^1]: can also be built as subprojects, in which case they are
statically linked.


### Building

* meson
* ninja
* wayland protocols
* scdoc
* [tllist](https://codeberg.org/dnkl/tllist) [^1]


## Installation

To build, first, create a build directory, and switch to it:
```sh
mkdir -p bld/release && cd bld/release
```

Second, configure the build (if you intend to install it globally, you
might also want `--prefix=/usr`):
```sh
meson --buildtype=release \
    -Denable-cairo=disabled|enabled|auto \
    -Dpng-backend=none|libpng \
    -Dsvg-backend=none|librsvg|nanosvg \
    ../..
```

`-D{png,svg}-backend` can be used to force-enable or force-disable a
specific png and/or svg backend. Note that _nanosvg_ is builtin
(i.e. it needs to external dependencies).

`-Denable-cairo` can be used to force-enable or force-disable cairo support.
When disabled, fuzzel will not support SVGs using the _librsvg_ backend.

Three, build it:
```sh
ninja
```

You can now run it directly from the build directory:
```sh
./fuzzel
```

Use command line arguments to configure the look-and-feel:
```sh
./fuzzel --help
```

Optionally, install it:
```sh
ninja install
```

For more detailed configuration information, see the man pages:
```sh
man fuzzel
man fuzzel.ini
```

## License

tussle is released under the [MIT license](LICENSE).

tussle uses nanosvg, released under the [Zlib
license](3rd-party/nanosvg/LICENSE.txt).