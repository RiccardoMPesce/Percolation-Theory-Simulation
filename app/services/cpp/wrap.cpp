#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "MonteCarlo.h"

namespace py = pybind11;

PYBIND11_MODULE(wrap, m) {
    m.doc() = "Example plugin";
    m.def("compute_mean", &compute_mean<double>, "Desc");
    return m.ptr();
}
