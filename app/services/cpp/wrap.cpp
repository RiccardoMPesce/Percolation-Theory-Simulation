#include <pybind11/pybind11.h>

#include "MonteCarlo.h"

namespace py = pybind11;

PYBIND11_MODULE(wrap, handle) {
    handle.doc() = "Hello World";

    py::class_<MonteCarlo>(
        handle, "monte_carlo"
    )
    .def(py::init<int>());
    ;
}
