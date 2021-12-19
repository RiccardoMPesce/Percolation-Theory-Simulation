from fastapi import APIRouter

from ..services.data_source import DataSourceService

router = APIRouter(
    prefix="/data_source",
    tags=["data_source"],
    responses={404: {"description": "Not found"}}
)

dss = DataSourceService()

@router.get("/")
def data_source_root():
    return {"message": "Please enter a valid data source operation"}

@router.get("/generate_set_by_size/{size}/{sample_size}")
def generate_set_by_size(size: int, sample_size: int):
    return dss.generate_set_by_size(size, sample_size)