# meson.build

project(
    'miscgeom', 
    ['c', 'cpp'], 
    version: '0.0.2', 
    meson_version: '>=1.2.0',
    default_options: [
        'c_std=c99', 
        'cpp_std=c++17'
    ]
)

py = import('python').find_installation(pure: false)

# find numpy include directory
numpy_include = run_command(py, '-c', 'import numpy; print(numpy.get_include())', check: true).stdout().strip()

subdir('miscgeom')
