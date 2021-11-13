# Fawn
Fawn is a header-only GTK+ widget library which provides easy-to-use functions to create widgets.

### Install

To use this library, you need to install `gtk3-dev` package in your GNU/Linux distribution.
In debian-based distributions it's `libgtk-3-dev`.

### Sample Code:

[`demo.c`](demo.c) file is the sample file which contains some widgets.

Compile and run it:

```shell
$ make demo
```

or manually:

```shell
$ gcc demo.c -o bin/fawn-demo `pkg-config --libs --cflags gtk+-3.0`
$ ./bin/fawn-demo
```

Result:

<div>
  <img title="Screenshot" src="./screenshot.png">
</div>

### Functions

All functions list are available in [`fawn.h`](fawn.h) file.
