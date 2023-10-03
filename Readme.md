This microservice is responsible for evaluating `ast` against millions of rows of tables with high performance.

## cpp-evaluate

Here, we are translating evaluate service from python to cuda c++.

```sh
cd cpp-evaluate

# pre-requisites
brew install nlohmann-json

# Command to run python file
python evaluate.py

# Command to run c++ file
g++ -o evaluate evaluate.cpp -I/opt/homebrew/Cellar/nlohmann-json/3.11.2/include -std=c++14
./evaluate

# Command to run cuda c++ file
# pending...
```

## grpc

Here, we are testing grpc communication between 2 microservices based on django and c++ respectively.

```sh
cd grpc

docker-compose up
```