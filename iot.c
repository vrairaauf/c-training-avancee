#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Device{
	char nom[10];
	char id[3];
	char marque[10];
	char type[10];
	char addresse[20];
} Device;
/*
type def enum {
	false,
	true
} Boolean;
*/
void addDevice(Device *device){
	FILE *deviceFile=fopen("devices.JSON", "r+");
	fseek(deviceFile, -5, SEEK_END);
	fprintf(deviceFile ,"\t},\n\t\"%s\":{\n\t\t\"%s\":\"%s\",\n\t\t\"%s\":\"%s\",\n\t\t\"%s\":\"%s\",\n\t\t\"%s\":\"%s\"\n\t}\n}", device->nom, "id", device->id, "marque", device->marque, "type",device->type, "addresse", device->addresse);
	printf("Information inserted with succed\n");
	fclose(deviceFile);
}
int main(int argc, char const *argv[])
{
	//ajout d'un nouvelle object
	Device device={
		.nom = "iphone",
		.id="56",
		.marque="arduino",
		.type="smtp",
		.addresse="56-89-ac-65-af"
	};
	addDevice(&device);
	return 0;
}