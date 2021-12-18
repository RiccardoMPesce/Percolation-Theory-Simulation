import wrap

mc = wrap.monte_carlo(10)
mc.simulate()
print(mc.get_threshold())