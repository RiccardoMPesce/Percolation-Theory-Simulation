FROM python:3.9

WORKDIR /src
COPY . .
RUN rm -rf build/

RUN apt-get update && apt-get -y install build-essential cmake python3-dev

WORKDIR /src/build

RUN cmake ..
RUN make

WORKDIR /src

RUN pip install --no-cache-dir --upgrade -r /src/requirements.txt

EXPOSE 5000

# CMD ["python", "main.py"]
CMD ["uvicorn", "app.app:app", "--host", "0.0.0.0", "--port", "5000"]