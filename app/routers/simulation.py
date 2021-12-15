from fastapi import APIRouter

router = APIRouter(
    prefix="/simulation",
    tags=["simulation"],
    responses={404: {"description": "Not found"}}
)

@router.get("/")
async def root_simulation():
    return {"message": "Please enter valid simulation related commands"}

@router.get("/test_simulation")
async def test_simulation():
    return {"message": "ok"}