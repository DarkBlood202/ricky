#include<iostream>
#include<string.h>
#include<fstream>
#include<exception>
#include<stdlib.h>
#include<time.h>
using namespace std;

/*//puntero hacia la ubicacion y nombre del archivo
string ubicacion_registro = "data.txt";
string *a_ubicacion= &ubicacion_registro;*/

//estructura usuario
struct Usuario{
    string nombre;
    char sexo[10];
    int edad;
};

//linea divisoria de texto
void linea_divisoria(int n){
	for(int i=0;i<n;i++){
		for(int j=0; j<50; j++){
			cout << "-";
		}
		cout << endl;
	}
	cout << endl;
}

//frases de presentacion de informacion
void frase_presentar_informacion(){
	srand(time(NULL));
	int indice_frase = rand() % 10;
	switch(indice_frase){
		case 0:	cout << "\nPor supuesto. Aqui te presento la informacion que poseo:\n"; break;
		case 1:	cout << "\nEsta es la informacion que tengo al respecto:\n"; break;
		case 2:	cout << "\nHe podido encontrar esto:\n"; break;
		case 3:	cout << "\nPresentando informacion:\n"; break;
		case 4:	cout << "\nLa siguiente informacion le puede ser util:\n"; break;
		case 5:	cout << "\nEsto he podido recabar:\n"; break;
		case 6:	cout << "\nAqui tiene la informacion recolectada:\n"; break;
		case 7:	cout << "\nAqui te muestro lo que tengo a mi disposicion.\n"; break;
		case 8:	cout << "\nMira :3\n"; break;
		case 9:	cout << "\nLook what I got for you, milad... wait, were you a girl?\nAnyway...\n"; break;
	}
}

//informacion sobre stenosis coronaria al usuario
void informacion(){
	
	int opcion_menu;
	bool menu = true;
	
	while(menu){
		cout << "\nPor favor elige el apartado del cual deseas saber:\n\n\t1.Que es la stenosis coronaria." <<
		"\n\t2.Causas de la enfermedad." << "\n\t3.Tratamiento de la enfermedad." << "\n\t4.Regresar al menu principal.";
		cout << "\n\tIngrese opcion: ";
		while(!(cin>>opcion_menu)){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\n\nUhm... Te has confundido. Por favor, ingresa una opcion valida.\n\n";
			cout << "\tIngrese opcion: ";
		}
		
		switch(opcion_menu){
			case 1:
				linea_divisoria(1);
				frase_presentar_informacion();
				cout << "\n\tSTENOSIS CORONARIA\n\n" << 
				"La stenosis coronaria o tambien llamada cardiopatia isquemica, es una enfermedad\n" <<
				"ocasionada por la arteriosclerosis de las arterias coronarias. Estas, son las\n" <<
				"encargadas de proporcionar sangre al musculo cardiaco. La arteriosclerosis coronaria\n" <<
				"es un proceso lento de acumulacion de lipidos (grasa) y linfocitos. Estos procesos\n" <<
				"provocan el estrechamiento (stenosis) de las arterias coronarias.\n" <<
				"Este proceso inicia en las primeras decadas de vida pero es asintomatico hasta que\n" <<
				"la oclusion es tan grave que causa un desequilibrio en el aporte de oxigeno al\n" <<
				"miocardio, provocando asi, una isquemia miocardica o una oclusion subita por trombosis\n" <<
				"de la arteria. Esto concluye finalmente en el sindrome coronario agudo, mas conocido\n" <<
				"como infarto agudo de miocardio.\n";
				break;
			case 2:
				linea_divisoria(1);
				frase_presentar_informacion();
				cout << "\n\tCAUSAS DE LA STENOSIS CORONARIA\n\n" <<
				"Los principales factores que producen la enfermedad son:\n" <<
				"-Edad avanzada.\n-Menopausia.\n-Antecedentes de la enfermedad en la familia.\n" <<
				"-Aumento del colesterol LDL (malo).\n-Disminucion del colesterol HDL (bueno).\n" <<
				"-Tabaquismo.\n-Hipertension arterial.\n-Diabetes miellitus.\n-Obesidad.\n" <<
				"-Sedentarismo.\n-Haber padecido previamente la enfermedad.\n";
				break;
			case 3:
				linea_divisoria(1);
				frase_presentar_informacion();
				cout << "\n\tTRATAMIENTO DE LA STENOSIS CORONARIA\n\n";
				break;
			case 4:
				linea_divisoria(2);
				menu = false; break;
			default:
				cout << "\n\nUhm... Te has confundido. Por favor, ingresa una opcion valida.\n\n"; break;
		}
		
		
		
	}
	
	
}

