from . import wrap

class SimulationService:
    def __init__(self):
        """
            Empty constructor
        """
        pass 

    def basic_simulation(self, size: int, sample_size: int = 20):
        """
            Service module to perform a basic simulation
        """
        mc = wrap.monte_carlo(size)
        mc.simulate(sample_size)
        
        return {"threshold": mc.get_threshold(), "threshold_std": mc.get_threshold_std()}

    def basic_simulation_thresholds(self, size: int, sample_size: int = 20):
        """
            Service module to perform a basic simulation and return 
            the thresholds
        """
        mc = wrap.monte_carlo(size)
        mc.simulate(sample_size)

        return mc.get_sample_thresholds()

    def multiple_simulations(self, size: int, sample_size: int = 20, n_simulations: int = 10):
        """
            Performing different simulations
        """

        return {i: self.basic_simulation(size, sample_size) for i in range(n_simulations)}