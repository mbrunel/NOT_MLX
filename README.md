# NOT_MLX

Parce qu'mlx aime les leaks (et n'est pas portable btw)

### WARNINGS

The original minilibx one was made by Olivier Crouzet.         __           __
I don't exactly know how the copyright stuff should be handled   \__(*_*)__/

all the functions of the current mlx are defined;
however the following functions do nothing and return 0 or NULL :
```
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color); (useless trash)
unsigned int	mlx_get_color_value(void *mlx_ptr, int color); (didn't really understand what it does)
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param); (same here)

int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);  |           SORRY
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);         | I don't yet manage to compile
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);     | flawlessly sdl-extension on OS X
void  *mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);         |  So coming soon (maybe)

int	mlx_do_sync(void *mlx_ptr); (maybe usefull for libX but it seems useless anyway)
```

if you really find an interest in some of these of these functions don't hesitate to fork (:

### Prerequisites

None : just take your validated (or not) project and follow the guide below to make it compile easily on any platform
the keycode to use to deal with events will be the MAC OS ones as it is already the case when you use the mlx in 42.
This implementation should work as fine as it works actually in MAC OS on any platform.

### Installing

* first you have to put this repo in the libs directory or in the root of your project;
* then you have to do the following adjustment in your makefile :

```
$(MAKE) -C NOT_MLX before the link
gcc *.o libmlx.dylib (or -lmlx) should become gcc *.o $(libpath)/NOT_MLX/libnmlx.a $(flags)
with flags = `NOT_MLX/SDL2-2.0.10/sdl2-config --cflags --libs`
```
you can keep the same mlx.h header.
add unnoficial.h if you want to add the extra features.

if you don't success :
try to delete all your -Werror flags because linux's gcc has the habit to add some random warnings
don't forget that linux's gcc want you to add the used library explicetly during the link
so if you use the libmath for example : 
```
gcc *.o $(libpath)/NOT_MLX/libnmlx.a $(flags) -lm
```
same for pthread etc...

You can see the Makefile's rule [test](Makefile) for a basic idea of what it should look like.
You can also try to see the Makefile of my [miniRT](https://github.com/mbrunel/miniRTA2/Makefile).

If you still have problem don't hesitate to find me on Slack (login : mbrunel)

If you are from Epitech well gl hf (but you should be able to afford a Mac anyway)

### MLX tutorial

since nmlx do approximatively the same things than the mlx here's a tuto for beginners :

with that you should have a window with something put in it :

* start by use mlx_init()
* call mlx_new_window() , mlx_new_img(), and mlx_get_data_addr()
* fill the returned buffer with the pixels description (ARGB8888) format.
* call mlx_put_img_to_win()


if you want to go further :

* put the mlx_put_img_to_win() call into an other function.
* call mlx_loop_hook() with the addr of that funct.
* the previous function will be called constantly permitting a real time randering.


mlx_hook() can manage events :

--- read the [X.h](incs/X.h) file for descriptions of these events.

* the given function will be called with the given parameter when the given event is triggered.
* if the want your function to be called after a keyboard even then it must be defined like that : foo(int i, void *param);

i will be the keycode of the touch which triggered the event. (see the [MAC OS keycodes](https://eastmanreference.com/complete-list-of-applescript-key-codes) for further description.)

* else if you want it to be called by a mouse event : bar(int i, int x, int y, void *param);

i is the button, x and y are the coordinates of the mouse when she triggered the event (0,0) for the top left corner of the main window.

see the [test_main.c](test_srcs/main.c) file for a basic implementation of nmlx.

## Extra features

see the unofficial.h header for the protos.

4 functions : 

* nmlx_smart_hook_on/off : off by default, usefull for the low fps projects : (the loop_hooked function will be called only if an hooked event was triggered

* nmlx_loop_stop : the mlx_loop function will return.

* nmlx_quit : you should use this after you destroyed all your images and windows.
              it will free all the remaining ressources used by nmlx.
              put it just after the mlx_loop call (it will itself be called just after the nmlx_loop_stop call)

these features are added on my miniRT if you want a proper example.

## Built With

* [SDL2](https://www.libsdl.org/download-2.0.php)

## Contributing

If you find bugs or have ideas for improvments don't hesitate to fork or message me on slack.

## License

This is licensed under the GNU-3 License - see the [LICENSE.md](LICENSE.md) file for details
