# miscgeom/intersection/meson.build

# Define the include directory for c_core
c_core_include = include_directories('../c_core')
eigen_include = include_directories('../third_party/eigen')

# C++ sources that need to be compiled and linked
cpp_sources = [
    '../c_core/min_distance.cpp',
    '../c_core/Point3D.cpp',
    '../c_core/utils.cpp'
]

fast_mindist = py.extension_module(
    'fast_mindist',
    ['fast_mindist.c'] + cpp_sources,  # Include C++ source files
    include_directories: [
        numpy_include,
        c_core_include,
        eigen_include
    ],
    install: true,
    subdir: 'miscgeom/mindist'
)

py.install_sources(
    [
        '__init__.py',
        '_mindist.py'
    ],
    subdir: 'miscgeom/mindist'
)

py.install_sources(
    [
        'tests/test_mindist.py'
    ],
    subdir: 'miscgeom/mindist/tests',
    install_tag: 'tests'
)
