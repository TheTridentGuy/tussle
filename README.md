# tussle

My personal fork of [Fuzzel](https://codeberg.org/dnkl/fuzzel)
## What's new
- Current time is displayed above the prompt, in a format that can be set using the `time-format` config option (defaults to `%H:%M:%S`)
- Battery percentage can be displayed across from time. To enable this, add the line `battery=true` in the main section of `tussle.ini`. You can set the path that the battery percentage is read from with the `battery-path` config option (defaults to `/sys/class/power_supply/BAT0/capacity`).


## Requirements

### Runtime

* pixman
* wayland (_client_ and _cursor_ libraries)
* xkbcommon
* cairo (optional, required by librsvg)
* libpng (optional)
* librsvg (optional, for enhanced SVG icon support)
* [fcft](https://codeberg.org/dnkl/fcft) [^1]

Tussle uses the builtin nanosvg backend to render SVG icons by
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
Install dependencies:
```shell
sudo pacman -S resvg libutf8proc
```


To build, create a build directory, and switch to it:
```shell
mkdir -p build/release && cd build/release
```

Configure the build (if you intend to install it globally, you
might also want `--prefix=/usr`):
```shell
meson --buildtype=release \
    -Denable-cairo=disabled|enabled|auto \
    -Dpng-backend=none|libpng \
    -Dsvg-backend=none|librsvg|nanosvg \
    ../..
```

My configuration command looked like:
```shell
meson setup --buildtype=release -Denable-cairo=disabled --reconfigure ../..
```

`-D{png,svg}-backend` can be used to force-enable or force-disable a
specific png and/or svg backend. Note that _nanosvg_ is builtin
(i.e. it needs to external dependencies).

`-Denable-cairo` can be used to force-enable or force-disable cairo support.
When disabled, tussle will not support SVGs using the _librsvg_ backend.

Build it:
```shell
ninja
```

You can now run it directly from the build directory:
```shell
./tussle
```

Use command line arguments to configure the look-and-feel:
```shell
./tussle --help
```

Optionally, install it:
```shell
sudo ninja install
```

## License

tussle, being a fork of [Fuzzel](https://codeberg.org/dnkl/fuzzel), is released under the [MIT license](LICENSE).

tussle uses nanosvg, released under the [Zlib license](3rd-party/nanosvg/LICENSE.txt).