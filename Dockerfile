FROM mambaorg/micromamba:latest
WORKDIR /.
COPY . .
RUN micromamba env create -f environment.yml
RUN cd build
RUN cmake .. 
RUN make 
RUN cd ..
EXPOSE 5000
CMD ["python", "main.py"]