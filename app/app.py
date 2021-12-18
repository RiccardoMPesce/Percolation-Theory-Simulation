from fastapi import FastAPI

from .routers import simulation
from .routers import dataset
from .routers import statistical_learning

app = FastAPI()

app.include_router(simulation.router)
app.include_router(dataset.router)
app.include_router(statistical_learning.router)

@app.get("/")
async def root():
    return {"message": "Hello World"}