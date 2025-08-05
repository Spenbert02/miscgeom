# miscgeom/intersection/meson.build

# Define the include directory for c_core
c_core_include = include_directories('../c_core')
# eigen_include = include_directories('../third_party/eigen')

# C++ sources that need to be compiled and linked
cpp_sources = [
    '../c_core/curves.c'
]

fast_curves = py.extension_module(
    'fast_curves',
    ['fast_curves.c'] + cpp_sources,  # Include C++ source files
    include_directories: [
        numpy_include,
        c_core_include
    ],
    install: true,
    subdir: 'miscgeom/curves'
)

py.install_sources(
    [
        '__init__.py',
        '_curves.py'
    ],
    subdir: 'miscgeom/curves'
)

py.install_sources(
    [
        'tests/test_curves.py'
    ],
    subdir: 'miscgeom/curves/tests',
    install_tag: 'tests'
)
