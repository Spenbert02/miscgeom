#define NPY_TARGET_VERSION NPY_2_0_API_VERSION
#define NPY_NO_DEPRECATED_API NPY_API_VERSION

#include <Python.h>
#include <numpy/arrayobject.h>
#include "min_distance.h"


static PyObject* cPointPoint(PyObject* self, PyObject* args) {
    PyObject* p1=NULL, *q1=NULL;
    PyArrayObject* p1_arr=NULL, *q1_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!", &PyArray_Type, &p1, &PyArray_Type, &q1)) {
        return NULL;
    }

    p1_arr = (PyArrayObject*) PyArray_FROM_OTF(p1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    q1_arr = (PyArrayObject*) PyArray_FROM_OTF(q1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    if (!p1_arr || !q1_arr) {
        Py_XDECREF(p1_arr);
        Py_XDECREF(q1_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }

    double* p1_data = (double*) PyArray_DATA(p1_arr);
    double* q1_data = (double*) PyArray_DATA(q1_arr);

    double result = _minDistancePP(p1_data, q1_data);

    Py_DECREF(p1_arr);
    Py_DECREF(q1_arr);

    return Py_BuildValue("d", result);
}

static PyObject* cPointSegment(PyObject* self, PyObject* args) {
    PyObject* p1=NULL, *q1=NULL, *q2=NULL;
    PyArrayObject* p1_arr=NULL, *q1_arr=NULL, *q2_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!O!", &PyArray_Type, &p1, &PyArray_Type, &q1, &PyArray_Type, &q2)) {
        return NULL;
    }

    p1_arr = (PyArrayObject*) PyArray_FROM_OTF(p1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    q1_arr = (PyArrayObject*) PyArray_FROM_OTF(q1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q2_arr = (PyArrayObject*) PyArray_FROM_OTF(q2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    if (!p1_arr || !q1_arr || !q2_arr) {
        Py_XDECREF(p1_arr);
        Py_XDECREF(q1_arr); 
        Py_XDECREF(q2_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }
    
    double* p1_data = (double*) PyArray_DATA(p1_arr);
    double* q1_data = (double*) PyArray_DATA(q1_arr);
    double* q2_data = (double*) PyArray_DATA(q2_arr);

    double result = _minDistancePS(p1_data, q1_data, q2_data);

    Py_DECREF(p1_arr);
    Py_DECREF(q1_arr);
    Py_DECREF(q2_arr);

    return Py_BuildValue("d", result);
}

static PyObject* cPointLine(PyObject* self, PyObject* args) {
    PyObject* p1=NULL, *q1=NULL, *q2=NULL;
    PyArrayObject* p1_arr=NULL, *q1_arr=NULL, *q2_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!O!", &PyArray_Type, &p1, &PyArray_Type, &q1, &PyArray_Type, &q2)) {
        return NULL;
    }

    p1_arr = (PyArrayObject*) PyArray_FROM_OTF(p1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    q1_arr = (PyArrayObject*) PyArray_FROM_OTF(q1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q2_arr = (PyArrayObject*) PyArray_FROM_OTF(q2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    if (!p1_arr || !q1_arr || !q2_arr) {
        Py_XDECREF(p1_arr);
        Py_XDECREF(q1_arr);
        Py_XDECREF(q2_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }

    double* p1_data = (double*) PyArray_DATA(p1_arr);
    double* q1_data = (double*) PyArray_DATA(q1_arr);
    double* q2_data = (double*) PyArray_DATA(q2_arr);

    double result = _minDistancePL(p1_data, q1_data, q2_data);

    Py_DECREF(p1_arr);
    Py_DECREF(q1_arr);
    Py_DECREF(q2_arr);

    return Py_BuildValue("d", result);
}

static PyObject* cSegmentSegment(PyObject* self, PyObject* args) {
    PyObject* p1=NULL, *p2=NULL, *q1=NULL, *q2=NULL;
    PyArrayObject* p1_arr=NULL, *p2_arr=NULL, *q1_arr=NULL, *q2_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!O!O!", &PyArray_Type, &p1, &PyArray_Type, &p2, &PyArray_Type, &q1, &PyArray_Type, &q2)) {
        return NULL;
    }
    
    p1_arr = (PyArrayObject*) PyArray_FROM_OTF(p1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    p2_arr = (PyArrayObject*) PyArray_FROM_OTF(p2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q1_arr = (PyArrayObject*) PyArray_FROM_OTF(q1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q2_arr = (PyArrayObject*) PyArray_FROM_OTF(q2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    
    if (!p1_arr || !p2_arr || !q1_arr || !q2_arr) {
        Py_XDECREF(p1_arr);
        Py_XDECREF(p2_arr);
        Py_XDECREF(q1_arr);
        Py_XDECREF(q2_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }
    
    double* p1_data = (double*) PyArray_DATA(p1_arr);
    double* p2_data = (double*) PyArray_DATA(p2_arr);
    double* q1_data = (double*) PyArray_DATA(q1_arr);
    double* q2_data = (double*) PyArray_DATA(q2_arr);

    double result = _minDistanceSS(p1_data, p2_data, q1_data, q2_data);

    Py_DECREF(p1_arr);
    Py_DECREF(p2_arr);
    Py_DECREF(q1_arr);
    Py_DECREF(q2_arr);

    return Py_BuildValue("d", result);
}

static PyObject* cSegmentLine(PyObject* self, PyObject* args) {
    PyObject* p1=NULL, *p2=NULL, *q1=NULL, *q2=NULL;
    PyArrayObject* p1_arr=NULL, *p2_arr=NULL, *q1_arr=NULL, *q2_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!O!O!", &PyArray_Type, &p1, &PyArray_Type, &p2, &PyArray_Type, &q1, &PyArray_Type, &q2)) {
        return NULL;
    }

    p1_arr = (PyArrayObject*) PyArray_FROM_OTF(p1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    p2_arr = (PyArrayObject*) PyArray_FROM_OTF(p2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q1_arr = (PyArrayObject*) PyArray_FROM_OTF(q1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q2_arr = (PyArrayObject*) PyArray_FROM_OTF(q2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    if (!p1_arr || !p2_arr || !q1_arr || !q2_arr) {
        Py_XDECREF(p1_arr);
        Py_XDECREF(p2_arr);
        Py_XDECREF(q1_arr);
        Py_XDECREF(q2_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }

    double* p1_data = (double*) PyArray_DATA(p1_arr);
    double* p2_data = (double*) PyArray_DATA(p2_arr);
    double* q1_data = (double*) PyArray_DATA(q1_arr);
    double* q2_data = (double*) PyArray_DATA(q2_arr);

    double result = _minDistanceSL(p1_data, p2_data, q1_data, q2_data);

    Py_DECREF(p1_arr);
    Py_DECREF(p2_arr);
    Py_DECREF(q1_arr);
    Py_DECREF(q2_arr);

    return Py_BuildValue("d", result);
}

static PyObject* cLineLine(PyObject* self, PyObject* args) {
    PyObject* p1=NULL, *p2=NULL, *q1=NULL, *q2=NULL;
    PyArrayObject* p1_arr=NULL, *p2_arr=NULL, *q1_arr=NULL, *q2_arr=NULL;

    if (!PyArg_ParseTuple(args, "O!O!O!O!", &PyArray_Type, &p1, &PyArray_Type, &p2, &PyArray_Type, &q1, &PyArray_Type, &q2)) {
        return NULL;
    }

    p1_arr = (PyArrayObject*) PyArray_FROM_OTF(p1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY); 
    p2_arr = (PyArrayObject*) PyArray_FROM_OTF(p2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q1_arr = (PyArrayObject*) PyArray_FROM_OTF(q1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    q2_arr = (PyArrayObject*) PyArray_FROM_OTF(q2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

    if (!p1_arr || !p2_arr || !q1_arr || !q2_arr) {
        Py_XDECREF(p1_arr);
        Py_XDECREF(p2_arr);
        Py_XDECREF(q1_arr);
        Py_XDECREF(q2_arr);
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory for numpy arrays.");
        return NULL;
    }
    
    double* p1_data = (double*) PyArray_DATA(p1_arr);
    double* p2_data = (double*) PyArray_DATA(p2_arr);
    double* q1_data = (double*) PyArray_DATA(q1_arr);
    double* q2_data = (double*) PyArray_DATA(q2_arr);

    double result = _minDistanceLL(p1_data, p2_data, q1_data, q2_data);
    
    Py_DECREF(p1_arr);
    Py_DECREF(p2_arr);
    Py_DECREF(q1_arr);
    Py_DECREF(q2_arr);

    return Py_BuildValue("d", result);
}

static PyMethodDef methods[] = {
    {"cPointPoint", (PyCFunction)cPointPoint, METH_VARARGS, NULL},
    {"cPointSegment", (PyCFunction)cPointSegment, METH_VARARGS, NULL},
    {"cPointLine", (PyCFunction)cPointLine, METH_VARARGS, NULL},
    {"cSegmentSegment", (PyCFunction)cSegmentSegment, METH_VARARGS, NULL},
    {"cSegmentLine", (PyCFunction)cSegmentLine, METH_VARARGS, NULL},
    {"cLineLine", (PyCFunction)cLineLine, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "fast_mindist",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_fast_mindist(void) {
    import_array();  // Initialize the NumPy C API
    return PyModule_Create(&module);
}
