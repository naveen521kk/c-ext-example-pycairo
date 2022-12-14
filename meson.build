project('manim_renderer', 'c', 'cython',
  version : '0.1.0',
  default_options : ['warning_level=3'])

pymod = import('python')
python = pymod.find_installation('python3')

pyver = python.language_version()
if pyver.version_compare('< 3.7')
  error('Requires Python >= 3.7')
endif

cc = meson.get_compiler('c')

cairo_dep = dependency('cairo', required: true, 
      version: '>= 1.16.0', fallback: ['cairo', 'cairo_dep'])
pycairo_dep = dependency('pycairo', required: true, 
      version: '>= 1.18.0', fallback: ['pycairo', 'pycairo_dep'])

subdir('manim_renderer')
