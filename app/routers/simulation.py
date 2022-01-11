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

# Esempio ciao

@router.get("/test_simulation")
def test_simulation():
    return {"message": "ok"}

@router.get("/simulate/{size}/{sample_size}")
def simulate(size: int, sample_size: int):
    return mc.simulate(size, sample_size)
