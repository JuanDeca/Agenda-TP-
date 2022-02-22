#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

	int contadorContactos;
	typedef struct {
		int dni;
		int telefono;
		char nombre[20];
		char apellido[20];
		int dia, mes, anio;
	}Contacto;
	Contacto arrayContactos[100];
	Contacto arrayContactosOA[100];
	Contacto arrayContactosOD[100];
	int ordernarContactos(Contacto c1, Contacto c2) {
	
		if ( c1.anio < c2.anio ) {
			return 1;
		} else if ( c1.anio > c2.anio ) {
			return -1;
		} else if ( c1.mes < c2.mes ) {
			return 1;
		} else if ( c1.mes > c2.mes ) {
			return -1;
		} else if ( c1.dia < c2.dia ) {
			return 1;
		} else if ( c1.dia > c2.dia ) {
			return -1;
		} else {
			return 0;
		}
	
	}

int main(int argc, char *argv[]) {
	
	printf(" ------- Bienvenido a la agenda virtual! ------- \n ");
	
	mostrarMenu();
	
	return 0;
}

void mostrarMenu() {
	
	int selectorMenu;
	
	printf(" \n Que desea hacer?\n");
	
	printf("\n -- Agregar un nuevo contacto       (Presione 1) -- \n");
	printf(" -- Eliminar un contacto            (Presione 2) -- \n");
	printf(" -- Ver lista actual de contactos   (Presione 3) -- \n");
	printf(" -- Buscar un contacto              (Presione 4) -- \n");
	printf(" -- Salir                           (Presione 5) -- \n \n");
	scanf("%d", &selectorMenu);
	
	switch (selectorMenu) {
		case 1:
			agregarContacto();
			break;
		case 2:
			eliminarContacto();
			break;
		case 3:
			verContactos();
			break;
		case 4:
			buscarContacto();
			break;
		case 5:
			return 0;
			break;
		default:
			printf("\n Opcion incorrecta");
			printf("\n Presione cualquier tecla para continuar \n ");
			getch();
			system("cls");
			mostrarMenu();
			break;
	}
	
}

void agregarContacto() {
	
	int dni;
	int i;

	system("cls");
	
	printf("\n  Ingrese el D.N.I del nuevo contacto \n \n ");
	scanf("%d", &dni);
	
	for(i = 0; i < contadorContactos; i++) {
		if (arrayContactos[i].dni == dni) {
			printf("\n Error! El D.N.I ingresado ya esta en el sistema");
			printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
			getch();
			agregarContacto();
		}
	}
	
	
	arrayContactos[contadorContactos].dni = dni;
	
	printf("\n  Ingrese el nombre del nuevo contacto \n \n ");
	scanf("%s", arrayContactos[contadorContactos].nombre); 
	
	printf("\n  Ingrese el apellido del nuevo contacto \n \n ");
	scanf("%s", arrayContactos[contadorContactos].apellido); 
	
	printf("\n Ingrese el numero de telefono del nuevo contacto \n \n ");
	scanf("%d", &arrayContactos[contadorContactos].telefono);
	
	printf("\n Ingrese la fecha en que nacio el contacto nuevo en formato dd/mm/aaaa \n \n ");
	scanf("%d/%d/%d", &arrayContactos[contadorContactos].dia, &arrayContactos[contadorContactos].mes, &arrayContactos[contadorContactos].anio);
	
	contadorContactos = contadorContactos + 1;
	
	printf("\n -------Contacto agregado correctamente! ------- \n ");
	printf("\n Presione cualquier tecla para volver al menu principal \n ");
	getch();
	system("cls");
	mostrarMenu();
	
}

