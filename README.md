### 1、 To build the lib

```bash
g++ --shared -fPIC lib.cpp -o libtest.so -I./spdlog/include
```

### 2 、To build the excutable

```bash
g++ main.cpp -o main -ltest -L./ -I./spdlog/include
```

### 3 、run the excutable

```
./main
```

got an excetion:

```bash
terminate called after throwing an instance of 'spdlog::spdlog_ex'

  what():  logger with name 'example' already exists

Aborted (core dumped)
```

