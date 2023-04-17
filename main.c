#include <stdio.h>

int main() {
  int opcion, cantidad, continuar;
  float subtotal = 0, descuento, total = 0;
  char nombre[50], cedula[20];
  
  do {
    printf("Menú:\n");
    printf("1. Facturar producto\n");
    printf("2. Imprimir factura\n");
    printf("3. Salir\n");
    printf("Elija una opción: ");
    scanf("%d", &opcion);
    
    switch(opcion) {
      case 1:
        printf("\nProductos:\n");
        printf("a) Llantas (Precio: $150)\n");
        printf("b) Kit Pastillas de freno (Precio: $55)\n");
        printf("c) Kit de embrague (Precio: $180)\n");
        printf("d) Faro (Precio: $70)\n");
        printf("e) Radiador (Precio: $120)\n");
        printf("Elija un producto (a-e): ");
        
        char producto;
        scanf(" %c", &producto);
        
        printf("Ingrese la cantidad: ");
        scanf("%d", &cantidad);
        
        switch(producto) {
          case 'a':
            subtotal += cantidad * 150;
            break;
          case 'b':
            subtotal += cantidad * 55;
            break;
          case 'c':
            subtotal += cantidad * 180;
            break;
          case 'd':
            subtotal += cantidad * 70;
            break;
          case 'e':
            subtotal += cantidad * 120;
            break;
          default:
            printf("Producto no válido\n");
            break;
        }
        
        printf("¿Desea facturar otro producto? (0: No, 1: Sí): ");
        scanf("%d", &continuar);
        break;
        
      case 2:
        if (subtotal == 0) {
          printf("No hay productos en la factura\n");
          break;
        }
        
        printf("Ingrese su nombre: ");
        scanf("%s", nombre);
        
        printf("Ingrese su número de cédula: ");
        scanf("%s", cedula);
        
        printf("\nFactura:\n");
        
        if (subtotal <= 100) {
          descuento = 0;
        } else if (subtotal <= 500) {
          descuento = subtotal * 0.05;
        } else if (subtotal <= 1000) {
          descuento = subtotal * 0.07;
        } else {
          descuento = subtotal * 0.1;
        }
        
        total = subtotal - descuento;
        
        printf("Nombre: %s\n", nombre);
        printf("Cédula: %s\n", cedula);
        printf("Subtotal: $%.2f\n", subtotal);
        printf("Descuento: $%.2f\n", descuento);
        printf("Total: $%.2f\n", total);
        
        subtotal = 0;
        descuento = 0;
        total = 0;
        
        break;
        
      case 3:
        printf("Saliendo...\n");
        break;
        
      default:
        printf("Opción no válida\n");
        break;
    }
  } while (opcion != 3);
  
  return 0;
}