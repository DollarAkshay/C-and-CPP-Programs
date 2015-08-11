#include <stdio.h>
#include <string.h>

typedef struct {
	unsigned int width;
	unsigned int height;
	unsigned int planes;
	unsigned short bitcount;
	unsigned int size;
} BITMAPINFOHEADER;

typedef struct {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} PIXEL;


int main(){

	FILE *image, *test;
	char fpath[1000], tpath[1000];
	BITMAPINFOHEADER bih;
	int i = 0, b[8], g[8], r[8];

	strcpy(fpath,"MyBMP_200.bmp");

	image = fopen(fpath, "rb+");

	while (image==NULL){
		strcpy(fpath, "MyBMP.bmp");
		image = fopen(fpath, "rb+");
	}

	fseek(image, 2, SEEK_SET);
	fread(&bih.size, 4, 1, image);
	printf("Size=%d\n", bih.size);
	fseek(image, 18, SEEK_SET);
	fread(&bih.width, 4, 1, image);
	fseek(image, 22, SEEK_SET);
	fread(&bih.height, 4, 1, image);
	printf("Width=%d\tHeight=%d\n", bih.width, bih.height);
	fseek(image, 26, SEEK_SET);
	fread(&bih.planes, 2, 1, image);
	printf("Number of planes:%d\n", bih.planes);
	fseek(image, 28, SEEK_SET);
	fread(&bih.bitcount, 2, 1, image);
	printf("Bit Count:%d\n", bih.bitcount);

	PIXEL pic[1000000], p;

	strcpy(tpath, "test.txt");

	test = fopen(tpath, "wb+");

	fseek(image, 56+22*3, SEEK_SET);

	/*for(i=0;i<bih.width*bih.height;i++)*/while (!feof(image)){
		//fread(&p,sizeof(p),1,image);
		fread(&p.blue, sizeof(p.blue), 1, image);
		fread(&p.green, sizeof(p.green), 1, image);
		fread(&p.red, sizeof(p.red), 1, image);
		pic[i] = p;
		fprintf(test, " color(%3d,%3d,%3d),",pic[i].red, pic[i].green, pic[i].blue);
		if (i%5==4)
			fprintf(test, "\n");
		i++;
	}
	fclose(image);
	fclose(test);

	printf("\b\b\n");

	return 0;
}
