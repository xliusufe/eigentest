#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <Python.h>
#include <numpy/arrayobject.h>
#include <Eigen/Dense>
#include "cfunct.h"

//using namespace Eigen;
using std::size_t;

typedef double real_t;

typedef Eigen::Matrix<real_t, Eigen::Dynamic, Eigen::Dynamic> pyMatrix;

static PyObject* p_eigen_python_error(NULL);

static PyObject *py_randomDxDMatrix(PyObject *self, PyObject *args) {
    PyObject* p(NULL);
    PyObject* item(NULL);    

    try{
        Py_ssize_t d(0);

        PyArg_ParseTuple(args, "L", &d);
        //Matrix M = Matrix::Random(d,d);
        pyMatrix M1 = pyMatrix::Random(d,d);
        //Eigen::MatrixXd M = MatrixXd::Constant(d, d, 0);
        //Eigen::MatrixXd M = MatrixXd::Random(d, d);
        //pyMatrix M(d,d);
        pyMatrix M = Cov(M1, d);

        Py_ssize_t length = d * d;

        p = PyList_New(length);

        if (p == NULL) {
            std::stringstream msg;
            msg << "Could not allocate a Pylist of "
                << d << "x" << d << " = " << d*d 
                << " size for the return Object";
            throw std::runtime_error(msg.str().c_str());
        } else {
            for (Py_ssize_t i = 0; i < length; ++i) {
                item = PyFloat_FromDouble(M.data()[i]);
                PyList_SET_ITEM(p, i, item);
            }            
        }

    } catch (const std::exception& e) {
        delete p; p = NULL;
        delete item; item = NULL;

        std::string msg = ("randomDxDMatrix failed: ");
        msg += e.what();
        PyErr_SetString(p_eigen_python_error, msg.c_str());
    }

    return p;
}


/* Documentations */
static char module_docs[] = "Calculates the factorial of a large integer, which may be much greater than the maximum memory of any data type.";
static char cfunction_docs[] = "Calculates the factorial of a large integer.";

static PyMethodDef EigenMethods[] = {
    {"randomDxDMatrix",  py_randomDxDMatrix, METH_VARARGS, cfunction_docs},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


/* Module structure */
static struct PyModuleDef eigentestmodule = {
    PyModuleDef_HEAD_INIT,
    "eigentest",           /* name of module */
    module_docs,        /* Doc string (may be NULL) */
    -1,                 /* Size of per-interpreter state or -1 */
    EigenMethods       /* Method table */
};

/*
PyMODINIT_FUNC initeigentest(void) {

    PyObject* p;

    p = Py_InitModule("eigentest", EigenMethods);
    if (p == NULL)
        return;

    p_eigen_python_error = PyErr_NewException(
                                const_cast<char*>("eigentest.error"), 
                                NULL, NULL
                            );
    Py_INCREF(p_eigen_python_error);
    PyModule_AddObject(p, "error", p_eigen_python_error);
}
*/

PyMODINIT_FUNC PyInit_eigentest(void) {
    PyObject *object = PyModule_Create(&eigentestmodule);
    if(object == NULL) {
        return NULL;
    }
    import_array();
    return object;
}