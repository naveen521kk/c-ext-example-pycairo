#include <Python.h>
#include <stdio.h>
#include <py3cairo.h>

static PyObject *
helloworld(PyObject *self, PyObject *args)
{
    printf("Hello World\n");
    return Py_None;
}

static PyObject *
pycairo_plain_surface(PyObject *self, PyObject *args)
{
    cairo_surface_t *surface;
    PyObject *py_surface;
    int width, height;
    if (!PyArg_ParseTuple(args, "ii", &width, &height))
        return NULL;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    py_surface = PycairoSurface_FromSurface(surface, NULL);
    return py_surface;
}

static PyMethodDef
    myMethods[] = {
        {"helloworld", helloworld, METH_NOARGS, "Prints Hello World"},
        {"pycairo_plain_surface", pycairo_plain_surface, METH_VARARGS, "Creates a pycairo surface"},
        {NULL, NULL, 0, NULL}};
static struct PyModuleDef hello = {
    PyModuleDef_HEAD_INIT,
    "hello",
    "Hello World",
    -1,
    myMethods};

PyMODINIT_FUNC
PyInit_hello(void)
{
    PyObject *m;

    m = PyModule_Create(&hello);
    if (m == NULL)
        return NULL;
    if (import_cairo() < 0)
        return NULL;
    return m;
}