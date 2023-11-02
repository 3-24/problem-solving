FROM ubuntu:22.04

COPY requirements.txt .

# Install dependencies
RUN apt-get update && \
    apt-get install -y git clang python3-pip && \
    pip3 install -r requirements.txt
