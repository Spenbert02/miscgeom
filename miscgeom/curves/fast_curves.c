#define NPY_TARGET_VERSION NPY_2_0_API_VERSION
#define NPY_NO_DEPRECATED_API NPY_API_VERSION

#include <Python.h>
#include <numpy/arrayobject.h>
#include "curves.h"


static PyObject* cLagrangeInterpolation1D(PyObject* self, PyObject* args) {
    PyObject* t=NULL, *control_points=NULL;
    PyArrayObject* t_arr=NULL, *control_points_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!", &PyArray_Type, &t, &PyArray_Type, &control_points)) {
        return NULL;
    }

    t_arr = (PyArrayObject*) PyArray_FROM_OTF(t, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    control_points_arr = (PyArrayObject*) PyArray_FROM_OTF(control_points, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    if (!t_arr || !control_points_arr) {
        Py_XDECREF(t_arr);
        Py_XDECREF(control_points_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }

    double* t_data = (double*) PyArray_DATA(t_arr);
    double* control_points_data = (double*) PyArray_DATA(control_points_arr);
    npy_intp num_control_points = PyArray_DIM(control_points_arr, 0);

    // Get the size of the t array
    npy_intp t_size = PyArray_SIZE(t_arr);
    
    // Create a new numpy array to hold the result
    PyArrayObject* result_arr = (PyArrayObject*) PyArray_SimpleNew(
        1,                    // number of dimensions
        &t_size,             // shape array
        NPY_DOUBLE           // data type
    );

    if (!result_arr) {
        Py_DECREF(t_arr);
        Py_DECREF(control_points_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to create result numpy array.");
        return NULL;
    }

    double* result_data = (double*) PyArray_DATA(result_arr);
    
    // Call your C function to compute the result
    // Assuming _lagrangeInterpolation1D fills the result_data array
    _lagrangeInterpolation1D(t_data, control_points_data, num_control_points, result_data, t_size);

    Py_DECREF(t_arr);
    Py_DECREF(control_points_arr);

    return (PyObject*) result_arr;
}

static PyMethodDef methods[] = {
    {"cLagrangeInterpolation1D", (PyCFunction)cLagrangeInterpolation1D, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "fast_curves",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_fast_curves(void) {
    import_array();  // Initialize the NumPy C API
    return PyModule_Create(&module);
}
