from fastapi import APIRouter

from ..services.dataset import DatasetService

router = APIRouter(
    prefix="/dataset",
    tags=["dataset"],
    responses={404: {"description": "Not found"}}
)

ds = DatasetService()

@router.get("/")
def root_dataset():
    return {"message": "Please enter valid dataset related commands"}

@router.get("/create/{low}/{high}/{n_objs}")
def get_dataset(low: int, high: int, n_objs: int):
    return ds.dataset_to_json(low, high, n_objs)