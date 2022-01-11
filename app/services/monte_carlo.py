from . import wrap

class SimulationService:
    def __init__(self):
        """
            Empty constructor
        """
        pass 

    def simulate(self, size: int, sample_size: int = 20):
        """
            Service module to perform a basic simulation
        """
        mc = wrap.monte_carlo(size)
        mc.simulate(sample_size)
        
        return {
            "threshold": mc.get_threshold(), 
            "threshold_std": mc.get_threshold_std(),
            "results": mc.get_sample_thresholds()
        }