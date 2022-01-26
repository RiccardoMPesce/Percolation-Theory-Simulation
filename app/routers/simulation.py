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

@router.get("/simulate/{size}/{sample_size}")
def simulate(size: int, sample_size: int):
    return mc.simulate(size, sample_size)

@router.get("/simulate_custom_p/{p}/{size}/{sample_size}")
def simulate(p: float, size: int, sample_size: int):
    return mc.simulate_custom_p(p, size, sample_size)
