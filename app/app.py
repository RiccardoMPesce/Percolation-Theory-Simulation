from fastapi import FastAPI

from .routers import simulation
from .routers import dataset
from .routers import data_source

app = FastAPI()

app.include_router(simulation.router)
app.include_router(dataset.router)
app.include_router(data_source.router)

@app.get("/")
async def root():
    return {"message": "Hello World"}

    