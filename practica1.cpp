#include<stdio.h>
#include<string.h>

struct CD
{
	int codigo;
	char artista[30];
	char album[30];
	int no_canciones;
	float precio;
	int existencias;
};

void AddCd(struct CD discos[], int contador){
	int codigo, noCanciones, existencias;
	char artista[30], album[30];
	float precio;
	
	printf("Agrege el codigo del CD: ");
	scanf("%i", &codigo);
	printf("Agrege el Artista: ");
	scanf("%s", artista);
	printf("Agrege el album: ");
	scanf("%s", album);
	printf("Agrege el numero de canciones: ");
	scanf("%i", &noCanciones);
	printf("Agrege las existencias: ");
	scanf("%i", &existencias);
	printf("Agrege el precio: ");
	scanf("%f", &precio);
	
	discos[contador].codigo = codigo;
	strcpy(discos[contador].artista, artista);
	strcpy(discos[contador].album, album);
	discos[contador].no_canciones = noCanciones;
	discos[contador].existencias = existencias;
	discos[contador].precio = precio;
	
	printf("Listo\n");
}

void ShowCds(struct CD discos[], int contador, int inicio){
	printf("Lista de CDs\n");
	for(inicio; inicio < contador; inicio++){
		printf("--------------\n");
		printf("Codigo: %i\n", discos[inicio].codigo);
		printf("Artista: %s\n", discos[inicio].artista);
		printf("Album: %s\n", discos[inicio].album);
		printf("N. Canciones: %i\n", discos[inicio].no_canciones);
		printf("Existencias: %i\n", discos[inicio].existencias);
		printf("Precio: %f\n", discos[inicio].precio);
		printf("--------------\n");
	}
}

int SearchCd(struct CD discos[], int contador, int codigo){
	printf("Buscando...\n");
	for(int i = 0; i < contador; i++){
		if(discos[i].codigo == codigo)
			return i;
	}
	printf("No se a encontrado ese codigo\n");
	return 404;
}

void UpdateCd(struct CD discos[], int posicion){
	int codigo, noCanciones, existencias, opcion = 0;
	char artista[30], album[30];
	float precio;
	
	while(opcion != 8){
		printf("Seleccione el campo que quiere modificar\n");
		printf("1.-Codigo del CD\n");
		printf("2.-Artista\n");
		printf("3.-Album\n");
		printf("4.-Canciones\n");
		printf("6.-Precio\n");
		printf("7.-Todo\n");
		printf("8.-Salir\n");
		printf("Ingrese su opcion: ");
		scanf("%i", &opcion);
		
		switch(opcion){
			case 1:
				printf("Ingrese el nuevo valor: ");
				scanf("%i", &codigo);
				discos[posicion].codigo=codigo;
				break;
			case 2:
				printf("Ingrese el nuevo valor: ");
				scanf("%s", &artista);
				strcpy(discos[posicion].artista, artista);
				break;
			case 3:
				printf("Ingrese el nuevo valor: ");
				scanf("%s", &album);
				strcpy(discos[posicion].album, album);
				break;
			case 4:
				printf("Ingrese el nuevo valor: ");
				scanf("%i", &existencias);
				discos[posicion].no_canciones = noCanciones;
				break;
			case 5:
				printf("Ingrese el nuevo valor: ");
				scanf("%i", &noCanciones);
				discos[posicion].existencias = existencias;
				break;
			case 6:
				printf("Ingrese el nuevo valor: ");
				scanf("%f", &precio);
				discos[posicion].precio = precio;
				break;
			case 7:
				AddCd(discos, posicion);
				break;
			case 8:
				printf("Saliendo de Actualizar..\n");
				break;
			default:
				printf("Escoja una opcion correecta");
				break;
		}
	}
}

void SaleCd(struct CD discos[], int posicion){
	printf("Revisando existencias...\n");
	
	if(discos[posicion].existencias < 1){
		printf("No hay disponibilidad en esa unidad, :c\n");
		return;
	}
	
	discos[posicion].existencias = discos[posicion].existencias-1;
	printf("Compra realizada\n");  
		
}

int main(){
	
	int opcion, contadorRegistro = 0, codigo, searchCode;
	struct CD discos[50];
	
	while (opcion != 6){
		printf("----------Menu-----------\n");
		printf("1.- Agregar CD\n");
		printf("2.- Mostrar todos los CDs\n");
		printf("3.- Buscar por Codigo\n");
		printf("4.- Modificar\n");
		printf("5.- Realizar Venta\n");
		printf("6.- Salir\n");
		printf("Escoja su opcion:");
		scanf("%i", &opcion);
		
		switch(opcion){
			case 1:
				printf("Bienvenido al menu de agragar CD\n");
				AddCd(discos, contadorRegistro);
				contadorRegistro++;
				break;
			case 2:
				ShowCds(discos, contadorRegistro, 0);
				break;
			case 3:
				printf("Ingrese el codigo a buscar");
				scanf("%i", &codigo);
				searchCode = SearchCd(discos, contadorRegistro, codigo);
				if(searchCode != 404)
					ShowCds(discos, searchCode+1, searchCode);
				break;
			case 4:
				printf("Ingrese el codigo a buscar para modificar");
				scanf("%i", &codigo);
				searchCode = SearchCd(discos, contadorRegistro, codigo);
				if(searchCode != 404)
					UpdateCd(discos, searchCode);
				break;
			case 5:
				printf("Ingrese el codigo del producto que desea comprar");
				scanf("%i", &codigo);
				searchCode = SearchCd(discos, contadorRegistro, codigo);
				if(searchCode != 404)
					SaleCd(discos, searchCode);
				break;
			case 6:
				printf("Adios!...");
				break;
			default:
				printf("escoja una opcion correcta\n");
				break;
				
		}
	}
	
	return 0;
}