//guardar datos al archivo
void guardar_datos(Usuario user){
    ofstream registro;
    registro.open("data.txt",ios::app);
    if(registro.fail()){
        cout << "\n\nHubo un error al tratar de abrir el arhivo de datos.";
        throw exception();      
    }
    
    registro /*<< "Nombre: " */<< user.nombre << "\n" <<
	 /*"Sexo: " <<*/ user.sexo << "\n" <<
	  /*"Edad: " <<*/ user.edad << "\n\n";
    
    cout << "\n(Se han guardado los datos)\n\n";
    
    registro.close();
}

//leer nombre desde el archivo
string leer_nombre(){
	ifstream registro;
	registro.open("data.txt",ios::in);
	if(registro.fail()){
		
	}
	else{
		string nombre_de_usuario;
		getline(registro,nombre_de_usuario);
		registro.close();
		return nombre_de_usuario;
	}
}

//primer uso del programa
void primer_uso(Usuario usuario){
	bool confirmar_datos = false;

	cout << "Bienvenid@ a su sistema de asistencia en salud." << "\n\nVeo que es un usuario nuevo. Por favor, cuentame un poco sobre ti." << endl;

	//si datos no son correctos, se sigue preguntando por ellos
    while(!confirmar_datos){
    
        cout <<"\nTu nombre, por favor: ";
        getline(cin,usuario.nombre);
        
        cout << "Un gusto, " << usuario.nombre << ".\n\n";
        
        cout << "Y dime, " << usuario.nombre << ", tu eres del sexo : ";
        cin.getline(usuario.sexo,10,'\n');
        
        cout << "Ya veo. Excelente. Eres del sexo " << /*strlwr(*/usuario.sexo/*)*/ << ".\n\n";

        cout << "Por ultimo, " << usuario.nombre << " , cual es tu edad: ";
        
        //validacion de numero entero
        while(!(cin >> usuario.edad)){
        	cin.clear();
        	cin.ignore(100,'\n');
        	cout << "Uhm... creo que te has confundido, " << usuario.nombre << ".\n";
        	cout << "Por ultimo, " << usuario.nombre << " , cual es tu edad: ";
        }
        
        cout << "Oh entiendo. Tienes " << usuario.edad << ".\n\n";
        
        cout << "Ok. Recapitulemos, te parece?\nEres " << usuario.nombre;
		cout << ", del sexo " << usuario.sexo << " y tienes " << usuario.edad << " anios de edad.";
		
		//limpiar el buffer
  		fflush(stdin);
  		
		bool validez_respuesta=false;
		string respuesta_sn;
		
		while(!validez_respuesta){
			cout << "\n\nSon correctos estos datos? (S/N)\nIngrese su respuesta: ";
			getline(cin,respuesta_sn);
			if (respuesta_sn == "N" || respuesta_sn == "n"){
				cout << "\nComprendido. Intentemoslo nuevamente.\n";
				validez_respuesta=true;
			}
			else if(respuesta_sn == "S" || respuesta_sn == "s"){
				cout << "\nEsplendido. Entonces comencemos.\n";
				guardar_datos(usuario);
    			validez_respuesta=true;
				confirmar_datos=true;
			}
		}

	}
}

//menu de opciones
void menu(){
	bool confirmar_opcion = false;
	int opcion_menu;
	
	while(!confirmar_opcion){
		cout << "\n\tMENU PRINCIPAL\n";
		cout << "1.Informacion.\n2.Iniciar evaluacion de diagnostico.\n3.Revisar previas evaluaciones.\n4.Salir.";
		cout << "\nIngrese opcion: ";
	
		while(!(cin>>opcion_menu)){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\n\nUhm... creo que te has equivocado. Intentalo de nuevo.\n\n";
			cout << "Ingrese opcion: ";
		}
	
		switch(opcion_menu){
			case 1:
				informacion();
				break;
			case 2:
				confirmar_opcion = true; break;
			case 3:
				confirmar_opcion = true; break;
			case 4:
				confirmar_opcion = true; break;
			default:
				cout << "\n\nUhm... creo que te has equivocado. Intentalo de nuevo.\n\n";
		}
	}
}

int main(int argc, char** argv){
    
    Usuario usuario;
    
    ifstream registro;
    registro.open("data.txt",ios::in);
    if(registro.fail()){
    	primer_uso(usuario);
    }
    else{
    	cout << "Bienvenid@ de vuelta, " << leer_nombre() << "!\n";
    }
    menu();

    return 0;
}
