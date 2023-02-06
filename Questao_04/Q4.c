#include <opencv2/opencv.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


void process_1()
{


}

void process_2()
{

}



int main (int argc, char **argv)
{
  IpLImage *image = cvLoadImage("carro.jpeg",CV_LOAD_IMAGE_UNCHANGED);
  
 if (!image)
  {
    printf("Erro o carregar image");
  } 

}



