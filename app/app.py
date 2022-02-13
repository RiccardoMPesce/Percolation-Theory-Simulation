from fastapi import FastAPI

from .routers import simulation

app = FastAPI()

app.include_router(simulation.router)

@app.get("/")
async def root():
    return {"message": "Hello World"}

    