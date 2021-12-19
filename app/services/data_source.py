from . import wrap

class DataSourceService:
    def __init__(self):
        pass

    def generate_set_by_size(self, percolation_size, sample_size):
        mc = wrap.monte_carlo(percolation_size)
        mc.simulate(sample_size)
        return {i: val for i, val in enumerate(mc.get_sample_thresholds())}