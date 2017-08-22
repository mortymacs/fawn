# <u>GT</u>K <u>WI</u>DGET <u>LI</u>BRARY (GTWILI)
gtwili is a GTK+ widget library which provides easy-to-use functions to create widgets.

### Install

To use this library, you need to install `gtk-3-dev` package in your GNU/Linux distribution.

### Sample Code:

```c
#include "gtwili.h"

int main(int argc, char *argv[]) {
  gtwili_init(argc, argv);

  // simple button
  gtwili top_btn = create_button("Add New", "button_success");

  // big button
  gtwili big_btn = create_bigbutton("Hello World!", "Some description about title", "bigbutton");
  
  // window
  gtwili header = create_headerbar("My Application", 1, top_btn);
  gtwili window = create_window("My Window", 500, 200, header, TRUE, "", TRUE);

  // create box and attach widgets
  gtwili box = create_box(true, 1);
  attach(big_btn, box);
  attach(box, window);

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

### Future Plans

* develop good CSS and styles
* develop more and custom widgets
* develop test cases