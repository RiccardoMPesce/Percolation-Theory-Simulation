from fastapi import FastAPI

from .routers import simulation
from .routers import dataset

app = FastAPI()

app.include_router(simulation.router)
app.include_router(dataset.router)

@app.get("/")
async def root():
    return {"message": "Hello World"}