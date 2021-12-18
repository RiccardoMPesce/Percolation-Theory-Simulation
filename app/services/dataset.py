import numpy as np 
import pandas as pd

import random

from .monte_carlo import SimulationService

class DatasetService:
    """
        With this helper class, we are going to generate our dataset,
        either by an iterator or by dumping all of our simulations
        into a csv file
    """
    def __init__(self):
        self.mc = SimulationService()

    def generate_dataset(self, low_size, high_size, n_objs, batch_size):
        n_loops = n_objs // batch_size
        last_loop_n = n_objs % batch_size

        for _ in range(n_loops):
            x = np.random.randint(low_size, high_size + 1, batch_size)
            y = np.array([self.mc.basic_simulation(size).get("threshold") for size in x])

            yield x, y

        if last_loop_n > 0:
            x = np.random.randint(low_size, high_size + 1, last_loop_n)
            y = np.array([self.mc.basic_simulation(size).get("threshold") for size in x])

            yield x, y

    def dataset_to_json(self, low_size, high_size, n_objs):
        sizes = []
        thresholds = []
        
        for _ in range(n_objs):
            size = random.randint(low_size, high_size + 1)
            sizes += [size]
            thresholds += [self.mc.basic_simulation(size).get("threshold")]
        
        return {i: {sizes[i]: thresholds[i]} for i in range(n_objs)}


def main():
    ds = DatasetService()
    for (x, y) in ds.generate_dataset(10, 20, 1000, 54):
        print(x, y)

if __name__ == "__main__":
    main()

    