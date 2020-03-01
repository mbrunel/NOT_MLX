# NOT_MLX

Parce qu'mlx aime les leaks (et n'est pas portable btw)

### WARNINGS
```
The original minilibx was made by Olivier Crouzet.             __           __
I don't exactly know how the copyright stuff should be handled   \__(*_*)__/
```
All the functions of the current mlx are implemented;
however the following functions do nothing and return 0 or NULL :
```
mlx_pixel_put(); (useless trash)
mlx_get_color_value(); (didn't really understand what it does)
mlx_expose_hook (); (same here)

mlx_string_put();           |             SORRY
mlx_xpm_to_image();         | I don't yet manage to compile
mlx_xpm_file_to_image();    | flawlessly sdl-extension on OS X
mlx_png_file_to_image();    |      So coming soon (maybe)

mlx_do_sync(void *mlx_ptr); (maybe usefull for libX but it seems useless anyway)
```
If you really find an interest in some of these of these functions don't hesitate to fork it(:

### Prerequisites

None : just take your validated (or not) project and follow the guideline below to make it compile easily on any platform.
The keycodes which are used to deal with key events will be the MAC OS ones as it is already the case when you use the mlx at 42.
With this implementation you should be able to make a multi-platform graphical project.

## Installing

* first you have to put this repo in the root of your project;
* then you have to do the following adjustments in your makefile :

put before the link commande line
```
$(MAKE) -C NOT_MLX
```
then replace your previous link line which should be something like one of these :
```
gcc *.o libmlx.dylib -o miniRT  ||  gcc *.o mlx/libmlx.a -o miniRT || gcc *.o -lmlx -o miniRT
```
by :
```
gcc *.o NOT_MLX/libnmlx.a `NOT_MLX/libs/SDL2-2.0.10/sdl2-config --cflags --libs` -o miniRT
```
You can keep the same includes and the same source code
or add unnoficial.h if you want to add the extra features.

If you don't success :
* Try to delete all your -Werror flags because linux's gcc has the habit to add some random warnings
* Don't forget that linux's gcc want you to add the used library explicetly during the link

So if you use the libmath for example : 
```
gcc *.o -lm
```
same for pthread etc...

If you still have problems :

* You can see the Makefile's rule [test](Makefile) for a basic idea of what it should look like.
* You can also try to see the Makefile of my [miniRT](https://github.com/42A2/miniRTA2).
* Finally you can contact me on Slack (login : mbrunel, 42 Paris)

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

* nmlx_smart_hook_on/off : Off by default, usefull for static graphics : (the loop_hooked function will be called only if an hooked event was triggered

* nmlx_loop_stop : The mlx_loop function will return.

* nmlx_quit : You should use this after you destroyed all your images and windows.
              It will free all the remaining ressources used by nmlx internally.

these features are added on my miniRT if you want a proper example.

### Built With

* [SDL2](https://www.libsdl.org/download-2.0.php)

### Contributing

If you find bugs or have any ideas of improvements, start an new issue or message me on slack.

### License

This is licensed under the LGPL-3.0 License - see the [LICENSE.md](LICENSE.md) file for details
