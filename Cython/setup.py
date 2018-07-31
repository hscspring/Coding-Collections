from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

ext_modules = [
    Extension("mysin",
              sources=["mysin.pyx"],
              libraries=["m"]  # Unix-like specific
              )
]

setup(name="Demos",
      ext_modules=cythonize(ext_modules))