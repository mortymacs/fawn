# <u>GT</u>K <u>WI</u>DGET <u>LI</u>BRARY (GTWILI)
gtwili is a GTK+ widget library which provides easy-to-use functions to create widgets.

### Install

To use this library, you need to install `gtk-3-dev` package in your GNU/Linux distribution.

### Sample Code:

```c
#include "gtwili.h"

int main(int argc, char *argv[]) {
  gtwili_init(argc, argv);

  gtwili add_new_btn = create_button("Add New", "button_success");
  gtwili header = create_headerbar("My Application", 1, add_new_btn);
  gtwili window = create_window("My Window", 500, 200, header, TRUE, "", TRUE);

  gtwili_render();
}
```

Compile and run it:

```shell
$ make
$ ./bin/gtwili
```

or manually:

```sh
$ gcc gtwili.c sample.c `pkg-config --cflags gtk+-3.0` -o sample `pkg-config --libs gtk+-3.0`
$ ./sample
```

Result:

![Screenshot](screenshot.png)

