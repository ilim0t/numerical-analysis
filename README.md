# numerical-analysis

# Google Test の Setup
```bash=
git submodule init
git submodule update
```

## Setup
```bash=
mkdir -p build
cd build
cmake ..
make
```

## Usage
```bash=
# buildフォルダの中で
./numerical-analysis  # main.cppの実行
./test/NumericalAnalysisTest  # testの実行
```
