#include <stdexcept>
#include <string>
#include <sstream>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "cfunct.h"

//using namespace Eigen;
using std::size_t;

typedef double real_t;

typedef Eigen::Matrix<real_t, Eigen::Dynamic, Eigen::Dynamic> pyMatrix;

static PyObject* PY_EIGEN_ERROR(NULL);

static PyObject *py_MatrixPlus_(PyObject *self, PyObject *args) {
    PyObject* p(NULL);
    PyObject* item(NULL);    
	PyObject* M0_,*V0_; 
	
    int d;
    
    if (!PyArg_ParseTuple(args, "OOi", &M0_,&V0_,&d)){
        return NULL;
    }
    pyMatrix M1 = pyMatrix::Random(d,d);
    pyMatrix M = pyMatrix::Random(d,d); 
    _MatrixPlus_(M, M1, d);


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
	Py_DECREF(M0_array);
	Py_DECREF(V0_array);
	
    return p;
}


/* Documentations */
static char module_docs[] = "The module introduction.";
static char cfunction_docs[] = "The function introduction.";

static PyMethodDef EigenMethods[] = {
    {"MatrixPlus_",  py_MatrixPlus_, METH_VARARGS, cfunction_docs},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


/* Module structure */
static struct PyModuleDef eigentestmodule = {
    PyModuleDef_HEAD_INIT,
    "_EIGENTEST",           /* name of module */
    module_docs,        /* Doc string (may be NULL) */
    -1,                 /* Size of per-interpreter state or -1 */
    EigenMethods       /* Method table */
};


PyMODINIT_FUNC PyInit__EIGENTEST(void) {
    PyObject *object = PyModule_Create(&eigentestmodule);
    if(object == NULL) {
        return NULL;
    }
    import_array();
    return object;
}