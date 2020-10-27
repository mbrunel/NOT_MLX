# NOT_MLX

This library was created because 42's mlx isn't completely portable.

The functions are implemented with the SDL2 library which means that your project will work everywhere (even windows)
with the same keycodes.

### WARNINGS
```
The original minilibx was made by Olivier Crouzet.             __           __
I don't exactly know how the copyright stuff should be handled   \__(*_*)__/
```
All the functions of the current mlx are implemented;
however the following functions do nothing and return 0 or NULL :
```
mlx_pixel_put(); (useless anyway)
mlx_get_color_value();
mlx_expose_hook ();
mlx_string_put();
mlx_xpm_to_image();
mlx_xpm_file_to_image();
mlx_png_file_to_image();
mlx_do_sync(void *mlx_ptr);
```

## NOT_MLX usage

include:
* mlx.h is the official of the minilibx library
* unofficial.h is declaring some extra functions that you can use
* nmlx.h is including both

linux and macos:
* make this repository to build libnmlx.a
* then link with : gcc *.o \`sdl2-config --libs\` libnmlx.a

windows:
* the most simple solution is to just add the src repository into your visual studio project or whatever
as if they were part of your project

## MLX tutorial

Since nmlx do approximatively the same things than the mlx here's a tuto for beginners :

With that you should have a window with something in it :

* Start by use mlx_init()
* Call mlx_new_window() , mlx_new_img(), and mlx_get_data_addr()
* Fill the returned buffer with the pixels description (ARGB8888) format.
* Call mlx_put_img_to_win()
* Call mlx_loop()

If you want to go further :

* Put the mlx_put_img_to_win() call into an other function.
* Call mlx_loop_hook() with the addr of that funct.
* The previous function will be called constantly permitting a real time randering.


mlx_hook() can manage events :

--- Read the [X.h](incs/X.h) file for descriptions of these events.

* The given function will be called with the given parameter when the given event is triggered.

* If the want your function to be called after a keyboard even then it must be defined like that : foo(int i, void *param);

     i will be the keycode of the touch which triggered the event. (see the [MAC OS keycodes]( https://eastmanreference.com/complete-list-of-applescript-key-codes) for further description.)


* Else if you want it to be called by a mouse event : bar(int i, int x, int y, void *param);

     i is the button, x and y are the coordinates of the mouse when she triggered the event (0,0) for the top left corner of the main window.

See the [test_main.c](test_srcs/main.c) file for a basic implementation of nmlx.

## Extra features

For the functions prototypes, see unofficial.h

4 functions :

* nmlx_smart_hook_on/off : off by default, usefull for static graphics : (the loop_hooked function will be called only if an hooked event was triggered

* nmlx_loop_stop : the mlx_loop function will return.

* nmlx_quit : you should use this after you destroyed all your images and windows.
              it will free all the remaining ressources used by nmlx.
              put it just after the mlx_loop call (it will itself be called just after the nmlx_loop_stop call)

these features are added on my miniRT if you want a proper example.

### Built With

* [SDL2](https://www.libsdl.org/download-2.0.php)

### Contributing

If you find bugs or have any ideas of improvements, start a new issue or message me on slack.

### License

This is licensed under the GNU-3 License - see the [LICENSE.md](LICENSE.md) file for details
