from setuptools import setup, Extension, find_packages
import numpy
import os
import sys
from os import path


VERSION = '1.0'
os_type = 'MS_WIN64'
if sys.platform.startswith('win32'):
    python_path = sys.base_prefix
    temp = python_path.split("\\")
    version = str(sys.version_info.major) + str(sys.version_info.minor)
    CURRENT_DIR = os.path.dirname(__file__)
    path1 = "-I" + python_path + "\\include"
    path2 = "-L" + python_path + "\\libs"
    os.system('bash pre.sh ' + python_path + ' ' + version)

    extensions = Extension(name='eigentest',
                             sources = ['src/_cfunct.cpp', 'src/cfunct.cpp'],
                             language='c++',
                             extra_compile_args=["-DNDEBUG", "-fopenmp", "-O2", "-Wall", "-std=c++11", "-mtune=generic", "-D%s" % os_type, path1, path2],
                             extra_link_args=['-lgomp'],
                             #libraries=["vcruntime140"],
                             #include_dirs=[numpy.get_include(), 'include','src'],
                             include_dirs=[numpy.get_include(), 'include'],
                             )
else:
    extensions = Extension(name='eigentest',
                             sources = ['src/_cfunct.cpp', 'src/cfunct.cpp'],
                             language='c++',
                             extra_compile_args=["-DNDEBUG", "-fopenmp", "-O2", "-Wall", "-std=c++11"],
                             extra_link_args=['-lgomp'],
                             #libraries=["vcruntime140"],
                             #include_dirs=[numpy.get_include(), 'include','src'],
                             include_dirs=[numpy.get_include(), 'include'],
                             )
                             
                             
this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'README.md')) as f:
      long_description = f.read()


setup (
    name = 'eigentest',
    version=VERSION, 
    ext_modules = [extensions],
    license='MIT',
    description='This is just a demo',
    long_description=long_description,
    long_description_content_type="text/markdown",
    packages=find_packages(),
    install_requires=[],
    url='https://github.com/xliusufe/factpy/',
    author='Xu Liu',
    author_email='liu.xu@sufe.edu.cn',
    maintainer="Xu Liu",
    maintainer_email='liu.xu@sufe.edu.cn',  
    python_requires='>=3.5'
    )