void eliminarContacto() {
	
	system("cls");
	
	int i;
		
	for( i = 0; i < contadorContactos; i++ ) {
		printf("\n %d) %s, %s \n \n ", i, arrayContactos[i].apellido, arrayContactos[i].nombre);
	}
		
	int select5, select6, se, sf;
	
	printf("\n --- Ingrese el numero del contacto que desea eliminar --- \n \n ");
	scanf("%d", &select5);
	
	system("cls");
		
	int result = 0;
	Contacto temp2;
			
	for(i = 0; i < contadorContactos; i++) {
		
		if (select5 == i) {
			
			result = 1;
			
			printf("\n Seguro que desea eliminar a %s, %s ? \n", arrayContactos[i].apellido, arrayContactos[i].apellido);
				
			printf("\n --- si    (Presione 1) --- \n \n ");
			printf("\n --- No    (Presione 2) --- \n \n ");
			scanf("%d", &select6);
			
			int dniE = arrayContactos[select5].dni;
			
			if ( select6 == 1 ) {
				
				for (se = 0; se < contadorContactos; se++) {
					
					sf = se + 1;
					
					if ( arrayContactos[se].dni == dniE ) {
						
						temp2 = arrayContactos[sf];
						arrayContactos[sf] = arrayContactos[se];
						arrayContactos[se] = temp2;
						
					}
					
				}
				
				contadorContactos = contadorContactos - 1;
				
				printf("\n \n --- Contacto eliminado correctamente! --- \n ");
				printf("\n --- Presione cualquier tecla para continuar --- \n ");
				getch();
				system("cls");
				mostrarMenu();				
				
			} else if ( select6 == 2 ) {
				
				system("cls");
				mostrarMenu();
				
			} else {
				
				printf("\n Opcion incorrecta \n");
				printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
				getch();
				system("cls");
				mostrarMenu();
				
			}
			
		}
		
	}

		
	if ( result == 0 ) {
		printf("\n No se ha encontrado ese contacto \n");
		printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		mostrarMenu();
	}
	
}

