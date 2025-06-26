# Configurações do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = Jogodaforca
SRC = Jogodaforca.cpp

# Regra principal
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Limpar o executável
clean:
	del $(TARGET).exe