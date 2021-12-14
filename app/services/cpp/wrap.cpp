#include <pybind11/pybind11.h>

#include "MonteCarlo.h"

namespace py = pybind11;

PYBIND11_MODULE(wrap, handle) {
    handle.doc() = "MonteCarlo simulation wrapper for Python";

    py::class_<MonteCarlo>(
        handle, "monte_carlo"
    )
    .def(py::init<int>())
    .def_property("network_size", &MonteCarlo::get_network_size, &MonteCarlo::set_network_size)
    .def("get_threshold", &MonteCarlo::get_threshold)
    .def("get_threshold_std", &MonteCarlo::get_threshold_std)
    .def("get_sample_thresholds", &MonteCarlo::get_sample_thresholds)
    .def("get_results_custom_p", &MonteCarlo::get_results_custom_p)
    .def("simulate", &MonteCarlo::simulate)
    .def("simulate_custom_p", &MonteCarlo::simulate_custom_p)
    ;
}
