from fastapi import APIRouter

from ..services.monte_carlo import SimulationService

router = APIRouter(
    prefix="/simulation",
    tags=["simulation"],
    responses={404: {"description": "Not found"}}
)

mc = SimulationService()

@router.get("/")
def root_simulation():
    return {"message": "Please enter valid simulation related commands"}

@router.get("/test_simulation")
def test_simulation():
    return {"message": "ok"}

@router.get("/basic_simulation/{size}/{sample_size}")
def basic_simulation(size: int, sample_size: int):
    return mc.basic_simulation(size, sample_size)

@router.get("/multiple_simulations/{size}/{sample_size}/{n_simulations}")
def multiple_simulations(size: int, sample_size: int, n_simulations: int):
    return mc.multiple_simulations(size, sample_size, n_simulations)