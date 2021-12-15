FROM continuumio/miniconda3

WORKDIR /.
COPY ./ ./src

RUN apt-get update && apt-get -y install build-essential cmake

WORKDIR /build

RUN cmake ../src && make 

WORKDIR /../src

RUN conda env create -f environment.yml
SHELL ["conda", "run", "-n", "py3", "/bin/bash", "-c"]

EXPOSE 5000

ENTRYPOINT ["conda", "run", "-n", "py3", "python3", "main.py"]