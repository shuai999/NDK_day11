#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*void main(){

	// ���ļ�  ����1���ļ���������2��ģʽ r:�ɶ� w:��д rb:��Ϊ�����ƶ� wb(��Ϊ������д)
	// FILE *fopen(const char *filename , const char *mode)

	// �ļ���
	char *filename = "E:\\code\\ndk\\NDK_day11\\Simple.txt";
	// ��Simple.txt�ļ��е����ݶ�����������fileָ��
	// ����1���ļ���������2���ɶ�
	// ���ļ����Զ��ķ�ʽ
	FILE *file = fopen(filename , "r");

	//  ���file���ڿ�
	if (!file){
		printf("�ļ���ʧ��");
		// ��һЩ�쳣���� , ���˳�����
		exit(0);
	}

	// ���file��Ϊ��

	// �Ѷ����������ݴ洢��buffer��������
	char buffer[10];
	// ������buffer��һ�ζ�ȡ�ĳ�����10���ļ�ָ��
	// ��whileѭ����ȡ���ݣ����Զ�ȡ��������
	while (fgets(buffer, 10, file)){
		// I am Novate.
		// Don't kill me,I have a family.
		printf("%s", buffer);
	}


	// �ر��ļ�
	fclose(file);
	getchar();
}*/


/*// �ļ���д��
void main(){
	// �ļ���
	// �Լ����±�Ŀ¼ ����һ���ļ���Simple_Write.txt
	char *filename = "E:\\code\\ndk\\NDK_day11\\Simple_Write.txt";
	// ���ļ�����д�ķ�ʽ
	FILE *file = fopen(filename, "w");
	if (!file){
		printf("�ļ�д��ʧ��");
		// ��һЩ�쳣����
		exit(0);  // �˳�����
	}

	// д���ļ������±�����д�뵽Simple_Write.txt�ļ���
	// ����1��Ҫд������ݣ� ����2���ļ�ָ��
	fputs("I am Novate" , file);

	// ���гɹ���Ȼ��Ϳ������ϱ�Ŀ¼ȥ��Simple_Write.txt�ļ����򿪸��ļ����Ϳ��Կ���д������
	// �ر��ļ�
	fclose(file);
	getchar();
}*/

/*// �ļ��ĸ���
void main(){
	// �ļ���
	char *filename = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	char *fileCopyName = "E:\\code\\ndk\\NDK_day11\\image_copy.jpg";

	// ���ļ�
	FILE *file = fopen(filename , "rb");  // ���ļ��󣬻᷵��һ������ָ��
	FILE *file_copy = fopen(fileCopyName , "wb"); // ����������½�һ�� 0kb���ļ�

	if (!file || !file_copy){
		printf("�ļ���ʧ��");
		exit(0);  // �˳�����
	}

	// ����1�����Ļ�����������2��ÿ��ƫ�ƶ��ٸ��ֽڣ�����3��ÿ�ζ�ȡ���ٸ�������4����ȡ���ĸ��ļ�
	// size_t fread(void *buffer , size_t size , size_t count , FILE *stream) 

	// int ���͵Ļ�����
	int buffer[512];
	// ��ȡ�ĳ���
	int len;
	while ((len = fread(buffer, sizeof(int), 512, file))!=0){
		// д������1��ʾ������������2��ʾÿ��ƫ�ƶ��ٸ��ֽڣ�����3��ʾд��ĳ��ȣ�����4��ʾд���ĸ��ļ�
		fwrite(buffer , sizeof(int) , len , file_copy); 
	}

	// �ر��ļ�
	fclose(file);
	fclose(file_copy);
	//getchar();
}*/

/*// ��ȡ�ļ��Ĵ�С
void main(){
	// �ļ���
	char *filename = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	// ���ļ�
	FILE *file = fopen(filename, "rb");  // ���ļ��󣬻᷵��һ������ָ��
	if (!file){
		printf("�ļ���ʧ��");
		exit(0);  // �˳�����
	}

	// û��һ�������ǿ���ֱ���õ��ļ���С��
	// ˼·�����ļ���ָ���ƶ������Ȼ����ȥ����ƫ�������Ϳ���

	// fseek�����ļ��ƶ�������ȥ
	// ����1���ļ�ָ�� ����2����0��ʼ ����3�����ʼ���� SEEK_SET(�ƶ�����ͷ) SEEK_CUR(�ƶ�����ǰ) SEEK_END(�ƶ������)
	fseek(file , 0 , SEEK_END);

	// ����ƫ�Ƶ�λ��: ��0��ʼͳ�Ƶ���ǰ��ͳ�Ƶ����
	long file_size = ftell(file);
	// �ļ���С�� 14493
	printf("�ļ���С�� %ld" , file_size);
	// �ر��ļ�
	fclose(file);

	getchar();
}*/

/*// �ļ�����
void main(){
	// �ļ���
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	char *fileEncrpyName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";

	// ���ļ�
	FILE *file = fopen(fileName, "rb");  // ���ļ��󣬻᷵��һ������ָ��
	FILE *file_encrpy = fopen(fileEncrpyName, "wb"); // ����������½�һ�� 0kb���ļ�

	if (!file || !file_encrpy){
		printf("�ļ���ʧ��");
		exit(0);  // �˳�����
	}


	//--------------- ���� ----------------//
	// ��ȡÿһ���ֽ�
	int c;  // EOF end of file���ļ���β
	while ((c = fgetc(file)) != EOF){
		// �Ѽ��ܺ���ֽ�д�� file_encrpy
		fputc(c ^ 5, file_encrpy);
	}
	getchar();
}*/


