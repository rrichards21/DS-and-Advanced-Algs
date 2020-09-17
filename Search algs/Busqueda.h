class Busqueda {
 private:
  int tam;
  int *vec;
 public:
  Busqueda(int n);
  ~Busqueda();	//constructor
  int size();
  int lineal(int num);
  int binaria(int num);
  int doblada(int num);
};
