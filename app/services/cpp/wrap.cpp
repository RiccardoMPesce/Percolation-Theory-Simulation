#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "MonteCarlo.h"

namespace py = pybind11;

PYBIND11_PLUGIN(wrap) {
    py::module m("wrap", "Example");
    m.def("compute_mean", &compute_mean<double>, "Desc");
    return m.ptr();
}