/*// �ļ�����
void main(){
	// �ļ���
	char *fileEnName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";
	char *fileDeName = "E:\\code\\ndk\\NDK_day11\\image_de.jpg";

	// ���ļ�
	FILE *file = fopen(fileEnName, "rb");  // ���ļ��󣬻᷵��һ������ָ��
	FILE *file_decrpy = fopen(fileDeName, "wb"); // ����������½�һ�� 0kb���ļ�

	if (!file || !file_decrpy){
		printf("�ļ���ʧ��");
		exit(0);  // �˳�����
	}


	//--------------- ���� ----------------//
	// ��ȡÿһ���ֽ�
	int c;  // EOF end of file���ļ���β
	while ((c = fgetc(file)) != EOF){
		// �Ѽ��ܺ���ֽ�д�� file_encrpy
		fputc(c ^ 5, file_decrpy);
	}
	getchar();
}*/

/*// �͸�һ���ֽڣ����еģ�����ʹ�� Mat����
void main(){
	// �ļ���
	char *fileEnName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";
	// ���ļ�
	FILE *file = fopen(fileEnName, "rb");  // ���ļ��󣬻᷵��һ������ָ��
	// file��������ͷָ��
	getchar();
}*/


/*// �ַ���������м���
void main(){

	// �ļ���
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	char *fileEncrpyName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";

	// ���룺��123456��������������
	char *passWord = "123456";


	// ���ļ�
	FILE *file = fopen(fileName, "rb");  // ���ļ��󣬻᷵��һ������ָ��
	FILE *file_encrpy = fopen(fileEncrpyName, "wb"); // ����������½�һ�� 0kb���ļ�

	if (!file || !file_encrpy){
		printf("�ļ���ʧ��");
		exit(0);  // �˳�����
	}


	//--------------- ���� ----------------//
	// ��ȡÿһ���ֽ�
	int c;  // EOF end of file���ļ���β
	int index = 0;
	// ��ȡ����
	int pass_len = strlen(passWord);
	while ((c = fgetc(file)) != EOF){
		// �Ѽ��ܺ���ֽ�д�� file_encrpy
		fputc(c ^ passWord[index%pass_len], file_encrpy);
		index++;
	}
	// getchar();
}*/

/*// �ַ���������н���
void main(){

	// �ļ���
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";
	char *fileDeName = "E:\\code\\ndk\\NDK_day11\\image_de.jpg";

	// ���룺��123456��������������
	char *passWord = "123456";


	// ���ļ�
	FILE *file = fopen(fileName, "rb");  // ���ļ��󣬻᷵��һ������ָ��
	FILE *file_decrpty = fopen(fileDeName, "wb"); // ����������½�һ�� 0kb���ļ�

	if (!file || !file_decrpty){
		printf("�ļ���ʧ��");
		exit(0);  // �˳�����
	}


	//--------------- ���� ----------------//
	// ��ȡÿһ���ֽ�
	int c;  // EOF end of file���ļ���β
	int index = 0;
	// ��ȡ����
	int pass_len = strlen(passWord);
	while ((c = fgetc(file)) != EOF){
		// �Ѽ��ܺ���ֽ�д�� file_encrpy
		fputc(c ^ passWord[index%pass_len], file_decrpty);
		index++;
	}


	// �ر��ļ�
	fclose(file);
	fclose(file_decrpty);
	// getchar();
}*/

// ��ȡ�ļ��Ĵ�С
int getFileSize(char *fileName){
	FILE *file = fopen(fileName , "rb");

	// ���file�����ڣ��ͷ���0
	if (!file){
		return 0;
	}

	// ���file���ڣ����ƶ��ļ�ָ��
	fseek(file , 0 ,SEEK_END);
	int file_size = ftell(file);

	// �ر��ļ�
	fclose(file);

	return file_size;
}
// �ļ����и�
void main(){

	// �ļ���
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image.jpg";

	FILE *file = fopen(fileName , "rb");
	int file_size = getFileSize(fileName);

	// ���壺�ж��١������С��ָ���ļ���

	// ��3��
	int file_number = 3;
	// ��ά���飬��ʵ���Ƕ���ָ��
	// image_0.jpg�������һ�� char[], ����char*, ����һ��һά����
	// image_1.jpg�������һ�� char[], ����char*, ����һ��һά����
	// image_2.jpg�������һ�� char[], ����char*, ����һ��һά����

	// ����3����ά����
	// �ϱ�3���ŵ�һ�����һ�� char[][], ���� char**������һ����ά����
	char **file_names = (char**)malloc(sizeof(char*)* file_number);
	int preFileSize = file_size / file_number;
	// ���и�ֵ size_t��int���͵ı���

	int i = 0;
	for (; i < 3; i++){
		// ��ȡ�ϱ�3����ά�����е�ÿ��һά���飬Ȼ���ÿ��һά���鿪��30���ֽ�
		file_names[i] = (char*)malloc(sizeof(char)* 100);

		// ��fileName���д
		sprintf(file_names[i], "E:\\code\\ndk\\NDK_day11\\image_%d.jpg", i);

		printf("%s\n", file_names[i]);
	}

	// forѭ��
	i = 0;
	for (; i < file_number; i++){
		// ��ԭ�����ļ����� �и��ļ� д�����ݣ����ص�ǰfileָ��
		FILE *cur_file = fopen(file_names[i] , "wb");
		// д�����ļ�
		int start = i * preFileSize;
		int end = (i + 1)*preFileSize;
		if (i == file_number - 1){
			end = file_size;
		}


		// ��һ��ѭ����file��߶����ڶ���ѭ����file��߶�
		for (int j = start; j < end; j++){
			// ��file�ж�ȡ��Ȼ��д��cur_file��
			fputc(fgetc(file) , cur_file);
		}

		fclose(cur_file);
		free(file_names[i]);
	}

	fclose(file);
	free(file_names);
	printf("%d" , file_size);
	getchar();
}
