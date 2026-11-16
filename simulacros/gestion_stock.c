#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 50
#define MAX_RAZON 40
#define LEN_CUIT 14 /* formato XX-XXXXXXXX-X + '\0' */

typedef struct {
  int dia;
  int mes;
  int anio;
} Fecha;

typedef struct {
  char razonSocial[MAX_RAZON];
  char cuit[LEN_CUIT];
} Proveedor;

typedef struct {
  int codigo;
  char descripcion[MAX_DESC];
  int stock;
  float precio;
  Fecha ultimoIngreso;
  Proveedor proveedor;
} Producto;

/* ---------- Prototipos ---------- */

/* Valida una fecha. Devuelve 1 si es válida, 0 si no. */
int fechaValida(const Fecha *f);

/* Carga n productos al final del inventario, haciendo crecer el arreglo.
   Devuelve la cantidad de productos efectivamente cargados.
   Debe actualizar *inventario y *cantidad por referencia. */
int cargarProductos(Producto **inventario, int *cantidad);

/* Devuelve puntero al producto con ese código, o NULL si no existe. */
Producto *buscarPorCodigo(const Producto *inventario, int cantidad, int codigo);

/* Ingreso (cantidad > 0) o egreso (cantidad < 0). Devuelve 1 si tuvo éxito, 0
 * si no. */
int actualizarStock(Producto *inventario, int cantidad, int codigo,
                    int variacion, const Fecha *fechaIngreso);

/* Devuelve puntero al producto de mayor valor total en stock, o NULL. */
Producto *productoMasValioso(const Producto *inventario, int cantidad);

/* Elimina el producto con ese código. Devuelve 1 si lo eliminó, 0 si no existe
   o si ocurrió un error. */
int eliminarProducto(Producto **inventario, int *cantidad, int codigo);

/* Devuelve arreglo dinámico de punteros a productos con stock < umbral.
 *cantidadEncontrada indica el tamaño del arreglo devuelto. */
Producto **productosStockBajo(Producto *inventario, int cantidad, int umbral,
                              int *cantidadEncontrada);

/* Muestra un producto (usar notación ->). */
void mostrarProducto(const Producto *p);

/* Libera toda la memoria y deja los punteros en estado seguro. */
void liberarInventario(Producto **inventario, int *cantidad);

/* ---------- main parcial ---------- */

int main(void) {
  Producto *inventario = NULL;
  int cantidad = 0;

  /* 1. Cargar productos */
  /* TODO: invocar cargarProductos y verificar el resultado */

  /* 2. Buscar un producto por código ingresado por el usuario y mostrarlo */
  /* TODO */

  /* 3. Registrar un ingreso y luego un egreso sobre un producto.
        Probar también un egreso mayor al stock disponible. */
  /* TODO */

  /* 4. Mostrar el producto de mayor valor total en stock */
  /* TODO */

  /* 5. Pedir un umbral, obtener los productos con stock bajo y listarlos.
        Recordar liberar el arreglo de punteros (¡pero NO los productos
     apuntados!). */
  /* TODO */

  /* 6. Eliminar un producto por código y volver a listar el inventario */
  /* TODO */

  /* 7. Liberar toda la memoria */
  /* TODO */

  return 0;
}

/* ---------- Implementaciones: A COMPLETAR ---------- */
int cargarProductos(Producto **inventario, int *cantidad) {
  printf("Ingrese cuantos productos desea cargar: ");
  scanf("%d", cantidad);
}