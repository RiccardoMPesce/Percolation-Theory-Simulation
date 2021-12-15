import wrap

class WrapperClass:
    def __init__(self, size):
        self.mc = wrap.monte_carlo(size)

wc = WrapperClass(150)
print(wc)