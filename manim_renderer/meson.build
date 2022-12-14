python_dep = python.dependency()

python.extension_module(
    'hello',
    'hello.c',
    dependencies: [python_dep, pycairo_dep, cairo_dep],
    install: true,
    subdir: 'manim_renderer',
)
