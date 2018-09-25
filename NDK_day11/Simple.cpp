#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*void main(){

	// 打开文件  参数1：文件名；参数2：模式 r:可读 w:可写 rb:作为二进制读 wb(作为二进制写)
	// FILE *fopen(const char *filename , const char *mode)

	// 文件名
	char *filename = "E:\\code\\ndk\\NDK_day11\\Simple.txt";
	// 把Simple.txt文件中的内容读出来，返回file指针
	// 参数1：文件名；参数2：可读
	// 打开文件，以读的方式
	FILE *file = fopen(filename , "r");

	//  如果file等于空
	if (!file){
		printf("文件打开失败");
		// 做一些异常处理 , 如退出程序
		exit(0);
	}

	// 如果file不为空

	// 把读出来的数据存储到buffer缓冲区中
	char buffer[10];
	// 缓冲区buffer，一次读取的长度是10，文件指针
	// 用while循环读取数据，可以读取所有数据
	while (fgets(buffer, 10, file)){
		// I am Novate.
		// Don't kill me,I have a family.
		printf("%s", buffer);
	}


	// 关闭文件
	fclose(file);
	getchar();
}*/


/*// 文件的写入
void main(){
	// 文件名
	// 自己在下边目录 定义一个文件名Simple_Write.txt
	char *filename = "E:\\code\\ndk\\NDK_day11\\Simple_Write.txt";
	// 打开文件，以写的方式
	FILE *file = fopen(filename, "w");
	if (!file){
		printf("文件写入失败");
		// 做一些异常处理
		exit(0);  // 退出程序
	}

	// 写入文件：把下边内容写入到Simple_Write.txt文件中
	// 参数1：要写入的内容； 参数2：文件指针
	fputs("I am Novate" , file);

	// 运行成功后，然后就可以在上边目录去找Simple_Write.txt文件，打开该文件，就可以看到写的内容
	// 关闭文件
	fclose(file);
	getchar();
}*/

/*// 文件的复制
void main(){
	// 文件名
	char *filename = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	char *fileCopyName = "E:\\code\\ndk\\NDK_day11\\image_copy.jpg";

	// 打开文件
	FILE *file = fopen(filename , "rb");  // 打开文件后，会返回一个流的指针
	FILE *file_copy = fopen(fileCopyName , "wb"); // 这里会立即新建一个 0kb的文件

	if (!file || !file_copy){
		printf("文件打开失败");
		exit(0);  // 退出程序
	}

	// 参数1：读的缓冲区；参数2：每次偏移多少个字节；参数3：每次读取多少个；参数4：读取的哪个文件
	// size_t fread(void *buffer , size_t size , size_t count , FILE *stream) 

	// int 类型的缓冲区
	int buffer[512];
	// 读取的长度
	int len;
	while ((len = fread(buffer, sizeof(int), 512, file))!=0){
		// 写：参数1表示缓冲区；参数2表示每次偏移多少个字节；参数3表示写入的长度；参数4表示写到哪个文件
		fwrite(buffer , sizeof(int) , len , file_copy); 
	}

	// 关闭文件
	fclose(file);
	fclose(file_copy);
	//getchar();
}*/

/*// 获取文件的大小
void main(){
	// 文件名
	char *filename = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	// 打开文件
	FILE *file = fopen(filename, "rb");  // 打开文件后，会返回一个流的指针
	if (!file){
		printf("文件打开失败");
		exit(0);  // 退出程序
	}

	// 没有一个函数是可以直接拿到文件大小的
	// 思路：将文件的指针移动打最后，然后再去计算偏移量，就可以

	// fseek：将文件移动到哪里去
	// 参数1：文件指针 参数2：从0开始 参数3：从最开始计数 SEEK_SET(移动到开头) SEEK_CUR(移动到当前) SEEK_END(移动到最后)
	fseek(file , 0 , SEEK_END);

	// 计算偏移的位置: 从0开始统计到当前（统计到最后）
	long file_size = ftell(file);
	// 文件大小： 14493
	printf("文件大小： %ld" , file_size);
	// 关闭文件
	fclose(file);

	getchar();
}*/

/*// 文件加密
void main(){
	// 文件名
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	char *fileEncrpyName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";

	// 打开文件
	FILE *file = fopen(fileName, "rb");  // 打开文件后，会返回一个流的指针
	FILE *file_encrpy = fopen(fileEncrpyName, "wb"); // 这里会立即新建一个 0kb的文件

	if (!file || !file_encrpy){
		printf("文件打开失败");
		exit(0);  // 退出程序
	}


	//--------------- 加密 ----------------//
	// 获取每一个字节
	int c;  // EOF end of file：文件结尾
	while ((c = fgetc(file)) != EOF){
		// 把加密后的字节写到 file_encrpy
		fputc(c ^ 5, file_encrpy);
	}
	getchar();
}*/