void verContactos() {

	system("cls");
	
/*	if (contadorContactos == 0) {
		printf("\n Todavia no tiene contactos guardados");
		printf("\n \n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		mostrarMenu();
		return;
	}  */

	int i;
	
	for(i = 0; i < contadorContactos; i++) {
		printf("\n - %s, %s \n \n ", arrayContactos[i].apellido, arrayContactos[i].nombre);
	}
	
	int select;
	printf("\n --- Editar contacto       (Presione 1) --- \n ");
	printf("\n --- Ordenar contactos     (Presione 2) --- \n ");
	printf("\n<-- Regresar               (Presione 3) --- \n \n ");
	scanf("%d", &select);
	
	if ( select == 1 ) {
		
		system("cls");
		
		for(i = 0; i < contadorContactos; i++) {
			printf("\n %d) %s, %s \n \n ", i, arrayContactos[i].apellido, arrayContactos[i].nombre);
		}
		
		int select2, select4;
		printf("\n --- Ingrese el numero del contacto que quiera editar --- \n \n ");
		scanf("%d", &select2);
		
		system("cls");
		
		int result = 0;
		
		for(i = 0; i < contadorContactos; i++) {
			if (select2 == i) {
				result = 1;
				printf("\n 1) Apellido: %s \n", arrayContactos[i].apellido);
				printf("\n 2) Nombre: %s \n", arrayContactos[i].nombre);
				printf("\n 3) D.N.I: %d \n", arrayContactos[i].dni);
				printf("\n 4) Telefono: %d \n", arrayContactos[i].telefono);
				printf("\n 5) dia de nacimiento : %d \n", arrayContactos[i].dia);
				printf("\n 6) mes de nacimiento : %d \n", arrayContactos[i].mes);
				printf("\n 7) anio de nacimiento : %d \n \n", arrayContactos[i].anio);
				
				printf("\n --- Ingrese el numero del dato que quiera editar --- \n \n ");
				scanf("%d", &select4);
			
				switch (select4) {
					case 1:
						printf("\n --- Ingrese el nuevo Apellido --- \n \n ");
						scanf("%s", &arrayContactos[i].apellido);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;
					case 2:
						printf("\n --- Ingrese el nuevo Nombre --- \n \n ");
						scanf("%s", &arrayContactos[i].nombre);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;	
					case 3:
						printf("\n --- Ingrese el nuevo D.N.I --- \n \n ");
						scanf("%d", &arrayContactos[i].dni);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;			
					case 4:
						printf("\n --- Ingrese el nuevo telefono --- \n \n ");
						scanf("%d", &arrayContactos[i].telefono);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;
					case 5:
						printf("\n --- Ingrese el nuevo numero del dia de nacimiento --- \n \n ");
						scanf("%d", &arrayContactos[i].dia);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;
					case 6:
						printf("\n --- Ingrese el nuevo numero del mes de nacimiento --- \n \n ");
						scanf("%d", &arrayContactos[i].mes);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;
					case 7:
						printf("\n --- Ingrese el nuevo anio de nacimiento --- \n \n ");
						scanf("%d", &arrayContactos[i].anio);
						printf("\n \n --- Cambio realizado correctamente! --- \n ");
						printf("\n --- Presione cualquier tecla para continuar --- \n ");
						getch();
						system("cls");
						mostrarMenu();
						break;										
					default:
						printf("\n \n Opcion incorrecta \n");
						printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
						getch();
						system("cls");
						verContactos();
						break;
				}
			}
		}
		
		if ( result == 0 ) {
			printf("\n Opcion incorrecta \n");
			printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
			getch();
			system("cls");
			verContactos();
		}
		
	} else if ( select == 2 ) {
		
		system("cls");
		
		int select3;
			
		printf("\n  --- Ordenar por juventud ascendente       (Presione 1) --- \n ");
		printf("\n  --- Ordenar por juventud descendiente     (Presione 2) --- \n ");
		printf("\n  <-- Regresar                              (Presione 3) --- \n \n ");
		scanf("%d", &select3);
		
		if ( select3 == 1 ) {
			
			system("cls");
			
			int z, f, h, o;
			Contacto temp;
			
			for ( o = 0; o < contadorContactos; o++ ) {
				
				arrayContactosOA[o] = arrayContactos[o];
				
			}

			for (f = 0; f < contadorContactos; f++) {
				
				for ( z = f + 1; z < contadorContactos; z++ ) {
				
					if ( ordernarContactos( arrayContactosOA[f], arrayContactosOA[z] ) == 1 ) {
						
						temp = arrayContactosOA[f];
						arrayContactosOA[f] = arrayContactosOA[z];
						arrayContactosOA[z] = temp;		
						
					}
					
				}
				
			}
			
			for ( h = 0; h < contadorContactos; h++ ) {
				
				printf("\n  --- %s --- \n ", arrayContactosOA[h].nombre);
				printf(" Fecha de nacimiento : %d/%d/%d \n \n", arrayContactosOA[h].dia, arrayContactosOA[h].mes, arrayContactosOA[h].anio);
				
			}
			
			printf("\n Presione cualquier tecla para continuar \n ");
			getch();
			system("cls");
			mostrarMenu();
			
		} else if ( select3 == 2 ) {
			
			system("cls");
			
			int z, f, h, o;
			Contacto temp;
			
			for ( o = 0; o < contadorContactos; o++ ) {
				
				arrayContactosOA[o] = arrayContactos[o];
				
			}

			for (f = 0; f < contadorContactos; f++) {
				
				for ( z = f + 1; z < contadorContactos; z++ ) {
				
					if ( ordernarContactos( arrayContactosOA[f], arrayContactosOA[z] ) == -1 ) {
						
						temp = arrayContactosOA[f];
						arrayContactosOA[f] = arrayContactosOA[z];
						arrayContactosOA[z] = temp;		
						
					}
					
				}
				
			}
			
			for ( h = 0; h < contadorContactos; h++ ) {
				
				printf("\n  --- %s --- \n ", arrayContactosOA[h].nombre);
				printf(" Fecha de nacimiento : %d/%d/%d \n \n", arrayContactosOA[h].dia, arrayContactosOA[h].mes, arrayContactosOA[h].anio);
				
			}		
			
			printf("\n Presione cualquier tecla para continuar \n ");
			getch();
			system("cls");
			mostrarMenu();

		} else if ( select3 == 3 ) {
			
			verContactos();
			
		} else {
			
			printf("\n Opcion incorrecta");
			printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
			getch();
			system("cls");
			verContactos();
			
		}
					
		
	} else if ( select == 3 ) {
		
			system("cls");
			mostrarMenu();		
			
	} else {

		printf("\n Opcion incorrecta");
		printf("\n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		verContactos();
		
	}
	
}

void buscarContacto() {
	
	if (contadorContactos == 0) {
		printf("\n Necesita al menos 1 contacto para poder buscar");
		printf("\n \n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		mostrarMenu();
		return;
	}
	
	system("cls");
	
	int select;
	printf("\n -- Buscar por D.N.I    (Presione 1) -- \n");
	printf("\n -- Buscar por anio     (Presione 2) -- \n");
	printf("\n<-- Regresar            (Presione 3) -- \n \n");
	scanf("%d", &select);
	
	if(select == 1) {
		
		system("cls");
		
		int bdni;
		printf("\n Ingrese el D.N.I de la persona que quiera buscar \n \n");
		scanf("%d", &bdni);
		
		int i;
		
		for(i = 0; i < contadorContactos; i++) {
			
			if(arrayContactos[i].dni == bdni) {
				
				system("cls");
				
				printf(" - %s, %s \n", arrayContactos[i].apellido, arrayContactos[i].nombre);
				printf(" D.N.I: %d \n", arrayContactos[i].dni);
				printf(" Telefono: %d \n", arrayContactos[i].telefono);
				printf(" Fecha de nacimiento : %d/%d/%d \n \n", arrayContactos[i].dia, arrayContactos[i].mes, arrayContactos[i].anio);
				
				printf("\n ---- Presione cualquier tecla para volver al menu principal ---- \n ");
				getch();
				system("cls");
				mostrarMenu();
			}
				
		}
		
		printf("\n No hay ningun contacto con ese D.N.I");
		printf("\n \n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		mostrarMenu();
		
	} else if (select == 2) {
		
		system("cls");
		
		int banio;
		printf("\n Ingrese el anio de nacimiento de la persona que quiera buscar \n \n");
		scanf("%d", &banio);
		
		int i;
		int fin = 1;
		
		for(i = 0; i < contadorContactos; i++) {
			
			if(arrayContactos[i].anio == banio) {
				
				
				if ( fin == 1 )	{
					system("cls");
				}
				
				printf(" - %s, %s \n", arrayContactos[i].apellido, arrayContactos[i].nombre);
				printf(" D.N.I: %d \n", arrayContactos[i].dni);
				printf(" Telefono: %d \n", arrayContactos[i].telefono);
				printf(" Fecha de nacimiento : %d/%d/%d \n \n", arrayContactos[i].dia, arrayContactos[i].mes, arrayContactos[i].anio);
				
				fin = 0;
			
			}
			
		}
		
		if ( fin == 0 ) {
			
				printf("\n ---- Presione cualquier tecla para volver al menu principal ---- \n ");
				getch();
				system("cls");
				mostrarMenu();
		
		}
		
		printf("\n No hay ningun contacto con ese anio de nacimiento");
		printf("\n \n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		mostrarMenu();
		
	} else if (select == 3) {
		
		system("cls");
		mostrarMenu();
		
	} else {
		
		printf("\n Opcion incorrecta");
		printf("\n \n ---- Presione cualquier tecla para continuar ---- \n ");
		getch();
		system("cls");
		buscarContacto();
		
	}
	

}
