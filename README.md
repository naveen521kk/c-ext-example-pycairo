To get the up and running, install the following dependencies:

1. [Meson](http://mesonbuild.com/) - `pip install meson`
2. [ninja](https://ninja-build.org/) - `pip install ninja`
3. [Python](https://www.python.org/) - `sudo apt install python3-dev` (with dev headers)
4. [Cairo](https://www.cairographics.org/) - `sudo apt install libcairo2-dev`

Then, run the following commands:

1. `meson setup builddir` # This will create a build directory, called builddir
2. `meson compile -C builddir` # This will compile the project
3. Set the `PYTHONPATH` environment variable to the `builddir/manim_renderer` directory as well as `builddir/subprojects/pycairo/cairo` directory.
4. Run any command you want.

I would recommend configuring VSCode with `compile_command.json` from `builddir` directory. This will allow you to get autocompletion and other features.
