#include <opencv2/opencv.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


void process_1()
{


}

void process_2(int pipe[2])
{
  int size;
  int image_data[999999];
//o erro esta aqui
  read(f_d[2],&image_data,sizeof(size))
}



int main (int argc, char **argv)
{
  int f_d[2];
  pid_t p_id;

IpLImage *image = cvLoadImage("carro,jpeg",CV_LOAD_IMAGE_UNCHANGED);
 if (!image)
  {
    printf("Erro o carregar image");
  } 

 pipe(f_d);

}