/*// 文件解密
void main(){
	// 文件名
	char *fileEnName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";
	char *fileDeName = "E:\\code\\ndk\\NDK_day11\\image_de.jpg";

	// 打开文件
	FILE *file = fopen(fileEnName, "rb");  // 打开文件后，会返回一个流的指针
	FILE *file_decrpy = fopen(fileDeName, "wb"); // 这里会立即新建一个 0kb的文件

	if (!file || !file_decrpy){
		printf("文件打开失败");
		exit(0);  // 退出程序
	}


	//--------------- 加密 ----------------//
	// 获取每一个字节
	int c;  // EOF end of file：文件结尾
	while ((c = fgetc(file)) != EOF){
		// 把加密后的字节写到 file_encrpy
		fputc(c ^ 5, file_decrpy);
	}
	getchar();
}*/

/*// 就改一个字节，不行的，可以使用 Mat矩阵
void main(){
	// 文件名
	char *fileEnName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";
	// 打开文件
	FILE *file = fopen(fileEnName, "rb");  // 打开文件后，会返回一个流的指针
	// file叫做流的头指针
	getchar();
}*/


/*// 字符串密码进行加密
void main(){

	// 文件名
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image.jpg";
	char *fileEncrpyName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";

	// 密码：让123456轮流进行异或操作
	char *passWord = "123456";


	// 打开文件
	FILE *file = fopen(fileName, "rb");  // 打开文件后，会返回一个流的指针
	FILE *file_encrpy = fopen(fileEncrpyName, "wb"); // 这里会立即新建一个 0kb的文件

	if (!file || !file_encrpy){
		printf("文件打开失败");
		exit(0);  // 退出程序
	}


	//--------------- 加密 ----------------//
	// 获取每一个字节
	int c;  // EOF end of file：文件结尾
	int index = 0;
	// 获取长度
	int pass_len = strlen(passWord);
	while ((c = fgetc(file)) != EOF){
		// 把加密后的字节写到 file_encrpy
		fputc(c ^ passWord[index%pass_len], file_encrpy);
		index++;
	}
	// getchar();
}*/

/*// 字符串密码进行解密
void main(){

	// 文件名
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image_en.jpg";
	char *fileDeName = "E:\\code\\ndk\\NDK_day11\\image_de.jpg";

	// 密码：让123456轮流进行异或操作
	char *passWord = "123456";


	// 打开文件
	FILE *file = fopen(fileName, "rb");  // 打开文件后，会返回一个流的指针
	FILE *file_decrpty = fopen(fileDeName, "wb"); // 这里会立即新建一个 0kb的文件

	if (!file || !file_decrpty){
		printf("文件打开失败");
		exit(0);  // 退出程序
	}


	//--------------- 加密 ----------------//
	// 获取每一个字节
	int c;  // EOF end of file：文件结尾
	int index = 0;
	// 获取长度
	int pass_len = strlen(passWord);
	while ((c = fgetc(file)) != EOF){
		// 把加密后的字节写到 file_encrpy
		fputc(c ^ passWord[index%pass_len], file_decrpty);
		index++;
	}


	// 关闭文件
	fclose(file);
	fclose(file_decrpty);
	// getchar();
}*/

// 获取文件的大小
int getFileSize(char *fileName){
	FILE *file = fopen(fileName , "rb");

	// 如果file不存在，就返回0
	if (!file){
		return 0;
	}

	// 如果file存在，就移动文件指针
	fseek(file , 0 ,SEEK_END);
	int file_size = ftell(file);

	// 关闭文件
	fclose(file);

	return file_size;
}
// 文件的切割
void main(){

	// 文件名
	char *fileName = "E:\\code\\ndk\\NDK_day11\\image.jpg";

	FILE *file = fopen(fileName , "rb");
	int file_size = getFileSize(fileName);

	// 定义：切多少、计算大小、指定文件名

	// 切3个
	int file_number = 3;
	// 二维数组，其实就是二级指针
	// image_0.jpg：这个是一个 char[], 就是char*, 就是一个一维数组
	// image_1.jpg：这个是一个 char[], 就是char*, 就是一个一维数组
	// image_2.jpg：这个是一个 char[], 就是char*, 就是一个一维数组

	// 开辟3个二维数组
	// 上边3个放到一起就是一个 char[][], 就是 char**，就是一个二维数组
	char **file_names = (char**)malloc(sizeof(char*)* file_number);
	int preFileSize = file_size / file_number;
	// 进行赋值 size_t是int类型的别名

	int i = 0;
	for (; i < 3; i++){
		// 获取上边3个二维数组中的每个一维数组，然后对每个一维数组开辟30个字节
		file_names[i] = (char*)malloc(sizeof(char)* 100);

		// 往fileName里边写
		sprintf(file_names[i], "E:\\code\\ndk\\NDK_day11\\image_%d.jpg", i);

		printf("%s\n", file_names[i]);
	}

	// for循环
	i = 0;
	for (; i < file_number; i++){
		// 从原来的文件中往 切割文件 写入数据，返回当前file指针
		FILE *cur_file = fopen(file_names[i] , "wb");
		// 写多少文件
		int start = i * preFileSize;
		int end = (i + 1)*preFileSize;
		if (i == file_number - 1){
			end = file_size;
		}


		// 第一个循环从file里边读，第二个循环从file里边读
		for (int j = start; j < end; j++){
			// 从file中读取，然后写到cur_file中
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
